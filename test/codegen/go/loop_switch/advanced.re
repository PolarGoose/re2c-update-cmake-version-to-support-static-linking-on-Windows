//go:generate re2go $INPUT -o $OUTPUT -cf --loop-switch -Wno-nondeterministic-tags
package main

import (
	"fmt"
	"os"
)

/*!conditions:re2c*/

const debug bool = true

// Intentionally small to trigger buffer refill.
const SIZE int = 4095

const (
	mtagRoot int = -1
	tagNone int = -1
)

// An m-tag tree is a way to store histories with an O(1) copy operation.
// Histories naturally form a tree, as they have common start and fork at some
// point. The tree is stored as an array of pairs (tag value, link to parent).
// An m-tag is represented with a single link in the tree (array index).
type mtagElem struct {
	elem int
	pred int
}
type mtagTrie = []mtagElem

// Append a single value to an m-tag history.
func add_mtag(trie *mtagTrie, mtag int, value int) int {
	*trie = append(*trie, mtagElem{value, mtag})
	return len(*trie) - 1
}

// Recursively unwind tag histories and collect version components.
func unwind(trie mtagTrie, x int, y int, str []byte) []string {
	// Reached the root of the m-tag tree, stop recursion.
	if x == mtagRoot && y == mtagRoot {
		return []string{}
	}

	// Unwind history further.
	result := unwind(trie, trie[x].pred, trie[y].pred, str)

	// Get tag values. Tag histories must have equal length.
	if x == mtagRoot || y == mtagRoot {
		panic("tag histories have different length")
	}
	ex := trie[x].elem
	ey := trie[y].elem

	if ex != tagNone && ey != tagNone {
		// Both tags are valid string indices, extract component.
		result = append(result, string(str[ex:ey]))
	} else if !(ex == tagNone && ey == tagNone) {
		panic("both tags should be tagNone")
	}
	return result
}

type State struct {
	file     *os.File
	data     []byte
	cur      int
	mar      int
	tok      int
	lim      int
	cond     int
	state    int
	trie     mtagTrie
	/*!stags:re2c format = '\n\t@@ int'; */
	/*!mtags:re2c format = '\n\t@@ int'; */
	accept   int
}

const (
	lexEnd = iota
	lexReady
	lexWaiting
	lexBadPacket
	lexBigPacket
)

func fill(st *State) int {
	shift := st.tok
	used := st.lim - st.tok
	free := SIZE - used

	// Error: no space. In real life can reallocate a larger buffer.
	if free < 1 { return lexBigPacket }

	// Shift buffer contents (discard already processed data).
	copy(st.data[0:], st.data[shift:shift+used])
	st.cur -= shift
	st.mar -= shift
	st.lim -= shift
	st.tok -= shift
	/*!stags:re2c format = '\n\tif st.@@ != tagNone { st.@@ -= shift };'; */

	// Fill free space at the end of buffer with new data.
	n, _ := st.file.Read(st.data[st.lim:SIZE])
	st.lim += n
	st.data[st.lim] = 0 // append sentinel symbol

	return lexReady
}

func lex(st *State) int {
	var yych byte
	var l1, l2, f1, f2, p1, p2, p3, p4 int
loop:
	/*!re2c
		re2c:eof = 0;
		re2c:tags = 1;
		re2c:tags:expression = "st.@@";
		re2c:variable:yyaccept = "st.accept";
		re2c:define:YYPEEK     = "st.data[st.cur]";
		re2c:define:YYSKIP     = "st.cur += 1";
		re2c:define:YYBACKUP   = "st.mar = st.cur";
		re2c:define:YYRESTORE  = "st.cur = st.mar";
		re2c:define:YYSHIFT    = "st.cur += @@";
		re2c:define:YYLESSTHAN = "st.cur >= st.lim";
		re2c:define:YYGETSTATE = "st.state";
		re2c:define:YYSETSTATE = "st.state = @@";
		re2c:define:YYFILL     = "return lexWaiting";
		re2c:define:YYGETCONDITION = "st.cond";
		re2c:define:YYSETCONDITION = "st.cond = @@";
		re2c:define:YYSTAGP    = "@@ = st.cur";
		re2c:define:YYSTAGN    = "@@ = tagNone";
		re2c:define:YYMTAGP    = "@@ = add_mtag(&st.trie, @@, st.cur)";
		re2c:define:YYMTAGN    = "@@ = add_mtag(&st.trie, @@, tagNone)";

		crlf  = '\r\n';
		sp    = ' ';
		htab  = '\t';
		ows   = (sp | htab)*;
		digit = [0-9];
		alpha = [a-zA-Z];
		vchar = [\x1f-\x7e];
		tchar = [-!#$%&'*+.^_`|~] | digit | alpha;

		obs_fold            = #f1 crlf (sp | htab)+ #f2;
		obs_text            = [\x80-\xff];
		field_name          = tchar+;
		field_vchar         = vchar | obs_text;
		field_content       = field_vchar ((sp | htab)+ field_vchar)?;
		field_value_folded  = (field_content* obs_fold field_content*)+;
		header_field_folded = field_value_folded ows;
		token               = tchar+;
		qdtext
			= htab
			| sp
			| [\x21-\x5B\x5D-\x7E] \ '"'
			| obs_text;
		quoted_pair         = '\\' ( htab | sp | vchar | obs_text );
		quoted_string       = '"' ( qdtext | quoted_pair )* '"';
		parameter           = #p1 token #p2 '=' #p3 ( token | quoted_string ) #p4;
		media_type          = @l1 token '/' token @l2 ( ows ';' ows parameter )*;

		<media_type> media_type ows crlf {
			if debug {fmt.Printf("media type: %v\n", string(st.data[l1:l2]))}

			pnames := unwind(st.trie, p1, p2, st.data)
			if debug {fmt.Printf("pnames: %v\n", pnames)}
    
			pvals := unwind(st.trie, p3, p4, st.data)
			if debug {fmt.Printf("pvals: %v\n", pvals)}

			st.tok = st.cur
			goto loop
		}

		<header> header_field_folded crlf {
			folds := unwind(st.trie, f1, f2, st.data)
			if debug {fmt.Printf("folds: %v\n", folds)}

			st.tok = st.cur
			goto loop
		}

		<*> $ { return lexEnd }
		<*> * { return lexBadPacket }
	*/
}

func test(packets []string) int {
	fname := "pipe"
	fw, _ := os.Create(fname);
	fr, _ := os.Open(fname);

	st := &State{
		file:   fr,
		data:   make([]byte, SIZE+1),
		cur:    SIZE,
		mar:    SIZE,
		tok:    SIZE,
		lim:    SIZE,
		cond:   yycmedia_type,
		state:  -1,
		trie:   make([]mtagElem, 0),
		/*!stags:re2c format = '\n\t\t@@: tagNone,'; */
		/*!mtags:re2c format = '\n\t\t@@: mtagRoot,'; */
		accept: 0,
	}
	// data is zero-initialized, no need to write sentinel

	var status int
	send := 0
loop:
	for {
		status = lex(st)
		if status == lexEnd {
			//fmt.Printf("ok, done\n")
			break loop
		} else if status == lexWaiting {
			//fmt.Printf("need more input\n")
			if send < len(packets) {
				//fmt.Printf("sending %d-th packet '%s'\n", send, packets[send])
				fw.WriteString(packets[send])
				send += 1
			}
			status = fill(st)
			if status != lexReady {
				break loop
			}
			//fmt.Printf("refilled buffer, ready to continue\n")
		} else if status == lexBadPacket {
			//fmt.Printf("bad packet\n")
			break loop
		} else {
			panic("unexpected status")
		}
	}

	fr.Close()
	fw.Close()
	os.Remove(fname)

	return status
}

func main() {
	packets := []string{"ap", "plication/j", "son;", " charset=\"", "utf\\\"-8\"\r", "\n", ""}
	if test(packets) != lexEnd { panic("error") }
}

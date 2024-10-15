//go:generate re2go $INPUT -o $OUTPUT -d
package main

import "fmt"

func Lex(str string) int {
	var cursor, marker int

	/*!re2c
	re2c:yyfill:enable = 0;
	re2c:define:YYCTYPE = byte;
	re2c:define:YYPEEK = "str[cursor]";
	re2c:define:YYSKIP = "cursor += 1";
	re2c:define:YYBACKUP  = "marker = cursor";
	re2c:define:YYRESTORE = "cursor = marker";
	re2c:define:YYDEBUG = "fmt.Printf(\"Lex: char '%c' int state %u\\n\", @@{char}, @@{state});";

	end = [\x00];

	* {
		return -1
	}

	[0-9]+ end {
		return 1
	}
	*/
}

func main() {
	if Lex("123\000") != 1 {
		panic("expected 123")
	}
}

// Code generated by re2c, DO NOT EDIT.
//go:generate re2go $INPUT -o $OUTPUT --recursive-functions -i
package main

import (
	"os"
	"strings"
)

const BUFSIZE uint = 4096

type Input struct {
	file  *os.File
	buf   []byte
	cur   uint
	mar   uint
	tok   uint
	lim   uint
	eof   bool
	count int
}

func fill(in *Input) int {
	if in.eof { return -1 } // unexpected EOF

	// Error: lexeme too long. In real life can reallocate a larger buffer.
	if in.tok < 1 { return -2 }

	// Shift buffer contents (discard everything up to the current token).
	copy(in.buf[0:], in.buf[in.tok:in.lim])
	in.cur -= in.tok
	in.mar -= in.tok
	in.lim -= in.tok
	in.tok = 0

	// Fill free space at the end of buffer with new data from file.
	n, _ := in.file.Read(in.buf[in.lim:BUFSIZE])
	in.lim += uint(n)
	in.buf[in.lim] = 0

	// If read less than expected, this is the end of input.
	in.eof = in.lim < BUFSIZE

	return 0
}


func yy0(in *Input) int {
	yych := in.buf[in.cur]
	switch (yych) {
	case ' ':
		in.cur += 1
		return yy3(in)
	case '\'':
		in.cur += 1
		return yy5(in)
	default:
		if (in.lim <= in.cur) {
			if (fill(in) == 0) {
				return yy0(in)
			} else {
				return yy10(in)
			}
		} else {
			in.cur += 1
			return yy1(in)
		}
	}
}

func yy1(in *Input) int {
	return yy2(in)
}

func yy2(in *Input) int {
	return -1
}

func yy3(in *Input) int {
	yych := in.buf[in.cur]
	switch (yych) {
	case ' ':
		in.cur += 1
		return yy3(in)
	default:
		if (in.lim <= in.cur) {
			if (fill(in) == 0) {
				return yy3(in)
			} else {
				return yy4(in)
			}
		} else {
			return yy4(in)
		}
	}
}

func yy4(in *Input) int {
	return lex_loop(in)
}

func yy5(in *Input) int {
	in.mar = in.cur
	yych := in.buf[in.cur]
	if (yych <= 0x00) {
		if (in.lim <= in.cur) {
			if (fill(in) == 0) {
				return yy5(in)
			} else {
				return yy2(in)
			}
		} else {
			in.cur += 1
			return yy6(in)
		}
	} else {
		return yy7(in, yych)
	}
}

func yy6(in *Input) int {
	yych := in.buf[in.cur]
	return yy7(in, yych)
}

func yy7(in *Input, yych byte) int {
	switch (yych) {
	case '\'':
		in.cur += 1
		return yy8(in)
	case '\\':
		in.cur += 1
		return yy9(in)
	default:
		if (in.lim <= in.cur) {
			if (fill(in) == 0) {
				return yy6(in)
			} else {
				return yy11(in)
			}
		} else {
			in.cur += 1
			return yy6(in)
		}
	}
}

func yy8(in *Input) int {
	in.count += 1; return lex_loop(in)
}

func yy9(in *Input) int {
	yych := in.buf[in.cur]
	if (yych <= 0x00) {
		if (in.lim <= in.cur) {
			if (fill(in) == 0) {
				return yy9(in)
			} else {
				return yy11(in)
			}
		} else {
			in.cur += 1
			return yy6(in)
		}
	} else {
		in.cur += 1
		return yy6(in)
	}
}

func yy10(in *Input) int {
	return in.count
}

func yy11(in *Input) int {
	in.cur = in.mar
	return yy2(in)
}

func lex(in *Input) int {
	return yy0(in)
}



func lex_loop(in *Input) int {
	in.tok = in.cur
	return lex(in)
}

func main() () {
	fname := "input"
	content := "'qu\000tes' 'are' 'fine: \\'' ";

	// Prepare input file: a few times the size of the buffer, containing
	// strings with zeroes and escaped quotes.
	f, _ := os.Create(fname)
	f.WriteString(strings.Repeat(content, int(BUFSIZE)))
	f.Seek(0, 0)
	count := 3 * int(BUFSIZE) // number of quoted strings written to file

	// Prepare lexer state: all offsets are at the end of buffer.
	in := &Input{
		file:  f,
		// Sentinel at `lim` offset is set to zero, which triggers YYFILL.
		buf:   make([]byte, BUFSIZE+1),
		cur:   BUFSIZE,
		mar:   BUFSIZE,
		tok:   BUFSIZE,
		lim:   BUFSIZE,
		eof:   false,
		count: 0,
	}

	// Run the lexer.
	if lex_loop(in) != count { panic("error"); }

	// Cleanup: remove input file.
	f.Close();
	os.Remove(fname);
}

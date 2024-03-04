// Code generated by re2c, DO NOT EDIT.
//go:generate re2go $INPUT -o $OUTPUT --recursive-functions -i
package main

import "errors"

const u32Limit uint64 = 1<<32
var (
	eSyntax   = errors.New("syntax error")
	eOverflow = errors.New("overflow error")
)

func adddgt(base uint64, digit byte, result uint64) uint64 {
	result = result * base + uint64(digit)
	if result >= u32Limit {
		result = u32Limit
	}
	return result
}


func yy0(str string, cur int, mar int, result uint64) (uint64, error) {
	yych := str[cur]
	cur += 1
	switch (yych) {
	case '0':
		return yy2(str, cur, mar, result)
	case '1','2','3','4','5','6','7','8','9':
		return yy4(str, cur, mar, result)
	default:
		return yy1(str, cur, mar, result)
	}
}

func yy1(str string, cur int, mar int, result uint64) (uint64, error) {
	return 0, eSyntax
}

func yy2(str string, cur int, mar int, result uint64) (uint64, error) {
	mar = cur
	yych := str[cur]
	switch (yych) {
	case 'B':
		fallthrough
	case 'b':
		cur += 1
		return yy5(str, cur, mar, result)
	case 'X':
		fallthrough
	case 'x':
		cur += 1
		return yy7(str, cur, mar, result)
	default:
		return yy3(str, cur, mar, result)
	}
}

func yy3(str string, cur int, mar int, result uint64) (uint64, error) {
	return lex_oct(str, cur, mar, result)
}

func yy4(str string, cur int, mar int, result uint64) (uint64, error) {
	cur += -1
	return lex_dec(str, cur, mar, result)
}

func yy5(str string, cur int, mar int, result uint64) (uint64, error) {
	yych := str[cur]
	switch (yych) {
	case '0','1':
		cur += 1
		return yy8(str, cur, mar, result)
	default:
		return yy6(str, cur, mar, result)
	}
}

func yy6(str string, cur int, mar int, result uint64) (uint64, error) {
	cur = mar
	return yy3(str, cur, mar, result)
}

func yy7(str string, cur int, mar int, result uint64) (uint64, error) {
	yych := str[cur]
	switch (yych) {
	case '0','1','2','3','4','5','6','7','8','9':
		fallthrough
	case 'A','B','C','D','E','F':
		fallthrough
	case 'a','b','c','d','e','f':
		cur += 1
		return yy9(str, cur, mar, result)
	default:
		return yy6(str, cur, mar, result)
	}
}

func yy8(str string, cur int, mar int, result uint64) (uint64, error) {
	cur += -1
	return lex_bin(str, cur, mar, result)
}

func yy9(str string, cur int, mar int, result uint64) (uint64, error) {
	cur += -1
	return lex_hex(str, cur, mar, result)
}

func lex(str string, cur int, mar int, result uint64) (uint64, error) {
	return yy0(str, cur, mar, result)
}




func yy10(str string, cur int, mar int, result uint64) (uint64, error) {
	yych := str[cur]
	cur += 1
	switch (yych) {
	case 0x00:
		return yy11(str, cur, mar, result)
	case '0','1':
		return yy13(str, cur, mar, result)
	default:
		return yy12(str, cur, mar, result)
	}
}

func yy11(str string, cur int, mar int, result uint64) (uint64, error) {
	return result, nil
}

func yy12(str string, cur int, mar int, result uint64) (uint64, error) {
	return 0, eSyntax
}

func yy13(str string, cur int, mar int, result uint64) (uint64, error) {
	result = adddgt(2, str[cur-1]-'0', result); return lex_bin(str, cur, mar, result)
}

func lex_bin(str string, cur int, mar int, result uint64) (uint64, error) {
	return yy10(str, cur, mar, result)
}




func yy14(str string, cur int, mar int, result uint64) (uint64, error) {
	yych := str[cur]
	cur += 1
	switch (yych) {
	case 0x00:
		return yy15(str, cur, mar, result)
	case '0','1','2','3','4','5','6','7':
		return yy17(str, cur, mar, result)
	default:
		return yy16(str, cur, mar, result)
	}
}

func yy15(str string, cur int, mar int, result uint64) (uint64, error) {
	return result, nil
}

func yy16(str string, cur int, mar int, result uint64) (uint64, error) {
	return 0, eSyntax
}

func yy17(str string, cur int, mar int, result uint64) (uint64, error) {
	result = adddgt(8, str[cur-1]-'0', result); return lex_oct(str, cur, mar, result)
}

func lex_oct(str string, cur int, mar int, result uint64) (uint64, error) {
	return yy14(str, cur, mar, result)
}




func yy18(str string, cur int, mar int, result uint64) (uint64, error) {
	yych := str[cur]
	cur += 1
	switch (yych) {
	case 0x00:
		return yy19(str, cur, mar, result)
	case '0','1','2','3','4','5','6','7','8','9':
		return yy21(str, cur, mar, result)
	default:
		return yy20(str, cur, mar, result)
	}
}

func yy19(str string, cur int, mar int, result uint64) (uint64, error) {
	return result, nil
}

func yy20(str string, cur int, mar int, result uint64) (uint64, error) {
	return 0, eSyntax
}

func yy21(str string, cur int, mar int, result uint64) (uint64, error) {
	result = adddgt(10, str[cur-1]-'0', result); return lex_dec(str, cur, mar, result)
}

func lex_dec(str string, cur int, mar int, result uint64) (uint64, error) {
	return yy18(str, cur, mar, result)
}




func yy22(str string, cur int, mar int, result uint64) (uint64, error) {
	yych := str[cur]
	cur += 1
	switch (yych) {
	case 0x00:
		return yy23(str, cur, mar, result)
	case '0','1','2','3','4','5','6','7','8','9':
		return yy25(str, cur, mar, result)
	case 'A','B','C','D','E','F':
		return yy26(str, cur, mar, result)
	case 'a','b','c','d','e','f':
		return yy27(str, cur, mar, result)
	default:
		return yy24(str, cur, mar, result)
	}
}

func yy23(str string, cur int, mar int, result uint64) (uint64, error) {
	return result, nil
}

func yy24(str string, cur int, mar int, result uint64) (uint64, error) {
	return 0, eSyntax
}

func yy25(str string, cur int, mar int, result uint64) (uint64, error) {
	result = adddgt(16, str[cur-1]-'0', result);    return lex_hex(str, cur, mar, result)
}

func yy26(str string, cur int, mar int, result uint64) (uint64, error) {
	result = adddgt(16, str[cur-1]-'A'+10, result); return lex_hex(str, cur, mar, result)
}

func yy27(str string, cur int, mar int, result uint64) (uint64, error) {
	result = adddgt(16, str[cur-1]-'a'+10, result); return lex_hex(str, cur, mar, result)
}

func lex_hex(str string, cur int, mar int, result uint64) (uint64, error) {
	return yy22(str, cur, mar, result)
}



func parse_u32(str string) (uint32, error) {
	result, err := lex(str, 0, 0, uint64(0))
	if err != nil {
		return 0, err
	} else if result < u32Limit {
		return uint32(result), nil
	} else {
		return 0, eOverflow
	}
}

func main() {
	test := func(num uint32, str string, err error) {
		if n, e := parse_u32(str); !(n == num && e == err) {
			panic("error")
		}
	}
	test(1234567890, "1234567890\000", nil)
	test(13, "0b1101\000", nil)
	test(0x7fe, "0x007Fe\000", nil)
	test(0644, "0644\000", nil)
	test(0, "9999999999\000", eOverflow)
	test(0, "123??\000", eSyntax)
}
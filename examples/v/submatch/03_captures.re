// re2v $INPUT -o $OUTPUT

struct SemVer {
    major int
    minor int
    patch int
}

fn s2n(s string) int { // convert pre-parsed string to number
    mut n := 0
    for c in s { n = n * 10 + int(c - 48) }
    return n
}

fn parse(yyinput string) ?SemVer {
    mut yycursor, mut yymarker := 0, 0
    mut yytl0, mut yytl1, mut yytl2, mut yytl3 := 0, 0, 0, 0
    mut yytr0, mut yytr1, mut yytr2, mut yytr3 := 0, 0, 0, 0

    // Autogenerated tag variables used by the lexer to track tag values.
    /*!stags:re2c format = '\tmut @@ := 0\n'; */

    /*!re2c
        re2c:yyfill:enable = 0;
        re2c:captvars = 1;

        num = [0-9]+;

        (num) "." (num) ("." num)? [\x00] {
            _ := yytl0; _ := yytr0 // some variables are unused
            return SemVer {
                major: s2n(yyinput[yytl1..yytr1]),
                minor: s2n(yyinput[yytl2..yytr2]),
                patch: if yytl3 == -1 {0} else {s2n(yyinput[yytl3 + 1..yytr3])}
            }
        }
        * { return none }
    */
}

fn main() {
    test := fn (result ?SemVer, expect ?SemVer) {
        if r := result {
            if e := expect { if r != e { panic("expected $e, got $r") } }
        } else {
            if _ := result { panic("expected none") }
        }
    }
    test(parse("23.34\0"), SemVer{23, 34, 0})
    test(parse("1.2.9999\0"), SemVer{1, 2, 9999})
    test(parse("1.a\0"), none)
}

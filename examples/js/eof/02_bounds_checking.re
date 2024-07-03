// re2js $INPUT -o $OUTPUT

/*!max:re2c*/

function lex(yyinput) {
    var yycursor = 0;
    var yylimit = yyinput.length
    var count = 0

    loop: while (true) {
    /*!re2c
        re2c:define:YYFILL = "return -1";

        str = ['] ([^'\\] | [\\][^])* ['];

        [\x00] {
            // check that it is the sentinel, not some unexpected null
            return (yycursor == yylimit - YYMAXFILL + 1) ? count : -1
        }
        str  { count += 1; continue loop }
        [ ]+ { continue loop }
        *    { return -1 }
    */
    }
}

function test(s, n) {
    var padded_s = s + "\0".repeat(YYMAXFILL)
    if (lex(padded_s) != n) throw "error!"
}

test("", 0)
test("'unterminated\\'", -1)
test("'qu\0tes' 'are' 'fine: \\'' ", 3)
test("'unexpected \0 null", -1)

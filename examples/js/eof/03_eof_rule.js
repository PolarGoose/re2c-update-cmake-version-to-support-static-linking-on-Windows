// Generated by re2c
// re2js $INPUT -o $OUTPUT

// expects a null-terminated string
function lex(yyinput) {
    var yycursor = 0;
    var yylimit = yyinput.length - 1 // terminating null not included
    var count = 0

    loop: while (true) {
    
{
    var yych = 0
    var yystate = 0
    yyl: while (true) {
        switch (yystate) {
            case 0:
                yych = yyinput.charCodeAt(yycursor)
                switch (yych) {
                    case 0x20:
                        yycursor += 1;
                        yystate = 3
                        continue yyl
                    case 0x27:
                        yycursor += 1;
                        yystate = 5
                        continue yyl
                    default:
                        if (yylimit <= yycursor) {
                            yystate = 10
                            continue yyl
                        }
                        yycursor += 1;
                        yystate = 1
                        continue yyl
                }
            case 1:
                yystate = 2
                continue yyl
            case 2:
                { return -1 }
            case 3:
                yych = yyinput.charCodeAt(yycursor)
                switch (yych) {
                    case 0x20:
                        yycursor += 1;
                        yystate = 3
                        continue yyl
                    default:
                        yystate = 4
                        continue yyl
                }
            case 4:
                { continue loop }
            case 5:
                yymarker = yycursor;
                yych = yyinput.charCodeAt(yycursor)
                if (yych >= 0x01) {
                    yystate = 7
                    continue yyl
                }
                if (yylimit <= yycursor) {
                    yystate = 2
                    continue yyl
                }
                yycursor += 1;
                yystate = 6
                continue yyl
            case 6:
                yych = yyinput.charCodeAt(yycursor)
                yystate = 7
                continue yyl
            case 7:
                switch (yych) {
                    case 0x27:
                        yycursor += 1;
                        yystate = 8
                        continue yyl
                    case 0x5C:
                        yycursor += 1;
                        yystate = 9
                        continue yyl
                    default:
                        if (yylimit <= yycursor) {
                            yystate = 11
                            continue yyl
                        }
                        yycursor += 1;
                        yystate = 6
                        continue yyl
                }
            case 8:
                { count += 1; continue loop }
            case 9:
                yych = yyinput.charCodeAt(yycursor)
                if (yych <= 0x00) {
                    if (yylimit <= yycursor) {
                        yystate = 11
                        continue yyl
                    }
                    yycursor += 1;
                    yystate = 6
                    continue yyl
                }
                yycursor += 1;
                yystate = 6
                continue yyl
            case 10:
                { return count }
            case 11:
                yycursor = yymarker;
                yystate = 2
                continue yyl
            default:
                throw "internal lexer error"
        }
    }
}

    }
}

function test(s, n) { if (lex(s) != n) throw "error!"; }
test("\0", 0)
test("'qu\0tes' 'are' 'fine: \\'' \0", 3)
test("'unterminated\\'\0", -1)

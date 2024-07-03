// Generated by re2c
// re2js $INPUT -o $OUTPUT

const fs = require('fs')

const BUFSIZE = 4096
const OK = 0
const EOF = 1
const LONG_LEXEME = 2

function fill(st) {
    if (st.eof) return EOF

    // Error: lexeme too long. In real life could reallocate a larger buffer.
    if (st.token < 1) return LONG_LEXEME

    // Shift buffer contents (discard everything up to the current token).
    st.yyinput.copy(st.yyinput, 0, st.token, st.yylimit)
    st.yycursor -= st.token;
    st.yymarker -= st.token;
    st.yylimit -= st.token;
    st.token = 0;

    // Read a new chunk of data from file and append it to `yyinput`.
    var want = BUFSIZE - st.yylimit - 1 // -1 for sentinel
    var nread = fs.readSync(st.file, st.yyinput, st.yylimit, want)
    st.eof = nread < want // end of file?
    st.yylimit += nread
    st.yyinput.writeUInt8(0, st.yylimit) // sentinel

    return OK
}

function lex(yyrecord, count) {
    loop: while (true) {
        yyrecord.token = yyrecord.yycursor
        
{
    var yych = 0
    var yystate = 0
    yyl: while (true) {
        switch (yystate) {
            case 0:
                yych = yyrecord.yyinput.readUInt8(yyrecord.yycursor)
                switch (yych) {
                    case 0x20:
                        yyrecord.yycursor += 1;
                        yystate = 3
                        continue yyl
                    case 0x27:
                        yyrecord.yycursor += 1;
                        yystate = 5
                        continue yyl
                    default:
                        if (yyrecord.yylimit <= yyrecord.yycursor) {
                            if (fill(yyrecord) == OK) {
                                yystate = 0
                                continue yyl
                            }
                            yystate = 10
                            continue yyl
                        }
                        yyrecord.yycursor += 1;
                        yystate = 1
                        continue yyl
                }
            case 1:
                yystate = 2
                continue yyl
            case 2:
                { return -1 }
            case 3:
                yych = yyrecord.yyinput.readUInt8(yyrecord.yycursor)
                switch (yych) {
                    case 0x20:
                        yyrecord.yycursor += 1;
                        yystate = 3
                        continue yyl
                    default:
                        if (yyrecord.yylimit <= yyrecord.yycursor) {
                            if (fill(yyrecord) == OK) {
                                yystate = 3
                                continue yyl
                            }
                        }
                        yystate = 4
                        continue yyl
                }
            case 4:
                { continue loop }
            case 5:
                yyrecord.yymarker = yyrecord.yycursor;
                yych = yyrecord.yyinput.readUInt8(yyrecord.yycursor)
                if (yych >= 0x01) {
                    yystate = 7
                    continue yyl
                }
                if (yyrecord.yylimit <= yyrecord.yycursor) {
                    if (fill(yyrecord) == OK) {
                        yystate = 5
                        continue yyl
                    }
                    yystate = 2
                    continue yyl
                }
                yyrecord.yycursor += 1;
                yystate = 6
                continue yyl
            case 6:
                yych = yyrecord.yyinput.readUInt8(yyrecord.yycursor)
                yystate = 7
                continue yyl
            case 7:
                switch (yych) {
                    case 0x27:
                        yyrecord.yycursor += 1;
                        yystate = 8
                        continue yyl
                    case 0x5C:
                        yyrecord.yycursor += 1;
                        yystate = 9
                        continue yyl
                    default:
                        if (yyrecord.yylimit <= yyrecord.yycursor) {
                            if (fill(yyrecord) == OK) {
                                yystate = 6
                                continue yyl
                            }
                            yystate = 11
                            continue yyl
                        }
                        yyrecord.yycursor += 1;
                        yystate = 6
                        continue yyl
                }
            case 8:
                { count += 1; continue loop }
            case 9:
                yych = yyrecord.yyinput.readUInt8(yyrecord.yycursor)
                if (yych <= 0x00) {
                    if (yyrecord.yylimit <= yyrecord.yycursor) {
                        if (fill(yyrecord) == OK) {
                            yystate = 9
                            continue yyl
                        }
                        yystate = 11
                        continue yyl
                    }
                    yyrecord.yycursor += 1;
                    yystate = 6
                    continue yyl
                }
                yyrecord.yycursor += 1;
                yystate = 6
                continue yyl
            case 10:
                { return count }
            case 11:
                yyrecord.yycursor = yyrecord.yymarker;
                yystate = 2
                continue yyl
            default:
                throw "internal lexer error"
        }
    }
}

    }
}

function main() {
    var fname = "input"

    // Create input file.
    var content = "'qu\0tes' 'are' 'fine: \\'' ".repeat(BUFSIZE)
    fs.writeFileSync(fname, content, function(err) { if (err) throw err; })

    // Init lexer state.
    var limit = BUFSIZE - 1 // exclude terminating null
    var st = {
        file: fs.openSync(fname, 'r'),
        yyinput: Buffer.alloc(BUFSIZE),
        yylimit: limit,
        yycursor: limit,
        yymarker: limit,
        token: limit,
        eof: false
    }

    // Run lexer on the prepared file.
    if (lex(st, 0) != 3 * BUFSIZE) { throw "error :[" }

    // Cleanup.
    fs.unlink(fname, function(err){ if (err) throw err; })
}

main()

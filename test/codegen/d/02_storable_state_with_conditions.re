// re2d $INPUT -o $OUTPUT -fc --loop-switch
module main;

import core.stdc.stdio;
import core.stdc.string;

// Use a small buffer to cover the case when a lexeme doesn't fit.
// In real world use a larger buffer.
enum BUFSIZE = 10;

/*!conditions:re2c*/

struct State {
    FILE* file;
    char[BUFSIZE + 1] buf;
    char* lim, cur, mar, tok;
    int state;
};

enum Status {END, READY, WAITING, BAD_PACKET, BIG_PACKET};

private Status fill(ref State st) {
    const size_t shift = st.tok - cast(char*)st.buf;
    const size_t used = st.lim - st.tok;
    const size_t free = BUFSIZE - used;

    // Error: no space. In real life can reallocate a larger buffer.
    if (free < 1) return Status.BIG_PACKET;

    // Shift buffer contents (discard already processed data).
    memmove(cast(void*)st.buf, st.tok, used);
    st.lim -= shift;
    st.cur -= shift;
    st.mar -= shift;
    st.tok -= shift;

    // Fill free space at the end of buffer with new data.
    const size_t read = fread(st.lim, 1, free, st.file);
    st.lim += read;
    st.lim[0] = 0; // append sentinel symbol

    return Status.READY;
}

private Status lex(ref State st, uint* nc, uint* wc) {
    char yych;
    /* !getstate:re2c*/

lex:
    for (;;) {
        st.tok = st.cur;
    /*!re2c
        re2c:api = custom;
        re2c:define:YYCTYPE    = "char";
        re2c:define:YYPEEK     = "*st.cur";
        re2c:define:YYSKIP     = "st.cur += 1;";
        re2c:define:YYBACKUP   = "st.mar = st.cur;";
        re2c:define:YYRESTORE  = "st.cur = st.mar;";
        re2c:define:YYSHIFT    = "st.cur += @@;";
        re2c:define:YYLESSTHAN = "st.cur >= st.lim";
        re2c:define:YYGETSTATE = "st.state";
        re2c:define:YYSETSTATE = "st.state = @@;";
        re2c:define:YYFILL     = "return Status.WAITING;";
        re2c:eof = 0;

        digit  = [0-9];
        letter = [a-z];
        space  = [ \t];

        <*> * { return Status.BAD_PACKET; }
        <*> $ { return Status.END; }

        <INIT> "" / digit  :=> NUMBER
        <INIT> "" / letter :=> WORD
        <INIT> "" / space  :=> SPACES

        <SPACES> space+ => INIT{ continue lex; }

        <NUMBER> digit+  => SPACES { *nc += 1; continue lex; }
        <WORD>   letter+ => SPACES { *wc += 1; continue lex; }
    */
    }
    assert(0); // unreachable
}

private void test(string[] packets, Status expect, int numbers, int words) {
    // Create a "socket" (open the same file for reading and writing).
    const(char*) fname = "pipe";
    FILE* fw = fopen(fname, "w");
    FILE* fr = fopen(fname, "r");
    setvbuf(fw, null, _IONBF, 0);
    setvbuf(fr, null, _IONBF, 0);

    // Initialize lexer state: `state` value is -1, all pointers are at the end
    // of buffer.
    State st;
    st.file = fr;
    st.cur = st.mar = st.tok = st.lim = cast(char*)st.buf + BUFSIZE;
    // Sentinel (at YYLIMIT pointer) is set to zero, which triggers YYFILL.
    st.lim[0] = 0;
    st.state = -1;

    // Main loop. The buffer contains incomplete data which appears packet by
    // packet. When the lexer needs more input it saves its internal state and
    // returns to the caller which should provide more input and resume lexing.
    Status status;
    uint send = 0, nc = 0, wc = 0;
    for (;;) {
        status = lex(st, &nc, &wc);
        if (status == Status.END) {
            debug{printf("done: got %u numbers and %u words\n", nc, wc);}
            break;
        } else if (status == Status.WAITING) {
            debug{printf("waiting...\n");}
            if (send < packets.length) {
                debug{printf("sent packet %u\n", send);}
                fprintf(fw, "%s", cast(char*)packets[send]);
                ++send;
            }
            status = fill(st);
            debug{printf("queue: '%s'\n", cast(char*)st.buf);}
            if (status == Status.BIG_PACKET) {
                debug{printf("error: packet too big\n");}
                break;
            }
            assert(status == Status.READY);
        } else {
            assert(status == Status.BAD_PACKET);
            debug{printf("error: ill-formed packet\n");}
            break;
        }
    }

    // Check results.
    assert(status == expect);
    if (status == Status.END) assert(nc == numbers && wc == words);

    // Cleanup: remove input file.
    fclose(fw);
    fclose(fr);
    remove(fname);
}

void main() {
    string[] packets1 = [];
    string[] packets2 = [" zero one", " ", "123", "4 tw", "o  456789"];
    string[] packets3 = ["zer0"];
    string[] packets4 = ["looooooooooong;"];

    test(packets1, Status.END, 0, 0);
    test(packets2, Status.END, 2, 3);
    test(packets3, Status.BAD_PACKET, -1, -1);
    test(packets4, Status.BIG_PACKET, -1, -1);
}

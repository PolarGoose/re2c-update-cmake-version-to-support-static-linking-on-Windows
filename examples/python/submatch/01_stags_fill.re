# re2py $INPUT -o $OUTPUT

from collections import namedtuple
from enum import Enum
import os

BUFSIZE = 4096

SemVer = namedtuple('SemVer', 'major minor patch')

class State:
    def __init__(self, fname):
        self.file = open(fname, "rb")
        self.str = bytearray(BUFSIZE)
        self.lim = BUFSIZE - 1 # exclude terminating null
        self.cur = self.lim
        self.mar = self.lim
        self.tok = self.lim
        self.eof = False
        /*!stags:re2c format = "\n        self.@@ = -1"; */

    def __del__(self):
        self.file.close()

class Status(Enum):
    OK = 0
    EOF = 1
    LONG_LEXEME = 2

def fill(st):
    if st.eof:
        return Status.EOF

    # Error: lexeme too long. In real life could reallocate a larger buffer.
    if st.tok < 1:
        return Status.LONG_LEXEME

    # Shift buffer contents (discard everything up to the current token).
    st.str = st.str[st.tok:st.lim]
    st.cur -= st.tok;
    st.mar -= st.tok;
    st.lim -= st.tok;
    st.tok = 0;

    # Fill free space at the end of buffer with new data from file.
    bytes = st.file.read(BUFSIZE - st.lim - 1) # -1 for sentinel
    if not bytes:
        st.eof = True # end of file
    else:
        st.lim += len(bytes);
        st.str += bytes

    st.str += b'\0' # append sentinel

    return Status.OK

def lex(st, count):
    vers = []
    while True:
        st.tok = st.cur
        /*!re2c
            re2c:api = record;
            re2c:variable:yyrecord = st;
            re2c:define:YYFILL = "fill(st) == Status.OK";
            re2c:eof = 0;
            re2c:indent:top = 2;
            re2c:tags = 1;

            num = [0-9]+;

            num @t1 "." @t2 num @t3 ("." @t4 num)? [\n] {
                major = int(st.str[st.tok:t1]);
                minor = int(st.str[t2:t3]);
                patch = int(st.str[t4:st.cur - 1]) if t4 != -1 else 0
                vers.append(SemVer(major, minor, patch))
                break
            }
            $ { return vers }
            * { return None }
        */

def main():
    fname = "input"
    verstr = b"1.22.333\n"
    expect = [SemVer(1, 22, 333)] * BUFSIZE

    # Prepare input file.
    f = open(fname, "wb")
    for i in range(BUFSIZE):
        f.write(verstr)
    f.close()

    # Run lexer on the prepared file.
    st = State(fname)
    assert lex(st, 0) == expect

    # Cleanup.
    os.remove(fname)

if __name__ == '__main__':
    main()

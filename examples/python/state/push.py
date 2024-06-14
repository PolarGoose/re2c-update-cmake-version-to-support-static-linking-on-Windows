# Generated by re2c
# re2py $INPUT -o $OUTPUT -f

from enum import Enum
import os

# Use a small buffer to cover the case when a lexeme doesn't fit.
# In real world use a larger buffer.
BUFSIZE = 10
DEBUG = False

class State:
    def __init__(self, file):
        self.file = file
        self.str = bytearray(BUFSIZE)
        self.lim = BUFSIZE - 1 # exclude terminating null
        self.cur = self.lim
        self.mar = self.lim
        self.tok = self.lim
        self.state = -1

class Status(Enum):
    END = 0
    READY = 1
    WAITING = 2
    BIG_PACKET = 3
    BAD_PACKET = 4

def fill(st):
    # Error: lexeme too long. In real life could reallocate a larger buffer.
    if st.tok < 1:
        return Status.BIG_PACKET

    # Shift buffer contents (discard everything up to the current token).
    st.str = st.str[st.tok:st.lim]
    st.cur -= st.tok;
    st.mar -= st.tok;
    st.lim -= st.tok;
    st.tok = 0;

    # Fill free space at the end of buffer with new data from file.
    bytes = st.file.read(BUFSIZE - st.lim - 1) # -1 for sentinel
    if bytes:
        st.lim += len(bytes);
        st.str += bytes

    st.str += b'\0' # append sentinel

    return Status.READY

def lex(yyrecord, recv):
    while True:
        yyrecord.tok = yyrecord.cur
        
        yystate = yyrecord.state
        while True:
            match yystate:
                case -1|0:
                    yych = yyrecord.str[yyrecord.cur]
                    if yych <= 0x00:
                        if yyrecord.lim <= yyrecord.cur:
                            yyrecord.state = 8
                            return Status.WAITING, recv
                        yyrecord.cur += 1
                        yystate = 1
                        continue
                    if yych <= 0x60:
                        yyrecord.cur += 1
                        yystate = 1
                        continue
                    if yych <= 0x7A:
                        yyrecord.cur += 1
                        yystate = 3
                        continue
                    yyrecord.cur += 1
                    yystate = 1
                    continue
                case 1:
                    yystate = 2
                    continue
                case 2:
                    yyrecord.state = -1
                    return Status.BAD_PACKET, recv
                case 3:
                    yyrecord.mar = yyrecord.cur
                    yych = yyrecord.str[yyrecord.cur]
                    if yych <= 0x3B:
                        if yych <= 0x00:
                            if yyrecord.lim <= yyrecord.cur:
                                yyrecord.state = 9
                                return Status.WAITING, recv
                            yystate = 2
                            continue
                        if yych <= 0x3A:
                            yystate = 2
                            continue
                        yyrecord.cur += 1
                        yystate = 4
                        continue
                    else:
                        if yych <= 0x60:
                            yystate = 2
                            continue
                        if yych <= 0x7A:
                            yyrecord.cur += 1
                            yystate = 5
                            continue
                        yystate = 2
                        continue
                case 4:
                    yyrecord.state = -1
                    recv += 1
                    break
                case 5:
                    yych = yyrecord.str[yyrecord.cur]
                    if yych <= 0x3B:
                        if yych <= 0x00:
                            if yyrecord.lim <= yyrecord.cur:
                                yyrecord.state = 10
                                return Status.WAITING, recv
                            yystate = 6
                            continue
                        if yych >= 0x3B:
                            yyrecord.cur += 1
                            yystate = 4
                            continue
                        yystate = 6
                        continue
                    else:
                        if yych <= 0x60:
                            yystate = 6
                            continue
                        if yych <= 0x7A:
                            yyrecord.cur += 1
                            yystate = 5
                            continue
                        yystate = 6
                        continue
                case 6:
                    yyrecord.cur = yyrecord.mar
                    yystate = 2
                    continue
                case 7:
                    yyrecord.state = -1
                    return Status.END, recv
                case 8:
                    if yyrecord.lim <= yyrecord.cur:
                        yystate = 7
                        continue
                    yystate = 0
                    continue
                case 9:
                    if yyrecord.lim <= yyrecord.cur:
                        yystate = 2
                        continue
                    yystate = 3
                    continue
                case 10:
                    if yyrecord.lim <= yyrecord.cur:
                        yystate = 6
                        continue
                    yystate = 5
                    continue
                case _:
                    raise "internal lexer error"


def test(packets, expect):
    # Create a "socket" (open the same file for reading and writing).
    fname = "pipe"
    fw = open(fname, "wb")
    fr = open(fname, "rb")

    # Initialize lexer state
    st = State(fr)

    # Main loop. The buffer contains incomplete data which appears packet by
    # packet. When the lexer needs more input it saves its internal state and
    # returns to the caller which should provide more input and resume lexing.
    send = 0
    recv = 0
    while True:
        status, recv = lex(st, recv)

        if status == Status.END:
            if DEBUG: print("done: got {} packets".format(recv))
            break

        elif status == Status.WAITING:
            if DEBUG: print("waiting...");

            if send < len(packets):
                if DEBUG: print("sent packet {}: {}".format(send, packets[send]))
                fw.write(packets[send])
                fw.flush()
                send += 1

            status = fill(st)
            if DEBUG: print("queue: '{}', status: {}".format(st.str, status))
            if status == Status.BIG_PACKET:
                if DEBUG: print("error: packet too big")
                break

            assert status == Status.READY

        else:
            assert status == Status.BAD_PACKET
            if DEBUG: print("error: ill-formed packet")
            break

    # Check results.
    assert status == expect
    if status == Status.END:
        assert recv == send

    # Cleanup: remove input file.
    fr.close()
    fw.close()
    os.remove(fname)

def main():
    test([], Status.END)
    test([b"zero;", b"one;", b"two;", b"three;", b"four;"], Status.END)
    test([b"zer0;"], Status.BAD_PACKET)
    test([b"goooooooooogle;"], Status.BIG_PACKET)

if __name__ == '__main__':
    main()

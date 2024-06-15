// re2rust $INPUT -o $OUTPUT

use std::fs::File;
use std::io::{Read, Write};

/*!max:re2c*/
const BUFSIZE: usize = 4096;

struct State {
    file: File,
    str: [u8; BUFSIZE],
    lim: usize,
    cur: usize,
    mar: usize,
    tok: usize,
    eof: bool,
}

#[derive(PartialEq)]
enum Fill { Ok, Eof, LongLexeme }

fn fill(st: &mut State, need: usize) -> Fill {
    if st.eof { return Fill::Eof; }

    // Error: lexeme too long. In real life can reallocate a larger buffer.
    if st.tok < need { return Fill::LongLexeme; }

    // Shift buffer contents (discard everything up to the current token).
    st.str.copy_within(st.tok..st.lim, 0);
    st.lim -= st.tok;
    st.cur -= st.tok;
    st.mar = st.mar.overflowing_sub(st.tok).0; // underflows if marker is unused
    st.tok = 0;

    // Fill free space at the end of buffer with new data from file.
    let n = match st.file.read(&mut st.str[st.lim..BUFSIZE - YYMAXFILL]) {
        Ok(n) => n,
        Err(why) => panic!("cannot read from file: {}", why)
    };
    st.lim += n;

    // If read zero characters, this is end of input => add zero padding
    // so that the lexer can access characters at the end of buffer.
    if n == 0 {
        st.eof = true;
        for i in 0..YYMAXFILL { st.str[st.lim + i] = 0; }
        st.lim += YYMAXFILL;
    }

    return Fill::Ok;
}

fn lex(yyrecord: &mut State) -> isize {
    let mut count: isize = 0;

    'lex: loop {
        yyrecord.tok = yyrecord.cur;
    /*!re2c
        re2c:api = record;
        re2c:define:YYCTYPE = u8;
        re2c:define:YYFILL = "if fill(yyrecord, @@) != Fill::Ok { return -1; }";

        str = ['] ([^'\\] | [\\][^])* ['];

        [\x00] {
            // Check that it is the sentinel, not some unexpected null.
            return if yyrecord.tok == yyrecord.lim - YYMAXFILL { count } else { -1 }
        }
        str  { count += 1; continue 'lex; }
        [ ]+ { continue 'lex; }
        *    { return -1; }
    */}
}

fn main() {
    let fname = "input";
    let content = b"'qu\0tes' 'are' 'fine: \\'' ";

    // Prepare input file: a few times the size of the buffer, containing
    // strings with zeroes and escaped quotes.
    match File::create(fname) {
        Err(why) => panic!("cannot open {}: {}", fname, why),
        Ok(mut file) => match file.write_all(&content.repeat(BUFSIZE)) {
            Err(why) => panic!("cannot write to {}: {}", fname, why),
            Ok(_) => {}
        }
    };
    let count = 3 * BUFSIZE; // number of quoted strings written to file

    // Reopen input file for reading.
    let file = match File::open(fname) {
        Err(why) => panic!("cannot read file {}: {}", fname, why),
        Ok(file) => file,
    };

    // Initialize lexer state: all offsets are at the end of buffer.
    // This immediately triggers YYFILL, as the YYLESSTHAN condition is true.
    let lim = BUFSIZE - YYMAXFILL;
    let mut st = State {
        file: file,
        str: [0; BUFSIZE],
        lim: lim,
        cur: lim,
        mar: lim,
        tok: lim,
        eof: false,
    };

    // Run the lexer.
    assert_eq!(lex(&mut st), count as isize);

    // Cleanup: remove input file.
    match std::fs::remove_file(fname) {
        Err(why) => panic!("cannot remove {}: {}", fname, why),
        Ok(_) => {}
    }
}

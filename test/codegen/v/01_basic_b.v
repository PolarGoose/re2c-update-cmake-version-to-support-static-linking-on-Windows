// Code generated by re2c, DO NOT EDIT.
//line "codegen/v/01_basic_b.re":1
// re2v $INPUT -o $OUTPUT -b

fn lex(str string) {
    mut cursor := 0
    
//line "codegen/v/01_basic_b.v":9
    mut yych := 0
    yybm := [
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
        128, 128, 128, 128, 128, 128, 128, 128,
        128, 128,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
    ]
    yych = str[cursor]
    if yych <= 0x30 {
        unsafe { goto yy1 }
    }
    if yych <= 0x39 {
        unsafe { goto yy2 }
    }
yy1:
    cursor += 1
//line "codegen/v/01_basic_b.re":15
    panic("error!")
//line "codegen/v/01_basic_b.v":56
yy2:
    cursor += 1
    yych = str[cursor]
    if (yybm[0+yych] & 128) != 0 {
        unsafe { goto yy2 }
    }
//line "codegen/v/01_basic_b.re":14
    return
//line "codegen/v/01_basic_b.v":65
//line "codegen/v/01_basic_b.re":16

}

fn main() {
    lex("1234\x00")
}

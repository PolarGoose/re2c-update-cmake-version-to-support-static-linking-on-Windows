// Code generated by re2c, DO NOT EDIT.
//line "codegen/v/01_basic_s.re":1
// re2v $INPUT -o $OUTPUT -s

fn lex(str string) {
    mut cursor := 0
    
//line "codegen/v/01_basic_s.v":9
    mut yych := 0
    yych = str[cursor]
    if yych <= 0x30 {
        unsafe { goto yy1 }
    }
    if yych <= 0x39 {
        unsafe { goto yy2 }
    }
yy1:
    cursor += 1
//line "codegen/v/01_basic_s.re":15
    panic("error!")
//line "codegen/v/01_basic_s.v":22
yy2:
    cursor += 1
    yych = str[cursor]
    if yych <= 0x2F {
        unsafe { goto yy3 }
    }
    if yych <= 0x39 {
        unsafe { goto yy2 }
    }
yy3:
//line "codegen/v/01_basic_s.re":14
    return
//line "codegen/v/01_basic_s.v":35
//line "codegen/v/01_basic_s.re":16

}

fn main() {
    lex("1234\x00")
}

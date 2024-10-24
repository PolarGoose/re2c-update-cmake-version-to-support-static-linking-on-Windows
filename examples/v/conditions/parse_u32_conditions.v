// Code generated by re2v, DO NOT EDIT.
// re2v $INPUT -o $OUTPUT -ci

enum YYCONDTYPE {
    yycinit
    yycbin
    yycdec
    yychex
    yycoct
}


const u32_lim = u64(1) << 32

fn parse_u32(yyinput string) ?u32 {
    mut yycursor, mut yymarker := 0, 0
    mut n := u64(0)
    mut yycond := YYCONDTYPE.yycinit

    adddgt := fn (num u64, base u64, digit u8) u64 {
        n := num * base + u64(digit)
        return if n >= u32_lim { u32_lim } else { n }
    }

    
    mut yych := 0
    match yycond {
        .yycinit { unsafe { goto yyc_init } }
        .yycbin { unsafe { goto yyc_bin } }
        .yycdec { unsafe { goto yyc_dec } }
        .yychex { unsafe { goto yyc_hex } }
        .yycoct { unsafe { goto yyc_oct } }
    }
/* *********************************** */
yyc_init:
    yych = yyinput[yycursor]
    match yych {
        0x30 { unsafe { goto yy2 } }
        0x31...0x39 { unsafe { goto yy4 } }
        else { unsafe { goto yy1 } }
    }
yy1:
    yycursor += 1
    return none
yy2:
    yycursor += 1
    yymarker = yycursor
    yych = yyinput[yycursor]
    match yych {
        0x42, 0x62 { unsafe { goto yy5 } }
        0x58, 0x78 { unsafe { goto yy7 } }
        else { unsafe { goto yy3 } }
    }
yy3:
    yycond = .yycoct
    unsafe { goto yyc_oct }
yy4:
    yycursor += 1
    yycursor -= 1
    yycond = .yycdec
    unsafe { goto yyc_dec }
yy5:
    yycursor += 1
    yych = yyinput[yycursor]
    match yych {
        0x30...0x31 { unsafe { goto yy8 } }
        else { unsafe { goto yy6 } }
    }
yy6:
    yycursor = yymarker
    unsafe { goto yy3 }
yy7:
    yycursor += 1
    yych = yyinput[yycursor]
    match yych {
        0x30...0x39, 0x41...0x46, 0x61...0x66 { unsafe { goto yy9 } }
        else { unsafe { goto yy6 } }
    }
yy8:
    yycursor += 1
    yycursor -= 1
    yycond = .yycbin
    unsafe { goto yyc_bin }
yy9:
    yycursor += 1
    yycursor -= 1
    yycond = .yychex
    unsafe { goto yyc_hex }
/* *********************************** */
yyc_bin:
    yych = yyinput[yycursor]
    match yych {
        0x00 { unsafe { goto yy11 } }
        0x30...0x31 { unsafe { goto yy13 } }
        else { unsafe { goto yy12 } }
    }
yy11:
    yycursor += 1
    return if n < u32_lim { u32(n) } else { none }
yy12:
    yycursor += 1
    return none
yy13:
    yycursor += 1
    n = adddgt(n, 2,  yyinput[yycursor-1] - 48); unsafe{ goto yyc_bin }
/* *********************************** */
yyc_dec:
    yych = yyinput[yycursor]
    match yych {
        0x00 { unsafe { goto yy15 } }
        0x30...0x39 { unsafe { goto yy17 } }
        else { unsafe { goto yy16 } }
    }
yy15:
    yycursor += 1
    return if n < u32_lim { u32(n) } else { none }
yy16:
    yycursor += 1
    return none
yy17:
    yycursor += 1
    n = adddgt(n, 10, yyinput[yycursor-1] - 48); unsafe{ goto yyc_dec }
/* *********************************** */
yyc_hex:
    yych = yyinput[yycursor]
    match yych {
        0x00 { unsafe { goto yy19 } }
        0x30...0x39 { unsafe { goto yy21 } }
        0x41...0x46 { unsafe { goto yy22 } }
        0x61...0x66 { unsafe { goto yy23 } }
        else { unsafe { goto yy20 } }
    }
yy19:
    yycursor += 1
    return if n < u32_lim { u32(n) } else { none }
yy20:
    yycursor += 1
    return none
yy21:
    yycursor += 1
    n = adddgt(n, 16, yyinput[yycursor-1] - 48); unsafe{ goto yyc_hex }
yy22:
    yycursor += 1
    n = adddgt(n, 16, yyinput[yycursor-1] - 55); unsafe{ goto yyc_hex }
yy23:
    yycursor += 1
    n = adddgt(n, 16, yyinput[yycursor-1] - 87); unsafe{ goto yyc_hex }
/* *********************************** */
yyc_oct:
    yych = yyinput[yycursor]
    match yych {
        0x00 { unsafe { goto yy25 } }
        0x30...0x37 { unsafe { goto yy27 } }
        else { unsafe { goto yy26 } }
    }
yy25:
    yycursor += 1
    return if n < u32_lim { u32(n) } else { none }
yy26:
    yycursor += 1
    return none
yy27:
    yycursor += 1
    n = adddgt(n, 8,  yyinput[yycursor-1] - 48); unsafe{ goto yyc_oct }

}

fn main() {
    test := fn (num ?u32, str string) {
        if n := parse_u32(str) {
            if m := num { if n != m { panic("wrong number") } }
        } else {
            if _ := num { panic("expected none") }
        }
    }
    test(1234567890, "1234567890\0")
    test(13, "0b1101\0")
    test(0x7fe, "0x007Fe\0")
    test(0o644, "0644\0")
    test(none, "9999999999\0")
    test(none, "123??\0")
}
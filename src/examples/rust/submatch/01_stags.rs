/* Generated by re2rust */
// re2rust $INPUT -o $OUTPUT --api simple

#[derive(Debug, PartialEq)]
struct SemVer(u32, u32, u32); // version: (major, minor, patch)

const NONE: usize = std::usize::MAX;

fn s2n(str: &[u8]) -> u32 { // convert a pre-parsed string to a number
    let mut n = 0;
    for i in str { n = n * 10 + *i as u32 - 48; }
    return n;
}

fn parse(yyinput: &[u8]) -> Option<SemVer> {
    assert_eq!(yyinput.last(), Some(&0)); // expect null-terminated input

    let (mut yycursor, mut yymarker) = (0, 0);

    // Final tag variables available in semantic action.
    #[allow(unused_mut)]
let mut t1;
#[allow(unused_mut)]
let mut t2;
#[allow(unused_mut)]
let mut t3;
#[allow(unused_mut)]
let mut t4;
#[allow(unused_mut)]
let mut t5;


    // Intermediate tag variables used by the lexer (must be autogenerated).
    let mut yyt1 = NONE;let mut yyt2 = NONE;let mut yyt3 = NONE;let mut yyt4 = NONE;

    
{
    #[allow(unused_assignments)]
    let mut yych : u8 = 0;
    let mut yystate : usize = 0;
    'yyl: loop {
        match yystate {
            0 => {
                yych = unsafe {*yyinput.get_unchecked(yycursor)};
                match yych {
                    0x30 ..= 0x39 => {
                        yyt1 = yycursor;
                        yycursor += 1;
                        yystate = 3;
                        continue 'yyl;
                    }
                    _ => {
                        yycursor += 1;
                        yystate = 1;
                        continue 'yyl;
                    }
                }
            }
            1 => {
                yystate = 2;
                continue 'yyl;
            }
            2 => { return None; },
            3 => {
                yymarker = yycursor;
                yych = unsafe {*yyinput.get_unchecked(yycursor)};
                match yych {
                    0x2E => {
                        yycursor += 1;
                        yystate = 4;
                        continue 'yyl;
                    }
                    0x30 ..= 0x39 => {
                        yycursor += 1;
                        yystate = 6;
                        continue 'yyl;
                    }
                    _ => {
                        yystate = 2;
                        continue 'yyl;
                    }
                }
            }
            4 => {
                yych = unsafe {*yyinput.get_unchecked(yycursor)};
                match yych {
                    0x30 ..= 0x39 => {
                        yyt2 = yycursor;
                        yycursor += 1;
                        yystate = 7;
                        continue 'yyl;
                    }
                    _ => {
                        yystate = 5;
                        continue 'yyl;
                    }
                }
            }
            5 => {
                yycursor = yymarker;
                yystate = 2;
                continue 'yyl;
            }
            6 => {
                yych = unsafe {*yyinput.get_unchecked(yycursor)};
                match yych {
                    0x2E => {
                        yycursor += 1;
                        yystate = 4;
                        continue 'yyl;
                    }
                    0x30 ..= 0x39 => {
                        yycursor += 1;
                        yystate = 6;
                        continue 'yyl;
                    }
                    _ => {
                        yystate = 5;
                        continue 'yyl;
                    }
                }
            }
            7 => {
                yych = unsafe {*yyinput.get_unchecked(yycursor)};
                match yych {
                    0x00 => {
                        yyt3 = yycursor;
                        yyt4 = usize::MAX;
                        yycursor += 1;
                        yystate = 8;
                        continue 'yyl;
                    }
                    0x2E => {
                        yyt3 = yycursor;
                        yycursor += 1;
                        yystate = 9;
                        continue 'yyl;
                    }
                    0x30 ..= 0x39 => {
                        yycursor += 1;
                        yystate = 7;
                        continue 'yyl;
                    }
                    _ => {
                        yystate = 5;
                        continue 'yyl;
                    }
                }
            }
            8 => {
                t1 = yyt1;
                t3 = yyt2;
                t4 = yyt3;
                t5 = yyt4;
                t2 = yyt2;
                t2 -= 1;
                {
            let major = s2n(&yyinput[t1..t2]);
            let minor = s2n(&yyinput[t3..t4]);
            let patch = if t5 != NONE {s2n(&yyinput[t5..yycursor - 1])} else {0};
            return Some(SemVer(major, minor, patch));
        }
            }
            9 => {
                yych = unsafe {*yyinput.get_unchecked(yycursor)};
                match yych {
                    0x30 ..= 0x39 => {
                        yyt4 = yycursor;
                        yycursor += 1;
                        yystate = 10;
                        continue 'yyl;
                    }
                    _ => {
                        yystate = 5;
                        continue 'yyl;
                    }
                }
            }
            10 => {
                yych = unsafe {*yyinput.get_unchecked(yycursor)};
                match yych {
                    0x00 => {
                        yycursor += 1;
                        yystate = 8;
                        continue 'yyl;
                    }
                    0x30 ..= 0x39 => {
                        yycursor += 1;
                        yystate = 10;
                        continue 'yyl;
                    }
                    _ => {
                        yystate = 5;
                        continue 'yyl;
                    }
                }
            }
            _ => panic!("internal lexer error"),
        }
    }
}

}

fn main() {
    assert_eq!(parse(b"23.34\0"), Some(SemVer(23, 34, 0)));
    assert_eq!(parse(b"1.2.99999\0"), Some(SemVer(1, 2, 99999)));
    assert_eq!(parse(b"1.a\0"), None);
}
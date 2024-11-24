// Generated by re2zig
// re2zig $INPUT -o $OUTPUT

const std = @import("std");

fn lex(yyinput: [:0]const u8) bool {
    var yycursor: u32 = 0;
    
    var yych: i8 = 0;
    var yystate: u32 = 0;
    yyl: while (true) {
        switch (yystate) {
            0 => {
                yych = @intCast(yyinput[yycursor]);
                yycursor += 1;
                switch (yych) {
                    0x31...0x39 => {
                        yystate = 2;
                        continue :yyl;
                    },
                    else => {
                        yystate = 1;
                        continue :yyl;
                    },
                }
            },
            1 => { return false; },
            2 => {
                yych = @intCast(yyinput[yycursor]);
                switch (yych) {
                    0x30...0x39 => {
                        yycursor += 1;
                        yystate = 2;
                        continue :yyl;
                    },
                    else => {
                        yystate = 3;
                        continue :yyl;
                    },
                }
            },
            3 => { return true; },
            else => { @panic("internal lexer error"); },
        }
    }

}

test {
    try std.testing.expect(lex("1234"));
}
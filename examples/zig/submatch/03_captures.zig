// Generated by re2zig
// re2zig $INPUT -o $OUTPUT

const std = @import("std");

const none = std.math.maxInt(usize);

const SemVer = struct {
    major: u32,
    minor: u32,
    patch: u32,
};

fn s2n(str: []const u8) u32 { // convert pre-parsed string to a number
    var n: u32 = 0;
    for (str) |c| { n = n * 10 + (c - 48); }
    return n;
}

fn parse(yyinput: [:0]const u8) ?SemVer {
    var yycursor: usize = 0;
    var yymarker: usize = 0;
    var yytl0: usize = 0;
    var yytr0: usize = 0;
    var yytl1: usize = 0;
    var yytr1: usize = 0;
    var yytl2: usize = 0;
    var yytr2: usize = 0;
    var yytl3: usize = 0;
    var yytr3: usize = 0;

    // Autogenerated tag variables used by the lexer to track tag values.
    var yyt1: usize = none;var yyt2: usize = none;var yyt3: usize = none;var yyt4: usize = none;var yyt5: usize = none;

    
    var yych: u8 = 0;
    var yystate: u32 = 0;
    while (true) {
        switch (yystate) {
            0 => {
                yych = yyinput[yycursor];
                switch (yych) {
                    0x30...0x39 => {
                        yyt1 = yycursor;
                        yycursor += 1;
                        yystate = 3;
                        continue;
                    },
                    else => {
                        yycursor += 1;
                        yystate = 1;
                        continue;
                    },
                }
            },
            1 => {
                yystate = 2;
                continue;
            },
            2 => { return null; },
            3 => {
                yymarker = yycursor;
                yych = yyinput[yycursor];
                switch (yych) {
                    0x2E => {
                        yycursor += 1;
                        yystate = 4;
                        continue;
                    },
                    0x30...0x39 => {
                        yycursor += 1;
                        yystate = 6;
                        continue;
                    },
                    else => {
                        yystate = 2;
                        continue;
                    },
                }
            },
            4 => {
                yych = yyinput[yycursor];
                switch (yych) {
                    0x30...0x39 => {
                        yyt2 = yycursor;
                        yycursor += 1;
                        yystate = 7;
                        continue;
                    },
                    else => {
                        yystate = 5;
                        continue;
                    },
                }
            },
            5 => {
                yycursor = yymarker;
                yystate = 2;
                continue;
            },
            6 => {
                yych = yyinput[yycursor];
                switch (yych) {
                    0x2E => {
                        yycursor += 1;
                        yystate = 4;
                        continue;
                    },
                    0x30...0x39 => {
                        yycursor += 1;
                        yystate = 6;
                        continue;
                    },
                    else => {
                        yystate = 5;
                        continue;
                    },
                }
            },
            7 => {
                yych = yyinput[yycursor];
                switch (yych) {
                    0x00 => {
                        yyt3 = yycursor;
                        yyt4 = std.math.maxInt(usize);
                        yyt5 = std.math.maxInt(usize);
                        yycursor += 1;
                        yystate = 8;
                        continue;
                    },
                    0x2E => {
                        yyt3 = yycursor;
                        yyt5 = yycursor;
                        yycursor += 1;
                        yystate = 9;
                        continue;
                    },
                    0x30...0x39 => {
                        yycursor += 1;
                        yystate = 7;
                        continue;
                    },
                    else => {
                        yystate = 5;
                        continue;
                    },
                }
            },
            8 => {
                yytl1 = yyt1;
                yytl2 = yyt2;
                yytr2 = yyt3;
                yytl3 = yyt5;
                yytr3 = yyt4;
                yytl0 = yyt1;
                yytr0 = yycursor;
                yytr1 = yyt2;
                yytr1 -= 1;
                
            return SemVer {
                .major = s2n(yyinput[yytl1..yytr1]),
                .minor = s2n(yyinput[yytl2..yytr2]),
                .patch = if (yytl3 == none) 0 else s2n(yyinput[yytl3 + 1..yytr3])
            };

            },
            9 => {
                yych = yyinput[yycursor];
                if (yych <= 0x00) {
                    yystate = 5;
                    continue;
                }
                yystate = 11;
                continue;
            },
            10 => {
                yych = yyinput[yycursor];
                yystate = 11;
                continue;
            },
            11 => {
                switch (yych) {
                    0x00 => {
                        yyt4 = yycursor;
                        yycursor += 1;
                        yystate = 8;
                        continue;
                    },
                    0x30...0x39 => {
                        yycursor += 1;
                        yystate = 10;
                        continue;
                    },
                    else => {
                        yystate = 5;
                        continue;
                    },
                }
            },
            else => { @panic("internal lexer error"); },
        }
    }

}

test {
    try std.testing.expectEqual(parse("23.34"), SemVer{.major = 23, .minor = 34, .patch = 0});
    try std.testing.expectEqual(parse("1.2.99999"), SemVer{.major = 1, .minor = 2, .patch = 99999});
    try std.testing.expectEqual(parse("1.a"), null);
}

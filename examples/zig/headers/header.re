// re2zig $INPUT -o $OUTPUT --header lexer/state.zig

const std = @import("std");
const state = @import("lexer/state.zig"); // the module is generated by re2c

/*!header:re2c:on*/
pub const State = struct {
    yyinput: [:0]const u8,
    yycursor: usize,
    /*!stags:re2c format = "@@: usize,"; */
};
/*!header:re2c:off*/

fn lex(yyrecord: *state.State) usize {
    var t: usize = 0;
    /*!re2c
        re2c:header = "lexer/state.zig";
        re2c:api = record;
        re2c:define:YYCTYPE = "u8";
        re2c:yyfill:enable = 0;
        re2c:tags = 1;

        [a]* @t [b]* { return t; }
    */
}

test {
    var st = state.State {
        .yyinput = "ab",
        .yycursor = 0,
        /*!stags:re2c format = ".@@ = 0,"; */
    };
    try std.testing.expectEqual(lex(&st), 1);
}

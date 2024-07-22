// re2zig $INPUT -o $OUTPUT

const std = @import("std");

const none = std.math.maxInt(usize);
const mtag_root = none - 1;

const err = error.SyntaxError;

// An m-tag tree is a way to store histories with an O(1) copy operation.
// Histories naturally form a tree, as they have common start and fork at some
// point. The tree is stored as an array of pairs (tag value, link to parent).
// An m-tag is represented with a single link in the tree (array index).
const MtagElem = struct {
    elem: usize, // tag value
    pred: usize, // index of the predecessor node or root
};

// Append a single value to an m-tag history.
fn add_mtag(trie: *std.ArrayList(MtagElem), mtag: usize, value: usize) !usize {
    try trie.append(MtagElem{.elem = value, .pred = mtag});
    return trie.items.len - 1;
}

// Recursively unwind tag histories and collect version components.
fn unwind(trie: *std.ArrayList(MtagElem),
          x: usize,
          y: usize,
          str: []const u8,
          ver: *std.ArrayList(u32)) !void {
    // Reached the root of the m-tag tree, stop recursion.
    if (x == mtag_root and y == mtag_root) return;

    // Unwind history further.
    try unwind(trie, trie.items[x].pred, trie.items[y].pred, str, ver);

    // Get tag values. Tag histories must have equal length.
    std.debug.assert(x != mtag_root and y != mtag_root);
    var ex = trie.items[x].elem;
    var ey = trie.items[y].elem;

    if (ex != none and ey != none) {
        // Both tags are valid string indices, extract component.
        try ver.append(s2n(str[ex..ey]));
    } else {
        // Both tags are none (this corresponds to zero repetitions).
        std.debug.assert(ex == none and ey == none);
    }
}

fn s2n(str: []const u8) u32 { // convert a pre-parsed string to a number
    var n: u32 = 0;
    for (str) |c| { n = n * 10 + (c - 48); }
    return n;
}

fn parse(yyinput: [:0]const u8) !std.ArrayList(u32) {
    var yycursor: usize = 0;
    var yymarker: usize = 0;
    var mt = std.ArrayList(MtagElem).init(std.testing.allocator);
    defer mt.deinit();

    // User-defined tag variables that are available in semantic action.
    var t1: usize = 0;
    var t2: usize = 0;
    var t3: usize = 0;
    var t4: usize = 0;

    // Autogenerated tag variables used by the lexer to track tag values.
    %{stags format = "var @@: usize = none;"; %}
    %{mtags format = "var @@: usize = mtag_root;"; %}

    %{
        re2c:define:YYMTAGP = "@@ = add_mtag(&mt, @@, yycursor) catch none;";
        re2c:define:YYMTAGN = "@@ = add_mtag(&mt, @@, none) catch none;";
        re2c:yyfill:enable = 0;
        re2c:tags = 1;

        num = [0-9]+;

        @t1 num @t2 ("." #t3 num #t4)* [\x00] {
            var ver = std.ArrayList(u32).init(std.testing.allocator);
            try ver.append(s2n(yyinput[t1..t2]));
            try unwind(&mt, t3, t4, yyinput, &ver);
            return ver;
        }
        * { return error.SyntaxError; }
    %}
}

test {
    var result = try parse("1");
    var expect = std.ArrayList(u32).init(std.testing.allocator);
    try expect.appendSlice(&[_]u32{1});
    try std.testing.expectEqualDeep(result, expect);
    expect.deinit();
    result.deinit();
}

test {
    var result = try parse("1.2.3.4.5.6.7");
    var expect = std.ArrayList(u32).init(std.testing.allocator);
    try expect.appendSlice(&[_]u32{1, 2, 3, 4, 5, 6, 7});
    try std.testing.expectEqualDeep(result, expect);
    expect.deinit();
    result.deinit();
}

test {
    var result = parse("1.2.") catch null;
    try std.testing.expectEqualDeep(result, null);
}

(* re2ocaml $INPUT -o $OUTPUT *)

open String

type state = {
    yyinput: string;
    mutable yycursor: int;
    mutable yymarker: int;
    mutable yytl0: int;
    mutable yytr0: int;
    mutable yytl1: int;
    mutable yytr1: int;
    mutable yytl2: int;
    mutable yytr2: int;
    mutable yytl3: int;
    mutable yytr3: int;
    %{stags format = "\n\tmutable @@{tag}: int;"; %}
}

type semver = {
    major: int;
    minor: int;
    patch: int;
}

let s2n (str: string) (i1: int) (i2: int) : int =
    let rec f s i j n =
        if i >= j then n else f s (i + 1) j (n * 10 + Char.code s.[i] - 48)
    in f str i1 i2 0

%{local
    re2c:define:YYFN = ["parse;semver option", "st;state"];
    re2c:variable:yyrecord = "st";
    re2c:captvars = 1;
    re2c:yyfill:enable = 0;

    num = [0-9]+;

    (num) "." (num) ("." num)? [\x00] {
        Some {
            major = s2n st.yyinput st.yytl1 st.yytr1;
            minor = s2n st.yyinput st.yytl2 st.yytr2;
            patch = if st.yytl3 = -1 then 0 else s2n st.yyinput (st.yytl3 + 1) st.yytr3
        }
    }
    * { None }
%}

let test (str: string) (result: semver option) =
    let st = {
        yyinput = str;
        yycursor = 0;
        yymarker = 0;
        yytl0 = 0;
        yytr0 = 0;
        yytl1 = 0;
        yytr1 = 0;
        yytl2 = 0;
        yytr2 = 0;
        yytl3 = 0;
        yytr3 = 0;
        %{stags format = "\n\t\t@@{tag} = -1;"; %}
    }
    in if not (parse st = result) then raise (Failure "error")

let main () =
    test "23.34\x00" (Some {major = 23; minor = 34; patch = 0});
    test "1.2.99999\x00" (Some {major = 1; minor = 2; patch = 99999});
    test "1.a\x00" None

let _ = main ()

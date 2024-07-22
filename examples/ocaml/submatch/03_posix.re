(* re2ocaml $INPUT -o $OUTPUT *)

open String

(* Maximum number of capturing groups among all rules. *)
%{maxnmatch %}

type state = {
    yyinput: string;
    mutable yycursor: int;
    mutable yymarker: int;
    mutable yynmatch: int; (* number of capturing groups *)
    mutable yypmatch: int array; (* memory for capturing parentheses *)
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
    re2c:posix-captures = 1;
    re2c:yyfill:enable = 0;

    num = [0-9]+;

    (num) "." (num) ("." num)? [\x00] {
        (* Even `yypmatch` values are for opening parentheses, odd values
           are for closing parentheses, the first group is the whole match. *)
        Some {
            major = s2n st.yyinput st.yypmatch.(2) st.yypmatch.(3);
            minor = s2n st.yyinput st.yypmatch.(4) st.yypmatch.(5);
            patch = if st.yypmatch.(6) = -1 then 0
                else s2n st.yyinput (st.yypmatch.(6) + 1) st.yypmatch.(7)
        }
    }
    * { None }
%}

let test (str: string) (result: semver option) =
    let st = {
        yyinput = str;
        yycursor = 0;
        yymarker = 0;
        yynmatch = 0;
        yypmatch = Array.make (2 * yymaxnmatch) (-1);
        %{stags format = "\n\t\t@@{tag} = -1;"; %}
    }
    in if not (parse st = result) then raise (Failure "error")

let main () =
    test "23.34\x00" (Some {major = 23; minor = 34; patch = 0});
    test "1.2.99999\x00" (Some {major = 1; minor = 2; patch = 99999});
    test "1.a\x00" None

let _ = main ()

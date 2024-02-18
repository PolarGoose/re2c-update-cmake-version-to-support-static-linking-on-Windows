(* Generated by re2c *)
#1 "ocaml/submatch/03_posix.re"
(* re2ocaml $INPUT -o $OUTPUT *)

(* Maximum number of capturing groups among all rules. *)
#7 "ocaml/submatch/03_posix.ml"
let yymaxnmatch = 4
#4 "ocaml/submatch/03_posix.re"


let none = max_int

type state = {
    str: string;
    mutable cur: int;
    mutable mar: int;
    mutable yynmatch: int; (* number of capturing groups *)
    mutable yypmatch: int array; (* memory for capturing parentheses *)
    
#21 "ocaml/submatch/03_posix.ml"

	mutable yyt1: int;
	mutable yyt2: int;
	mutable yyt3: int;
	mutable yyt4: int;
	mutable yyt5: int;
#14 "ocaml/submatch/03_posix.re"

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


#44 "ocaml/submatch/03_posix.ml"
let rec yy0 (st : state) : semver option =
	let yych = Char.code st.str.[st.cur] in
	match yych with
		| 0x30|0x31|0x32|0x33|0x34|0x35|0x36|0x37|0x38|0x39 ->
			st.yyt1 <- st.cur;
			st.cur <- st.cur + 1;
			(yy3 [@tailcall]) st
		| _ ->
			st.cur <- st.cur + 1;
			(yy1 [@tailcall]) st

and yy1 (st : state) : semver option =
	(yy2 [@tailcall]) st

and yy2 (st : state) : semver option =
#54 "ocaml/submatch/03_posix.re"
	None
#62 "ocaml/submatch/03_posix.ml"

and yy3 (st : state) : semver option =
	st.mar <- st.cur;
	let yych = Char.code st.str.[st.cur] in
	match yych with
		| 0x2E ->
			st.cur <- st.cur + 1;
			(yy4 [@tailcall]) st
		| 0x30|0x31|0x32|0x33|0x34|0x35|0x36|0x37|0x38|0x39 ->
			st.cur <- st.cur + 1;
			(yy6 [@tailcall]) st
		| _ -> (yy2 [@tailcall]) st

and yy4 (st : state) : semver option =
	let yych = Char.code st.str.[st.cur] in
	match yych with
		| 0x30|0x31|0x32|0x33|0x34|0x35|0x36|0x37|0x38|0x39 ->
			st.yyt2 <- st.cur;
			st.cur <- st.cur + 1;
			(yy7 [@tailcall]) st
		| _ -> (yy5 [@tailcall]) st

and yy5 (st : state) : semver option =
	st.cur <- st.mar;
	(yy2 [@tailcall]) st

and yy6 (st : state) : semver option =
	let yych = Char.code st.str.[st.cur] in
	match yych with
		| 0x2E ->
			st.cur <- st.cur + 1;
			(yy4 [@tailcall]) st
		| 0x30|0x31|0x32|0x33|0x34|0x35|0x36|0x37|0x38|0x39 ->
			st.cur <- st.cur + 1;
			(yy6 [@tailcall]) st
		| _ -> (yy5 [@tailcall]) st

and yy7 (st : state) : semver option =
	let yych = Char.code st.str.[st.cur] in
	match yych with
		| 0x00 ->
			st.yyt3 <- st.cur;
			st.yyt4 <- none;
			st.yyt5 <- none;
			st.cur <- st.cur + 1;
			(yy8 [@tailcall]) st
		| 0x2E ->
			st.yyt3 <- st.cur;
			st.yyt5 <- st.cur;
			st.cur <- st.cur + 1;
			(yy9 [@tailcall]) st
		| 0x30|0x31|0x32|0x33|0x34|0x35|0x36|0x37|0x38|0x39 ->
			st.cur <- st.cur + 1;
			(yy7 [@tailcall]) st
		| _ -> (yy5 [@tailcall]) st

and yy8 (st : state) : semver option =
	st.yynmatch <- 4;
	st.yypmatch.(2) <- st.yyt1;
	st.yypmatch.(4) <- st.yyt2;
	st.yypmatch.(5) <- st.yyt3;
	st.yypmatch.(6) <- st.yyt5;
	st.yypmatch.(7) <- st.yyt4;
	st.yypmatch.(0) <- st.yyt1;
	st.yypmatch.(1) <- st.cur;
	st.yypmatch.(3) <- st.yyt2;
	st.yypmatch.(3) <- st.yypmatch.(3) + -1;
#44 "ocaml/submatch/03_posix.re"
	
        (* Even `yypmatch` values are for opening parentheses, odd values
           are for closing parentheses, the first group is the whole match. *)
        Some {
            major = s2n st.str st.yypmatch.(2) st.yypmatch.(3);
            minor = s2n st.str st.yypmatch.(4) st.yypmatch.(5);
            patch = if st.yypmatch.(6) = none then 0
                else s2n st.str (st.yypmatch.(6) + 1) st.yypmatch.(7)
        }

#141 "ocaml/submatch/03_posix.ml"

and yy9 (st : state) : semver option =
	let yych = Char.code st.str.[st.cur] in
	if (yych <= 0x00) then (yy5 [@tailcall]) st
	else (yy11 [@tailcall]) st yych

and yy10 (st : state) : semver option =
	let yych = Char.code st.str.[st.cur] in
	(yy11 [@tailcall]) st yych

and yy11 (st : state) (yych : int) : semver option =
	match yych with
		| 0x00 ->
			st.yyt4 <- st.cur;
			st.cur <- st.cur + 1;
			(yy8 [@tailcall]) st
		| 0x30|0x31|0x32|0x33|0x34|0x35|0x36|0x37|0x38|0x39 ->
			st.cur <- st.cur + 1;
			(yy10 [@tailcall]) st
		| _ -> (yy5 [@tailcall]) st

and parse (st : state) : semver option =
	(yy0 [@tailcall]) st

#55 "ocaml/submatch/03_posix.re"


let test (str: string) (result: semver option) =
    let st = {
        str = str;
        cur = 0;
        mar = 0;
        yynmatch = 0;
        yypmatch = Array.make (2 * yymaxnmatch) none;
        
#177 "ocaml/submatch/03_posix.ml"

		yyt1 = none;
		yyt2 = none;
		yyt3 = none;
		yyt4 = none;
		yyt5 = none;
#64 "ocaml/submatch/03_posix.re"

    }
    in if not (parse st = result) then raise (Failure "error")

let main () =
    test "23.34\x00" (Some {major = 23; minor = 34; patch = 0});
    test "1.2.99999\x00" (Some {major = 1; minor = 2; patch = 99999});
    test "1.a\x00" None

let _ = main ()

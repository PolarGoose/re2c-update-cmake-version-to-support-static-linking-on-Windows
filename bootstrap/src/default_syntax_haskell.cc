#include "src/parse/conf_parser.h"
const char* DEFAULT_SYNTAX_HASKELL =
    "supported_apis = [\"record\", \"generic\"];\n"
    "supported_api_styles = [\"free-form\"];\n"
    "supported_code_models = [\"recursive_functions\"];\n"
    "supported_targets = [\"code\", \"dot\"];\n"
    "supported_features = [\"nested_ifs\", \"monadic\"];\n"
    "\n"
    "semicolons = 1;\n"
    "//semicolons = 0;\n"
    "implicit_bool_conversion = 0;\n"
    "backtick_quoted_strings = 0;\n"
    "standalone_single_quotes = 1; // TODO: what about identifiers?\n"
    "indentation_sensitive = 1;\n"
    "wrap_blocks_in_braces = 0;\n"
    "\n"
    "conf:api = record;\n"
    "conf:api:style = free-form;\n"
    "conf:api:sigil = \"@@\";\n"
    "conf:define:YYGETCOND:naked = 0;\n"
    "conf:define:YYSETCOND:naked = 0;\n"
    "conf:define:YYSETCOND@cond = \"@@\";\n"
    "conf:define:YYGETSTATE:naked = 0;\n"
    "conf:define:YYSETSTATE:naked = 0;\n"
    "conf:define:YYSETSTATE@state = \"@@\";\n"
    "conf:define:YYFILL@len = \"@@\";\n"
    "conf:define:YYFILL:naked = 0;\n"
    "conf:define:YYFN = [\"<undefined-function-name>;<undefined-function-type>\"];\n"
    "conf:yyfn:sep = \";\";\n"
    "conf:variable:yycond = \"_yycond\";\n"
    "conf:variable:yyctable = \"\"; // unused\n"
    "conf:variable:yyaccept = \"_yyaccept\";\n"
    "conf:variable:yytarget = \"\"; // unused\n"
    "conf:variable:yystate = \"_yystate\";\n"
    "conf:variable:yynmatch = \"\"; // no array for `yypmatch` in Haskell => no need for `yynmatch`\n"
    "conf:variable:yypmatch = \"yypmatch\";\n"
    "conf:variable:yyrecord = \"yyrecord\";\n"
    "conf:variable:yych = \"yych\";\n"
    "conf:variable:yych:conversion = 0;\n"
    "conf:variable:yych:literals = hex;\n"
    "conf:variable:yych:emit = (code_model.recursive_functions ? 0 : 1);\n"
    "conf:variable:yybm = \"yybm\";\n"
    "conf:variable:yybm:hex = 0;\n"
    "conf:variable:yyfill = \"yyfill\";\n"
    "conf:variable:yystable = \"\"; // deprecated\n"
    "conf:header = \"\";\n"
    "conf:eof = -1;\n"
    "conf:sentinel = -1;\n"
    "conf:yyfill:enable = 1;\n"
    "conf:yyfill:parameter = 1;\n"
    "conf:yyfill:check = 1;\n"
    "conf:tags = 0;\n"
    "conf:leftmost-captures = 0;\n"
    "conf:posix-captures = 0;\n"
    "conf:tags:prefix = \"_yyt\";\n"
    "conf:invert-captures = 0;\n"
    "conf:cond:abort = 1;\n"
    "conf:cond:prefix = \"yyc_\";\n"
    "conf:cond:enumprefix = \"YYC_\";\n"
    "conf:cond:divider@cond = \"@@\";\n"
    "conf:cond:goto@cond = \"@@\";\n"
    "conf:state:abort = 1;\n"
    "conf:state:nextlabel = 0;\n"
    "conf:bit-vectors = 0;\n"
    "conf:debug-output = 0;\n"
    "conf:computed-gotos = 0;\n"
    "conf:computed-gotos:threshold = 9;\n"
    "conf:nested-ifs = 0;\n"
    "conf:case-insensitive = 0;\n"
    "conf:case-inverted = 0;\n"
    "conf:case-ranges = 0;\n"
    "conf:unsafe = 0;\n"
    "conf:monadic = 0;\n"
    "conf:encoding:ebcdic = 0;\n"
    "conf:encoding:utf32 = 0;\n"
    "conf:encoding:ucs2 = 0;\n"
    "conf:encoding:utf16 = 0;\n"
    "conf:encoding:utf8 = 0;\n"
    "conf:encoding-policy = ignore;\n"
    "conf:empty-class = match-empty;\n"
    "conf:indent:string = \"    \";\n"
    "conf:indent:top = 0;\n"
    "conf:label:prefix = \"yy\";\n"
    "conf:label:yyfill = \"yyFillLabel\";\n"
    "conf:label:yyloop = \"\";\n"
    "conf:label:yyNext = \"yyNext\";\n"
    "conf:label:start = 0;\n"
    "\n"
    "conf:define:YYBACKUP = \"yybackup\";\n"
    "conf:define:YYBACKUPCTX = \"yybackupctx\";\n"
    "conf:define:YYCONDTYPE = \"YYCONDTYPE\";\n"
    "conf:define:YYCOPYMTAG = \"yycopymtag\";\n"
    "conf:define:YYCOPYSTAG = \"yycopystag\";\n"
    "conf:define:YYCTYPE = \"YYCTYPE\";\n"
    "conf:define:YYCTXMARKER = \"_yyctxmarker\";\n"
    "conf:define:YYCURSOR = \"_yycursor\";\n"
    "conf:define:YYDEBUG = \"yydebug\";\n"
    "conf:define:YYFILL = \"yyfill\";\n"
    "conf:define:YYGETACCEPT = \"yygetaccept\";\n"
    "conf:define:YYGETCOND = \"yygetcond\";\n"
    "conf:define:YYGETSTATE = \"yygetstate\";\n"
    "conf:define:YYINPUT = \"_yyinput\";\n"
    "conf:define:YYLESSTHAN = \"yylessthan\";\n"
    "conf:define:YYLIMIT = \"_yylimit\";\n"
    "conf:define:YYMARKER = \"_yymarker\";\n"
    "conf:define:YYMAXFILL = \"yymaxfill\";\n"
    "conf:define:YYMAXNMATCH = \"yymaxnmatch\";\n"
    "conf:define:YYMTAGN = \"yymtagn\";\n"
    "conf:define:YYMTAGP = \"yymtagp\";\n"
    "conf:define:YYPEEK = (api.record ? \"index\" : \"yypeek\");\n"
    "conf:define:YYRESTORE = \"yyrestore\";\n"
    "conf:define:YYRESTORECTX = \"yyrestorectx\";\n"
    "conf:define:YYRESTORETAG = \"yyrestoretag\";\n"
    "conf:define:YYSETACCEPT = \"yysetaccept\";\n"
    "conf:define:YYSETCOND = \"yysetcond\";\n"
    "conf:define:YYSETSTATE = \"yysetstate\";\n"
    "conf:define:YYSHIFT = \"yyshift\";\n"
    "conf:define:YYSHIFTSTAG = \"yyshiftstag\";\n"
    "conf:define:YYSHIFTMTAG = \"yyshiftmtag\";\n"
    "conf:define:YYSKIP = \"yyskip\";\n"
    "conf:define:YYSTAGN = \"yystagn\";\n"
    "conf:define:YYSTAGP = \"yystagp\";\n"
    "conf:tags:expression = sigil;\n"
    "conf:tags:negative = (api.generic ? \"@@\" : \"(-1)\");\n"
    "conf:cond:divider = \"\";\n"
    "conf:cond:goto = \"\";\n"
    "\n"
    "code:var_local = topindent \"let \" name \" = \" init \" in\" nl;\n"
    "code:var_global = topindent \"let \" name \" = \" init nl;\n"
    "\n"
    "code:const_local = topindent \"let \" name \" = \" init \" in\" nl;\n"
    "code:const_global = topindent name \" = \" init nl;\n"
    "\n"
    "// code:array_local\n"
    "// code:array_global\n"
    "\n"
    "// `code:array_elem` is used to generate operations on POSIX `yypmatch` array.\n"
    "// Override it to generate an identifier instead, as mutable arrays are non-idiomatic in Haskell.\n"
    "code:array_elem = array index;\n"
    "\n"
    "code:type_int = \"int\";\n"
    "code:type_uint = \"uint\";\n"
    "code:type_cond_enum = (storable_state? \"int\" : \"uint\");\n"
    "// code:type_yybm\n"
    "// code:type_yytarget\n"
    "\n"
    "// code:assign\n"
    "\n"
    "code:if_then_else =\n"
    "    [branch{0}: topindent (many ? \"if \" cond \" then\" : \"when (\" cond \") $\") (monadic ? \" do\") nl\n"
    "        indent [stmt: stmt] dedent]\n"
    "    [branch{1:-1}: topindent \"else\" (have_cond? \" if \" cond \" then\") (monadic ? \" do\") nl\n"
    "        indent [stmt: stmt] dedent];\n"
    "\n"
    "code:if_then_else_oneline =\n"
    "    [branch{0}: topindent (many ? \"if \" cond \" then \" : \"when (\" cond \") $ \") [stmt: stmt] nl]\n"
    "    [branch{1:-1}: topindent \"else \" (have_cond? \"if \" cond \" then \") [stmt: stmt] nl];\n"
    "\n"
    "code:switch =\n"
    "    topindent \"case \" expr \" of\" nl\n"
    "        indent [case: case] dedent;\n"
    "\n"
    "code:switch_cases = topindent \"_c | \"\n"
    "    [case{0:-2}: case \" || \"]\n"
    "    [case{-1}:   case \" ->\" (monadic ? \" do\") nl\n"
    "        indent [stmt: stmt] dedent\n"
    "    ];\n"
    "\n"
    "code:switch_case_range = (many\n"
    "    ? [val{0}: val] \" <= _c && _c <= \" [val{-1}: val]\n"
    "    : [val{0}: val] \" == _c\");\n"
    "\n"
    "code:switch_case_default = \"True\";\n"
    "\n"
    "code:enum =\n"
    "    \"data \" name \" = \"\n"
    "        [elem{0:-2}: elem \" | \"]\n"
    "        [elem{-1}: elem] \" deriving (Eq, Show)\"\n"
    "    nl;\n"
    "\n"
    "code:enum_elem = name;\n"
    "\n"
    "code:fndef =\n"
    "    name \" :: \" [arg: argtype \" -> \"] type nl\n"
    "    name [arg: \" \" argname] \" =\" (monadic ? \" do\") nl\n"
    "        indent [stmt: stmt] dedent;\n"
    "\n"
    "code:fncall =\n"
    "    topindent (have_retval ? \"let \" retval \" = \")\n"
    "        name (have_args ? [arg: \" \" arg] : \" ()\") nl;\n"
    "\n"
    "code:tailcall = topindent name (have_args ? [arg: \" \" arg] : \" ()\") nl;\n"
    "\n"
    "code:recursive_functions = [fn: fndef nl];\n"
    "\n"
    "code:fingerprint =\n"
    "    \"-- Generated by re2c\" (have_version? \" \" version) (have_date? \" on \" date) nl\n"
    "    (api.record ? \"{-# LANGUAGE RecordWildCards #-}\" nl);\n"
    "\n"
    "code:line_info = \"#\" line \" \\\"\" file \"\\\"\" nl;\n"
    "\n"
    "code:abort = topindent \"error \\\"internal lexer error\\\"\" nl;\n"
    "\n"
    "code:yydebug = topindent debug nl;\n"
    "\n"
    "code:yypeek =\n"
    "    topindent (api.record\n"
    "        ? (monadic\n"
    "            ? char \" <- return $ \" peek \" \" input \" \" cursor\n"
    "            : \"let \" char \" = \" peek \" \" input \" \" cursor \" in\")\n"
    "        : (monadic\n"
    "            ? char \" <- \" peek\n"
    "            : \"let \" char \" = \" peek \" in\")\n"
    "    ) nl;\n"
    "\n"
    "code:yyskip =\n"
    "    topindent (api.record\n"
    "        ? (monadic\n"
    "            ? cursor \" <- return $ \" cursor \" + 1\"\n"
    "            : \"let __ = \" cursor \" + 1 in let \" cursor \" = __ in\")\n"
    "        : skip\n"
    "    ) nl;\n"
    "\n"
    "code:yybackup =\n"
    "    topindent (api.record\n"
    "        ? (monadic\n"
    "            ? \"let \" marker \" = \" cursor\n"
    "            : \"let \" marker \" = \" cursor \" in\")\n"
    "        : backup\n"
    "    ) nl;\n"
    "\n"
    "code:yybackupctx =\n"
    "    topindent (api.record\n"
    "        ? (monadic\n"
    "            ? \"let \" ctxmarker \" = \" cursor\n"
    "            : \"let \" ctxmarker \" = \" cursor \" in\")\n"
    "        : backupctx\n"
    "    ) nl;\n"
    "\n"
    "code:yyrestore =\n"
    "    topindent (api.record\n"
    "        ? (monadic\n"
    "            ? \"let \" cursor \" = \" marker\n"
    "            : \"let \" cursor \" = \" marker \" in\")\n"
    "        : restore\n"
    "    ) nl;\n"
    "\n"
    "code:yyrestorectx =\n"
    "    topindent (api.record\n"
    "        ? (monadic\n"
    "            ? \"let \" cursor \" = \" ctxmarker\n"
    "            : \"let \" cursor \" = \" ctxmarker \" in\")\n"
    "        : restorectx\n"
    "    ) nl;\n"
    "\n"
    "code:yyrestoretag =\n"
    "    topindent (api.record\n"
    "        ? (monadic\n"
    "            ? \"let \" cursor \" = \" tag\n"
    "            : \"let \" cursor \" = \" tag \" in\")\n"
    "        : restoretag\n"
    "    ) nl;\n"
    "\n"
    "code:yyshift =\n"
    "    topindent (api.record\n"
    "        ? (monadic\n"
    "            ? cursor \" <- return $ \" cursor \" - \" offset\n"
    "            : \"let __ = \" cursor \" - \" offset \" in let \" cursor \" = __ in\")\n"
    "        : shift\n"
    "    ) nl;\n"
    "\n"
    "code:yyshiftstag =\n"
    "    topindent (api.record\n"
    "        ? (monadic\n"
    "            ? tag \" <- return $ if \" tag \" == \" neg \" then \" neg \" else \" tag \" - \" offset\n"
    "            :         \"let __ = if \" tag \" == \" neg \" then \" neg \" else \" tag \" - \" offset\n"
    "                \" in let \" tag \" = __ in\")\n"
    "        : shiftstag\n"
    "    ) nl;\n"
    "\n"
    "code:yyshiftmtag = topindent shiftmtag nl;\n"
    "\n"
    "code:yystagp =\n"
    "    topindent (api.record\n"
    "        ? (monadic\n"
    "            ? \"let \" tag \" = \" cursor\n"
    "            : \"let \" tag \" = \" cursor \" in\")\n"
    "        : stagp\n"
    "    ) nl;\n"
    "\n"
    "code:yymtagp = topindent mtagp nl;\n"
    "\n"
    "code:yystagn =\n"
    "    topindent (api.record\n"
    "        ? (monadic\n"
    "            ? \"let \" tag \" = \" neg\n"
    "            : \"let \" tag \" = \" neg \" in\")\n"
    "        : stagn\n"
    "    ) nl;\n"
    "\n"
    "code:yymtagn = topindent mtagn nl;\n"
    "\n"
    "code:yycopystag =\n"
    "    topindent (api.record\n"
    "        ? (monadic\n"
    "            ? \"let \" lhs \" = \" rhs\n"
    "            : \"let \" lhs \" = \" rhs \" in\")\n"
    "        : copystag\n"
    "    ) nl;\n"
    "\n"
    "code:yycopymtag =\n"
    "    topindent (api.record\n"
    "        ? (monadic\n"
    "            ? \"let \" lhs \" = \" rhs\n"
    "            : \"let \" lhs \" = \" rhs \" in\")\n"
    "        : copymtag\n"
    "    ) nl;\n"
    "\n"
    "code:yygetaccept = (api.record ? var : getaccept);\n"
    "\n"
    "code:yysetaccept =\n"
    "    topindent (api.record\n"
    "        ? (monadic\n"
    "            ? \"let \" var \" = \" val\n"
    "            : \"let \" var \" = \" val \" in\")\n"
    "        : setaccept\n"
    "    ) nl;\n"
    "\n"
    "code:yygetcond = (api.record ? var : getcond);\n"
    "\n"
    "code:yysetcond =\n"
    "    topindent (api.record\n"
    "        ? (monadic\n"
    "            ? \"let \" var \" = \" val\n"
    "            : \"let \" var \" = \" val \" in\")\n"
    "        : setcond\n"
    "    ) nl;\n"
    "\n"
    "code:yygetstate = (api.record ? var : getstate);\n"
    "\n"
    "code:yysetstate =\n"
    "    topindent (api.record\n"
    "        ? (monadic\n"
    "            ? \"let \" var \" = \" val\n"
    "            : \"let \" var \" = \" val \" in\")\n"
    "        : setstate\n"
    "    ) nl;\n"
    "\n"
    "code:yylessthan =\n"
    "    (api.record\n"
    "        ? cursor \" >= \" limit // YYFILL check can only be used with EOF rule $\n"
    "        : lessthan);\n"
    ;

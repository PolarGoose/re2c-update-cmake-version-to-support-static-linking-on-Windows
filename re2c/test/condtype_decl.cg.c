/* Generated by re2c */
#line 1 "condtype_decl.cg.re"
#line 4 "condtype_decl.cg.c"

enum YYCONDTYPE {
	yyca,
	yycb,
};

#line 1 "condtype_decl.cg.re"

int main ()
{
	YYCONDTYPE cond;
	char * YYCURSOR;
#define YYGETCONDITION() cond

#line 19 "condtype_decl.cg.c"
{
	unsigned char yych;
	static void *yyctable[2] = {
		&&yyc_a,
		&&yyc_b,
	};
	goto *yyctable[YYGETCONDITION()];
/* *********************************** */
yyc_a:
	yych = *YYCURSOR;
	if (yych == 'a') goto yy4;
yy4:
	++YYCURSOR;
#line 11 "condtype_decl.cg.re"
	{}
#line 35 "condtype_decl.cg.c"
/* *********************************** */
yyc_b:
	yych = *YYCURSOR;
	if (yych == 'b') goto yy9;
yy9:
	++YYCURSOR;
#line 12 "condtype_decl.cg.re"
	{}
#line 44 "condtype_decl.cg.c"
}
#line 13 "condtype_decl.cg.re"

	return 0;
}
re2c: warning: line 13: control flow in condition 'a' is undefined for strings that match '[\x0-\x60\x62-\xFF]', use default rule '*' [-Wundefined-control-flow]
re2c: warning: line 13: control flow in condition 'b' is undefined for strings that match '[\x0-\x61\x63-\xFF]', use default rule '*' [-Wundefined-control-flow]
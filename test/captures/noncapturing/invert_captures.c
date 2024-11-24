/* Generated by re2c */
// re2c $INPUT -o $OUTPUT -i --leftmost-captures --invert-captures

// B is capturing

{
	YYCTYPE yych;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
		case 'A': goto yy2;
		case 'B': goto yy3;
		default: goto yy1;
	}
yy1:
	++YYCURSOR;
	{ * }
yy2:
	++YYCURSOR;
	{ A }
yy3:
	++YYCURSOR;
	yynmatch = 1;
	yypmatch[0] = YYCURSOR;
	yypmatch[0] -= 1;
	yypmatch[1] = YYCURSOR;
	{ B }
}


// B is non-capturing, A is capturing, plus the implicit whole rule capture for A and B

{
	YYCTYPE yych;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
		case 'A': goto yy6;
		case 'B': goto yy7;
		default: goto yy5;
	}
yy5:
	++YYCURSOR;
	{ * }
yy6:
	++YYCURSOR;
	yynmatch = 2;
	yypmatch[0] = YYCURSOR;
	yypmatch[0] -= 1;
	yypmatch[2] = yypmatch[0];
	yypmatch[1] = YYCURSOR;
	yypmatch[3] = yypmatch[1];
	{ A }
yy7:
	++YYCURSOR;
	yynmatch = 1;
	yypmatch[0] = YYCURSOR;
	yypmatch[0] -= 1;
	yypmatch[1] = YYCURSOR;
	{ B }
}


// B is capturing

{
	YYCTYPE yych;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
		case 'A': goto yy10;
		case 'B': goto yy11;
		default: goto yy9;
	}
yy9:
	++YYCURSOR;
	{ * }
yy10:
	++YYCURSOR;
	{ A }
yy11:
	++YYCURSOR;
	yynmatch = 1;
	yypmatch[0] = YYCURSOR;
	yypmatch[0] -= 1;
	yypmatch[1] = YYCURSOR;
	{ B }
}

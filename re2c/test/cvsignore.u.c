/* Generated by re2c */
#line 1 "cvsignore.u.re"

#define YYFILL(n) if (cursor >= limit) break;
#define YYCTYPE unsigned int
#define YYCURSOR cursor
#define YYLIMIT limit
#define YYMARKER marker

#line 16 "cvsignore.u.re"


#define APPEND(text) \
	append(output, outsize, text, sizeof(text) - sizeof(YYCTYPE))

inline void append(YYCTYPE *output, size_t & outsize, const YYCTYPE * text, size_t len)
{
	memcpy(output + outsize, text, len);
	outsize += (len / sizeof(YYCTYPE));
}

void scan(YYCTYPE *pText, size_t *pSize, int *pbChanged)
{
	// rule
	// scan lines
	// find $ in lines
	//   compact $<keyword>: .. $ to $<keyword>$
  
	YYCTYPE *output;
	const YYCTYPE *cursor, *limit, *marker;

	cursor = marker = output = *pText;

	size_t insize = *pSize;
	size_t outsize = 0;

	limit = cursor + insize;

	while(1) {
loop:

#line 43 "cvsignore.u.c"
{
	YYCTYPE yych;
	if ((YYLIMIT - YYCURSOR) < 11) YYFILL(11);
	yych = *YYCURSOR;
	if (yych != '$') goto yy4;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 'D':	goto yy10;
	case 'I':	goto yy9;
	case 'L':	goto yy8;
	case 'R':	goto yy7;
	case 'S':	goto yy5;
	default:	goto yy3;
	}
yy3:
#line 53 "cvsignore.u.re"
	{ output[outsize++] = cursor[-1]; if (cursor >= limit) break; goto loop; }
#line 61 "cvsignore.u.c"
yy4:
	yych = *++YYCURSOR;
	goto yy3;
yy5:
	yych = *++YYCURSOR;
	if (yych == 'o') goto yy44;
yy6:
	YYCURSOR = YYMARKER;
	goto yy3;
yy7:
	yych = *++YYCURSOR;
	if (yych == 'e') goto yy32;
	goto yy6;
yy8:
	yych = *++YYCURSOR;
	if (yych == 'o') goto yy25;
	goto yy6;
yy9:
	yych = *++YYCURSOR;
	if (yych == 'd') goto yy19;
	goto yy6;
yy10:
	yych = *++YYCURSOR;
	if (yych != 'a') goto yy6;
	yych = *++YYCURSOR;
	if (yych != 't') goto yy6;
	yych = *++YYCURSOR;
	if (yych != 'e') goto yy6;
	yych = *++YYCURSOR;
	if (yych == '$') goto yy15;
	if (yych != ':') goto yy6;
	yych = *++YYCURSOR;
	if (yych == '$') goto yy6;
	goto yy18;
yy15:
	++YYCURSOR;
#line 48 "cvsignore.u.re"
	{ APPEND(L"$" L"Date$"); goto loop; }
#line 100 "cvsignore.u.c"
yy17:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy18:
	if (yych == '\n') goto yy6;
	if (yych == '$') goto yy15;
	goto yy17;
yy19:
	yych = *++YYCURSOR;
	if (yych == '$') goto yy21;
	if (yych != ':') goto yy6;
	yych = *++YYCURSOR;
	if (yych == '$') goto yy6;
	goto yy24;
yy21:
	++YYCURSOR;
#line 49 "cvsignore.u.re"
	{ APPEND(L"$" L"Id$"); goto loop; }
#line 120 "cvsignore.u.c"
yy23:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy24:
	if (yych == '\n') goto yy6;
	if (yych == '$') goto yy21;
	goto yy23;
yy25:
	yych = *++YYCURSOR;
	if (yych != 'g') goto yy6;
	yych = *++YYCURSOR;
	if (yych == '$') goto yy28;
	if (yych != ':') goto yy6;
	yych = *++YYCURSOR;
	if (yych == '$') goto yy6;
	goto yy31;
yy28:
	++YYCURSOR;
#line 50 "cvsignore.u.re"
	{ APPEND(L"$" L"Log$"); goto loop; }
#line 142 "cvsignore.u.c"
yy30:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy31:
	if (yych == '\n') goto yy6;
	if (yych == '$') goto yy28;
	goto yy30;
yy32:
	yych = *++YYCURSOR;
	if (yych != 'v') goto yy6;
	yych = *++YYCURSOR;
	if (yych != 'i') goto yy6;
	yych = *++YYCURSOR;
	if (yych != 's') goto yy6;
	yych = *++YYCURSOR;
	if (yych != 'i') goto yy6;
	yych = *++YYCURSOR;
	if (yych != 'o') goto yy6;
	yych = *++YYCURSOR;
	if (yych != 'n') goto yy6;
	yych = *++YYCURSOR;
	if (yych == '$') goto yy40;
	if (yych != ':') goto yy6;
	yych = *++YYCURSOR;
	if (yych == '$') goto yy6;
	goto yy43;
yy40:
	++YYCURSOR;
#line 51 "cvsignore.u.re"
	{ APPEND(L"$" L"Revision$"); goto loop; }
#line 174 "cvsignore.u.c"
yy42:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy43:
	if (yych == '\n') goto yy6;
	if (yych == '$') goto yy40;
	goto yy42;
yy44:
	yych = *++YYCURSOR;
	if (yych != 'u') goto yy6;
	yych = *++YYCURSOR;
	if (yych != 'r') goto yy6;
	yych = *++YYCURSOR;
	if (yych != 'c') goto yy6;
	yych = *++YYCURSOR;
	if (yych != 'e') goto yy6;
	yych = *++YYCURSOR;
	if (yych == '$') goto yy50;
	if (yych != ':') goto yy6;
	yych = *++YYCURSOR;
	if (yych == '$') goto yy6;
	goto yy53;
yy50:
	++YYCURSOR;
#line 52 "cvsignore.u.re"
	{ APPEND(L"$" L"Source$"); goto loop; }
#line 202 "cvsignore.u.c"
yy52:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy53:
	if (yych == '\n') goto yy6;
	if (yych == '$') goto yy50;
	goto yy52;
}
#line 55 "cvsignore.u.re"

	}
	output[outsize] = '\0';

	// set the new size
	*pSize = outsize;
	
	*pbChanged = (insize == outsize) ? 0 : 1;
}
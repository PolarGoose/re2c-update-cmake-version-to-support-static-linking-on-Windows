/* Generated by re2c */
#line 1 "input11_b.re"
// re2c $INPUT -o $OUTPUT -b

#line 6 "input11_b.c"
{
	YYCTYPE yych;
	static const unsigned char yybm[] = {
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 
		0xE0, 0xE0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 
		0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 
		0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 
		0xC0, 0xC0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x80, 
		0x00, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 
		0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 
		0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 
		0xC0, 0xC0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	};
	if ((YYLIMIT - YYCURSOR) < 6) YYFILL(6);
	yych = *YYCURSOR;
	if (yych <= '@') {
		if (yych <= '/') {
			if (yych == '-') goto yy2;
		} else {
			if (yych <= '0') goto yy3;
			if (yych <= '9') goto yy5;
		}
	} else {
		if (yych <= 'q') {
			if (yych <= 'Z') goto yy6;
			if (yych >= 'a') goto yy6;
		} else {
			if (yych <= 'r') goto yy9;
			if (yych <= 'z') goto yy6;
		}
	}
	++YYCURSOR;
yy1:
#line 16 "input11_b.re"
	{ return -1; }
#line 65 "input11_b.c"
yy2:
	yych = *++YYCURSOR;
	if (yych <= '0') goto yy1;
	if (yych <= '9') goto yy5;
	goto yy1;
yy3:
	++YYCURSOR;
yy4:
#line 14 "input11_b.re"
	{ return 2; }
#line 76 "input11_b.c"
yy5:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yybm[0+yych] & 0x20) {
		goto yy5;
	}
	goto yy4;
yy6:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy7:
	if (yybm[0+yych] & 0x40) {
		goto yy6;
	}
yy8:
#line 13 "input11_b.re"
	{ return 1; }
#line 96 "input11_b.c"
yy9:
	yych = *++YYCURSOR;
	if (yych != 'e') goto yy7;
	yych = *++YYCURSOR;
	if (yych != '2') goto yy7;
	yych = *++YYCURSOR;
	if (yych != 'c') goto yy7;
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych != ':') goto yy7;
	yych = *++YYCURSOR;
	if (yych <= '^') {
		if (yych <= '@') goto yy10;
		if (yych <= 'Z') goto yy11;
	} else {
		if (yych == '`') goto yy10;
		if (yych <= 'z') goto yy11;
	}
yy10:
	YYCURSOR = YYMARKER;
	goto yy8;
yy11:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yybm[0+yych] & 0x80) {
		goto yy11;
	}
#line 12 "input11_b.re"
	{ return 0; }
#line 126 "input11_b.c"
}
#line 18 "input11_b.re"

/* Generated by re2c */
// re2c $INPUT -o $OUTPUT -i --flex-syntax

{
	YYCTYPE yych;
	if ((YYLIMIT - YYCURSOR) < 4) YYFILL(4);
	yych = *(YYMARKER = YYCURSOR);
	if (yych >= 0x01) {
		yyt1 = YYCURSOR;
		yyt2 = NULL;
		goto yy2;
	}
	yyt1 = YYCURSOR;
	yyt2 = NULL;
	yyt3 = NULL;
	yyt4 = YYCURSOR;
	yyt5 = NULL;
yy1:
	yynmatch = 7;
	yypmatch[2] = yyt1;
	yypmatch[5] = yyt2;
	yypmatch[7] = yyt3;
	yypmatch[8] = yyt4;
	yypmatch[11] = yyt5;
	yypmatch[13] = yyt5;
	yypmatch[0] = yyt1;
	yypmatch[1] = YYCURSOR;
	yypmatch[3] = yyt4;
	yypmatch[4] = yyt2;
	yypmatch[6] = yyt3;
	yypmatch[9] = YYCURSOR;
	yypmatch[10] = yyt5;
	yypmatch[12] = yyt5;
	if (yypmatch[4] != NULL) yypmatch[4] -= 2;
	if (yypmatch[6] != NULL) yypmatch[6] -= 3;
	if (yypmatch[10] != NULL) yypmatch[10] -= 2;
	if (yypmatch[12] != NULL) yypmatch[12] -= 3;
	{}
yy2:
	yych = *++YYCURSOR;
	if (yych >= 0x01) goto yy3;
	YYCURSOR = YYMARKER;
	yyt1 = YYCURSOR;
	yyt2 = NULL;
	yyt3 = NULL;
	yyt4 = YYCURSOR;
	yyt5 = NULL;
	goto yy1;
yy3:
	yych = *++YYCURSOR;
	if (yych <= 0x00) {
		yyt2 = YYCURSOR;
		yyt3 = NULL;
		yyt4 = YYCURSOR;
		yyt5 = NULL;
		goto yy1;
	}
	yyt3 = YYCURSOR;
	yych = *++YYCURSOR;
	if (yych <= 0x00) {
		yyt3 = YYCURSOR;
		yyt4 = YYCURSOR;
		yyt5 = NULL;
		goto yy1;
	}
yy4:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= 0x00) {
		yyt2 = YYCURSOR;
		yyt3 = NULL;
		yyt4 = YYCURSOR;
		yyt5 = NULL;
		goto yy1;
	}
	yyt2 = YYCURSOR;
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= 0x00) {
		yyt2 = yyt3;
		yyt3 = YYCURSOR;
		yyt4 = YYCURSOR;
		yyt5 = NULL;
		goto yy1;
	}
	yyt3 = yyt2;
	goto yy4;
}

captures/posix/glennfowler/44.re:6:4: warning: rule matches empty string [-Wmatch-empty-string]
captures/posix/glennfowler/44.re:7:7: warning: rule matches empty string [-Wmatch-empty-string]
captures/posix/glennfowler/44.re:7:7: warning: unreachable rule (shadowed by rule at line 6) [-Wunreachable-rules]
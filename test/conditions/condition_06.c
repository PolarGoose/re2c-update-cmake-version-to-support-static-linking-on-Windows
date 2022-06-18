/* Generated by re2c */
#line 1 "conditions/condition_06.re"
// re2c $INPUT -o $OUTPUT -cs
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	BSIZE	8192

typedef struct Scanner
{
	FILE			*fp;
	unsigned char	*cur, *tok, *lim, *eof;
	unsigned char 	buffer[BSIZE];
} Scanner;

int fill(Scanner *s, int len)
{
	if (!len)
	{
		s->cur = s->tok = s->lim = s->buffer;
		s->eof = 0;
	}
	if (!s->eof)
	{
		int got, cnt = s->tok - s->buffer;

		if (cnt > 0)
		{
			memcpy(s->buffer, s->tok, s->lim - s->tok);
			s->tok -= cnt;
			s->cur -= cnt;
			s->lim -= cnt;
		}
		cnt = BSIZE - cnt;
		if ((got = fread(s->lim, 1, cnt, s->fp)) != cnt)
		{
			s->eof = &s->lim[got];
		}
		s->lim += got;
	}
	else if (s->cur + len > s->eof)
	{
		return 0; /* not enough input data */
	}
	return -1;
}

void fputl(const char *s, size_t len, FILE *stream)
{
	while(len-- > 0)
	{
		fputc(*s++, stream);
	}
}

#line 58 "conditions/condition_06.c"
enum YYCONDTYPE {
	EStateNormal,
	EStateComment,
	EStateSkiptoeol,
	EStateString
};
#line 55 "conditions/condition_06.re"


void scan(Scanner *s)
{
	int cond = EStateNormal;
	
	fill(s, 0);

	for(;;)
	{
		s->tok = s->cur;

#line 78 "conditions/condition_06.c"
		{
			unsigned char yych;
			if (cond < 2) {
				if (cond < 1) {
					goto yyc_Normal;
				} else {
					goto yyc_Comment;
				}
			} else {
				if (cond < 3) {
					goto yyc_Skiptoeol;
				} else {
					goto yyc_String;
				}
			}
/* *********************************** */
yyc_Normal:
			if ((s->lim - s->cur) < 3) { if(fill(s, 3) >= 0) break; }
			yych = *s->cur;
			if (yych <= '.') {
				if (yych == '"') goto yy2;
			} else {
				if (yych <= '/') goto yy3;
				if (yych == '?') goto yy4;
			}
			++s->cur;
yy1:
#line 141 "conditions/condition_06.re"
			{
				fputc(*s->tok, stdout);
				continue;
			}
#line 111 "conditions/condition_06.c"
yy2:
			++s->cur;
#line 135 "conditions/condition_06.re"
			{
				fputc(*s->tok, stdout);
				state = EStateString;
				continue;
			}
#line 120 "conditions/condition_06.c"
yy3:
			yych = *++s->cur;
			if (yych == '*') goto yy5;
			if (yych == '/') goto yy6;
			goto yy1;
yy4:
			yych = *(s->tok = ++s->cur);
			if (yych == '?') goto yy7;
			goto yy1;
yy5:
			++s->cur;
#line 127 "conditions/condition_06.re"
			{
				goto yyc_Comment;
			}
#line 136 "conditions/condition_06.c"
yy6:
			++s->cur;
#line 131 "conditions/condition_06.re"
			{
				goto yyc_Skiptoeol;
			}
#line 143 "conditions/condition_06.c"
yy7:
			yych = *++s->cur;
			switch (yych) {
				case '!': goto yy9;
				case '\'': goto yy10;
				case '(': goto yy11;
				case ')': goto yy12;
				case '-': goto yy13;
				case '/': goto yy14;
				case '<': goto yy15;
				case '=': goto yy16;
				case '>': goto yy17;
				default: goto yy8;
			}
yy8:
			s->cur = s->tok;
			goto yy1;
yy9:
			++s->cur;
#line 117 "conditions/condition_06.re"
			{
				fputc('|', stdout);
				continue;
			}
#line 168 "conditions/condition_06.c"
yy10:
			++s->cur;
#line 112 "conditions/condition_06.re"
			{
				fputc('^', stdout);
				continue;
			}
#line 176 "conditions/condition_06.c"
yy11:
			++s->cur;
#line 82 "conditions/condition_06.re"
			{
				fputc('[', stdout);
				continue;
			}
#line 184 "conditions/condition_06.c"
yy12:
			++s->cur;
#line 87 "conditions/condition_06.re"
			{
				fputc(']', stdout);
				continue;
			}
#line 192 "conditions/condition_06.c"
yy13:
			++s->cur;
#line 122 "conditions/condition_06.re"
			{
				fputc('~', stdout);
				continue;
			}
#line 200 "conditions/condition_06.c"
yy14:
			++s->cur;
#line 107 "conditions/condition_06.re"
			{
				fputc('\\', stdout);
				continue;
			}
#line 208 "conditions/condition_06.c"
yy15:
			++s->cur;
#line 92 "conditions/condition_06.re"
			{
				fputc('{', stdout);
				continue;
			}
#line 216 "conditions/condition_06.c"
yy16:
			++s->cur;
#line 102 "conditions/condition_06.re"
			{
				fputc('#', stdout);
				continue;
			}
#line 224 "conditions/condition_06.c"
yy17:
			++s->cur;
#line 97 "conditions/condition_06.re"
			{
				fputc('}', stdout);
				continue;
			}
#line 232 "conditions/condition_06.c"
/* *********************************** */
yyc_Comment:
			if ((s->lim - s->cur) < 2) { if(fill(s, 2) >= 0) break; }
			yych = *s->cur;
			if (yych == '*') goto yy20;
			++s->cur;
yy19:
#line 150 "conditions/condition_06.re"
			{
				goto yyc_Comment;
			}
#line 244 "conditions/condition_06.c"
yy20:
			yych = *++s->cur;
			if (yych != '/') goto yy19;
			++s->cur;
#line 146 "conditions/condition_06.re"
			{
				continue;
			}
#line 253 "conditions/condition_06.c"
/* *********************************** */
yyc_Skiptoeol:
			if ((s->lim - s->cur) < 5) { if(fill(s, 5) >= 0) break; }
			yych = *s->cur;
			if (yych <= '>') {
				if (yych == '\n') goto yy23;
			} else {
				if (yych <= '?') goto yy24;
				if (yych == '\\') goto yy25;
			}
			++s->cur;
yy22:
#line 166 "conditions/condition_06.re"
			{
				goto yyc_Skiptoeol;
			}
#line 270 "conditions/condition_06.c"
yy23:
			++s->cur;
#line 162 "conditions/condition_06.re"
			{
				continue;
			}
#line 277 "conditions/condition_06.c"
yy24:
			yych = *(s->tok = ++s->cur);
			if (yych == '?') goto yy26;
			goto yy22;
yy25:
			yych = *(s->tok = ++s->cur);
			if (yych == '\n') goto yy28;
			if (yych == '\r') goto yy29;
			goto yy22;
yy26:
			yych = *++s->cur;
			if (yych == '/') goto yy30;
yy27:
			s->cur = s->tok;
			goto yy22;
yy28:
			++s->cur;
#line 158 "conditions/condition_06.re"
			{
				goto yyc_Skiptoeol;
			}
#line 299 "conditions/condition_06.c"
yy29:
			yych = *++s->cur;
			if (yych == '\n') goto yy28;
			goto yy27;
yy30:
			yych = *++s->cur;
			if (yych == '\n') goto yy31;
			if (yych == '\r') goto yy32;
			goto yy27;
yy31:
			++s->cur;
#line 154 "conditions/condition_06.re"
			{
				goto yyc_Skiptoeol;
			}
#line 315 "conditions/condition_06.c"
yy32:
			yych = *++s->cur;
			if (yych == '\n') goto yy31;
			goto yy27;
/* *********************************** */
yyc_String:
			if ((s->lim - s->cur) < 2) { if(fill(s, 2) >= 0) break; }
			yych = *s->cur;
			if (yych == '"') goto yy35;
			if (yych == '\\') goto yy36;
			++s->cur;
yy34:
#line 180 "conditions/condition_06.re"
			{
				fputc(*s->tok, stdout);
				continue;
			}
#line 333 "conditions/condition_06.c"
yy35:
			++s->cur;
#line 175 "conditions/condition_06.re"
			{
				fputc(*s->tok, stdout);
				continue;
			}
#line 341 "conditions/condition_06.c"
yy36:
			yych = *++s->cur;
			if (yych == '\n') goto yy34;
			++s->cur;
#line 170 "conditions/condition_06.re"
			{
				fputl((const char*)s->tok, 2, stdout);
				continue;
			}
#line 351 "conditions/condition_06.c"
		}
#line 184 "conditions/condition_06.re"

	}
}

int main(int argc, char **argv)
{
	Scanner in;
	char c;

	if (argc != 2)
	{
		fprintf(stderr, "%s <file>\n", argv[0]);
		return 1;;
	}

	memset((char*) &in, 0, sizeof(in));

	if (!strcmp(argv[1], "-"))
	{
		in.fp = stdin;
	}
	else if ((in.fp = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "Cannot open file '%s'\n", argv[1]);
		return 1;
	}

	scan(&in);

	if (in.fp != stdin)
	{
		fclose(in.fp);
	}
	return 0;
}
/* Generated by re2c */
// re2c $INPUT -o $OUTPUT -i --case-ranges
#include <assert.h>

bool lex(const char *s) {
    const char *YYCURSOR = s;
    
{
	char yych;
	yych = *YYCURSOR;
	switch (yych) {
		case '1' ... '9': goto yy2;
		default: goto yy1;
	}
yy1:
	++YYCURSOR;
	{ return false; }
yy2:
	yych = *++YYCURSOR;
	switch (yych) {
		case '0' ... '9': goto yy2;
		default: goto yy3;
	}
yy3:
	{ return true; }
}

}

int main() {
    assert(lex("1234"));
    return 0;
}
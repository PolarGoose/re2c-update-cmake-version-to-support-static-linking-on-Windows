/* Generated by re2c */
#line 1 "push_fb.re"
// re2c $INPUT -o $OUTPUT -fb
/*
 *  A push-model scanner example for re2c -f
 *  Written Mon Apr 11 2005 by mgix@mgix.com
 *  This file is in the public domain.
 *
 */

// ----------------------------------------------------------------------

#include <fcntl.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#if defined(WIN32)

    typedef signed char     int8_t;
    typedef signed short    int16_t;
    typedef signed int      int32_t;

    typedef unsigned char   uint8_t;
    typedef unsigned short  uint16_t;
    typedef unsigned int    uint32_t;

#else

    #include <stdint.h>
    #include <unistd.h>

    #ifndef O_BINARY
        #define O_BINARY 0
    #endif

#endif

// ----------------------------------------------------------------------
#define TOKENS              \
                            \
    TOK(kEOF)               \
    TOK(kEOL)               \
    TOK(kUnknown)           \
    TOK(kIdentifier)        \
    TOK(kDecimalConstant)   \
                            \
    TOK(kEqual)             \
    TOK(kLeftParen)         \
    TOK(kRightParen)        \
    TOK(kMinus)             \
    TOK(kPlus)              \
    TOK(kStar)              \
    TOK(kSlash)             \
                            \
    TOK(kIf)                \
    TOK(kFor)               \
    TOK(kElse)              \
    TOK(kGoto)              \
    TOK(kBreak)             \
    TOK(kWhile)             \
    TOK(kReturn)            \


// ----------------------------------------------------------------------
static const char *tokenNames[] =
{
    #define TOK(x) #x,
        TOKENS
    #undef TOK
};

// ----------------------------------------------------------------------
class PushScanner
{
public:

    enum Token
    {
        #define TOK(x) x,
            TOKENS
        #undef TOK
    };

private:

    bool        eof;
    int32_t     state;

    uint8_t     *limit;
    uint8_t     *start;
    uint8_t     *cursor;
    uint8_t     *marker;

    uint8_t     *buffer;
    uint8_t     *bufferEnd;

    uint8_t     yych;
    uint32_t    yyaccept;

public:

    // ----------------------------------------------------------------------
    PushScanner()
    {
        limit = 0;
        start = 0;
        state = -1;
        cursor = 0;
        marker = 0;
        buffer = 0;
        eof = false;
        bufferEnd = 0;
    }

    // ----------------------------------------------------------------------
    ~PushScanner()
    {
    }

    // ----------------------------------------------------------------------
    void send(
        Token token
    )
    {
        size_t tokenSize = cursor-start;
        const char *tokenName = tokenNames[token];
        printf(
            "scanner is pushing out a token of type %d (%s)",
            token,
            tokenName
        );

        if(token==kEOF) putchar('\n');
        else
        {
            size_t tokenNameSize = strlen(tokenNames[token]);
            size_t padSize = 20-(20<tokenNameSize ? 20 : tokenNameSize);
            for(size_t i=0; i<padSize; ++i) putchar(' ');
            printf(" : ---->");

            fwrite(
                start,
                tokenSize,
                1,
                stdout
            );

            printf("<----\n");
        }
    }

    // ----------------------------------------------------------------------
    uint32_t push(
        const void  *input,
        ssize_t     inputSize
    )
    {
        printf(
            "scanner is receiving a new data batch of length %d\n"
            "scanner continues with saved state = %d\n",
            inputSize,
            state
        );

        /*
         * Data source is signaling end of file when batch size
         * is less than maxFill. This is slightly annoying because
         * maxFill is a value that can only be known after re2c does
         * its thing. Practically though, maxFill is never bigger than
         * the longest keyword, so given our grammar, 32 is a safe bet.
         */
        uint8_t null[64];
        const ssize_t maxFill = 32;
        if(inputSize<maxFill)
        {
            eof = true;
            input = null;
            inputSize = sizeof(null);
            memset(null, 0, sizeof(null));
        }

        /*
         * When we get here, we have a partially
         * consumed buffer which is in the following state:
         *                                                                last valid char        last valid buffer spot
         *                                                                v                      v
         * +-------------------+-------------+---------------+-------------+----------------------+
         * ^                   ^             ^               ^             ^                      ^
         * buffer              start         marker          cursor        limit                  bufferEnd
         * 
         * We need to stretch the buffer and concatenate the new chunk of input to it
         *
         */
        size_t used = limit-buffer;
        size_t needed = used+inputSize;
        size_t allocated = bufferEnd-buffer;
        if(allocated<needed)
        {
            size_t limitOffset = limit-buffer;
            size_t startOffset = start-buffer;
            size_t markerOffset = marker-buffer;
            size_t cursorOffset = cursor-buffer;

                buffer = (uint8_t*)realloc(buffer, needed);
                bufferEnd = needed+buffer;

            marker = markerOffset + buffer;
            cursor = cursorOffset + buffer;
            start = buffer + startOffset;
            limit = limitOffset + buffer;
        }
        memcpy(limit, input, inputSize);
        limit += inputSize;

        // The scanner starts here
        #define YYLIMIT         limit
        #define YYCURSOR        cursor
        #define YYMARKER        marker
        #define YYCTYPE         uint8_t

        #define SKIP(x)         { start = cursor; goto yy0; }
        #define SEND(x)         { send(x); SKIP();          }
        #define YYFILL(n)       { goto fill;                }

        #define YYGETSTATE()    state
        #define YYSETSTATE(x)   { state = (x);  }

    start:

        
#line 234 "push_fb.c"
{
	static const unsigned char yybm[] = {
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192,   0,   0,   0,   0,   0,   0, 
		  0, 128, 128, 128, 128, 128, 128, 128, 
		128, 128, 128, 128, 128, 128, 128, 128, 
		128, 128, 128, 128, 128, 128, 128, 128, 
		128, 128, 128,   0,   0,   0,   0, 128, 
		  0, 128, 128, 128, 128, 128, 128, 128, 
		128, 128, 128, 128, 128, 128, 128, 128, 
		128, 128, 128, 128, 128, 128, 128, 128, 
		128, 128, 128,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
	};
	switch (YYGETSTATE()) {
		default: goto yy0;
		case 0: goto yyFillLabel0;
		case 1: goto yyFillLabel1;
		case 2: goto yyFillLabel2;
	}
yy0:
	if ((YYLIMIT - YYCURSOR) < 7) {
		YYSETSTATE(0);
		YYFILL(7);
	}
yyFillLabel0:
	yych = *YYCURSOR;
	if (yybm[0+yych] & 64) {
		goto yy12;
	}
	if (yych <= '=') {
		if (yych <= '(') {
			if (yych <= '\n') {
				if (yych <= 0x00) goto yy2;
				if (yych <= 0x08) goto yy3;
				if (yych <= '\t') goto yy4;
				goto yy5;
			} else {
				if (yych <= 0x1F) {
					if (yych <= '\r') goto yy4;
					goto yy3;
				} else {
					if (yych <= ' ') goto yy4;
					if (yych <= '\'') goto yy3;
					goto yy6;
				}
			}
		} else {
			if (yych <= ',') {
				if (yych <= ')') goto yy7;
				if (yych <= '*') goto yy8;
				if (yych <= '+') goto yy9;
				goto yy3;
			} else {
				if (yych <= '.') {
					if (yych <= '-') goto yy10;
					goto yy3;
				} else {
					if (yych <= '/') goto yy11;
					if (yych <= '<') goto yy3;
					goto yy13;
				}
			}
		}
	} else {
		if (yych <= 'e') {
			if (yych <= '_') {
				if (yych <= '@') goto yy3;
				if (yych <= 'Z') goto yy14;
				if (yych <= '^') goto yy3;
				goto yy14;
			} else {
				if (yych <= 'a') {
					if (yych <= '`') goto yy3;
					goto yy14;
				} else {
					if (yych <= 'b') goto yy16;
					if (yych <= 'd') goto yy14;
					goto yy17;
				}
			}
		} else {
			if (yych <= 'q') {
				if (yych <= 'g') {
					if (yych <= 'f') goto yy18;
					goto yy19;
				} else {
					if (yych == 'i') goto yy20;
					goto yy14;
				}
			} else {
				if (yych <= 'v') {
					if (yych <= 'r') goto yy21;
					goto yy14;
				} else {
					if (yych <= 'w') goto yy22;
					if (yych <= 'z') goto yy14;
					goto yy3;
				}
			}
		}
	}
yy2:
	++YYCURSOR;
	YYSETSTATE(-1);
#line 260 "push_fb.re"
	{ send(kEOF); return 1;  }
#line 363 "push_fb.c"
yy3:
	++YYCURSOR;
	YYSETSTATE(-1);
#line 261 "push_fb.re"
	{ SEND(kUnknown);        }
#line 369 "push_fb.c"
yy4:
	++YYCURSOR;
	YYSETSTATE(-1);
#line 259 "push_fb.re"
	{ SKIP();                }
#line 375 "push_fb.c"
yy5:
	++YYCURSOR;
	YYSETSTATE(-1);
#line 258 "push_fb.re"
	{ SKIP();                }
#line 381 "push_fb.c"
yy6:
	++YYCURSOR;
	YYSETSTATE(-1);
#line 251 "push_fb.re"
	{ SEND(kLeftParen);      }
#line 387 "push_fb.c"
yy7:
	++YYCURSOR;
	YYSETSTATE(-1);
#line 252 "push_fb.re"
	{ SEND(kRightParen);     }
#line 393 "push_fb.c"
yy8:
	++YYCURSOR;
	YYSETSTATE(-1);
#line 255 "push_fb.re"
	{ SEND(kStar);           }
#line 399 "push_fb.c"
yy9:
	++YYCURSOR;
	YYSETSTATE(-1);
#line 254 "push_fb.re"
	{ SEND(kPlus);           }
#line 405 "push_fb.c"
yy10:
	++YYCURSOR;
	YYSETSTATE(-1);
#line 253 "push_fb.re"
	{ SEND(kMinus);          }
#line 411 "push_fb.c"
yy11:
	++YYCURSOR;
	YYSETSTATE(-1);
#line 256 "push_fb.re"
	{ SEND(kSlash);          }
#line 417 "push_fb.c"
yy12:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) {
		YYSETSTATE(1);
		YYFILL(1);
	}
yyFillLabel1:
	yych = *YYCURSOR;
	if (yybm[0+yych] & 64) {
		goto yy12;
	}
	YYSETSTATE(-1);
#line 248 "push_fb.re"
	{ SEND(kDecimalConstant);}
#line 432 "push_fb.c"
yy13:
	++YYCURSOR;
	YYSETSTATE(-1);
#line 250 "push_fb.re"
	{ SEND(kEqual);          }
#line 438 "push_fb.c"
yy14:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) {
		YYSETSTATE(2);
		YYFILL(1);
	}
yyFillLabel2:
	yych = *YYCURSOR;
yy15:
	if (yybm[0+yych] & 128) {
		goto yy14;
	}
	YYSETSTATE(-1);
#line 247 "push_fb.re"
	{ SEND(kIdentifier);     }
#line 454 "push_fb.c"
yy16:
	yych = *++YYCURSOR;
	if (yych == 'r') goto yy23;
	goto yy15;
yy17:
	yych = *++YYCURSOR;
	if (yych == 'l') goto yy24;
	goto yy15;
yy18:
	yych = *++YYCURSOR;
	if (yych == 'o') goto yy25;
	goto yy15;
yy19:
	yych = *++YYCURSOR;
	if (yych == 'o') goto yy26;
	goto yy15;
yy20:
	yych = *++YYCURSOR;
	if (yych == 'f') goto yy27;
	goto yy15;
yy21:
	yych = *++YYCURSOR;
	if (yych == 'e') goto yy28;
	goto yy15;
yy22:
	yych = *++YYCURSOR;
	if (yych == 'h') goto yy29;
	goto yy15;
yy23:
	yych = *++YYCURSOR;
	if (yych == 'e') goto yy30;
	goto yy15;
yy24:
	yych = *++YYCURSOR;
	if (yych == 's') goto yy31;
	goto yy15;
yy25:
	yych = *++YYCURSOR;
	if (yych == 'r') goto yy32;
	goto yy15;
yy26:
	yych = *++YYCURSOR;
	if (yych == 't') goto yy33;
	goto yy15;
yy27:
	yych = *++YYCURSOR;
	if (yybm[0+yych] & 128) {
		goto yy14;
	}
	YYSETSTATE(-1);
#line 240 "push_fb.re"
	{ SEND(kIf);             }
#line 507 "push_fb.c"
yy28:
	yych = *++YYCURSOR;
	if (yych == 't') goto yy34;
	goto yy15;
yy29:
	yych = *++YYCURSOR;
	if (yych == 'i') goto yy35;
	goto yy15;
yy30:
	yych = *++YYCURSOR;
	if (yych == 'a') goto yy36;
	goto yy15;
yy31:
	yych = *++YYCURSOR;
	if (yych == 'e') goto yy37;
	goto yy15;
yy32:
	yych = *++YYCURSOR;
	if (yybm[0+yych] & 128) {
		goto yy14;
	}
	YYSETSTATE(-1);
#line 241 "push_fb.re"
	{ SEND(kFor);            }
#line 532 "push_fb.c"
yy33:
	yych = *++YYCURSOR;
	if (yych == 'o') goto yy38;
	goto yy15;
yy34:
	yych = *++YYCURSOR;
	if (yych == 'u') goto yy39;
	goto yy15;
yy35:
	yych = *++YYCURSOR;
	if (yych == 'l') goto yy40;
	goto yy15;
yy36:
	yych = *++YYCURSOR;
	if (yych == 'k') goto yy41;
	goto yy15;
yy37:
	yych = *++YYCURSOR;
	if (yybm[0+yych] & 128) {
		goto yy14;
	}
	YYSETSTATE(-1);
#line 242 "push_fb.re"
	{ SEND(kElse);           }
#line 557 "push_fb.c"
yy38:
	yych = *++YYCURSOR;
	if (yybm[0+yych] & 128) {
		goto yy14;
	}
	YYSETSTATE(-1);
#line 243 "push_fb.re"
	{ SEND(kGoto);           }
#line 566 "push_fb.c"
yy39:
	yych = *++YYCURSOR;
	if (yych == 'r') goto yy42;
	goto yy15;
yy40:
	yych = *++YYCURSOR;
	if (yych == 'e') goto yy43;
	goto yy15;
yy41:
	yych = *++YYCURSOR;
	if (yybm[0+yych] & 128) {
		goto yy14;
	}
	YYSETSTATE(-1);
#line 244 "push_fb.re"
	{ SEND(kBreak);          }
#line 583 "push_fb.c"
yy42:
	yych = *++YYCURSOR;
	if (yych == 'n') goto yy44;
	goto yy15;
yy43:
	yych = *++YYCURSOR;
	if (yybm[0+yych] & 128) {
		goto yy14;
	}
	YYSETSTATE(-1);
#line 245 "push_fb.re"
	{ SEND(kWhile);          }
#line 596 "push_fb.c"
yy44:
	yych = *++YYCURSOR;
	if (yybm[0+yych] & 128) {
		goto yy14;
	}
	YYSETSTATE(-1);
#line 246 "push_fb.re"
	{ SEND(kReturn);         }
#line 605 "push_fb.c"
}
#line 262 "push_fb.re"


    fill:
        ssize_t unfinishedSize = cursor-start;
        printf(
            "scanner needs a refill. Exiting for now with:\n"
            "    saved fill state = %d\n"
            "    unfinished token size = %d\n",
            state,
            unfinishedSize
        );

        if(0<unfinishedSize && start<limit)
        {
            printf("    unfinished token is :");
            fwrite(start, 1, cursor-start, stdout);
            putchar('\n');
        }
        putchar('\n');

        /*
         * Once we get here, we can get rid of
         * everything before start and after limit.
         */
        if(eof==true) goto start;
        if(buffer<start)
        {
            size_t startOffset = start-buffer;
            memmove(buffer, start, limit-start);
            marker -= startOffset;
            cursor -= startOffset;
            limit -= startOffset;
            start -= startOffset;
        }
        return 0;
    }
};

// ----------------------------------------------------------------------
int main(
    int     argc,
    char    **argv
)
{
    // Parse cmd line
    int input = 0;
    if(1<argc)
    {
        input = open(argv[1], O_RDONLY | O_BINARY);
        if(input<0)
        {
            fprintf(
                stderr,
                "could not open file %s\n",
                argv[1]
            );
            exit(1);
        }
    }

    /*
     * Tokenize input file by pushing batches
     * of data one by one into the scanner.
     */
    const size_t batchSize = 256;
    uint8_t buffer[batchSize];
    PushScanner scanner;
    while(1)
    {
        ssize_t n = read(input, buffer, batchSize);
        scanner.push(buffer, n);
        if(n<batchSize) break;
    }
    scanner.push(0, -1);
    close(input);

    // Done
    return 0;
}

push_fb.re:238:22: warning: escape has no effect: '\h' [-Wuseless-escape]

# re2py $INPUT -o $OUTPUT -b

def lex(yyinput):
    yycursor = 0
    /*!re2c
        re2c:yyfill:enable = 0;
        re2c:indent:top = 1;

        number = [1-9][0-9]*;

        number { return True }
        *      { return False }
    */

assert lex(b"1234\0")

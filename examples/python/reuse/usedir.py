# Generated by re2py
# re2py $INPUT -o $OUTPUT

# This example shows how to combine reusable re2c blocks: two blocks
# ('colors' and 'fish') are merged into one. The 'salmon' rule occurs
# in both blocks; the 'fish' block takes priority because it is used
# earlier. Default rule * occurs in all three blocks; the local (not
# inherited) definition takes priority.

from enum import Enum

class Ans(Enum):
    COLOR = 1
    FISH = 2
    DUNNO = 3





def lex(yyinput):
    yycursor = 0

    yystate = 0
    while True:
        match yystate:
            case 0:
                yych = yyinput[yycursor]
                yycursor += 1
                match yych:
                    case 0x65:
                        yystate = 3
                        continue
                    case 0x68:
                        yystate = 4
                        continue
                    case 0x6D:
                        yystate = 5
                        continue
                    case 0x72:
                        yystate = 6
                        continue
                    case 0x73:
                        yystate = 7
                        continue
                    case _:
                        yystate = 1
                        continue
            case 1:
                yystate = 2
                continue
            case 2:
                return Ans.DUNNO
            case 3:
                yymarker = yycursor
                yych = yyinput[yycursor]
                if yych == 0x65:
                    yycursor += 1
                    yystate = 8
                    continue
                yystate = 2
                continue
            case 4:
                yymarker = yycursor
                yych = yyinput[yycursor]
                if yych == 0x61:
                    yycursor += 1
                    yystate = 10
                    continue
                yystate = 2
                continue
            case 5:
                yymarker = yycursor
                yych = yyinput[yycursor]
                if yych == 0x61:
                    yycursor += 1
                    yystate = 11
                    continue
                yystate = 2
                continue
            case 6:
                yymarker = yycursor
                yych = yyinput[yycursor]
                if yych == 0x65:
                    yycursor += 1
                    yystate = 12
                    continue
                yystate = 2
                continue
            case 7:
                yymarker = yycursor
                yych = yyinput[yycursor]
                if yych == 0x61:
                    yycursor += 1
                    yystate = 13
                    continue
                yystate = 2
                continue
            case 8:
                yych = yyinput[yycursor]
                if yych == 0x6C:
                    yycursor += 1
                    yystate = 14
                    continue
                yystate = 9
                continue
            case 9:
                yycursor = yymarker
                yystate = 2
                continue
            case 10:
                yych = yyinput[yycursor]
                if yych == 0x64:
                    yycursor += 1
                    yystate = 15
                    continue
                yystate = 9
                continue
            case 11:
                yych = yyinput[yycursor]
                if yych == 0x67:
                    yycursor += 1
                    yystate = 16
                    continue
                yystate = 9
                continue
            case 12:
                yych = yyinput[yycursor]
                if yych == 0x64:
                    yycursor += 1
                    yystate = 17
                    continue
                yystate = 9
                continue
            case 13:
                yych = yyinput[yycursor]
                if yych == 0x6C:
                    yycursor += 1
                    yystate = 18
                    continue
                yystate = 9
                continue
            case 14:
                return Ans.FISH
            case 15:
                yych = yyinput[yycursor]
                if yych == 0x64:
                    yycursor += 1
                    yystate = 19
                    continue
                yystate = 9
                continue
            case 16:
                yych = yyinput[yycursor]
                if yych == 0x65:
                    yycursor += 1
                    yystate = 20
                    continue
                yystate = 9
                continue
            case 17:
                return Ans.COLOR
            case 18:
                yych = yyinput[yycursor]
                if yych == 0x6D:
                    yycursor += 1
                    yystate = 21
                    continue
                yystate = 9
                continue
            case 19:
                yych = yyinput[yycursor]
                if yych == 0x6F:
                    yycursor += 1
                    yystate = 22
                    continue
                yystate = 9
                continue
            case 20:
                yych = yyinput[yycursor]
                if yych == 0x6E:
                    yycursor += 1
                    yystate = 23
                    continue
                yystate = 9
                continue
            case 21:
                yych = yyinput[yycursor]
                if yych == 0x6F:
                    yycursor += 1
                    yystate = 24
                    continue
                yystate = 9
                continue
            case 22:
                yych = yyinput[yycursor]
                if yych == 0x63:
                    yycursor += 1
                    yystate = 25
                    continue
                yystate = 9
                continue
            case 23:
                yych = yyinput[yycursor]
                if yych == 0x74:
                    yycursor += 1
                    yystate = 26
                    continue
                yystate = 9
                continue
            case 24:
                yych = yyinput[yycursor]
                if yych == 0x6E:
                    yycursor += 1
                    yystate = 14
                    continue
                yystate = 9
                continue
            case 25:
                yych = yyinput[yycursor]
                if yych == 0x6B:
                    yycursor += 1
                    yystate = 14
                    continue
                yystate = 9
                continue
            case 26:
                yych = yyinput[yycursor]
                if yych == 0x61:
                    yycursor += 1
                    yystate = 17
                    continue
                yystate = 9
                continue
            case _:
                raise "internal lexer error"


assert lex(b"salmon") == Ans.FISH
assert lex(b"what?") == Ans.DUNNO
/* Generated by re2c */
// re2c $INPUT -o $OUTPUT -fi --loop-switch



	int yystate = YYGETSTATE();
	for (;;) {
		switch (yystate) {
		case -1:
		case 0:
			YYSETSTATE(5);
			if (YYLIMIT <= YYCURSOR) YYFILL(1);
			yych = *YYCURSOR;
			++YYCURSOR;
			switch (yych) {
			case 'a':
				yystate = 3;
				continue;
			default:
				yystate = 1;
				continue;
			}
		case 1:
			yystate = 2;
			continue;
		case 2:
			YYSETSTATE(0);
			{ * }
		case 3:
			yystate = 4;
			continue;
		case 4:
			YYSETSTATE(0);
			{ a }
		case 5:
			yystate = 0;
			continue;
		}
	}




	int yystate = YYGETSTATE();
	for (;;) {
		switch (yystate) {
		case -1:
		case 0:
			yych = *YYCURSOR;
			switch (yych) {
			case 'b':
				++YYCURSOR;
				yystate = 3;
				continue;
			default:
				if (YYLIMIT <= YYCURSOR) {
					YYSETSTATE(6);
					YYFILL();
				}
				++YYCURSOR;
				yystate = 1;
				continue;
			}
		case 1:
			yystate = 2;
			continue;
		case 2:
			YYSETSTATE(0);
			{ * }
		case 3:
			yystate = 4;
			continue;
		case 4:
			YYSETSTATE(0);
			{ b }
		case 5:
			YYSETSTATE(0);
			{ $ }
		case 6:
			if (YYLIMIT <= YYCURSOR) {
				yystate = 5;
				continue;
			}
			yystate = 0;
			continue;
		}
	}

/* Generated by re2c */
// re2c $INPUT -o $OUTPUT --recursive-functions -i
#include <assert.h>

struct State {
    const char* cur;
    const char* mar;
    const char* lim;
    int count;
};


int yy0(State& st);
int yy1(State& st);
int yy2(State& st);
int yy3(State& st);
int yy4(State& st);
int yy5(State& st);
int yy6(State& st);
int yy7(State& st, char yych);
int yy8(State& st);
int yy9(State& st);
int yy10(State& st);
int yy11(State& st);
int lex(State& st);

int yy0(State& st) {
	char yych = *st.cur;
	switch (yych) {
		case ' ':
			++st.cur;
			return yy3(st);
		case '\'':
			++st.cur;
			return yy5(st);
		default:
			if (st.lim <= st.cur) {
				return yy10(st);
			} else {
				++st.cur;
				return yy1(st);
			}
	}
}

int yy1(State& st) {
	return yy2(st);
}

int yy2(State& st) {
	return -1;
}

int yy3(State& st) {
	char yych = *st.cur;
	switch (yych) {
		case ' ':
			++st.cur;
			return yy3(st);
		default: return yy4(st);
	}
}

int yy4(State& st) {
	return lex(st);
}

int yy5(State& st) {
	char yych = *(st.mar = st.cur);
	if (yych <= 0x00) {
		if (st.lim <= st.cur) {
			return yy2(st);
		} else {
			++st.cur;
			return yy6(st);
		}
	} else {
		return yy7(st, yych);
	}
}

int yy6(State& st) {
	char yych = *st.cur;
	return yy7(st, yych);
}

int yy7(State& st, char yych) {
	switch (yych) {
		case '\'':
			++st.cur;
			return yy8(st);
		case '\\':
			++st.cur;
			return yy9(st);
		default:
			if (st.lim <= st.cur) {
				return yy11(st);
			} else {
				++st.cur;
				return yy6(st);
			}
	}
}

int yy8(State& st) {
	++st.count; return lex(st);
}

int yy9(State& st) {
	char yych = *st.cur;
	if (yych <= 0x00) {
		if (st.lim <= st.cur) {
			return yy11(st);
		} else {
			++st.cur;
			return yy6(st);
		}
	} else {
		++st.cur;
		return yy6(st);
	}
}

int yy10(State& st) {
	return st.count;
}

int yy11(State& st) {
	st.cur = st.mar;
	return yy2(st);
}

int lex(State& st) {
	return yy0(st);
}



#define TEST(s, r) do { \
    State st{s, s, s + sizeof(s) - 1, 0}; \
    assert(lex(st) == r); \
} while(0)

int main() {
    TEST("", 0);
    TEST("'qu\0tes' 'are' 'fine: \\'' ", 3);
    TEST("'unterminated\\'", -1);
    return 0;
}

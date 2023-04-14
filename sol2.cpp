#include <bits/stdc++.h>
using namespace std;

class FastIn {
	static constexpr int MAX_SIZE = 1e5;
	char buffer[MAX_SIZE];
	int index, size;
	bool state, space[1 << 8], digit[1 << 8];
	string word;
private:
	char sys_getchar() {
		if (index == size) { index = 0, size = fread(buffer, 1, MAX_SIZE, stdin); }
		return size ? buffer[index++] : (state = false);
	}
	char next_char(char c) {
		char c2;
		while (space[(int) (c2 = sys_getchar())]) {}
		return c2 ? c2 : c;
	}
	const string& next_word() {
		char c; word.clear();
		while (space[(int) (c = sys_getchar())]) {}
		while (!space[(int) c] && c) { word += c, c = sys_getchar(); }
		return word;
	}
	long long stoll2(const string& s) {
		long long ll = 0, sign = 1; int i = 0;
		if (s.size() && (s[i] == '+' || s[i] == '-')) { sign = -(s[i++] - ','); }
		while (i < (int) s.size() && digit[(int) s[i]]) { ll = ll * 10 + (s[i++] - '0'); }
		return ll * sign;
	}
	unsigned long long stoull2(const string& s) {
		unsigned long long ull = 0; int i = 0;
		while (i < (int) s.size() && digit[(int) s[i]]) { ull = ull * 10 + (s[i++] - '0'); }
		return ull;
	}
	int lowcmp(const string& s1, const string& s2) {
		int i = -1;
		while (++i < (int) min(s1.size(), s2.size()) && tolower(s1[i]) == tolower(s2[i])) {}
		int c1 = (i < (int) s1.size() ? tolower(s1[i]) : '\0');
		int c2 = (i < (int) s2.size() ? tolower(s2[i]) : '\0');
		return c1 - c2;
	}
public:
	FastIn() : index(), size(), state(true) {
		space[32] = true;
		for (int i = 9; i <= 13; ++i) { space[i] = true; }
		for (int i = '0'; i <= '9'; ++i) { digit[i] = true; }
	}
	FastIn& operator>>(bool& b)       { b = (!lowcmp(next_word(), "true") ? true : (!lowcmp(word, "false") ? false : stoll2(word))); return *this; }
	FastIn& operator>>(char& c)       { c = next_char(c);               return *this; }
	FastIn& operator>>(char* s)       { strcpy(s, next_word().c_str()); return *this; }
	FastIn& operator>>(string& s)     { s = next_word();                return *this; }
	FastIn& operator>>(double& d)     { d = stod(next_word());          return *this; }
	FastIn& operator>>(float& f)      { f = stof(next_word());          return *this; }
	FastIn& operator>>(long long& ll) { ll = stoll2(next_word());       return *this; }
	FastIn& operator>>(long& l)       { l = stoll2(next_word());        return *this; }
	FastIn& operator>>(int& i)        { i = stoll2(next_word());        return *this; }
	FastIn& operator>>(short& sh)     { sh = stoll2(next_word());       return *this; }
	FastIn& operator>>(unsigned long long& ull) { ull = stoull2(next_word()); return *this; }
	FastIn& operator>>(unsigned long& ul)       { ul = stoull2(next_word());  return *this; }
	FastIn& operator>>(unsigned int& ui)        { ui = stoull2(next_word());  return *this; }
	FastIn& operator>>(unsigned short& ush)     { ush = stoull2(next_word()); return *this; }
	operator bool() { return state; }
};
class FastOut {
	string buffer;
public:
	~FastOut() { assert(buffer.size() == fwrite(buffer.c_str(), 1, buffer.size(), stdout)); }
	FastOut& operator<<(bool b)          { return (b ? *this << "true" : *this << "false"); }
	FastOut& operator<<(char c)          { buffer += c; return *this; }
	FastOut& operator<<(const char* s)   { buffer += s; return *this; }
	FastOut& operator<<(const string& s) { buffer += s; return *this; }
	FastOut& operator<<(double d)        { return *this << to_string(d);  }
	FastOut& operator<<(float f)         { return *this << to_string(f);  }
	FastOut& operator<<(long long ll)    { return *this << to_string(ll); }
	FastOut& operator<<(long l)          { return *this << to_string(l);  }
	FastOut& operator<<(int i)           { return *this << to_string(i);  }
	FastOut& operator<<(short sh)        { return *this << to_string(sh); }
	FastOut& operator<<(unsigned long long ull) { return *this << to_string(ull); }
	FastOut& operator<<(unsigned long ul)       { return *this << to_string(ul);  }
	FastOut& operator<<(unsigned int ui)        { return *this << to_string(ui);  }
	FastOut& operator<<(unsigned short ush)     { return *this << to_string(ush); }
};
static FastIn fin;
static FastOut fout;

#define int long long
#define F first
#define S second
#define untie cin.tie(0)->sync_with_stdio(0)
#define testcase(N) int t; for (N ? t=N : bool(fin>>t); t>0; --t) solve()
#define solution(N)\
	void solve();\
	signed main() { untie; testcase(N); assert(fin && !(fin>>t)); }\
	void solve()

solution(1) {

}

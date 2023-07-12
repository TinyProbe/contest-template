#include <bits/stdc++.h>
using namespace std;
class FastIO {
	static constexpr int MAX_SIZE=(1<<20);
	char i_buffer[MAX_SIZE], *pb, *pe, c, delimiter;
	string o_buffer, word;
	bool state;
private:
	inline char sys_getchar() { return pb==pe && (pe=(pb=i_buffer)+fread(i_buffer, sizeof(char), MAX_SIZE, stdin), pb==pe) ? (state=false) : *pb++; }
	inline bool isspace2(int c) { return (c>=9 && c<=13) || c==32; }
	inline bool isdigit2(int c) { return c>='0' && c<='9'; }
	template <typename T>
	inline bool isliteral(const T &type) {
		(void) type;
		return typeid(typename T::value_type)==typeid(bool)
			|| typeid(typename T::value_type)==typeid(char)
			|| typeid(typename T::value_type)==typeid(char *)
			|| typeid(typename T::value_type)==typeid(string)
			|| typeid(typename T::value_type)==typeid(double)
			|| typeid(typename T::value_type)==typeid(float)
			|| typeid(typename T::value_type)==typeid(long long)
			|| typeid(typename T::value_type)==typeid(long)
			|| typeid(typename T::value_type)==typeid(int)
			|| typeid(typename T::value_type)==typeid(short)
			|| typeid(typename T::value_type)==typeid(unsigned long long)
			|| typeid(typename T::value_type)==typeid(unsigned long)
			|| typeid(typename T::value_type)==typeid(unsigned int)
			|| typeid(typename T::value_type)==typeid(unsigned short);
	}
	inline int lowercmp(const char *s1, const char *s2) {
		while (*s1 && *s2 && tolower(*s1)==tolower(*s2)) { ++s1, ++s2; }
		return *s1-*s2;
	}
	inline bool next_bool() {
		const char *s = next_word().c_str();
		return !lowercmp(s, "true") ? true : (!lowercmp(s, "false") ? false : atoll(s));
	}
	inline char next_char(char src) {
		while (isspace2(c = sys_getchar())) {}
		return (c ? c : src);
	}
	inline const string &next_word() {
		word.clear();
		while (isspace2(c=sys_getchar())) {}
		while (!isspace2(c) && c) { word+=c, c=sys_getchar(); }
		return word;
	}
	inline long long next_llong() {
		long long ll=0, sign=1;
		while ((c=sys_getchar()) && isspace2(c)) {}
		if (c=='+' || c=='-') { sign= -(c - ','), c=sys_getchar(); }
		while (isdigit2(c)) { ll=(ll<<1)+(ll<<3)+(c^48), c=sys_getchar(); }
		while (!isspace2(c) && c) { c=sys_getchar(); }
		return ll*sign;
	}
	inline unsigned long long next_ullong() {
		unsigned long long ull=0;
		while ((c=sys_getchar()) && isspace2(c)) {}
		while (isdigit2(c)) { ull=(ull<<1)+(ull<<3)+(c^48), c=sys_getchar(); }
		while (!isspace2(c) && c) { c=sys_getchar(); }
		return ull;
	}
public:
	inline void setdelimiter(int c) { delimiter=c; }

	FastIO() : pb(), pe(), c(), delimiter(' '), state(true) {}
	~FastIO() { assert(o_buffer.size()==fwrite(o_buffer.c_str(), sizeof(char), o_buffer.size(), stdout)); }
	template <typename T>
	inline FastIO &operator>>(T &type)       { for (auto &e: type) { *this>>e; } return *this; }
	inline FastIO &operator>>(bool &b)       { b=next_bool();  return *this; }
	inline FastIO &operator>>(char &c)       { c=next_char(c); return *this; }
	inline FastIO &operator>>(char *s)       { strcpy(s, next_word().c_str()); return *this; }
	inline FastIO &operator>>(string &s)     { s=std::move(next_word());       return *this; }
	inline FastIO &operator>>(double &d)     { d=atof(next_word().c_str());    return *this; }
	inline FastIO &operator>>(float &f)      { f=atof(next_word().c_str());    return *this; }
	inline FastIO &operator>>(long long &ll) { ll=next_llong(); return *this; }
	inline FastIO &operator>>(long &l)       { l=next_llong();  return *this; }
	inline FastIO &operator>>(int &i)        { i=next_llong();  return *this; }
	inline FastIO &operator>>(short &sh)     { sh=next_llong(); return *this; }
	inline FastIO &operator>>(unsigned long long &ull) { ull=next_ullong(); return *this; }
	inline FastIO &operator>>(unsigned long &ul)       { ul=next_ullong();  return *this; }
	inline FastIO &operator>>(unsigned int &ui)        { ui=next_ullong();  return *this; }
	inline FastIO &operator>>(unsigned short &ush)     { ush=next_ullong(); return *this; }

	template <typename T>
	inline FastIO &operator<<(const T &type) {
		bool islit=isliteral(type);
		for (auto &e: type) { *this<<e<<(islit ? delimiter : '\n'); }
		return *this;
	}
	inline FastIO &operator<<(bool b)          { return *this<<(b ? "true" : "false"); }
	inline FastIO &operator<<(char c)          { o_buffer+=c; return *this; }
	inline FastIO &operator<<(const char *s)   { o_buffer+=s; return *this; }
	inline FastIO &operator<<(const string &s) { o_buffer+=s; return *this; }
	inline FastIO &operator<<(double d)        { return *this<<to_string(d);  }
	inline FastIO &operator<<(float f)         { return *this<<to_string(f);  }
	inline FastIO &operator<<(long long ll)    { return *this<<to_string(ll); }
	inline FastIO &operator<<(long l)          { return *this<<to_string(l);  }
	inline FastIO &operator<<(int i)           { return *this<<to_string(i);  }
	inline FastIO &operator<<(short sh)        { return *this<<to_string(sh); }
	inline FastIO &operator<<(unsigned long long ull) { return *this<<to_string(ull); }
	inline FastIO &operator<<(unsigned long ul)       { return *this<<to_string(ul);  }
	inline FastIO &operator<<(unsigned int ui)        { return *this<<to_string(ui);  }
	inline FastIO &operator<<(unsigned short ush)     { return *this<<to_string(ush); }
	operator bool() { return state; }
} fio;
#define int long long
#define untie ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define testcase(N) int t; for (N?t=N:bool(fio>>t); t>0; --t) solve()
#define main__(N) signed main() { untie; testcase(N); assert(fio && !(fio>>t)); }
#define solution(N) inline void solve(); main__(N) inline void solve()

solution(1) {
	fio << "Hello World!\n";
}


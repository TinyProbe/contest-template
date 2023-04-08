#include <bits/stdc++.h>
#define cin fin
#define F first
#define S second
using namespace std;

class fastin {
	bool state;
private:
	const char* next_chars(char* buffer = nullptr) {
		static char chars[1000010], *buff;
		static int index;
		buff = buffer ? buffer : chars;
		index = 0;
		while (true) {
			buff[index] = getchar_unlocked();
			if ((buff[index] >= 9 && buff[index] <= 13) || buff[index] == 32 || !~buff[index]) {
				if (~buff[index] && !index) { continue; }
				state = ~buff[index];
				buff[index] = '\0'; break;
			}
			index += 1;
		}
		return buff;
	}
public:
	fastin() : state(true) {}
	fastin& operator>>(char&      c)  { c = getchar_unlocked();   return *this; }
	fastin& operator>>(char*      s)  { next_chars(s);            return *this; }
	fastin& operator>>(string&    s)  { s = string(next_chars()); return *this; }
	fastin& operator>>(long long& ll) { ll = atoll(next_chars()); return *this; }
	fastin& operator>>(long&      l)  { l = atol(next_chars());   return *this; }
	fastin& operator>>(int&       i)  { i = atoi(next_chars());   return *this; }
	fastin& operator>>(short&     sh) { sh = atoi(next_chars());  return *this; }
	fastin& operator>>(double&    d)  { d = atof(next_chars());   return *this; }
	fastin& operator>>(float&     f)  { f = atof(next_chars());   return *this; }
	fastin& operator>>(unsigned long long& ull) { ull = stoull(next_chars()); return *this; }
	fastin& operator>>(unsigned long&      ul)  { ul = stoul(next_chars());   return *this; }
	fastin& operator>>(unsigned int&       ui)  { ui = stoul(next_chars());   return *this; }
	fastin& operator>>(unsigned short&     ush) { ush = stoul(next_chars());  return *this; }
	operator bool() { return state; }
} fin;

void solve() {
	
}
int main() {
	int t = 1;
	// cin >> t;
	while (t--) { solve(); }
	assert(cin && !(cin >> t));
}

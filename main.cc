#include <bits/stdc++.h>
using namespace std;
using u8 = unsigned char;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = unsigned long long;
using usize = unsigned long;
using i8 = char;
using i16 = short;
using i32 = int;
using i64 = long long;
using isize = long;
using f32 = float;
using f64 = double;

#define BUFF_SIZE (1 << 5)
#define _isspace(c) (((c)>=9 && (c)<=13) || (c)==' ')
#define _isdigit(c) ((c)>='0' && (c)<='9')

class Scanner {
  i8 buff[BUFF_SIZE];
  usize len, cur;

 public:
  Scanner() : len(), cur() {}
  inline i8 const *nextItem() { // no check memory.
    usize   i = 0;
    do { buff[i] = getchar(); } while (buff[i]!=-1 && _isspace(buff[i]));
    while (buff[i]!=-1 && !_isspace(buff[i])) { buff[++i] = getchar(); }
    buff[i] = '\0';
    return buff;
  }
  inline i64 _atoll(i8 const *s) {
    usize   i = 0;
    bool    pos = true;
    i64     res = 0;
    if (s[i]=='-' || s[i]=='+') { pos = s[i++]=='+'; }
    while (_isdigit(s[i])) {
      res = (res<<1) + (res<<3) + (s[i++]^'0');
    }
    return pos ? res : -res;
  }
  inline Scanner &operator>>(u8 &ref) { ref = _atoll(nextItem()); return *this; }
  inline Scanner &operator>>(u16 &ref) { ref = _atoll(nextItem()); return *this; }
  inline Scanner &operator>>(u32 &ref) { ref = _atoll(nextItem()); return *this; }
  inline Scanner &operator>>(u64 &ref) { ref = _atoll(nextItem()); return *this; }
  inline Scanner &operator>>(usize &ref) { ref = _atoll(nextItem()); return *this; }
  inline Scanner &operator>>(i8 &ref) { ref = _atoll(nextItem()); return *this; }
  inline Scanner &operator>>(i16 &ref) { ref = _atoll(nextItem()); return *this; }
  inline Scanner &operator>>(i32 &ref) { ref = _atoll(nextItem()); return *this; }
  inline Scanner &operator>>(i64 &ref) { ref = _atoll(nextItem()); return *this; }
  inline Scanner &operator>>(isize &ref) { ref = _atoll(nextItem()); return *this; }
  inline Scanner &operator>>(f32 &ref) { ref = atof(nextItem()); return *this; }
  inline Scanner &operator>>(f64 &ref) { ref = atof(nextItem()); return *this; }
  inline Scanner &operator>>(string &ref) { ref = string(nextItem()); return *this; }
} scan;

void solve(); int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(20);
  usize t = 1;
  scan >> t;
  while (t--) { solve(); }
}

void solve() {
}

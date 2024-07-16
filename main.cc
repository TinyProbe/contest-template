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

class Scanner {
  static constexpr usize BUFFER_SIZE = 1 << 22; // warning: string cutting.
  i8 buffer[BUFFER_SIZE];
  usize len, cur;

 public:
  Scanner() : len(fread(buffer, sizeof(i8), BUFFER_SIZE, stdin)), cur() {}
  inline bool _isspace(i8 c) { return (c>=9 && c<=13) || c==' '; }
  inline bool _isdigit(i8 c) { return c>='0' && c<='9'; }
  inline i64 _atoll(i8 const *s) {
    i64 res = 0;
    bool pos = true;
    if (*s=='-' || *s=='+') { pos = *(s++)=='+'; }
    while (*s && _isdigit(*s)) {
      res = (res<<1) + (res<<3) + (*(s++)^'0');
    }
    return pos ? res : -res;
  }
  inline i8 const *nextItem() {
    while (cur < len && _isspace(buffer[cur])) { ++cur; }
    usize l = cur;
    while (cur < len && !_isspace(buffer[cur])) { ++cur; }
    buffer[cur++] = '\0';
    return buffer + l;
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
  // scan >> t;
  while (t--) { solve(); }
}

void solve() {
}

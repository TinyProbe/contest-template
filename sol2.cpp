#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i8 = char;
using i16 = short;
using i32 = int;
using i64 = long long;
using isize = long;
using u8 = unsigned char;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = unsigned long long;
using usize = unsigned long;
using f32 = float;
using f64 = double;

#define untie ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define testcase(N) usize t;for(N?t=N:bool(fio>>t);t>0;--t)solve()
#define main__(N) i32 main(){untie;testcase(N);assert(fio&&!(fio>>t));}
#define solution(N) inline void solve();main__(N)inline void solve()

class FastIO {
 public:
  FastIO() : pb(), pe(), c(), delimiter(' '), state(true) {}
  ~FastIO() { fwrite(o_buffer.c_str(), sizeof(i8), o_buffer.size(), stdout); }

  template <typename T>
  inline FastIO &operator>>(T &ty)     { for (auto &e : ty) *this >> e;  return *this; }
  inline FastIO &operator>>(bool &b)   { b=next_bool();  return *this; }
  inline FastIO &operator>>(i8 &c)     { c=next_char(c); return *this; }
  inline FastIO &operator>>(i8 *s)     { strcpy(s, next_word().c_str()); return *this; }
  inline FastIO &operator>>(string &s) { s=std::move(next_word());       return *this; }
  inline FastIO &operator>>(i16 &sh)   { sh=next_llong(); return *this; }
  inline FastIO &operator>>(i32 &i)    { i=next_llong();  return *this; }
  inline FastIO &operator>>(i64 &ll)   { ll=next_llong(); return *this; }
  inline FastIO &operator>>(isize &l)  { l=next_llong();  return *this; }
  inline FastIO &operator>>(u16 &ush)  { ush=next_ullong(); return *this; }
  inline FastIO &operator>>(u32 &ui)   { ui=next_ullong();  return *this; }
  inline FastIO &operator>>(u64 &ull)  { ull=next_ullong(); return *this; }
  inline FastIO &operator>>(usize &ul) { ul=next_ullong();  return *this; }
  inline FastIO &operator>>(f32 &f)    { f=atof(next_word().c_str()); return *this; }
  inline FastIO &operator>>(f64 &d)    { d=atof(next_word().c_str()); return *this; }

  template <typename T>
  inline FastIO &operator<<(const T &type) {
    bool is = isliteral(type);
    for (auto &e : type) { *this << e << (is ? delimiter : '\n'); }
    return *this;
  }
  inline FastIO &operator<<(bool b) { return *this << (b ? "true" : "false"); }
  inline FastIO &operator<<(i8 c)            { o_buffer += c; return *this; }
  inline FastIO &operator<<(const i8 *s)     { o_buffer += s; return *this; }
  inline FastIO &operator<<(const string &s) { o_buffer += s; return *this; }
  inline FastIO &operator<<(i16 sh)   { return *this << to_string(sh); }
  inline FastIO &operator<<(i32 i)    { return *this << to_string(i);  }
  inline FastIO &operator<<(i64 ll)   { return *this << to_string(ll); }
  inline FastIO &operator<<(isize l)  { return *this << to_string(l);  }
  inline FastIO &operator<<(u16 ush)  { return *this << to_string(ush); }
  inline FastIO &operator<<(u32 ui)   { return *this << to_string(ui);  }
  inline FastIO &operator<<(u64 ull)  { return *this << to_string(ull); }
  inline FastIO &operator<<(usize ul) { return *this << to_string(ul); }
  inline FastIO &operator<<(f32 f)    { return *this << to_string(f);  }
  inline FastIO &operator<<(f64 d)    { return *this << to_string(d);  }

  inline void setdelimiter(i8 c) { delimiter = c; }

  operator bool() { return state; }

 private:
  inline i8 sys_getchar() {
    return pb == pe && (pe = (pb = i_buffer) +
                        fread(i_buffer, sizeof(u8), MAX_SIZE, stdin),
                        pb == pe)
        ? (state = false)
        : *pb++;
  }
  inline bool isspace2(i8 c) { return (c >= 9 && c <= 13) || c == 32; }
  inline bool isdigit2(i8 c) { return c >= '0' && c <= '9'; }
  template <typename T>
  inline bool isliteral(const T &type) {
    (void) type;
    return typeid(typename T::value_type) == typeid(bool)
        || typeid(typename T::value_type) == typeid(i8)
        || typeid(typename T::value_type) == typeid(i8 *)
        || typeid(typename T::value_type) == typeid(string)
        || typeid(typename T::value_type) == typeid(i16)
        || typeid(typename T::value_type) == typeid(i32)
        || typeid(typename T::value_type) == typeid(i64)
        || typeid(typename T::value_type) == typeid(isize)
        || typeid(typename T::value_type) == typeid(u16)
        || typeid(typename T::value_type) == typeid(u32)
        || typeid(typename T::value_type) == typeid(u64)
        || typeid(typename T::value_type) == typeid(usize)
        || typeid(typename T::value_type) == typeid(f32)
        || typeid(typename T::value_type) == typeid(f64);
  }
  inline isize lowercmp(const i8 *s1, const i8 *s2) {
    while (*s1 && *s2 && tolower(*s1) == tolower(*s2)) { ++s1, ++s2; }
    return tolower(*s1) - tolower(*s2);
  }
  inline bool next_bool() {
    const i8 *s = next_word().c_str();
    return !lowercmp(s, "true") ? true
        : (!lowercmp(s, "false") ? false : atoll(s));
  }
  inline i8 next_char(i8 src) {
    while (isspace2(c = sys_getchar())) {}
    return (c ? c : src);
  }
  inline const string &next_word() {
    word.clear();
    while (isspace2(c = sys_getchar())) {}
    while (!isspace2(c) && c) { word += c, c = sys_getchar(); }
    return word;
  }
  inline i64 next_llong() {
    i64 ll = 0, sign = 1;
    while ((c = sys_getchar()) && isspace2(c)) {}
    if (c == '+' || c == '-') { sign = -(c - ','), c = sys_getchar(); }
    while (isdigit2(c)) {
      ll = (ll << 1) + (ll << 3) + (c ^ 48);
      c = sys_getchar();
    }
    while (!isspace2(c) && c) { c = sys_getchar(); }
    return ll * sign;
  }
  inline u64 next_ullong() {
    u64 ull = 0;
    while ((c = sys_getchar()) && isspace2(c)) {}
    while (isdigit2(c)) {
      ull = (ull << 1) + (ull << 3) + (c ^ 48);
      c = sys_getchar();
    }
    while (!isspace2(c) && c) { c = sys_getchar(); }
    return ull;
  }

  static constexpr usize MAX_SIZE = (1 << 20);
  i8 i_buffer[MAX_SIZE], *pb, *pe, c, delimiter;
  string o_buffer, word;
  bool state;
} fio;

solution(0) {
  fio << "hello World!!" << '\n';
}

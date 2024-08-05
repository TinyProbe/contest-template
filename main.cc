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
using f128 = long double;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define setprecision(n) cout << fixed << setprecision(n)
#define loop(var, init, end) \
    for (isize var = (init), __init = (init), __end = (end); \
        __init < __end ? var < __end : var-- > __end; \
        var += __init < __end ? 1 : 0)

class Fastio {
  static constexpr usize BUFF_SIZE = 1 << 20;
  i8 ibuff_[BUFF_SIZE], *pb_, *pe_, c_, delim_;
  string obuff_, item_;
  bool state_;

  inline static bool _isspace(i8 c) { return (c >= 9 && c <= 13) || c == ' '; }
  inline static bool _isdigit(i8 c) { return c >= '0' && c <= '9'; }
  inline static i32 lowercmp(i8 const *s1, i8 const *s2) {
    while (*s1 && *s2 && tolower(*s1) == tolower(*s2)) { ++s1, ++s2; }
    return tolower(*s1) - tolower(*s2);
  }
  inline i8 _getchar() {
    if (pb_ == pe_) {
      pb_ = ibuff_;
      pe_ = pb_ + fread(ibuff_, sizeof(char), BUFF_SIZE, stdin);
    }
    return pb_ == pe_ ? state_ = false : *(pb_++);
  }
  inline bool next_bool() {
    i8 const *s = next_item().c_str();
    return (!lowercmp(s, "true") ? true
            : (!lowercmp(s, "false") ? false : atoll(s)));
  }
  inline i8 next_char() {
    while (_isspace(c_ = _getchar()));
    return c_;
  }
  inline string const &next_item() {
    item_.clear();
    while (_isspace(c_ = _getchar()));
    while (c_ && !_isspace(c_)) { item_ += c_, c_ = _getchar(); } 
    return item_;
  }
  inline i64 next_llong() {
    i64 i = 0, pos = 1;
    while ((c_ = _getchar()) && _isspace(c_));
    if (c_ == '+' || c_ == '-') { pos = c_ == '+', c_ = _getchar(); }
    while (_isdigit(c_)) { i = (i<<1) + (i<<3) + (c_^'0'), c_ = _getchar(); }
    while (c_ && !_isspace(c_)) { c_ = _getchar(); }
    return pos ? i : -i;
  }
  inline u64 next_ullong() {
    u64 u = 0;
    while ((c_ = _getchar()) && _isspace(c_));
    while (_isdigit(c_)) { u = (u<<1) + (u<<3) + (c_^'0'), c_ = _getchar(); }
    while (c_ && !_isspace(c_)) { c_ = _getchar(); }
    return u;
  }
 public:
  Fastio() : pb_(), pe_(), c_(), delim_(' '), state_(true) {}
  ~Fastio() { flush(); assert(*this && !(*this >> c_)); }

  inline void setdelimiter(i8 c) { delim_ = c; }
  inline void flush() {
    fwrite(obuff_.c_str(), sizeof(char), obuff_.size(), stdout);
    obuff_.clear();
  }

  operator bool() { return state_; }

  template <class T>
  inline Fastio &operator>>(T &ref)      { for (auto &e : ref) *this >> e; return *this; }
  inline Fastio &operator>>(bool &ref)   { ref = next_bool(); return *this; }
  inline Fastio &operator>>(string &ref) { ref = move(next_item()); return *this; }
  inline Fastio &operator>>(i8 *ptr)     { strcpy(ptr, next_item().c_str()); return *this; }
  inline Fastio &operator>>(u8 &ref)     { ref = next_ullong(); return *this; }
  inline Fastio &operator>>(u16 &ref)    { ref = next_ullong(); return *this; }
  inline Fastio &operator>>(u32 &ref)    { ref = next_ullong(); return *this; }
  inline Fastio &operator>>(u64 &ref)    { ref = next_ullong(); return *this; }
  inline Fastio &operator>>(usize &ref)  { ref = next_ullong(); return *this; }
  inline Fastio &operator>>(i8 &ref)     { ref = next_char(); return *this; }
  inline Fastio &operator>>(i16 &ref)    { ref = next_llong(); return *this; }
  inline Fastio &operator>>(i32 &ref)    { ref = next_llong(); return *this; }
  inline Fastio &operator>>(i64 &ref)    { ref = next_llong(); return *this; }
  inline Fastio &operator>>(isize &ref)  { ref = next_llong(); return *this; }
  inline Fastio &operator>>(f32 &ref)    { ref = atof(next_item().c_str()); return *this; }
  inline Fastio &operator>>(f64 &ref)    { ref = atof(next_item().c_str()); return *this; }
  inline Fastio &operator>>(f128 &ref)   { ref = atof(next_item().c_str()); return *this; }

  template <class T>
  inline Fastio &operator<<(T const &ref) {
    for (auto &e : ref) *this << e << delim_;
    return *this << '\n';
  }
  inline Fastio &operator<<(bool val)  { return *this << (val ? "true" : "false"); }
  inline Fastio &operator<<(string const &ref) { obuff_ += ref; return *this; }
  inline Fastio &operator<<(i8 const *ptr) { obuff_ += ptr; return *this; }
  inline Fastio &operator<<(u8 val)    { return *this << to_string(val); }
  inline Fastio &operator<<(u16 val)   { return *this << to_string(val); }
  inline Fastio &operator<<(u32 val)   { return *this << to_string(val); }
  inline Fastio &operator<<(u64 val)   { return *this << to_string(val); }
  inline Fastio &operator<<(usize val) { return *this << to_string(val); }
  inline Fastio &operator<<(i8 val)    { obuff_ += val; return *this; }
  inline Fastio &operator<<(i16 val)   { return *this << to_string(val); }
  inline Fastio &operator<<(i32 val)   { return *this << to_string(val); }
  inline Fastio &operator<<(i64 val)   { return *this << to_string(val); }
  inline Fastio &operator<<(isize val) { return *this << to_string(val); }
  inline Fastio &operator<<(f32 val)   { return *this << to_string(val); }
  inline Fastio &operator<<(f64 val)   { return *this << to_string(val); }
  inline Fastio &operator<<(f128 val)  { return *this << to_string(val); }
} fio;

void solve(); int main() {
  fastio, setprecision(20);
  usize t = 1;
  // fio >> t;
  while (t--) { solve(); }
}

void solve() {
}

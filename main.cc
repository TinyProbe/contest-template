#include <bits/stdc++.h>
using namespace std;
using u8    = unsigned char;
using u16   = unsigned short;
using u32   = unsigned int;
using u64   = unsigned long long;
using usize = unsigned long;
using i8    = char;
using i16   = short;
using i32   = int;
using i64   = long long;
using isize = long;
using f32   = float;
using f64   = double;
using f128  = long double;

#define loop(var, init, end) \
    for (i64 var = (init), __end = (end), __asc = var < __end; \
        __asc ? var < __end : var-- > __end; \
        __asc ? ++var : var)

void solve(void); int main(void) {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(20);
  i64 t = 1;
  // cin >> t;
  loop (_, 0, t) { solve(); }
}

void solve(void) {
}

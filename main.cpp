#include <bits/stdc++.h>
using namespace std;

#define llong long long
#define ldouble long double
#define loop(var, init, end) \
    for (llong var = (init), __end = (end), __asc = var < __end; \
        __asc ? var < __end : var-- > __end; \
        __asc ? ++var : var)

void solve(); int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(20);
  llong t = 1;
  // cin >> t;
  loop (_, 0, t) { solve(); }
}

void solve() {
}

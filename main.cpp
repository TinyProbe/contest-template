#include <bits/stdc++.h>
using namespace std;

#define llong long long
#define ldouble long double
#define loop(var, init, end) \
    for (int var = (init), __end = (end), __asc = var < __end; \
            __asc ? var < __end + 1 : var > __end - 1; \
            __asc ? ++var : var) \
        if (__asc ? var < __end : var-- > __end)

void solve();
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) { solve(); }
}

void solve() {
}

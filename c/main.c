#include <stdio.h>

#define llong   long long
#define ldouble long double
#define bool    char
#define true    (bool)1
#define false   (bool)0
#define nullptr (void *)0
#define null    '\0'
#define min(a, b)   ((a)<(b) ? (a) : (b))
#define max(a, b)   ((a)>(b) ? (a) : (b))
#define swap(a, b)  ((a)^=(b),(b)^=(a),(a)^=(b))
#define psum(a)     (((a)*(a)+(a))/2)
#define loop(var, init, end) \
    for (int var = (init), __end = (end), __asc = var < __end; \
            __asc ? var < __end + 1 : var > __end - 1; \
            __asc ? ++var : var) \
        if (__asc ? var < __end : var-- > __end)

llong gcd(llong a, llong b) { return b ? gcd(b, a % b) : a; }
llong lcm(llong a, llong b) { return a * b / gcd(a, b); }

void solve();
int main() {
  llong t = 1;
  // scanf("%d", &t);
  loop (_, 0, t) { solve(); }
}

void solve() {
}

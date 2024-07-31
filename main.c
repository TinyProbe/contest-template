#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

#define min(a, b) ((a)<(b) ? (a) : (b))
#define max(a, b) ((a)>(b) ? (a) : (b))
#define swap(a, b) ((a)^=(b),(b)^=(a),(a)^=(b))
#define true  (u8)1
#define false (u8)0
#define null  (void *)0
#define getc  getchar
#define putc  putchar

typedef unsigned char       u8;
typedef unsigned short      u16;
typedef unsigned int        u32;
typedef unsigned long long  u64;
typedef unsigned long       usize;
typedef char                i8;
typedef short               i16;
typedef int                 i32;
typedef long long           i64;
typedef long                isize;
typedef float               f32;
typedef double              f64;
typedef u8                  bool;

i8 _io[1 << 5];

int getchar_unlocked(void);
int putchar_unlocked(int c);

i64 gcd(i64 a, i64 b) { return b ? gcd(b, a % b) : a; }
i64 lcm(i64 a, i64 b) { return a * b / gcd(a, b); }
bool _isspace(i8 c) { return (c>=9 && c<=13) || c==' '; }
bool _isdigit(i8 c) { return c>='0' && c<='9'; }
usize reads(i8 *const s) { // no check memory.
  usize   i = 0;
  do { s[i] = getc(); } while (s[i]!=-1 && _isspace(s[i]));
  while (s[i]!=-1 && !_isspace(s[i])) { s[++i] = getc(); }
  s[i] = '\0';
  return i;
}
i64 readi(void) {
  usize   i = 0;
  bool    pos = true;
  i64     res = 0;
  reads(_io);
  if (_io[i]=='-' || _io[i]=='+') { pos = _io[i++]=='+'; }
  while (_io[i] && _isdigit(_io[i]))
    res = (res<<1) + (res<<3) + (_io[i++]^'0');
  return pos ? res : -res;
}
void writes(i8 const *s) { while (*s) { putc(*(s++)); } }
void writei(i64 n) {
  usize   i = (1 << 5);
  bool    pos = n >= 0;
  _io[--i] = '\0';
  do { _io[--i] = (n % 10 + '0'), n /= 10; } while (n);
  if (!pos) { _io[--i] = '-'; }
  writes(_io + i);
}

void solve(void); int main(void) {
  usize t = 1;
  t = readi();
  while (t--) { solve(); }
  return 0;
}

void solve(void) {
}

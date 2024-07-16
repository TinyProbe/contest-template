#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define true  (u8)1
#define false (u8)0
#define getc getchar_unlocked
#define putc putchar_unlocked

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

int getchar_unlocked(void);
int putchar_unlocked(int c);

bool _isspace(i8 c) { return (c>=9 && c<=13) || c==' '; }
bool _isdigit(i8 c) { return c>='0' && c<='9'; }
i64 readi(void) {
  i64   res = 0;
  bool  pos = true;
  i8    c = getc();
  while (c!=-1 && _isspace(c)) { c = getc(); }
  if (c=='-' || c=='+') { pos = (c=='+'); c = getc(); }
  while (c!=-1 && _isdigit(c)) {
    res = (res<<1) + (res<<3) + (c^'0');
    c = getc();
  }
  while (c!=-1 && !_isspace(c)) { c = getc(); }
  return pos ? res : -res;
}
void writei(i64 n) {
  static usize const SIZE = 1 << 8;
  i8      buffer[SIZE];
  usize   i = SIZE;
  if (!n) { putc('0'); return; }
  while (n) {
    buffer[--i] = n % 10 + '0';
    n /= 10;
  }
  while (i < SIZE) { putc(buffer[i++]); }
}
void writes(i8 const *s) {
  usize i = 0;
  while (s[i]) { putc(s[i++]); }
}

void solve(void); int main(void) {
  usize t = 1;
  // t = readi();
  while (t--) { solve(); }
  return 0;
}

void solve(void) {
}

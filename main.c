#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define true  (u8)1
#define false (u8)0
#define null  (void *)0
#define getc  getchar_unlocked
#define putc  putchar_unlocked

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

i8 _buff[1 << 5];

bool _isspace(i8 c) { return (c>=9 && c<=13) || c==' '; }
bool _isdigit(i8 c) { return c>='0' && c<='9'; }
void reads(i8 *s) { // no check range.
  *s = getc();
  while (*s!=-1 && _isspace(*s)) { *s = getc(); }
  while (*s!=-1 && !_isspace(*s)) { *++s = getc(); }
  *s = '\0';
}
i64 readi(void) {
  usize   i = 0;
  i64     res = 0;
  bool    pos = true;
  reads(_buff);
  if (_buff[i]=='-' || _buff[i]=='+') { pos = _buff[i++]=='+'; }
  while (_buff[i] && _isdigit(_buff[i])) {
    res = (res<<1) + (res<<3) + (_buff[i++]^'0');
  }
  return pos ? res : -res;
}
void writes(i8 const *s) { while (*s) { putc(*(s++)); } }
void writei(i64 n) {
  usize   i = (1 << 5) - 1;
  if (!n) { putc('0'); return; }
  _buff[i] = '\0';
  while (n) {
    _buff[--i] = (n % 10 + '0'), n /= 10;
  }
  writes(_buff + i);
}

void solve(void); int main(void) {
  usize t = 1;
  // t = readi();
  while (t--) { solve(); }
  return 0;
}

void solve(void) {
}

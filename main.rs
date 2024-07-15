#![allow(dead_code, unused)]

use std::io::*;
use std::collections::*;
use std::{ isize, usize };
use std::{ mem, cmp };

struct UnsafeScanner<R: BufRead> {
  reader: R,
  buf_str: Vec<u8>,
  buf_iter: std::str::SplitAsciiWhitespace<'static>,
}
impl<R: BufRead> UnsafeScanner<R> {
  fn new(reader: R) -> Self {
    Self {
      reader,
      buf_str: vec![],
      buf_iter: "".split_ascii_whitespace(),
    }
  }
  fn scan<T: std::str::FromStr>(&mut self) -> T {
    loop {
      if let Some(token) = self.buf_iter.next() {
        return token.parse().ok().expect("Failed to parse.");
      }
      self.buf_str.clear();
      self.reader
        .read_until(b'\n', &mut self.buf_str)
        .expect("Failed to read.");
      self.buf_iter = unsafe {
        let slice = std::str::from_utf8_unchecked(&self.buf_str);
        std::mem::transmute(slice.split_ascii_whitespace())
      };
    }
  }
}
fn _i() -> &'static mut UnsafeScanner<StdinLock<'static>> {
  static mut SCN: Option<UnsafeScanner<StdinLock>> = None;
  unsafe {
    if let None = SCN {
      SCN = Some(UnsafeScanner::new(stdin().lock()));
    }
    return SCN.as_mut().unwrap();
  }
}
fn _o() -> &'static mut BufWriter<StdoutLock<'static>> {
  static mut WRT: Option<BufWriter<StdoutLock>> = None;
  unsafe {
    if let None = WRT {
      WRT = Some(BufWriter::new(stdout().lock()));
    }
    return WRT.as_mut().unwrap();
  }
}
macro_rules! input {
  ()=>{}; ()=>[];
  (mut $v:ident:$t:tt,$($r:tt)*)=>{input!(mut $v:$t);input!($($r)*);};
  (mut $v:ident:$t:tt)=>{let mut $v=input_inner!($t);};
  ($v:ident:$t:tt,$($r:tt)*)=>{input!($v:$t);input!($($r)*);};
  ($v:ident:$t:tt)=>{let $v=input_inner!($t);};
  (($($v:tt)*):($($t:tt),*),$($r:tt)*)=>{input!(($($v)*):($($t),*));input!($($r)*);};
  (($($v:tt)*):($($t:tt),*))=>{let ($($v)*)=input_inner!(($($t),*));};
}
macro_rules! input_inner {
  (($($t:tt),*))=>{($(input_inner!($t)),*)};
  ([$t:tt;$n:expr])=>{(0..$n).map(|_| input_inner!($t)).collect::<Vec<_>>()};
  ([$t:tt;$pad:expr;$n:expr])=>{{
    let mut tmp=Vec::with_capacity(($pad)+($n));
    tmp.resize_with(($pad),Default::default);
    tmp.resize_with(($pad)+($n),|| input_inner!($t));tmp
  }};
  (chars)=>{input_inner!(String).chars().collect::<Vec<_>>()};
  (vytes)=>{input_inner!(String).bytes().collect::<Vec<_>>()};
  (bytes)=>{input_inner!(String).into_bytes()};
  (usize_1)=>{input_inner!(usize)-1};
  ($t:ty)=>{_i().scan::<$t>()};
}
macro_rules! tny {($c:expr;$t:expr;$f:expr)=>{if $c{$t}else{$f}};}
macro_rules! println {($($fmt:tt)*)=>(writeln!(_o(),$($fmt)*))}
macro_rules! print {($($fmt:tt)*)=>(write!(_o(),$($fmt)*))}

fn main() {
  let t = 1usize;
  // input! { t: usize }
  for _ in 0 .. t { solve(); }
  _o().flush().unwrap();
}

fn solve() {
}

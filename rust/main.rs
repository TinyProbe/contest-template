#![allow(dead_code, unused, static_mut_refs)]

use std::{ io::*, collections::*, isize, usize, mem, cmp };

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

fn cin() -> &'static mut UnsafeScanner<StdinLock<'static>> {
    static mut SCANNER: Option<UnsafeScanner<StdinLock>> = None;
    unsafe {
        if let None = SCANNER { SCANNER = Some(UnsafeScanner::new(stdin().lock())); }
        return SCANNER.as_mut().unwrap();
    }
}

fn cout() -> &'static mut BufWriter<StdoutLock<'static>> {
    static mut PRINTER: Option<BufWriter<StdoutLock>> = None;
    unsafe {
        if let None = PRINTER { PRINTER = Some(BufWriter::new(stdout().lock())); }
        return PRINTER.as_mut().unwrap();
    }
}

macro_rules! input {
    () => {};
    () => [];
    (mut $v:ident:$t:tt,$($r:tt)*) => { input!(mut $v:$t); input!($($r)*); };
    (mut $v:ident:$t:tt) => { let mut $v = input_inner!($t); };
    ($v:ident:$t:tt,$($r:tt)*) => { input!($v:$t); input!($($r)*); };
    ($v:ident:$t:tt) => { let $v = input_inner!($t); };
    (($($v:tt)*):($($t:tt),*),$($r:tt)*) => { input!(($($v)*):($($t),*)); input!($($r)*); };
    (($($v:tt)*):($($t:tt),*)) => { let ($($v)*) = input_inner!(($($t),*)); };
}
macro_rules! input_inner {
    (($($t:tt),*)) => { ($(input_inner!($t)),*) };
    ([$t:tt;$n:expr]) => { (0 .. $n).map(|_| input_inner!($t)).collect::<Vec<_>>() };
    (chars) => { input_inner!(String).chars().collect::<Vec<_>>() };
    (vytes) => { input_inner!(String).bytes().collect::<Vec<_>>() };
    (bytes) => { input_inner!(String).into_bytes() };
    (usize_1) => { input_inner!(usize) - 1 };
    ($t:ty) => { cin().scan::<$t>() };
}
macro_rules! tny { ($c:expr;$t:expr;$f:expr) => (if $c {$t} else {$f}) }
macro_rules! println { ($($fmt:tt)*) => (writeln!(cout(),$($fmt)*)) }
macro_rules! print { ($($fmt:tt)*) => (write!(cout(),$($fmt)*)) }

fn main() {
    let t = 1usize;
    // input![t: usize];
    for _ in 0 .. t { solve(); }
    cout().flush().unwrap();
}

fn solve() {
    println!("hello world!");
}

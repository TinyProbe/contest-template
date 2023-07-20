#![allow(dead_code, unused)]
 
use std::io::*;
use std::mem::swap;
use std::cmp::{min, max};
use std::{isize, usize};
use std::collections::*;
type Queue<T> = LinkedList<T>;
 
struct UnsafeScanner<R: BufRead> {
    reader: R,
    buf_str: Vec<u8>,
    buf_iter: std::str::SplitAsciiWhitespace<'static>, // '
}
impl<R: BufRead> UnsafeScanner<R> {
    fn new(reader: R)->Self {
        Self {reader, buf_str: vec![], buf_iter: "".split_ascii_whitespace()}
    }
    fn scan<T: std::str::FromStr>(&mut self)->T {
        loop {
            if let Some(token) = self.buf_iter.next() {
                return token.parse().ok().expect("Failed to parse.");
            }
            self.buf_str.clear();
            self.reader.read_until(b'\n', &mut self.buf_str).expect("Failed to read.");
            self.buf_iter = unsafe {
                let slice = std::str::from_utf8_unchecked(&self.buf_str);
                std::mem::transmute(slice.split_ascii_whitespace())
            };
        }
    }
}
fn in__()->&'static mut UnsafeScanner<StdinLock<'static>> {
    static mut SCNR: Option<UnsafeScanner<StdinLock>> = None;
    unsafe {
        if let None = SCNR { SCNR = Some(UnsafeScanner::new(stdin().lock())); }
        return SCNR.as_mut().unwrap();
    }
}
fn out()->&'static mut BufWriter<StdoutLock<'static>> {
    static mut BUF: Option<BufWriter<StdoutLock>> = None;
    unsafe {
        if let None = BUF { BUF = Some(BufWriter::new(stdout().lock())); }
        return BUF.as_mut().unwrap();
    }
}
macro_rules! input {
    ()=>{};()=>[];
    (mut $var:ident: $t:tt, $($rest:tt)*)=>{input!(mut $var: $t);input!($($rest)*);};
    (mut $var:ident: $t:tt)=>{let mut $var = __input_inner!($t);};
    ($var:ident: $t:tt, $($rest:tt)*)=>{input!($var: $t);input!($($rest)*);};
    ($var:ident: $t:tt)=>{let $var = __input_inner!($t);};
    (($($var:tt)*): ($($t:tt),*), $($rest:tt)*)=>{input!(($($var)*): ($($t),*));input!($($rest)*);};
    (($($var:tt)*): ($($t:tt),*))=>{let ($($var)*) = __input_inner!(($($t),*));};
}
macro_rules! __input_inner {
    (($($t:tt),*))=>{($(__input_inner!($t)),*)};
    ([$t:tt; $n:expr])=>{(0..$n).map(|_| __input_inner!($t)).collect::<Vec<_>>()};
    ([$t:tt; $padd:expr; $n:expr])=>{{
        let mut tmp = Vec::with_capacity(($padd)+($n));
        tmp.resize_with(($padd), Default::default);
        tmp.resize_with(($padd)+($n), || __input_inner!($t)); tmp
    }};
    (chars)=>{__input_inner!(String).chars().collect::<Vec<_>>()};
    (vytes)=>{__input_inner!(String).bytes().collect::<Vec<_>>()};
    (bytes)=>{__input_inner!(String).into_bytes()};
    (usize_1)=>{__input_inner!(usize)-1};
    ($t:ty)=>{in__().scan::<$t>()};
}
macro_rules! u8 {($n:expr)=>(($n) as u8)}
macro_rules! u16 {($n:expr)=>(($n) as u16)}
macro_rules! u32 {($n:expr)=>(($n) as u32)}
macro_rules! u64 {($n:expr)=>(($n) as u64)}
macro_rules! u128 {($n:expr)=>(($n) as u128)}
macro_rules! usize {($n:expr)=>(($n) as usize)}
macro_rules! i8 {($n:expr)=>(($n) as i8)}
macro_rules! i16 {($n:expr)=>(($n) as i16)}
macro_rules! i32 {($n:expr)=>(($n) as i32)}
macro_rules! i64 {($n:expr)=>(($n) as i64)}
macro_rules! i128 {($n:expr)=>(($n) as i128)}
macro_rules! isize {($n:expr)=>(($n) as isize)}
macro_rules! char {($n:expr)=>(($n) as char)}
macro_rules! bool {($n:expr)=>(($n) as bool)}
macro_rules! flush {()=>(out().flush().unwrap())}
macro_rules! print {($($fmt:tt)*)=>(write!(out(),$($fmt)*))}
macro_rules! println {($($fmt:tt)*)=>(writeln!(out(),$($fmt)*))}
macro_rules! ternary {($cdt:expr;$true:expr;$false:expr)=>(if$cdt{$true}else{$false})}
macro_rules! testcase {($n:expr)=>(for _ in 0..ternary!(($n)!=0;($n);in__().scan()){solve();}flush!())}
 
fn main() { testcase!(0); }
fn solve() {
    
}


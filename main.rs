#![allow(dead_code, unused)]

use std::io::*;
use std::mem::swap;
use std::cmp::{min, max};
use std::{isize, usize};
use std::collections::*;
type Queue<T> = LinkedList<T>;
 
fn scan<T: std::str::FromStr>()->T {
    static mut BUF: Vec<String> = vec![];
    loop {
        if let Some(token) = unsafe {BUF.pop()} {
            return token.parse().ok().expect("Failed to parse.");
        }
        let mut line = String::new();
        std::io::stdin().read_line(&mut line).ok().expect("Failed to read.");
        unsafe { BUF = line.split_whitespace().rev().map(String::from).collect(); }
    }
}
fn bufw()->&'static mut BufWriter<Stdout> { // '
    static mut WR: Option<BufWriter<Stdout>> = None;
    unsafe {
        if let None = WR { WR = Some(BufWriter::new(stdout())); }
        return WR.as_mut().unwrap();
    }
}
macro_rules! print {($($fmt:tt)*)=>(write!(bufw(),$($fmt)*))}
macro_rules! println {($($fmt:tt)*)=>(writeln!(bufw(),$($fmt)*))}
macro_rules! ternary {($cdt:expr;$true:expr;$false:expr)=>(if$cdt{$true}else{$false})}
macro_rules! testcase {($n:expr)=>(for _ in 0..ternary!(($n)!=0;($n);scan()){solve();}bufw().flush().unwrap())}

fn main() { testcase!(0); }
fn solve() {
    
}


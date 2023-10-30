
use std::io::{stdin, Read};
fn main() {
    let mut input = String::new();
    stdin().read_to_string(&mut input).unwrap();
    let mut input = input.split_ascii_whitespace().flat_map(str::parse::<u32>);

    let mut h = input.next().unwrap();
    let m = input.next().unwrap();
    let am = input.next().unwrap();
    let m = m + am; 

    if(m >= 60) {
        h += m / 60;
    }
    let h = h % 24;
    let m = m % 60;


    println!("{h} {m}");
}

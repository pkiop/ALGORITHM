use std::io::{stdin, Read};
fn main() {
    let mut input = String::new();
    stdin().read_to_string(&mut input).unwrap();
    let mut input = input.split_ascii_whitespace().flat_map(str::parse::<u32>);

    let a = input.next().unwrap();
    let b = input.next().unwrap();
    let c = input.next().unwrap();

    let mut ans = 0;
    if a == b && a == c {
        ans = 10000 + a * 1000;
    } else if a == b {
        ans = 1000 + a * 100;
    } else if a == c {
        ans = 1000 + a * 100;
    } else if b == c {
        ans = 1000 + b * 100;
    } else {
        ans = std::cmp::max(std::cmp::max(a, b), c) * 100;
    }

    println!("{ans}");
}
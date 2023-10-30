// b25304
use std::io::{stdin, Read};
fn main() {
    let mut input = String::new();
    stdin().read_to_string(&mut input).unwrap();
    let mut input = input.split_ascii_whitespace().flat_map(str::parse::<i32>);

    let mut x = input.next().unwrap();
    let n = input.next().unwrap();
    
    for _i in 0..n {
        let a = input.next().unwrap();
        let b = input.next().unwrap();
        x -= a * b;
    }

    if x == 0 {
        println!("Yes")
    } else {
        println!("No")
    }

    
}

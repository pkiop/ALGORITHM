// b25314
use std::io::{stdin, Read};
fn main() {
    let mut input = String::new();
    stdin().read_to_string(&mut input).unwrap();
    let mut input = input.split_ascii_whitespace().flat_map(str::parse::<i32>);

    let x = input.next().unwrap();
    let mut x = x / 4;


    let mut res = String::new();
    while x != 0 {
        x -= 1;
        res.push_str("long ");
    }
    res.push_str("int");
    println!("{res}");
  
    
}

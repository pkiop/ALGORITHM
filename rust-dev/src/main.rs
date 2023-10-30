// b10807
use std::io::{stdin, Read};
fn main() {
    let mut input = String::new();
    stdin().read_to_string(&mut input).unwrap();
    let mut input = input.split_ascii_whitespace().flat_map(str::parse::<i8>);

    let n: usize = input.next().unwrap() as usize;
    let mut arr = vec![0; n];
    for i in 0..n {
        let t = input.next().unwrap();
        arr[i] = t;
    }
    let v = input.next().unwrap();
    let mut cnt = 0;
    for x in arr {
        if x == v {
            cnt += 1;
        }
    }
    println!("{cnt}");
  
    
}

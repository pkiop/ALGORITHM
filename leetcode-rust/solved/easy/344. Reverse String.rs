pub fn reverse_string(s: &mut Vec<char>) {
    let l = s.len();
    for v in 0..l / 2 {
        let temp_char = s[l - v - 1];
        s[l - v - 1] = s[v];
        s[v] = temp_char;
    }
}
fn main() {
    println!("Hello, world!");
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_reverse_str() {
        let mut vec = vec!['h', 'e', 'l', 'l', 'o'];
        reverse_string(&mut vec);
        assert_eq!(vec, vec!['o', 'l', 'l', 'e', 'h']);
    }
}

pub fn is_palindrome(x: i32) -> bool {
    let str_x = x.to_string();
    let lenx: i32 = (str_x.len()) as i32;
    for c in 0..(lenx / 2) {
        let bytes_str_x = str_x.as_bytes();
        if bytes_str_x[c as usize] != bytes_str_x[(lenx - 1 - c) as usize] {
            return false;
        }
    }
    true
}

fn main() {
    println!("Hello, world!");
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_is_palindrome() {
        assert_eq!(is_palindrome(121), true);
        assert_eq!(is_palindrome(-121), false);
        assert_eq!(is_palindrome(10), false);
        assert_eq!(is_palindrome(1112222111), true);
        assert_eq!(is_palindrome(1112222112), false);
    }
}

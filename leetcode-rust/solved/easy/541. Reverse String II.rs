pub fn reverse_str(s: String, k: i32) -> String {
    let mut new_str = String::new();
    let str_chars: Vec<char> = s.chars().collect();
    let mut current_idx: i32 = 0;
    let mut is_reverse = true;
    while current_idx < s.len() as i32 {
        if is_reverse == true && current_idx + k - 1 < s.len() as i32 {
            let current_idx_add_k = current_idx + k - 1;
            for i in 0..k {
                new_str.push(str_chars[(current_idx_add_k - i) as usize]);
                current_idx += 1;
                if current_idx == s.len() as i32 {
                    break;
                }
            }
        } else if is_reverse == true {
            for i in 0..s.len() {
                new_str.push(str_chars[(s.len() - i - 1) as usize]);
                current_idx += 1;
                if current_idx == s.len() as i32 {
                    break;
                }
            }
            break;
        } else {
            for i in 0..k {
                new_str.push(str_chars[current_idx as usize]);
                current_idx += 1;
                if current_idx == s.len() as i32 {
                    break;
                }
            }
        }
        is_reverse = !is_reverse;
    }

    new_str
}

fn main() {
    println!("Hello, world!");
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_reverse_str() {
        assert_eq!(reverse_str("abcdefg".to_string(), 2), "bacdfeg".to_string());
        assert_eq!(reverse_str("abcd".to_string(), 2), "bacd".to_string());
        assert_eq!(
            reverse_str("abcdabcdabcd".to_string(), 2),
            "bacdbacdbacd".to_string()
        );

        assert_eq!(reverse_str("abcd".to_string(), 4), "dcba".to_string());
        assert_eq!(reverse_str("abcdefg".to_string(), 8), "gfedcba".to_string());
    }
}

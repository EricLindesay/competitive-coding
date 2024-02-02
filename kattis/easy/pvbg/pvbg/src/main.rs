use std::cmp;
use std::io;

fn main() {
    let mut input_line = String::new();
    io::stdin()
        .read_line(&mut input_line)
        .expect("Failed to read line");
    let x: i32 = input_line.trim().parse().expect("Input not an integer");

    let mut nums_string: String = String::new();
    io::stdin()
        .read_line(&mut nums_string)
        .expect("Failed to read line");

    let mut ans = i32::MAX;
    for word in nums_string.split(" ") {
        let x: i32 = word.trim().parse().expect("Input not an integer");
        ans = cmp::min(x, ans);
    }

    ans += 1;
    println!("{ans}");
}

use std::cmp::max;
use std::io;

fn main() {
    let mut input = String::new();
    io::stdin()
        .read_line(&mut input)
        .expect("Failed to read line");

    // Parses a single integer
    let nums: Vec<i32> = input.trim().split(" ").map(|x| x.parse().unwrap()).collect::<Vec<_>>();

    println!("{}", max(nums[1]-nums[0], nums[2]-nums[1]) - 1);
}

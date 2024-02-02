use std::collections::HashMap;
use std::io;

fn main() {
    let mut input = String::new();
    io::stdin()
        .read_line(&mut input)
        .expect("Failed to read line");

    // Parses a single integer
    let nums: Vec<i32> = input.trim().split(" ").map(|x| x.parse().unwrap()).collect::<Vec<_>>();

    let mut a: HashMap<i32, i32> = HashMap::new();
    for i in 1..=nums[0] {
        for j in 1..=nums[1] {
            a.entry(i+j).and_modify(|f| *f += 1).or_insert(1);
        }
    }

    let mut max_v = 0;
    let mut vs: Vec<i32> = Vec::new();
    for (k, v) in a {
        if v > max_v {
            max_v = v;
            vs.clear();
            vs.push(k);
        } else if v == max_v {
            vs.push(k);
        }
    }
    vs.sort_unstable();
    for v in vs {
        println!("{v}");
    }
}

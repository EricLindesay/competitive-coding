use std::io;

fn main() {
    let mut input = String::new();
    io::stdin()
        .read_line(&mut input)
        .expect("Failed to read line");

    // Parses a single integer
    let nums = input.trim().split(" ").map(|x| x.parse().unwrap()).collect::<Vec<i32>>();

    let N = nums[0];
    let T = nums[1];

    let mut info: Vec<(i32, i32)> = Vec::new();
    for i in 0..N {
        input.clear();
        io::stdin()
            .read_line(&mut input)
            .expect("Failed to read line");
    
        nums.clear();
        nums = input.trim().split(" ").map(|x| x.parse().unwrap()).collect::<Vec<i32>>();
        let c = nums[0];
        let t = nums[1];

        info.push((t, c));
    }

    info.sort_unstable();

    let mut c_t = 0;
    for i in 0..N {
        if info[i as usize][1] > c_t {
            continue;
        }
    }
}

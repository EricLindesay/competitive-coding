use std::io;

fn main() {
    let mut input = String::new();
    io::stdin()
        .read_line(&mut input)
        .expect("Failed to read line");

    // Parses a single integer
    let nums = input.trim().split(" ").map(|x| x.parse().unwrap()).collect::<Vec<f64>>();

    let h = nums[0];
    let v = nums[1];

    if v >= 0.0 && v <= 180.0 {
        println!("safe");
    } else {
        let time = (h as f64) / (v as f64).to_radians().cos(); 
        println!("{}", f64::floor(time));
    }

}

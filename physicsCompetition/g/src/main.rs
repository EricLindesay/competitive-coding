use std::io;

fn main() {
    let mut input = String::new();
    io::stdin()
        .read_line(&mut input)
        .expect("Failed to read line");

    let top_line = input.trim().split(" ").map(|x| x.parse().unwrap()).collect::<Vec<f64>>();

    input.clear();
    io::stdin()
        .read_line(&mut input)
        .expect("Failed to read line");
    let bottom_line = input.trim().split(" ").map(|x| x.parse().unwrap()).collect::<Vec<f64>>();

    // PI * 2r  / angle
    // angle = 180/M

    // Go down if you can/need, if you can't then go around
    // then go up
}

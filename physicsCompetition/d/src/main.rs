use std::io;

fn main() {
    let mut input = String::new();
    io::stdin()
        .read_line(&mut input)
        .expect("Failed to read line");

    // Parses a single integer
    let nums: i32 = input.trim().parse().unwrap();

    input.clear();
    io::stdin()
        .read_line(&mut input)
        .expect("Failed to read line");

    let words = input.trim().split(" ").collect::<Vec<_>>();

    let mut count = 0;
    let mut invalid = false;
    for word in words {
        count += 1;
        match word.parse::<i32>() {
            Ok(num) => { 
                if count != num { invalid = true; break; } 
            },
            Err(_) => {},  // they do be mumbling
        }
    }

    if !invalid && count == nums {
        println!("makes sense")
    } else {
        println!("something is fishy")
    }
}

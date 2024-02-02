use std::collections::HashMap;
use std::io;
use std::cmp::max;
use std::cmp::min;

fn main() {
    let mut input = String::new();

    // Map which maps special values (21 and 11,22,33...) to other values. Lower = better
    let mut map = HashMap::new();
    map.insert(21, 0);
    for x in 1..=6 {
        map.insert(x*11, 7 - x);
    }

    loop {
        // Read in the line
        input.clear();
        io::stdin()
            .read_line(&mut input)
            .expect("Failed to read line");

        // Split the line into 4 integers
        let line = input.trim().split(" ")
                                .into_iter()
                                .map(|s| s.parse().unwrap())
                                .collect::<Vec<i32>>();
        
        // If they are all zero, its the end of input
        if line[0] == 0 && line[1] == 0 && line[2] == 0 && line[3] == 0 {
            break;
        }

        // The player's score is the max*10 + min. (Put the two numbers together, making the number as high as possible)
        let scores = vec![max(line[0], line[1])*10 + min(line[0], line[1]), max(line[2], line[3])*10 + min(line[2], line[3])];

        // Convert the special scores into their proper values
        // For other scores, they are 100 - value.
        let converted_scores = scores.iter().map(|&x| map.get(&x).cloned().unwrap_or(100 - x)).collect::<Vec<_>>();

        // Lower is better
        if converted_scores[0] < converted_scores[1] {
            println!("Player 1 wins.");
        } else if converted_scores[0] > converted_scores[1] {
            println!("Player 2 wins.");
        } else {
            println!("Tie.");
        }
    }
}

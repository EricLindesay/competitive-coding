use std::io;
use std::collections::HashSet;

fn main() {
    let alphabet = (b'a'..=b'z').collect::<HashSet<_>>();

    let mut input = String::new();
    io::stdin()
        .read_line(&mut input)
        .expect("Failed to read line");
    let lines: i32 = input.trim().parse().expect("Input not an integer");

    for i in 0..lines {
        input.clear();
        io::stdin()
            .read_line(&mut input)
            .expect("Failed to read line");

        // Get every character, if its alphabetic, convert it to lowercase then convert into a hashset
        let chars = input.bytes()
                        .filter(u8::is_ascii_alphabetic)
                        .map(|mut x| {x.make_ascii_lowercase(); x})
                        .collect::<HashSet<_>>();

        let mut diff = alphabet.difference(&chars).collect::<Vec<_>>();
        diff.sort_unstable();
        
        println!("");
        if diff.is_empty() {
            println!("pangram");
        } else {
            println!("missing {}", diff.into_iter().map(|&x| x as char).collect::<String>());
        }
    }
}

use std::io;
use std::collections::HashSet;

fn main() {
    let mut input = String::new();
    io::stdin()
        .read_line(&mut input)
        .expect("Failed to read line");
    let n_lines: i32 = input.trim().parse().expect("Input not an integer");
    
    let mut keywords: HashSet<String> = HashSet::new();
    for _ in 0..n_lines {
        input.clear();
        io::stdin()
            .read_line(&mut input)
            .expect("Failed to read line");

        let converted_string = input.bytes().map(|mut x| {
            x.make_ascii_lowercase();
            if x == b'-' {
                x = b' ';
            }
            x as char
        }).collect::<String>();

        keywords.insert(converted_string);
    }

    // let a = keywords.into_iter().collect::<Vec<_>>();
    // a.join(" ");
    println!("{}", keywords.len());
}

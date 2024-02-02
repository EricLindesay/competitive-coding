use std::io;

fn main() {
    let mut input = String::new();
    io::stdin()
        .read_line(&mut input)
        .expect("Failed to read line");

    let n_input: i32 = input.trim().parse().unwrap();
    
    let mut best_name: String = String::new();  // the pub name
    let mut best_time: i32 = 0;  // the total waiting time
    for _ in 0..n_input {
        input.clear();
        io::stdin()
            .read_line(&mut input)
            .expect("Failed to read line");
        
        let a: Vec<&str> = input.trim().split(" ").into_iter().collect::<Vec<_>>();
        let name = a[0];
        let mut people: i32 = a[1].parse().unwrap();
        people += 1;
        let time: i32 = a[2].parse().unwrap();

        if time * people > best_time {
            best_name = name.to_string();
            best_time = time * people;
        }
    }

    println!("{best_name} {best_time}");
}

use std::io;

fn main() {
    let mut lines = String::new();
    io::stdin()
        .read_line(&mut lines)
        .expect("Failed to read line");
    let n_lines = lines.trim().split(" ").map(|x| x.parse().unwrap()).collect::<Vec<i32>>();

    let mut potions: Vec<i32> = Vec::new();
    
    for i in 0..n_lines[0] {
        lines.clear();
        io::stdin()
            .read_line(&mut lines)
            .expect("Failed to read line");
        potions.push(lines.trim().parse().unwrap());
    }    
    potions.sort_unstable();
    potions.reverse();

    let mut possible = true;

    for i in 0..n_lines[0]-1 {
        let max_potions_after = n_lines[0] - i - 1;
        if potions[i as usize] <= max_potions_after * n_lines[1] {
            possible = false;
            break;
        }
    }
    if possible {
        println!("YES");
    } else {
        println!("NO");
    }
}

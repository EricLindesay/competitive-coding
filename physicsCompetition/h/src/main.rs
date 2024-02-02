use std::io;

fn main() {
    let mut encrypted = String::new();
    let mut cipher = String::new();
    io::stdin()
        .read_line(&mut encrypted)
        .expect("Failed to read line");
    io::stdin()
        .read_line(&mut cipher)
        .expect("Failed to read line");

    let e_conv = encrypted.trim().bytes().map(|x| x - b'A').collect::<Vec<_>>();
    let c_conv = cipher.trim().bytes().map(|x| x - b'A').collect::<Vec<_>>();

    let mut out = String::new();
    for i in 0..e_conv.len() { 
        let x = e_conv[i];
        let y = c_conv[i];
        if i%2 == 0 {
            if x >= y {
                let a = b'A' + (x - y)%26;
                out.push(a as char);
                // println!("- {}", a as char);
            } else {
                let a = b'Z' - (y - x);
                out.push(a as char);
                // println!("- {}", a as char);
            }
        } else {
            let a = b'A' + (x + y)%26;
            out.push(a as char);
            // println!("{}", a as char);
        }
    }

    println!("{out}");
}

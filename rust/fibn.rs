/**
 * Program to get the nth fibonacci number
 */

fn main() {
    let mut f0 = -1;
    let mut f1 = 1;
    let mut f_n = 0;
    let n = 10;
    for _ in 0..n {
        f_n = f0 + f1;
        f0 = f1;
        f1 = f_n;
    }
    println!("The {n} th fibonacci number is {f_n}");
}

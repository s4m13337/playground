/*
 * Expressions vs Statements
 * A statement ends with ; and returns nothing
 * An expression does not end with ; and returns a value
 */

fn main() {
    println!("Main function!");
    external_function();
    let x: i32 = 43;
    let y = add_two(x);
    println!("The result is {y}");
    let z = plus_one(72);
    println!("The result of adding one is {z}");
}

fn external_function() {
    println!("External function");
}

fn plus_one(n: i32) -> i32 {
    n + 1
}

fn add_two(n: i32) -> i32 {
    n + 2
}

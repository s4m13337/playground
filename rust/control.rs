/*
 * Control flows in rust
 */

fn main() {
    let number = 7;

    // if ... else
    // The condition must always be boolean
    if number < 5 {
        println!("number is less than 5");
    } else {
        println!("number is greater than 5");
    }

    // handling multiple conditions with if ... else if ... else
    let number = 6;
    if number % 2 == 0 {
        println!("number is divisible by 2");
    } else if number % 3 == 0 {
        println!("number is divisible by 3");
    } else if number % 4 == 0 {
        println!("number is divisible by 4");
    } else {
        println!("number is not divisible by 2, 3, or 4");
    }

    // Using if in a let statement
    let condition = true;
    let number = if condition { 5 } else { 6 };
    println!("The number is {number}");
    // This is possible because if ... else if ... else is an expression (notice the blocks don't have ; at the end)
    // Pitfall: The RHS of let statement has to be an expression, but entire assignment is still a statement and therefore must end with a ;
    // Blocks always evaluate to that last expression in them
    // !!Important: Values resulting from each branch must be of the same type!

    // Repetition with loops
    // Rust has 3 kinds of loops: loop, while & for

    // loop
    let mut count = 0;
    loop {
        println!("Hello, {count}");
        count += 1;
        if count > 10 {
            break;
        }
    }
    // loop labels: when nested loops are used, break and continue statements apply only to the innermost loop
    // An optional loop label can be prefixed to loop and it can be passed to break/continue statements
    // loop labels begin with single quote, e.g. 'conuting up: loop ...

    // while
    let mut number = 3;
    while number != 0 {
        number -= 1;
        println!("Hello from while");
    }

    // for --- used for looping through a collection of items
    let a = [10, 20, 30, 40, 50];
    for element in a {
        println!("the value is {element}");
    }

    for number in (1..4).rev() {
        println!("{number}");
    }
}

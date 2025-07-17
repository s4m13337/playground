fn main() {
    let s1 = String::from("hello");
    let len = calculate_length(&s1); // Reference to s1 is passed
    println!("The length of '{s1}' is {len}");

    let mut s2 = String::from("ahoy");
    hello(&mut s2);
    println!("'{s2}'");
}

fn calculate_length(s: &String) -> usize {
    // Argument is of type reference to String
    s.len()
}

/**
 * Passing by reference is called borrowing
 * Borrowed variables cannot be modified
 * To modify borrowed variables, they need to be passed through mutable references.
 */

fn hello(s: &mut String) {
    s.push_str(", world");
}

/**
 * Restriction on a mutable reference: There can only to one mutable reference to a variable at a time
 * This is understandable because if multiple mutable references are allowed, it is harder to synchronize changes and can cause curroption. (a.k.a data race conditions)
 * let mut s = String::from("hello");
 * let r1 = &mut s;
 * let r2 = &mut s; --- This is not allowed. Only one reference can be present at a time.
 * A workaround is to create new scopes and create new references inside
 * Additionally, a variable cannot be borrowed as mutable reference and immutable reference at the same time.
 * Multiple immutable references are permitted since they don't alter the data
 */
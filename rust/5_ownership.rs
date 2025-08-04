/**
 * Ownership
 * - Ownership feature in rust is used manage heap data
 * - One does not need to think much about the stack and heap after understanding ownerships
 *
 * Rules
 * - Each value in rust has an owner
 * - There can be only one owner at a time
 * - When the owner goes out of scope, the value is dropped
 */

fn main() {
    {
        let mut s = String::from("hello"); // s is valid from this point; s owns the memory
        s.push_str(", world!");
        println!("{s}");
    } // once the scope ends, s is no longer valid and the ownership is dropped

    {
        let x = 5;
        let y = x; // This works by duplicating variables as they are of fixed known size and they get pushed into the stack
        println!("x is {x}, y is {y}");

        let s1 = String::from("hello");
        let s2 = s1;
        // String data consists of a ptr, len & capacity. The above statement copies the string data, but the actual data to which the string points is not copied.
        // Only the pointer is copied. Both s1 and s2 point to the same memory location.
        // This is a problem when s1 and s2 try to go out of scope, they try to free the same memory (double free error)
        // To prevent this error, when s1 is assigned to s2, the ownership is also transferred to s2 and s1 no longer owns the memory. We say s1 is moved to s2.
        // Rust considers s1 as no longer valid and does not need to free it when it goes out of scope.
        // Trying to access s1 after the move, will result in a borrow error.
        println!("{s2}");

        let mut s = String::from("hello");
        s = String::from("ahoy!");
        println!("{s}, world");
    }

    /**
     * Variables bound to memory on heap go out of scope when then are passed into functions
     * Variables on stack don't because they have the Copy trait implemented.
     * ! Anything that requires memory allocation, cannot implement a Copy trait.
     * Any value returned from a function is owned by the variable to which it is bound
     * 
     * Passing a variable whose data is on the heap to a function, transfers ownership to the function
     * However, often we require the variable on the calling function later on. It is tedious to transfer ownerships frequently and is error prone too.
     * This issue is fixed by using references (similar to passing by reference in C) 
     */
}

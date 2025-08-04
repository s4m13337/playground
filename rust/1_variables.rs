fn main() {
    /*
     * variables are immutable by default
     * trying to change the value of a variable throws error at compile time
     * add the keyworkd mut if you plan to change the value in future
     * In rust, we say that value is bound to a varaible name instead of being assigned as in case of C
     */
    let mut x = 5;
    println!("The value of x is: {x}");
    x = 6;
    println!("The value of x is: {x}");

    /*
     * constants are immutable and can never be made mutable
     * they must be always type annotated!
     */
    const THREE_HOURS_IN_SECONDS: u32 = 60 * 60 * 3;
    println!("Three hours in seconds is {THREE_HOURS_IN_SECONDS}");

    /*
     * when a variable of an existing name is created, the existing one gets shadowed
     * It remains shadowed until it goes out of scope or if it shadowed by another
     */
    let y = 5;
    let y = y + 1;

    {
        let y = y + 2;
        println!("The value of y is {y}");
    }
    println!("The value of y is {y}");

    /*
     * one difference between mutable variables and shadowed variables is that the type can be altered in latter case
     */
    let spaces = "     ";
    let spaces = spaces.len();
    println!("The number of spaces is {spaces}");
}

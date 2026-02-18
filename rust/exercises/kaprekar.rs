/*
The number 3025 has a property that when we square the addition of the first half of the number and the next half of the number, the result will be the same number. That is, square of (30 + 25) is 3025.
*/

fn main() {
    println!("Printing All kaprekar numbers from 1000 to 9999");
    for number in 1000..9999 {
        let first_half: usize = number / 100;
        let second_half: usize = number % 100;
        let kaprekar: usize = (first_half + second_half).pow(2);
        if number == kaprekar {
            println!("{number}");
        }
    }
}
/*
An Adam number is one which satisfies the following: 
The reverse of the square of a number is the square of the reverse of that number.
That is, if the number is 12 then 12^2 = 144, the reverse is 441 which is 21^2.
*/

fn reverse(n: usize) -> usize {
    // This idea for this approach is to repeatedly extract the last digit of n using 
    // the modulus operator (n % 10) and appending it to the reverse number (revNum). 
    // After extracting the digit, the number n is reduced by dividing it by 10 (n = n / 10). 
    // This process continues until n becomes 0. Finally, the reversed number (revNum) 
    // is returned.
    let mut r: usize;
    let mut num: usize = n;
    let mut rev_num: usize= 0;
    while num != 0 {
        r = num % 10;
        rev_num = (rev_num * 10) + r;
        num = num / 10;
    }
    rev_num
}

fn main() {
    println!("Printing all Adam numbers between 10 to 100");
    for i in 10..100 {
        let num: usize = i;
        let num_square: usize = num.pow(2);
        let num_square_reverse: usize = reverse(num_square);
        let num_reverse: usize = reverse(num);
        let num_reverse_square: usize = num_reverse.pow(2);
        if num_square_reverse == num_reverse_square {
            println!("{num}");
        }
    }
}
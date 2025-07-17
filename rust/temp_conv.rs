/**
 * Program to convert temperature from celcius to farenheit & vice-versa
 */

fn main() {
    let temp_c: f32 = 37.0;
    let temp_f: f32 = (temp_c * 9.0 / 5.0) + 32.0;
    println!("{temp_c} degree celcius is {temp_f} degree farenheit");
}

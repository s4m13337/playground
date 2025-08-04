/*
 * in rust there are two datatype subsets: scalar and compound
 * rust is statically typed, so it needs to know the datatype of all variables at compile time
 * while it can infer the type in most cases based on the value, it is a better practice to type annotate
 * 
 * There are two primary datatype subsets: scaler and compound
 * There are are 4 scalar types
 * - integer
 * - float
 * - boolean
 * - character
 * 
 * Integer
 * Length       Signed      Unsigned
 * 8-bit        i8          u8
 * 16-bit       i16         u16
 * 32-bit       i32         u32
 * 64-bit       i64         u64
 * 128-bit      i128        u128
 * arch         isize       usize
 * 
 * Integer literals
 * Decimal      98_222
 * Hex          0xff
 * Octal        0o77
 * Binary       0b1111_0000
 * Byte         b'A' (only u8 is supported)
 * 
 * Float
 * two types: f32, f64
 * both are signed types
 * default is f64 since on modern cpus speed difference is not much noticeable and 64bits have more precision
 * 
 * Boolean
 * bool can be either true or false
 * 
 * Character
 * char are written inside single quotes
 * rust char takes up 4 bytes. 
 * 
 * Compound types
 * - tuples
 * - arrays
 * 
 * Tuples
 * combination of elemets of different datatypes
 * enclosed in (...)
 * elements are accessed either by pattern matching or indexing through . operator
 * 
 * Arrays
 * similar to arrays in C. 
 * when declaring type, the form [type; length] is used
 * there is also a shorthand to create repeating elements, e.g [3; 5] will create the array [3, 3, 3, 3, 3]
 */

 fn main(){
    let x = 2.0; // f64 by default
    let y: f32 = 3.14;

    println!("The value of x is {x}");
    println!("The value of y is {y}");

    let a: (u32, f32, char) = (23, 43.1, 'm');
    let b1 = a.0;
    let b2 = a.1;
    let b3 = a.2;
    println!("The tupple content is {b1}, {b2}, {b3}");
 }
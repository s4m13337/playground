/*
    Rust has two kinds of erros: recoverable & unrecoverable errors
    Unrecoverable erros are handled using the panic! macro and
    the program is prevented from further executing.
    e.g. Accessing an array index that does not exist is an unrecoverable error.

    Recoverable errors are handled using the Result<T, E> enum. 
    The Result<T, E> enum is defined as
    
    enum Result<T, E>{
        Ok(T),
        Err(E)
    }
    T, E are generics (To be reviewed later...)
    Ok and Err are variants
    T is the type of value that will be returned in case of success within Ok variant
    E is the type of error that will be returned in case of failuer within Err variant
*/

use::std::fs::File;

fn main(){
    // panic!("crash and burn!");
    // let v = vec![1, 2, 3];
    // v[99]; // Accessing an index that does not exist causes panic

    let test_file_result = File::open("test.txt");

    let test_file = match test_file_result {
        Ok(file) => file,
        Err(error) => panic!("Error opening file: {error:?}")
    };
}

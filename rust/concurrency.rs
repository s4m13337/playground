use std::thread;
use std::time::Duration;

fn main() { 
    /*
        The return type of a spawned thread is JoinHandle<T>
    */
    let handle = thread::spawn(|| {
        for i in 1..10 {
            println!("hi! iteration {i} from spawned thread");
            thread::sleep(Duration::from_millis(1));
        }
    });

    /*
        The main thread runs upto i = 4 after which it ends
        This causes the other spawned threads to terminate prematurely
    */
    for i in 1..5 { 
        println!("hi! iteration {i} from main thread");
        thread::sleep(Duration::from_millis(1));
    }

    // This blocks further execution of the main thread until handle is returned
    handle.join().unwrap();

    /*
        passing values from main thread to spawned thread
    */
    let v = vec![1, 2, 3];
    let handle = thread::spawn(move || {
        /* 
            References passed from main thread are not guaranteed.
            Therefore the ownership is moved to the spawned thread.
        */
        println!("Here's a vector {v:?}");
    });

    handle.join().unwrap();
}
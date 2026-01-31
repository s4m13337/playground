/*
    mpsc - Multiple Producer, Single Consumer
    A channel in Rust can have multiple producing ends but only single consuming end
*/
use std::sync::mpsc;
use std::thread;
use std::time::Duration;

fn main() {
    /*
        mpsc::channel returns a tuple
        The first element is the transmitter and second element is the receiver
    */
    let (tx, rx) = mpsc::channel(); 
    // Another producer
    let tx1 = tx.clone();

    /*
        The transmitter is moved to the spawend thread
        The spawned thread must own the transmitter in order to send messages through it
    */
    thread::spawn(move || {
        //let val = String::from("hi!");
        //let val: isize = 43;
        let vals = vec![
            String::from("hello"),
            String::from("from"),
            String::from("the"),
            String::from("thread")
        ];
        //tx.send(val).unwrap(); // What exactly does unwrap do here?
        /*
            The send method returns a Result<T, E> type
            If receiver is dropped, there's nowhere to send so it returns error
            unwrap panics in case of an error. Revist chapter 9 for proper error handling

            The send function transfer the ownership of val if val does not implement the Copy trait
        */

        //println!("val is {val}");
    
        for val in vals {
            tx.send(val).unwrap();
            thread::sleep(Duration::from_secs(1));
        }
    });

    thread::spawn(move || {
        let vals = vec![
            String::from("more"),
            String::from("messages"),
            String::from("for"),
            String::from("you"),
        ];

        for val in vals {
            tx1.send(val).unwrap();
            thread::sleep(Duration::from_secs(1));
        }
    });

    /*
        Receive the message in main thread
        This also returns Result<T, E>
        When transmitter closes, it returns an Error
        recv blocks the main thread until message is arrived
        try_recv is non-blocking that can be used to check and continue
    */
    //let received = rx.recv().unwrap();
    //println!("Got: {received}");

    for received in rx {
        println!("Got: {received}");
    }
}

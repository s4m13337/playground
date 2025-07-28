struct User {
    id: u32,
    username: String,
    email: String,
    active: bool
}

fn set_user(username: String, email: String) -> User {
    User{
        id: 1,
        username,
        email,
        active: true
    }
}

fn main(){
    /*
     * The entire struct must be mutable
     * It is not possible make part of struct mutable 
     */
    let user1 = User{
        id: 1,
        username: String::from("rippedraven8055"),
        email: String::from("rippedraven@email.com"),
        active: true
    };

    let user2 = User{
        id: 2,
        .. user1 // Takes rest of the values from this instance
    };
}
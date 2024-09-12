#include <iostream>
#include "User.h"

// TODO: Implement the non-member function + operator overload here!


void printFriends(const User& user) {
    std::cout << user.getName() << " is friends with: " << std::endl;
    for(auto& user : user.getFriends()) {
        std::cout << "  " << user.getName() << std::endl;
    }
}


User& operator+(User& user1, User& user2){
    user1.addFriends(user2.getName());
    user2.addFriends(user1.getName());
    return user1;
}


int main() {
    // create a bunch of users
    User alice("Alice");
    User bob("Bob");
    User charlie("Charlie");
    User dave("Dave");  
    // make them friends
    alice = alice + bob;
    alice = alice + charlie;

    dave = dave + bob;
    charlie = charlie + dave;


    // print out their friends
    printFriends(alice);
    printFriends(bob);
    printFriends(charlie);
    printFriends(dave);



    return 0;

}
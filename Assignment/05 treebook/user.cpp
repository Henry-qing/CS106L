#include "user.h"
#include <set>
#include <iostream>
#include <string>


// TODO: Implement the additional constructor here!
User::User(std::string name): name(name) {}

User::User(): name(""){}

User::~User(){}

User::User(const User& user){
    //私有成员不能直接访问
    this->name = user.getName();
    this->friends = user.getFriends();
}

User::User(User&& user) : name(std::move(user.name)),friends(std::move(user.friends)){}
// User& User::operator=(User&& user) {
//     if (this != &user) {
//         name = std::move(user.name);
//         friends = std::move(user.friends);
//     }
//     return *this;
// }
User& User::operator=(const User& user) {
    if (this != &user) {
        name = user.name;
        friends = user.friends;
    }
    return *this;
}
//以上均为special member functions
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
bool User::operator<(const User& a) const{
    return name < a.getName();
}
std::string User::getName() const {
    return name;
}

std::set<User> User::getFriends() const{
    return friends;
}

void User::setName(std::string name) {
    this->name = name;
}

// TODO: Implement the < operator overload here!
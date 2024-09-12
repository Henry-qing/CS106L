#include <set>
#include <string>

class User {
public:
    // TODO: write special member functions, including default constructor!
    User(std::string name);
    User();
    ~User();
    User(const User& user); //拷贝构造
    User(User&& user);
    //User& operator=(User&& user); //写不对= =
    User& operator=(const User& user); 
    // getter functions
    std::string getName() const;
    std::set<User> getFriends() const;
    // setter functions
    void setName(std::string name);

    // TODO: add the < operator overload here!
    bool operator<(const User& b) const;

    void addFriends(std::string name){
        this->friends.insert(name);
    }
private:
    std::string name;
    std::set<User> friends;

};
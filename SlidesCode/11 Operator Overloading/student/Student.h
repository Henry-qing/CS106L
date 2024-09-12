#include <iostream>
class Student{
private:
    std::string name;
    std::string state;
    int age;
public:
    Student(std::string name, std::string state, int age);
    Student();
    ~Student();
    std::string get_name();
    std::string get_state();
    bool operator<(const Student& rhs) const;
    bool operator>(const Student& lhs) const;
    int get_age();
    void set_name(std::string name);
    void set_state(std::string state);
    void set_age(int age);
};  
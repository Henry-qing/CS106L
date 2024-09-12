#include <iostream>
class Student{
public:
    using string = std::string;
    Student(string name, string state, int age);
    Student();
    ~Student();
    string get_name() const;
    string get_state();
    int get_age() const;
private:
    string name;
    string state;
    int age;
};
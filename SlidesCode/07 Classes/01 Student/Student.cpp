#include "Student.h"
#include <string>

//第一种初始化
// Student::Student(std::string name, std::string state, int age){
//     this->name = name;
//     this->state = state;
//     this->age = age;
// }
//列表初始化
Student::Student(std::string name, std::string state, int age): name{name}, state{state}, age{age} {}
Student::Student(): name{"Henry"}, state{"studying"}, age{20} {} //设置默认值
Student::~Student(){}
std::string Student::get_name() {return this-> name;}
std::string Student::get_state() {return this-> state;}
int Student::get_age() {return this->age;}
void Student::set_name(std::string name) {this->name = name;}
void Student::set_state(std::string state) {this->state = state;}
void Student::set_age(int age) {if(age >= 0) this->age = age;}

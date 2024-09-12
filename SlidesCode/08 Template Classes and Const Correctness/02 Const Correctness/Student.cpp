#include "Student.h"

Student::Student(string name,string state, int age): name{name}, state{state},age{age} {}
Student::~Student(){};
std::string Student::get_name() const{return this->name;}
std::string Student::get_state(){return this->state;}
int Student::get_age() const{return this->age;}

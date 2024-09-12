#include <iostream>
#include "Student.h"
#include <string>

std::string stringify(const Student& s){
    //不在声明的时候修改const类型会报错
    return s.get_name() + " is " + std::to_string(s.get_age()) + " years old.";
}


int main(){
    Student me("Henry","study",20);
    // std::cout << me.get_name() << '\n';
    std::cout << stringify(me) << '\n';
    
    return 0;
}


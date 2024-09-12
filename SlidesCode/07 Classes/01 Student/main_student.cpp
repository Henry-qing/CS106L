#include <iostream>
#include "Student.h"

int main(){
    Student me;
    Student you("张三", "吃饭", 12);
    std::cout << "我的名字是：" << me.get_name() << " 我正在" << me.get_state() << " 我今年" << me.get_age() << "岁了\n";
    return 0;
}
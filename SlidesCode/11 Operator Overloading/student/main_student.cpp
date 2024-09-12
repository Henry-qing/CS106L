#include <iostream>
#include "Student.h"

int main(){
    Student me;
    Student you("张三", "吃饭", 12);
    std::cout << "我的名字是：" << me.get_name() << " 我正在" << me.get_state() << " 我今年" << me.get_age() << "岁了\n";
    std::cout << "你的名字是：" << you.get_name() << " 你正在" << you.get_state() << " 你今年" << you.get_age() << "岁了\n";
    if(you < me){
        std::cout << "你的年龄比我小,重载的<运算符有效\n";
    }
    return 0;
}
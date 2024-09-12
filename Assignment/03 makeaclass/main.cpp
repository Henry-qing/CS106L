#include "class.h"

/*
 * Assigment 3: Make a class!
 * Requirements:
 * Must have a custom constructor ❌
 * Must have a default constructor ❌
    - i.e. constructor overloading
 * Must have private members (functions and/or variables) ❌
 * Must have public members (functions) ❌
 * Must have at least one getter function ❌
 * Must have at least one setter function ❌
 */

std::string stringify(const Lesson& s){
  std::string res = "这门课的名字是：" + s.get_name() + "，授课老师是:" + s.get_teacher();
  return res;
}

void print(const Lesson& s){
  std::cout << stringify(s) << '\n';
  std::cout << "这门课有" << s.get_credit_hours() << "学分" << ",我得了" << s.get_score() << "分\n";
}

int main() {
  // initialize class and run this file
  Lesson l1("数学分析","zs",90,3);
  // while(true){
  //   break;
  //   // char op;
  //   // std::cout << "请输入你的操作....." << '\n';
  //   // std::cin >> op;
  //   //if(op == ....)
  // }
  print(l1);
  return 0;
}
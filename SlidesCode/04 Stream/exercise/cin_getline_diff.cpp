#include <iostream>
#include <sstream>

int main(){
    std::string b;
    double a,c;
    //目标：输入 '3.14' 给 a 'Fabio Ibanez'给 b 2.5给c
    //错误写法1
    // std::cin >> a;
    // std::cin >> b;
    // std::cin >> c;
    //因为cin会在遇到'\n'时停止 cin默认在遇到 ' '停止 因此上述过程把Ibanez传给了c 发生错误

    //错误写法2
    // std::cin >> a;
    // std::getline(std::cin, b);
    // std::cin >> c;
    //cin遇到'\n'时停止 会在缓冲区留下 '\n' 而getline遇到'\n'停下 因此
    //此处getline相当于把''留给字符串b 然后初始化c的时候读入了Fabio故报错

    //正确写法
    std::cin >> a; //输入a
    std::getline(std::cin, b); //用于把缓冲器的'\n'读入后清空
    std::getline(std::cin, b); //用于输入带空格的字符串b
    std::cin >> c;
    //自己的思考：本质上错误写法2 是因为cin 会在缓冲区上留下'\n' 所以在cin后清空缓存区即可
    // std::cin >> a;
    // std::cin.ignore();//用于清空缓存区的内容；
    // std::getline(std::cin, b);
    // std::cin >> c;
    std::cout << a <<  " " << b << " " << c << '\n';
    return 0;
}   
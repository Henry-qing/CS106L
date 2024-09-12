#include <iostream>
#include "shape.h"

int main(){
    Circle O1(4);
    Rectangle R1(3,4);
    std::cout << "圆O1的面积是：" << O1.area() << '\n';
    std::cout << "长方形R1的面积是：" << R1.area() << '\n';
    return 0;
}
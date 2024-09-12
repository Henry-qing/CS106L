#include "Shape.h"

//写Circle的函数实现
Circle::Circle(double r): r(r) {}
Circle::~Circle(){}
double Circle::area() const {
    return 3.14 * r * r;
}
//写Rectangle
Rectangle::Rectangle(double a, double b): length{a}, width{b} {}
Rectangle::~Rectangle() {}
double Rectangle::area() const{return length * width;}
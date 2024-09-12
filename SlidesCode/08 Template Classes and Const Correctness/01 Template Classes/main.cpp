#include <iostream>
#include "class.cpp"

int main(){
    Circle<int> c(3);
    std::cout << c.get_area();
}

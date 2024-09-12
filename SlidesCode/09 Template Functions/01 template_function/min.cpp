#include <iostream>
template <typename Type>

Type min_1(Type a, Type b){
    return a < b ? a : b;
}

template<typename T, typename U>
auto min_2(T a, U b){
    return a < b ? a : b;
}


int main(){
    std::cout << min_2(3.2,4);
    //std::cout << "你好\n";
    return 0;
}
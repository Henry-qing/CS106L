#include <iostream>

int main(){
    int val = 18;
    int* ptr = &val;
    std::cout << "val = " << val << "\n";
    std::cout << "ptr = " << ptr << '\n';
    std::cout << "*ptr = " << *ptr << '\n';
    //指针ptr中如果有成员 first,second 访问有两种方式
    std::pair<int,int> p = {1,2};
    std::pair<int,int>* ptr_p = &p;
    //1
    std::cout << "p中第一个元素 = " << (*ptr_p).first << "\n";
    //2
    std::cout << "p中第二个元素 = " << ptr_p->second << '\n';
    return 0;
}

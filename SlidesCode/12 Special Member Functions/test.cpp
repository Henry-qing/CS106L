#include <iostream>
#include <cstring>

class MyString {
private:
    char* str;
    size_t length;

public:
    // 默认构造函数
    MyString() : str(nullptr), length(0) {}

    // 构造函数
    MyString(const char* s) : str(new char[strlen(s) + 1]), length(strlen(s)) {
        strcpy(str, s);
    }

    // 移动构造函数
    MyString(MyString&& other) noexcept : str(other.str), length(other.length) {
        other.str = nullptr;
        other.length = 0;
    }

    // 移动赋值运算符
    MyString& operator=(MyString&& other) noexcept {
        if (this != &other) {
            delete[] str;
            str = other.str;
            length = other.length;
            other.str = nullptr;
            other.length = 0;
        }
        return *this;
    }

    // 析构函数
    ~MyString() {
        delete[] str;
    }

    // 打印字符串
    void print() {
        std::cout << "String: " << str << std::endl;
    }
};

int main() {
    MyString str1("Hello");
    MyString str2 = std::move(str1); // 使用移动构造函数
    str2.print(); // 输出 "String: Hello"

    MyString str3;
    str3 = MyString("World"); // 使用移动赋值运算符
    str3.print(); // 输出 "String: World"

    str1.print();
    return 0;
}

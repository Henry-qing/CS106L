#include<iostream>
#include<vector>
using namespace std;

class stack{
private:
    vector<int> a;
public:
    stack() {}
    stack(int n) {
        init(n);
    }
    //初始化
    void init(int n){
        a.resize(n);
        for(int i = 0; i < n; i ++){
            int x;
            cin >> x;
            a.push_back(x);
        }
    }
    //元素入栈
    void push(int x){
        a.push_back(x);
    }
    //元素出栈
    void pop(){
        if(a.size() == 0){
            cout << "当前为空栈，无法执行出栈操作\n";
        }
        else{
            a.pop_back();
        }
    }
    //栈的大小
    int size(){
        return a.size();
    }
    //栈顶元素
    int top(){
        if(a.size() == 0){
            cout << "当前为空栈\n";
            return -1;
        }
        return a.back();
    }
    //栈底元素
    int bottom(){
        if(a.size() == 0){
            cout << "当前为空栈\n";
            return -1;
        }
        return a[0];
    }
    //判断栈是否为空
    bool empty(){
        return a.size() == 0 ? true : false;
    }
    
};

int main(){
    //首先要理解栈这个数据结构的特点：FILO : first in last out 即先进后出
    //这里我用类来写，不会类的话看看逻辑就可以;
    stack b;
    b.pop();
    b.push(3);
    b.push(4);
    int x = b.top();
    cout << x << '\n';
    b.pop();
    x = b.top();
    cout << x << '\n';
    b.pop();
    x = b.top();
    b.pop();
    return 0;
}
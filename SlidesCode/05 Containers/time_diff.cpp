#include<iostream>
#include<chrono> //添加chrono库函数用于计算程序运行时间
#include<map> //添加map容器
#include<unordered_map> //添加unorder_map容器
using namespace std;//使用命名空间std 

int main(){
    //比较操作次数较少的情况
    map<int,int> mp;
    unordered_map<int,int> ump;
    int n;
    cout << "输入0退出, 输入其他自然数进行询问\n";
    //ps：对于同样的n 访问的时间可能差别很大，存在随机性可以按照10 100 1000 ...进行询问
    //pps:数组里添加过多内容会爆内存,因此最多传入1e7的数据尝试即可;
    auto start = chrono::high_resolution_clock::now();
    auto end = chrono::high_resolution_clock::now();
    while(cin >> n && n){
        start = chrono::high_resolution_clock::now();
        for(int i = 0; i < n; i ++){
            mp[i] ++;
        }
        end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration1 = end - start;
        cout << "操作次数为" << n << " 时" << "使用map的时间为: " << duration1.count() << "秒" << '\n';

        start = chrono::high_resolution_clock::now();
        for(int i = 0; i < n; i ++){
            ump[i] ++;
        }
        end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration2 = end - start;
        cout << "操作次数为" << n << " 时" << "使用unordered_map的时间为: " << duration2.count() << "秒" << '\n';
    }


    return 0;
}
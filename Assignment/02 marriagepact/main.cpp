/* 
Assignment 2: Marriage Pact

This assignment asks you to discover your one true love using containers and pointers.
There are two parts: implement get_applicants and find_matches.

Submit to Paperless by 11:59pm on 2/1/2024.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <queue>
#include <set>
#include <random>

int getRandomNumber(int min, int max){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> res(min,max);
    return res(gen);
}


std::set<std::string> get_applicants(std::string filename) {
    // TODO: Implement this function. Feel free to change std::set to std::unordered_set if you wish!
    std::ifstream file(filename);
    std::set<std::string> s;
    if(!file.is_open()){
        std::cout << "文件打开失败\n";
        return s;
    }
    std::string name;
    while(getline(file,name)){
        s.insert(name);
    }
    return s;
}

std::queue<std::string*> find_matches(std::set<std::string> &students) {
    // TODO: Implement this function.
    std::queue<std::string*> q;
    for(const auto& studnet:students){
        auto fs_ch = studnet[0];
        auto sc_ch = studnet[studnet.find(' ') + 1];
        if(fs_ch == 'J' && sc_ch == 'P'){
            q.push(const_cast<std::string*>(& studnet));
        }
    }
    return q;
}



int main() {
    // Your code goes here. Don't forget to print your true love!
    std::string filename = R"(D:\code\code_vscode\cpp\CS106L\Assignment\2marriagepact_starter\students.txt)";
    std::set<std::string> s = get_applicants(filename);
    //for(auto x:s) std::cout << x << '\n';
    std::queue<std::string*> q = find_matches(s);
    if(q.empty()){
        std::cout << "NO STUDENT FOUND.\n";
    }
    else{
        int n = q.size();
        int target = getRandomNumber(1,n);//输出 第target个相同的
        std::cout << "第" << target << "个相同的名字" << ' ';
        while(target && !q.empty()){
            auto res = q.front();
            q.pop();
            target --;
            if(target == 0) std::cout << *res << '\n';
        }
    }
    
    return 0;
}

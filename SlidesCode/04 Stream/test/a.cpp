#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
struct Course{
    std::string a,b,c;
};


std::vector<std::string> split(std::string s, char t){
    std::stringstream ss(s);
    std::vector<std::string> rs;
    std::string line;
    while(getline(ss,line,t)){
        rs.push_back(line);
    }
    return rs;
}

int main(){
    //第一步 把内容修改好
    std::string filename = R"(D:\code\code_vscode\cpp\CS106L\SlidesCode\04 Stream\test\courses.csv)";
    std::ifstream file(filename); //打开course文件;
    std::vector<Course> course;
    if(!file.is_open()){
        std::cout << "无法打开文件" << '\n';
        return 1;
    }
    std::string line;
    while(getline(file,line)){
        std::vector<std::string> s = split(line,',');
        course.push_back({s[0],s[1],s[2]});
    }
    file.close();
    //写完第一阶段的检验 是否把内容输入进来
    // for(auto [a,b,c]:course){
    //     std::cout << a << ' ' << b << ' ' << c << '\n';
    // }
    //第二步 把内容写入
    filename = R"(D:\code\code_vscode\cpp\CS106L\SlidesCode\04 Stream\test\in.csv)";
    std::ofstream infile(filename);
    if(!infile.is_open()){
        std::cout << "无法打开文件" << '\n';
        return 1;
    }
    for(auto [a,b,c]:course){
        infile << a << ',' << b << ',' << c << std::endl;
    }
    infile.close();     
    return 0;
}
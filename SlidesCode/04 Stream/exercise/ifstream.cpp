#include <iostream>
#include <sstream>
#include <fstream>

int main(){ 
    std::ifstream ifs("append.txt");
    if(ifs.is_open()){
        std::string line;
        std::getline(ifs,line);
        std::cout <<  "Read from the file: " << line << '\n';
    }
    if(ifs.is_open()){
        std::string lineTwo;
        std::getline(ifs,lineTwo);
        std::cout <<  "Read from the file: " << lineTwo << '\n';
    }
}
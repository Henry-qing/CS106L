#include <iostream>
#include <fstream>

int main(){ 
    std::ofstream ofs("hello.txt");
    if(ofs.is_open()){
        ofs << "Hello CS106L!" << '\n';
    }
    ofs.close();
    ofs.open("hello.txt");
    ofs << "this will tough! It's open again!";
    return 0;
}
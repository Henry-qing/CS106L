#include <iostream>
#include <sstream>

int main(){
    std::string initial_quote = "I like eating apples";

    std::stringstream ss(initial_quote);
    std::string fs,sc,v,n;
    ss >> fs >> sc >> v >> n;
    std::cout << fs << " " << sc << " " << v << " " << n << '\n';
    return 0;
}
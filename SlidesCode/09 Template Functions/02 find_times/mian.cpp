#include <iostream>

template<typename T, typename U>
int cnt_occurrences(T begin, T end, U target){
    int cnt = 0;
    for(auto it = begin; it != end; it ++){
        if(*it == target) cnt ++;
    }
    return cnt;
}


int main(){
    std::string str = "Tchaikovsky";
    std::cout << "Occurrences of the letter k in Tchaikovsky:" << cnt_occurrences(str.begin(),str.end(),'k') << '\n';
    return 0;
}
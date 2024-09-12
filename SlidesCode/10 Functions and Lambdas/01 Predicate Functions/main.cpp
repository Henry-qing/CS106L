#include <iostream>
#include <vector>
bool isVowel(char c){
    std::string t = "aeiou";
    return t.find(c) != std::string::npos;
}

bool isDivided_by(int a, int b){
    return (a % b == 0);
}


template<typename T,typename U>
int cnt_occurrences(T begin, T end, U pred){
    int cnt = 0;
    for(auto it = begin; it != end; it ++){
        if(pred(*it)) cnt ++;
    }
    return cnt;
}

int main(){
    std::string test = "Xadiao";
    std::cout << "Occurrences of vowel letters in test:" << cnt_occurrences(test.begin(),test.end(),isVowel) << '\n';

    int limit = 5;
    std::vector<int> nums = {3,5,7,9,10};
    auto isMoreThan = [limit](int x){return x > limit;};
    std::cout << cnt_occurrences(nums.begin(),nums.end(),isMoreThan);
    return 0;
}
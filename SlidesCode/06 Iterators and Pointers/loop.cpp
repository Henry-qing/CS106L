#include <iostream>
#include <map>
int main(){
    std::map<int,int> mp{{1,6},{2,8},{0,3},{3,9}};
    for(auto it = mp.begin(); it != mp.end(); it ++){
        //std::cout << it->first << " " << it->second << '\n'; 传统输出
        const auto& [key, value] = *it;
        std::cout << key << " " << value << '\n'; // C ++17 结构化绑定
    }
    return 0;
}
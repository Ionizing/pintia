#include <iostream>
#include <string>
#include <algorithm>

void Add(std::string& str) {
    std::string tmp = str;
    std::reverse(tmp.begin(), tmp.end());
    int len(str.length()), carry(0);

    for(int i=0; i!=len; ++i){
        str[i] = str[i] + tmp[i] + carry - '0';
        carry = 0;
        if(str[i] > '9'){
            str[i] -= 10;
            carry = 1;
        }
    }
    if(carry) str += "1";
    std::reverse(str.begin(), str.end());
}

int main() {
    std::string str;
    int cnt(0);
    std::cin >> str >> cnt;

    for(int i=0; i!=cnt; ++i){
        std::string tmp = str;
        std::reverse(tmp.begin(), tmp.end());
        if(tmp == str){
            std::cout << str << std::endl << i;
            return 0;
        }
        else Add(str);
    }
    std::cout << str << std::endl << cnt;
}

// File:    3-1-2.cpp
// Author:  csh
// Date:    2020/08/29
// ===================


#include <iostream>
#include <string>
using namespace std;


int* Statistics(string s){
    int *ret = new int[36];
    for(int i = 0; i < 36; i++)
        ret[i] = 0;
    for(auto i = 0; i < s.size(); i ++){
        if(s[i] >= 65 && s[i] <= 90)
            // 属于A-Z，对应数组位置0-26，即减65
            ret[s[i] - 65] += 1;
        else if(s[i] >= 48 && s[i] <= 57)
            // 属于0~9，对应数组位置27-35，即减48+26=-22
            ret[s[i] - 22] += 1;
    }
    return ret;
}

int main(){
    string s = "ABAACUGH89789927";
    int *ret = Statistics(s);
    for(int i = 0; i < 36; i++){
        if(ret[i] == 0) continue;
        if(i >=0 && i < 26)
            cout << char(i+65) << "  " << ret[i] << endl;
        else
            cout << char(i+22) << "  " << ret[i] << endl;

    }
    return 0;
}

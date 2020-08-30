// File:    3-1-6.cpp
// Author:  csh
// Date:    2020/08/29
// ===================

#include <iostream>
#include <string>

using namespace std;

void Solution(string s, string t, string &r, int pos[]){
    // C++11
    int p = 0;
    for(auto ch:s){
        if(t.find(ch) == -1 && r.find(ch) == -1){   // t中不存在ch
            r += ch;
            pos[p++] = s.find(ch);
        }
    }

    /* for(size_t i = 0; i < s.size(); i++){
        if(t.find(s[i]) == -1 && r.find(s[i]) == -1){
            r += s[i];
            pos[p++] = i;       // 这里不用再次调用find函数
        }
    } */
}

int main(){
    string s = "ABCABE";
    string t = "AC";
    string r = "";
    int pos[5] = {-1, -1, -1, -1, -1};
    Solution(s, t, r, pos);
    cout << "r: " << r << endl;
    for(int i = 0; i < 5; i++){
        if(pos[i] != -1)
            cout << pos[i] << " ";
    }
    cout << endl;
    return 0;
}

// File:    1-2-1.cpp
// Author:  csh
// Date:    2020/05/01
// ===================


// 未做完，学完再补
#include <iostream>
#include <string>

using namespace std;


class strings{
    public:
        string str;
        strings *pNext;
        strings();
        strings(string s){str = s;};
};

int compareStr(char a, char b);

int main(){
    strings a[8] = {strings("ABC"), strings("5C"), strings("PABC"), strings("CXY"),
                    strings("CRSI"), strings("7"), strings("B899"), strings("B9")};

    strings head = a[0];
    a[0].pNext = NULL;
    for(int i = 0; i < 8; i++){
        int ret;            // 判别排序
        for(int j = 0; a[i].str[j] && (a[i-1].str[j]); j++){
            int ret = compareStr(a[i].str[j], a[i-1].str[j]);
        }
    }
    return 0;
}

int compareStr(char a, char b){
    int ret;
    // 1. a,b相等
    if(a-b == 0) ret = 0;

    // 2. a,b都属于A-Z或都属于0-9
    if(((a-'A' >= 0) && (b-'A' >= 0)) || ((a-'A' <= 0) && (b-'A' <= 0))){
        if(a-b > 0) ret = 1;
    }else{
        if(a-b > 0) ret = -1;
    }
    return ret;
}

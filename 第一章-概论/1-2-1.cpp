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

int main(){
    strings a[8] = {strings("ABC"), strings("5C"), strings("PABC"), strings("CXY"),
                    strings("CRSI"), strings("7"), strings("B899"), strings("B9")};
    printf("%d", '1');
    return 0;
}

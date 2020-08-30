// File:    3-1-8.cpp
// Author:  csh
// Date:    2020/08/29
// ===================


#include <iostream>
#include <string>

using namespace std;

void DelSubStr(string &s, const string t){
    int delsize = t.length();
    int pos;
    while((pos = s.find(t)) != -1){
        s.replace(pos, delsize, "");
        cout << s << endl;
    }
}


int main(){
    string s = "ABCEDHSJO12DFADDASDABC";
    string t = "ABC";
    DelSubStr(s, t);
    cout << s << endl;
    return 0;
}

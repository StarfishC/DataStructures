// File:    3-5-3.cpp
// Author:  csh
// Date:    2020/08/30
// ===================


#include <iostream>
#include <string>

using namespace std;


void format(const string &s1, string &s2, string &s3, int n){
    if(s2.size() != 0 || s3.size() != 0){
        cout << "s2,s3有非空串" << endl;
        return;
    }
    if(s1.size() <= n){
        s2 = s1;
        s3 = "";
        return;
    }
    for(size_t i = 0; i < s1.size(); i++){
        if(i <= n-1)
            s2 += s1[i];
        else
            s3 += s1[i];        // 也可以break之后用子串提取方式赋值
    }
}

int main(){
    string s1 = "ABCDEFGHIJKLMN";
    string s2 = "";
    string s3 = "";
    format(s1, s2, s3, 6);
    cout << "s2: " << s2 << endl;
    cout << "s3: " << s3 << endl;
    return 0;
}

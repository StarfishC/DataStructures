// File:    3-3-2.cpp
// Author:  csh
// Date:    2020/08/30
// ===================


#include <iostream>
#include <string>

using namespace std;

int* FindNext(string s){
    int *next = new int[s.length()];
    next[0] = 0;            // 第0个为0
    int i = 1;
    int len = 0;
    int n = s.length();
    while(i < n){
        if(s[i] == s[len]){
            len++;
            next[i] = len;
            i++;
        }else{
            if(len > 0)
                len = next[len-1];
            else{
                next[i] = len;              // 此时len=0，也可写0
                i++;
            }
        }
    }

    // 最后一项可不需要，方便KMP算法，结果后移一位，且第一位改成-1
    for(int i = n-1; i > 0; i--)
        next[i] = next[i-1];
    next[0] = -1;

    for(int i = 0; i < n; i++)
        cout << next[i] << " ";
    cout << endl;
    return next;
}


int main(){
    string s1 = "A B C D E F G H";
    string s2 = "I I I I I I I I";
    string s3 = "B A B B A B A B";
    FindNext(s1);
    FindNext(s2);
    FindNext(s3);
    return 0;
}

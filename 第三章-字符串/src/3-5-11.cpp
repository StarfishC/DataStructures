// File:    3-5-11.cpp
// Author:  csh
// Date:    2020/11/08
// ===================


#include <string>
#include <iostream>

using namespace std;


void CommonStr(string &s, string &sub, int &loc){
    int next[50];
    int i, j, k;
    int len = 0;
    int max = 0;
    for(k = 1; k < s.size(); k++){
        i = k;
        j = k - 1;
        next[k] = k - 1;
        while(i < s.size()){
            if(j == k - 1 || s[i] == s[j]){
                i++,j++;
                next[i] = j;
                if(s[i] == s[j])
                    len = j - k + 1;
                else
                    len = j - k;
            }else
                j = next[j];
            if(len > max){
                loc = k;
                max = len;
            }
        }
    }
    for(int i = loc; i < loc + max; i++)
        sub += s[i];
}


int main(){
    string s = "abcabcdefgdefdefg";
    string ret = "";
    int loc;
    CommonStr(s, ret, loc);
    cout << ret << endl;
    cout << loc << endl;
    return 0;
}

// File:    3-1-5.cpp
// Author:  csh
// Date:    2020/08/29
// ===================


#include <string>
#include <iostream>
using namespace std;


int Solution(string s)
{
    auto n = s.size();
    for(auto i = 0; i < s.size()/2; i++)
        if(s[i] != s[n-1-i])
            return 0;
    return 1;
}


int main()
{
    string s = "abcba";
    string s2 = "ab-ab";
    string s3 = "abba";
    cout << s << " : " << Solution(s) << endl;
    cout << s2 << " : " << Solution(s2) << endl;
    cout << s3 << " : " << Solution(s3) << endl;
    return 0;
}

// File:    4-1-8.cpp
// Author:  csh
// Date:    2020/08/29
// ===================


#include <iostream>
#include <string>

#include "../../include/kmp.h"

using namespace std;

void DelSubStr1(string &s, const string t)
{
    int delsize = t.length();
    int pos;
    while((pos = s.find(t)) != -1)
    {
        s.replace(pos, delsize, "");
        cout << s << endl;
    }
}

// 利用Kmp算法
void DelSubStr2(string &s, const string t)
{
    int *Next = findNext(t);
    int pos = KMPStrMatching(s, t, Next);
    while(pos != -1)
    {
        s.replace(pos, t.size(), "");
        cout << s << endl;
        pos = KMPStrMatching(s, t, Next);
    }
}


int main()
{
    string s = "ABCEDHSJO12DFADDASDABC";
    string t = "ABC";
    DelSubStr2(s, t);
    cout << s << endl;
    return 0;
}

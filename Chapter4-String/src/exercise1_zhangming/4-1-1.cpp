// File:    4-1-1.cpp
// Author:  csh
// Date:    2020/08/29
// ===================


#include <string>
#include <iostream>
using namespace std;


int main()
{
    string s = "(xyz)+*";
    string t = "(x+z)*y";
    char tmp = s[2];
    s.replace(2, 1, 1, s[5]);
    s.replace(5, 1, 1, s[6]);
    s.replace(6, 1, 1, tmp);
    cout << s << endl;
    return 0;
}

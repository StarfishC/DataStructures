// File:    4-5-5.cpp
// Author:  csh
// Date:    2020/08/30
// ===================


#include <iostream>
#include <cstring>

void reverseString(char *s1, int n = 1)
{
    int len = strlen(s1);
    if(len > n)
    {
        char tmp = s1[len-n];
        s1[len-n] = s1[0];
        s1[0] = tmp;
        return reverseString(++s1, ++n);
    }
}


int main()
{
    using namespace std;
    char s1[] = "abcde";
    char s2[] = "abcdef";
    reverseString(s1);
    reverseString(s2);
    cout << s1 << endl;
    cout << s2 << endl;
    return 0;
}

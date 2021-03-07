// File:    4-1-4.cpp
// Author:  csh
// Date:    2020/08/29
// ===================

#include <iostream>

void Solution(char s[], int n)
{
    for(int i = 1; i <= n/2; i++)
    {
        char tmp = s[i];
        for(int j = i; j <= n-i; j++) // 移动字符
            s[j] = s[j+1];
        s[n-i] = tmp;
    }
}


int main()
{
    using namespace std;
    char s[] = "ABCDEFGHIJKLM";
    Solution(s, 13);
    cout << s << endl;
    return 0;
}

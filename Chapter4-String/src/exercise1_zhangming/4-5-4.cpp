// File:    4-5-4.cpp
// Author:  csh
// Date:    2020/08/30
// ===================


#include <iostream>


int equal(char *s1, char *s2)
{
    int i = 0;
    while(s1[i] != '\0' && s2[i] != '\0')
    {
        if(s1[i] != s2[i])
            return 0;
        i++;
    }
    if(s1[i] == '\0' && s2[i] == '\0')
        return 1;
    return 0;
}


int main()
{
    using namespace std;
    char s1[] = "abc";
    char s2[] = "abc";
    char s3[] = "abd";
    cout << equal(s1, s2) << endl;
    cout << equal(s1, s3) << endl;
    return 0;
}


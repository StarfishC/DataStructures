// File:    4-5-8.cpp
// Author:  csh
// Date:    2020/08/30
// ===================


#include <iostream>


char* copystr(char *s1, const char *s2)
{
    // s2复制到s1
    if(s1 == NULL || s2 == NULL)
        return NULL;
    char *addr = s1;
    while((*s1++ = *s2++) != '\0');
    return addr;
}


int main()
{
    using namespace std;
    char s2[] = "asdfzxc";
    char s1[20];
    char *s3 = copystr(s1, s2);
    cout << s3 << endl;
    cout << s1 << endl;
    return 0;
}

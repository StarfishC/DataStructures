// File:    4-1-9.cpp
// Author:  csh
// Date:    2020/08/30
// ===================


#include <iostream>
#include <string>

using namespace std;

int* FindNext(string s)
{
    int *next = new int[s.length()];
    next[0] = 0;            // 第0个为0
    int i = 1;
    int len = 0;
    int n = s.length();
    while(i < n){
        if(s[i] == s[len])
        {
            len++;
            next[i] = len;
            i++;
        }else
        {
            if(len > 0)
                len = next[len-1];
            else
            {
                next[i] = len;              // 此时len=0，也可写0
                i++;
            }
        }
    }

    // 最后一项可不需要，方便KMP算法，结果后移一位，且第一位改成-1
    for(int i = n-1; i > 0; i--)
        next[i] = next[i-1];
    next[0] = -1;
    return next;
}

int KMP(string text, string pattern)
{
    int m = text.length(); 
    int n = pattern.length();
    int *next = FindNext(text);

    int i = 0;
    int j = 0;
    while(i < m)
    {
        if(j == n-1 && text[i] == pattern[j])
        {
            cout << "Found pattern at " << i - j << endl;
            return i - j;
            // j = next[j];         // 当查找所有符合匹配时可用
        }
        if(text[i] == pattern[j])
            i++,j++;
        else
        {
            j = next[j];
            if(j == -1)
            {
                i++;
                j++;
            }
        }
    }
    return -1;
}


int main()
{
    string s2 = "BAAABBBAA";
    int *next = FindNext(s2);
    for(int i = 0; i < s2.length(); i++)
        cout << next[i] << "  >  ";
    cout << endl;
    string text = "BAAABBBCDDDCCHHHHBBBAAABBBAADD";
    KMP(text, s2);
    return 0;
}

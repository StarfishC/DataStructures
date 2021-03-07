// File:    4-1-7.cpp
// Author:  csh
// Date:    2020/08/29
// ===================

#include <iostream>
#include <string>

using namespace std;

bool Solution(const string &T1, const string &T2)
{
    if(T1.size() != T2.size())
        return false;
    int pos = T2.find(T1[0]);
    size_t size = T1.size();
    for(size_t i = 0; i < size; i++)
    {
        if(T1[i] != T2[(i+pos) % size])
            return false;
    }
    return true;
}


int main()
{
    string T1 = "arc";
    string T2 = "car";
    cout << Solution(T1, T2) << endl;
    T1 = "abs";
    T2 = "asb";
    cout << Solution(T1, T2) << endl;
    return 0;
}

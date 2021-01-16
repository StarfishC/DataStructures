// File:    1-4-3.cpp
// Author:  csh
// Date:    2020/05/01
// Update:  2020/01/16
// ===================


#include <iostream>
#include <climits>

const int arrsize = 300;
const int maxint = INT_MAX;


bool Solution(int i, int a[])
{
    if(i < 1 || (i > arrsize))
        return false;
    a[0] = 2;
    for(int j = 2; j <= i; j++)
    {
        if(a[j-2]*2*j > maxint)
            return false;
        a[j-1] = a[j-2] * 2 * j;
    }
    return true;
}


int main()
{
    using namespace std;
    int i = 3;
    int a[arrsize];
    Solution(i, a);
    for(int j = 0; j < 5; j++)
        cout << a[j] << " ";
    cout << endl;
    return 0;
}

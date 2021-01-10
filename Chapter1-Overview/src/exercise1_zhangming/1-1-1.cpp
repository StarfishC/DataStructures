// File:    1-1-1.cpp
// Author:  csh
// Date:    2020/05/01
// Update:  2020/01/10
// ===================


#include <iostream>

using namespace std;

int main()
{
    int x, y, z;
    cin >> x >> y >> z;
    int t;          // 临时变量，用来交换值
    if(x < y)
    {
        t = x;
        x = y;
        y = t;
    }
    if(x < z)
    {
        t = x;
        x = z;
        z = t;
    }
    if(y < z)
    {
        t = y;
        y = z;
        z = t;
    }
    cout << x << " " << y << " " << z << endl;
    return 0;
}


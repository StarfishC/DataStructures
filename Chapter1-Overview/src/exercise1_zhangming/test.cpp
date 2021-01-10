// File:    test.cpp
// Author:  csh
// Date:    2021/01/10
// ===================


#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int x, y, z;
    cin >> x >> y >> z;
    int t;
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

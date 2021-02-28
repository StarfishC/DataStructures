// File:    3-1-11.cpp
// Author:  csh
// Date:    2020/08/23
// ===================


#include <iostream>

int GCD(int n, int m)
{
    if(m <= n && n % m == 0)
        return m;
    else if(n < m)
        return GCD(m, n);
    else
        return GCD(m, n % m);
}


int main()
{
    using namespace std;
    int ret = GCD(49*14, 28);
    cout << ret << endl;
    ret = GCD(12, 7);
    cout << ret << endl;
    return 0;
}

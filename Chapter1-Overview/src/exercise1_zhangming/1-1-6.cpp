// File:    1-1-6.cpp
// Author:  csh
// Date:    2021/01/10
// ===================


#include <iostream>


int test(int n);

int main(int argc, char *argv[])
{
    using namespace std;
    int ret1 = test(100);
    int ret2 = test(160);
    cout << "Times: " << ret1 << endl;
    cout << "Times: " << ret2 << endl;
    return 0;
}


int test(int n)
{
    int m = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 2*i; j <= n; j++)
            m = m + 1;
    return m;
}

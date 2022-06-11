/******************************************************************************
 * File:           1-4-4.cpp
 * Author:         caoshenghui <576365750@qq.com>
 * Github:         https://github.com/caoshenghui
 * Description:
 * LICENSE:        MIT
******************************************************************************/

#include <iostream>
#include <cmath>

double Solution1(double a[], int x, int n)
{
    double tmp = a[0];
    for (int i = 1; i <= n; i++)
        tmp += a[i] * pow(x, i);
    return tmp;
}

int Solution2(double a[], int x, int n)
{
    double tmp = a[n];
    for (int i = n; i > 0; i--)
        tmp = a[i - 1] + x * tmp;
    return tmp;
}

int main()
{
    using namespace std;
    double a[6] = { -2, 3, 6, 8, 7, 8 };
    int n = 5;
    int x = 3;

    double ret = Solution1(a, x, n);
    cout << ret << endl;
    cout << Solution2(a, x, n) << endl;
    return 0;
}

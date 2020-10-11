// File:    1-3-4.cpp
// Author:  csh
// Date:    2020/05/01
// ===================


#include <iostream>
#include <cmath>


double Solution1(double a[], int x, int n){
    double tmp = a[0];
    for(int i = 1; i <= n; i++)
        tmp += a[i] * pow(x,i);
    return tmp;
}

int Solution2(double a[], int x, int n){
    double tmp = a[n];
    for(int i = n; i > 0; i--)
        tmp = a[i-1] + x * tmp;
    return tmp;
}


int main(){
    using namespace std;
    double a[6] = {-2, 3, 6, 8, 7, 8};
    int n = 5;
    int x = 3;

    double ret = Solution1(a, x, n);
    cout << ret << endl;
    cout << Solution2(a, x, n) << endl;
    return 0;
}

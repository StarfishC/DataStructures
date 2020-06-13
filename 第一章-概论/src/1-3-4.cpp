// File:    1-3-4.cpp
// Author:  csh
// Date:    2020/05/01
// ===================


#include <iostream>
#include <cmath>

using namespace std;

int Algo(int a[], int x, int n){
    int tmp;
    int i;
    for(i = 1, tmp = 0; i <= n; i++)
        tmp += a[i-1] * pow(x,i-1);
    return tmp;
}


int main(){
    int a[5] = {-2, 3, 6, 8, 7};
    int n = 5;
    int x = 3;

    int ret = Algo(a, x, n);
    cout << ret << endl;
    return 0;
}

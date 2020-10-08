// File:    1-1-19.cpp
// Author:  csh
// Date:    2020/10/07
// ===================


#include <iostream>


int gcd(int m, int n){
    int t = 1;
    while(t != 0){
        t = m % n;
        m = n;
        n = t;
    }
    return m;
}


int main(int argc, char *argv[]){
    using namespace std;
    int m = 78, n = 36;
    cout << gcd(m, n) << endl;
    return 0;
}

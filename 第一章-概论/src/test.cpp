// File:    test.cpp
// Author:  csh
// Date:    2020/10/11
// ===================


#include <iostream>
#include <climits>

#define arrsize 30
#define maxint INT_MAX


int f(int n){
    int i, j, k, sum = 0;
    for(i = 1; i < n+1; i++){
        for(j = n; j > i-1; j--)
            for(k = 1; k < j+1; k++)
                sum++;
    }
    return sum;
}


int main(int argc, char *argv[]){
    using namespace std;
    cout << f(5) << endl;
    return 0;
}

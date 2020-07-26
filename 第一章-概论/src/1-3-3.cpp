// File:    1-3-3.cpp
// Author:  csh
// Date:    2020/05/01
// ===================


#include <iostream>
#include <climits>

using namespace std;

#define arrsize 300
#define maxint INT_MAX


// 非递归
bool Solution(int i, int a[]){
    if(i < 1 || (i > arrsize))
        return false;
    for(int j = 1; j <= i; j++){
        if(j == 1)
            a[j-1] = 2;
        else{
            if(a[j-2]*2*j > maxint)
                return false;
            a[j-1] = a[j-2] * 2 * j;
        }
    }
    return true;
}


int main(){
    int i = 3;
    int a[arrsize];
    Solution(i, a);
    for(int j = 0; j < 5; j++)
        cout << a[j] << " ";
    cout << endl;
    return 0;
}

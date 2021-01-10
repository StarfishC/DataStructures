// File:    1-4-2.cpp
// Author:  csh
// Date:    2020/05/01
// ===================


#include <iostream>

#define MAX 1000

using namespace std;

// 数组法
int Fibonacci_arr(int k, int m){
    int f;
    int arr[MAX];
    if(m <= k-1)
        f = 0;
    else{
        for(int i = 0; i < k-1; i++)
            arr[i] = 0;                 // 前K-1项均为零
        arr[k-1] = 1;
        for(int i = k; i < m; i++){
            int sum = 0;
            for(int j = 1; j <= k; j++)
                sum += arr[i-j];
            /* for(int j = i-k; j < i; j++)  // 前k项相加
                sum += arr[j]; */
            arr[i] = sum;
        }
        f = arr[m-1];
    }
    return f;
}

// 递归
int Fibonacci_rec(int k, int m){
    if(m <= k-1)
        return 0;
    else if((m == k) || (m == k+1))     // 第k项和k+1均为1
        return 1;
    else
        return 2*Fibonacci_rec(k, m-1) - Fibonacci_rec(k, m-k-1);
}



int main(){
    int f = Fibonacci_arr(2, 8);
    cout << f << endl;

    int f2 = Fibonacci_rec(2, 8);
    cout << f2 << endl;

    return 0;
}

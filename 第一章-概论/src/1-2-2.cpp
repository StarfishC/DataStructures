// File:    1-2-2.cpp
// Author:  csh
// Date:    2020/05/01
// ===================


#include <iostream>

using namespace std;


int* solution(double *A, int N){
    int *ret = new int[N];          // 用来记录最大值所在的位置
    int position = 0;               // 初始化设定数组的第一个元素
    int j = 1;                      // 控制最大值数组的存放
    for(int i = 1; i < N; i++){
        if(A[i] > A[position]){
            position = i;           // 更新最大值元素的位置
            j = 1;                  // 重置ret数组的下一个存放位置，0号位置预留给position
        }else if(A[i] == A[position])
            ret[j++] = i;           // 记录重复的最大值位置
    }
    ret[0] = position;
    if(j < N)
        ret[j] = -1;                // -1为哨兵，前j个元素均为最大值的位置
    return ret;
}


int main(){
    double Num[] = {4529.9, 88, 333, 22, 100, 232.3, 4529.9};
    int *ret = solution(Num, sizeof(Num)/sizeof(double));
    cout << "MaxNumber:" << Num[*ret] << endl;
    cout << "MaxPosition:";
    while(*ret != -1){
        cout << *ret << "  ";
        ret++;
    }
    cout << endl;
    return 0;
}


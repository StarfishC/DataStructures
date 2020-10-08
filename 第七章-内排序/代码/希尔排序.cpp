// File:    希尔排序.cpp
// Author:  csh
// Date:    2020/10/04
// ===================


#include <iostream>


// 改良插入算法
template <typename T>
void ModInsertSort(T array[], int n, int delta){
    int i, j;
    for(i = delta; i < n; i += delta)
        for(j = i; j >= delta; j -= delta){
            if(array[j] < array[j-delta]){
                T temp = array[j];
                array[j] = array[j-delta];
                array[j-delta] = temp;
            }
            else
                break;
        }
}


template <typename T>
void ShellSort(T array[], int n){
    int i, delta;
    for(delta = n/2; delta > 0; delta /= 2)
        for(i = 0; i < delta; i++)
            ModInsertSort(&array[i], n-1, delta);

    // 若最后delta不为1，用其他增量序列时
    if(delta != 1)
        ModInsertSort(array, n, 1);
}


int main(int argc, char *argv[])
{
    using namespace std;
    int array[] = {45, 34, 78, 12, 34, 32, 29, 64};
    ShellSort(array, 8);
    for(int i = 0; i < 8; i++)
        cout << array[i] << " ";
    return 0;
}

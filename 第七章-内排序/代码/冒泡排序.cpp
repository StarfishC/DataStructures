// File:    冒泡排序.cpp
// Author:  csh
// Date:    2020/10/04
// ===================


#include <iostream>


template <typename T>
void swap(T array[], int i, int j){
    T temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}


template <typename T>
void BubbleSort(T array[], int n){
    bool noSwap;
    int i, j;
    for(i = 0; i < n-1; i++){
        noSwap = true;
        for(j = n-1; j > i; j--)
            if(array[j] < array[j-1]){
                swap(array, j, j-1);
                noSwap = false;
            }
        if(noSwap)                          // 如果没发生过交换，表示已经排好序
            return;
    }
}

int main(int argc, char *argv[])
{
    using namespace std;
    int array[] = {45, 34, 78, 12, 34, 32, 29, 64};
    BubbleSort(array, 8);
    for(int i = 0; i < 8; i++)
        cout << array[i] << " ";
    return 0;
}

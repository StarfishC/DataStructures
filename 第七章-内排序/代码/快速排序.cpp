// File:    快速排序.cpp
// Author:  csh
// Date:    2020/10/04
// ===================


#include <iostream>


// 分割函数
template <typename T>
int Partition(T array[], int left, int right);

// 选择轴值
int SelectPivot(int left, int right){
    return (left + right)/2;
}

template <typename T>
void QucikSort(T array[], int left, int right){
    if(right <= left) return;
    int pivot = SelectPivot(left, right);
    swap(array, pivot, right);
    pivot = Partition(array, left, pivot-1);
    QucikSort(array, left, pivot-1);
    QucikSort(array, pivot+1, right);
}

template <typename T>
int Partition(T array[], int left, int right){
    int l = left;
    int r = right;
    T temp = array[r];
    while(l != r){
        while(array[l] <= temp && r > 1)
            l++;
        if(l < r){
            array[r] = array[l];
            r--;
        }

        while(array[r] >= temp && r > 1)
            r--;
        if(l < r){
            array[l] = array[r];
            l++;
        }
    }
    array[l] = temp;
    return 1;
}


// 优化的快速排序
#include "插入排序.cpp"
#define THRESHOLD 28    // 当小于28时使用插入排序

template <typename T>
void ModQuickSort(T array[], int left, int right){
    if(right - left + 1 > THRESHOLD){
        int pivot = SelectPivot(left, right);
        swap(array, left, right);
        pivot = Partition(array, left, right);
        ModQuickSort(array, left, pivot-1);
        ModQuickSort(array, pivot+1, right);
    }
}

template <typename T>
void QucikSort2(T *array, int n){
    ModQuickSort(array, 0, n-1);
    InsertSort(array, n);
}

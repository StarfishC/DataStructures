// File:    快速排序.cpp
// Author:  csh
// Date:    2021/01/02
// ===================


// 选取轴值
int SelectPivot(int left, int right);

// 交换
template <typename T>
void swap(T arr[], int i, int j);

// 分割函数
template <typename T>
int Partition(T array[], int left, int right);


template <typename T>
void QuickSort(T array[], int left, int right)
{
    if(right <= left) return;
    int pivot = SelectPivot(left, right);
    swap(array, pivot, right);      // 分割前先将轴值放到数组末端
    pivot = Partition(array, left, right);
    QuickSort(array, left, pivot-1);
    QuickSort(array, pivot+1, right);
}

inline int SelectPivot(int left, int right)
{
    return (left + right) / 2;
}

template <typename T>
inline void swap(T arr[], int i, int j)
{
    T tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = arr[i];
}

template <typename T>
int Partition(T array[], int left, int right){
    int l = left;
    int r = right;
    T tmp = array[r];
    while(l != r)
    {
        // l指针向右移动，越过那些小于等于轴值的记录
        while(array[l] <= tmp && r > l)
            l++;
        if(l < r)
        {
            array[r] = array[l];
            r--;
        }
        // r指针想做移动，越过哪些大于等于轴值的记录
        while(array[r] >= tmp && r > l)
            r--;
        if(l < r)
        {
            array[l] = array[r];
            l++;
        }
    }
    array[l] = tmp;
    return l;
}


template <typename T>
void QuickSort2(T array[], int left, int right)
{
    int pivot = SelectPivot(left, right);
    int i = left, j = right - 1;
    for(;;)
    {
        while(array[++i] < pivot){}
        while(array[--j] < pivot){}
        if(i < j)
            swap(array, i, j);
        else break;
    }
    swap(array, i, right-1);
    QuickSort2(array, left, i - 1);
    QuickSort2(array, i+1, right);
}


#include <iostream>

int main(int argc, char *argv[])
{
    using std::cout;
    int array[] = {45, 34, 78, 12, 34, 32, 29, 64};
    int n = 8;
    QuickSort(array, 0, 7);
    for(const auto i : array)
        cout << i << " ";
    return 0;
}

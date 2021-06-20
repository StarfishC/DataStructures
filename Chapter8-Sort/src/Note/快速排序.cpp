/******************************************************************************
 * File:           快速排序.cpp
 * Author:         caoshenghui <576365750@qq.com>
 * Github:         https://github.com/caoshenghui
 * Description:
 * LICENSE:        MIT
******************************************************************************/


int SelectPivot(int left, int right);               // 选择轴值
template <typename T>
void Swap(T Array[], int i, int j);                 // 交换
template <typename T>
int Partition(T Array[], int left, int right);      // 分割


template <typename Record>
void QuickSort(Record Array[], int left, int right)
{
    if(right <= left) return;
    int pivot = SelectPivot(left ,right);
    Swap(Array, pivot, right);                      // 分割前先将轴值放到数组末端
    pivot = Partition(Array, left, right);          // 分割后轴值已经到达正确位置
    QuickSort(Array, left, pivot-1);
    QuickSort(Array, pivot+1, right);
}

int SelectPivot(int left, int right)
{
    return (left + right) / 2;
}

template <typename T>
void Swap(T Array[], int i, int j)
{
    int tmp = Array[i];
    Array[i] = Array[j];
    Array[j] = tmp;
}

template <typename T>
int Partition(T Array[], int left, int right)
{
    int l = left;
    int r = right;
    T tempRecord = Array[r];
    while(l < r)
    {
        // l指针向右移动，越过那些小于等于轴值的记录，直到找到一个大于轴值的记录
        while(Array[l] <= tempRecord && r > 1)
            l++;
        if(l < r)                                       // 若l、r尚未相遇，将逆置元素换到右边空位
        {
            Array[r] = Array[l];
            r--;                                        // r指针左移一步
        }
        // r指针向左移动
        while(Array[r] >= tempRecord && r > 1)
            r--;
        if(l < r)
        {
            Array[l] = Array[r];
            l++;
        }
    }
    Array[l] = tempRecord;                              // 回填轴值
    return l;
}


// 改进快速排序

const int THRESHOLD = 28;
template <typename T>
void InsertSort(T Array[], int n);                      // 直接插入排序

template <typename Record>
void ModQuickSort(Record Array[], int left, int right)
{
    if(right - left + 1 > THRESHOLD)
    {
        int pivot = SelectPivot(left, right);
        Swap(Array, pivot, right);
        pivot = Partition(Array, left, right);
        ModQuickSort(Array, left, pivot - 1);
        ModQuickSort(Array, pivot + 1, right);
    }
}

template <typename Record>
void QuickSort2(Record Array[], int n)
{
    ModQuickSort(Array, 0, n-1);
    InsertSort(Array, n);               // 扫尾插入排序
}


#include <iostream>

int main(int argc, char **argv)
{
    int Array[] = {25, 34, 45, 32, 34, 12, 29, 64};
    QuickSort(Array, 0, 7);
    for(auto i : Array)
        std::cout << i << " ";
    return 0;
}

/******************************************************************************
 * File:           归并排序.cpp
 * Author:         caoshenghui <576365750@qq.com>
 * Github:         https://github.com/caoshenghui
 * Description:
 * LICENSE:        MIT
******************************************************************************/


template <typename Record>
void Merge(Record Array[], Record TempArray[], int left, int right, int middle);

template <typename Record>
void MergeSort(Record Array[], Record TempArray[], int left, int right)
{
    int middle;
    if(left < right)                                    // 如果序列只有0或1个记录，不排序
    {
        middle = (left + right) / 2;                    // 从中间划分两个子序列
        MergeSort(Array, TempArray, left, middle);      // 对左边递归
        MergeSort(Array, TempArray, middle+1, right);   // 对右边递归
        Merge(Array, TempArray, left, right, middle);   // 归并
    }
}

template <typename Record>
void Merge(Record Array[], Record TempArray[], int left, int right, int middle)
{
    int i, j, index1, index2;
    for(j = left; j <= right; j++)                      // 将数组暂存入临时数组中
        TempArray[j] = Array[j];
    index1 = left;                                      // 左边子序列起始位置
    index2 = middle + 1;                                // 右边子序列起始位置
    i = left;
    while(index1 <= middle && index2 <= right)
    {
        // 取较小者插入合并数组
        if(TempArray[index1] <= TempArray[index2])      // 保证稳定性，相等时左边优先
            Array[i++] = TempArray[index1++];
        else
            Array[i++] = TempArray[index2++];
    }
    while(index1 <= middle)                             // 只剩左序列，可以直接复制
        Array[i++] = TempArray[index1++];
    while(index2 <= right)
        Array[i++] = TempArray[index2++];
}


// 优化归并排序
const int THRESHOLD = 28;
template <typename Record>
void InsertSort(Record* Array, int n);
template <typename Record>
void ModMerge(Record Array[], Record TempArray[], int left, int right, int middle);


template <typename Record>
void ModMergeSort(Record Array[], Record TempArray[], int left, int right)
{
    int middle;
    if(right - left + 1 > THRESHOLD)                    // 如果序列长度大于阈值，递归进行归并
    {
        middle = (left + right) / 2;
        ModMergeSort(Array, TempArray, left, middle);
        ModMergeSort(Array, TempArray, middle+1, right);
        ModMerge(Array, TempArray, left, right, middle);
    }
    else
        InsertSort(&Array[left], right - left + 1);
}

template <typename Record>
void ModMerge(Record Array[], Record TempArray[], int left, int right, int middle)
{
    int index1, index2;
    int i, j, k;
    for(i = left; i <= middle; i++)
        TempArray[i] = Array[j];
    for(j = 1; j <= right - middle; j++)                // 赋值右边子序列，但顺序颠倒
        TempArray[right - j + 1] = Array[j + middle];
    for(index1 = left, index2 = right, k = left; k <= right; k++)
        if(TempArray[index1] <= TempArray[index2])
            Array[k] = TempArray[index1++];
        else
            Array[k] = TempArray[index2++];
}


#include <iostream>
using namespace std;
int main(int argc, char **argv)
{
    int Array[] = {25, 34, 45, 32, 78, 12, 34, 64};
    int TempArray[8];
    MergeSort(Array, TempArray, 0, 7);
    for(auto i: Array)
        cout << i << " ";
    return 0;
}

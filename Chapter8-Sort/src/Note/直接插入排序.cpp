/******************************************************************************
 * File:           直接插入排序.cpp
 * Author:         caoshenghui <576365750@qq.com>
 * Github:         https://github.com/caoshenghui
 * Description:
 * LICENSE:        MIT
******************************************************************************/


template <typename Record>
void InsertSort(Record Array[], int n)      // Array[]为待排数组，n为数组长度
{
    Record TempRecord;
    int i, j;
    for(i = 1; i < n; i++)
    {
        TempRecord = Array[i];
        j = i - 1;                          // 内循环j从i-1开始
        // 寻找记录i的正确位置
        while(j >= 0 && TempRecord < Array[j])
        {
            Array[j+1] = Array[j];          // 大于记录i的值后移
            j--;
        }
        Array[j+1] = TempRecord;            // 此时j+1就是记录i的正确位置
    }
}


#include <iostream>

int main(int argc, char **argv)
{
    int arr[] = {45, 34, 78, 12, 34, 32, 29, 64};
    InsertSort(arr, sizeof(arr)/sizeof(int));
    for(auto i : arr)
        std::cout << i << " ";
    return 0;
}

/******************************************************************************
 * File:           冒泡排序.cpp
 * Author:         caoshenghui <576365750@qq.com>
 * Github:         https://github.com/caoshenghui
 * Description:
 * LICENSE:        MIT
******************************************************************************/


template <typename Record>
void BubbleSort(Record Array[], int n)
{
    // `NoSwap`标志为`true`表示没有逆置对，整个数组已经有序了
    bool NoSwap = true;                 // 是否发生交换标志
    int i, j;
    for(i = 0; i < n-1; i++)
    {
        for(j = n-1; j > i; j--)
            if(Array[j] < Array[j-1])   // 出现逆置对
            {
                Record tmp = Array[j];
                Array[j] = Array[j-1];
                Array[j-1] = tmp;
                NoSwap = false;         // 发生了交换，标志变为假
            }
        if(NoSwap)
            break;
    }
}


#include <iostream>

int main(int argc, char **argv)
{
    int Array[] = {45, 34, 78, 12, 34, 32, 29, 64};
    BubbleSort(Array, sizeof(Array)/sizeof(int));
    for(auto i : Array)
        std::cout << i << " ";
    return 0;
}

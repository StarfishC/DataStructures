/******************************************************************************
 * File:           Shell排序.cpp
 * Author:         caoshenghui <576365750@qq.com>
 * Github:         https://github.com/caoshenghui
 * Description:
 * LICENSE:        MIT
******************************************************************************/


// 修改的插入排序算法
template <typename Record>
void ModInsSort(Record Array[], int n, int delta)   // delta表示当前增量
{
    int i, j;
    for(i = delta; i < n; i += delta)
        for(j = i; j >= delta; j -= delta)          // j以delta为步长向前寻找逆置对进行调整
        {
            if(Array[j] < Array[j-delta])
            {
                Record tmp = Array[j];
                Array[j] = Array[j-delta];
                Array[j-delta] = tmp;
            }
            else
                break;
        }
}

// 以增量每次除以2递减划分子序列
template <typename Record>
void ShellSort(Record Array[], int n)
{
    int i, delta;
    for(delta = n /2; delta > 0; delta /=2)         // 增量每次除以2
        for(i = 0; i < delta; i++)                  // 分别对delta个子序列进行插入排序
            ModInsSort(&Array[i], n-i, delta);      // 传入Array[i]地址，待处理数组长度为n-i
    // 如果增量序列不能保证最后一个delta为1，可以加入扫尾性质的插入排序
    // 本算法增量为2可以保证最后依次间距为1
    // ModInsSort(Array, n, 1)
}


#include <iostream>

int main(int argc, char **argv)
{
    int arr[] = {45, 34, 78, 12, 34, 32, 29, 64};
    ShellSort(arr, sizeof(arr)/sizeof(int));
    for(auto i: arr)
        std::cout << i << " ";
    return 0;
}

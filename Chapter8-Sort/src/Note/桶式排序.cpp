/******************************************************************************
 * File:           桶式排序.cpp
 * Author:         caoshenghui <576365750@qq.com>
 * Github:         https://github.com/caoshenghui
 * Description:
 * LICENSE:        MIT
******************************************************************************/


template <typename Record>
void BucketSort(Record Array[], int n, int max)
{
    Record *TempArray = new Record[n];          // 开辟临时数组
    int *count = new int[max];                  // 桶容量计数器，count[i]存储了第i个桶中的记录数

    int i;
    for(i = 0; i < n; i++)                      // 把序列复制到临时数组
        TempArray[i] = Array[i];
    for(i = 0; i < max; i++)                    // 初始化计数器为0
        count[i] = 0;
    for(i = 0; i < n; i++)                      // 统计每个值出现次数
        count[Array[i]]++;
    for(i = 1; i < max; i++)                    // 统计小于等于i的元素个数
        count[i] = count[i-1] + count[i];       // count[i]记录了i+1的开始位置
    for(i = n-1; i >= 0; i--)                   // 从尾部开始按顺序输出，保证稳定性
        Array[--count[TempArray[i]]] = TempArray[i];
}


#include <iostream>
using namespace std;
int main(int argc, char **argv)
{
    int Array[] = {7, 3, 8, 9, 6, 1, 8, 1, 2};
    BucketSort(Array, 9, 10);
    for(auto i: Array)
        cout << i << " ";
    return 0;
}

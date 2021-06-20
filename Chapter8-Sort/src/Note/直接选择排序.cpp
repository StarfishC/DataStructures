/******************************************************************************
 * File:           直接选择排序.cpp
 * Author:         caoshenghui <576365750@qq.com>
 * Github:         https://github.com/caoshenghui
 * Description:
 * LICENSE:        MIT
******************************************************************************/

template <typename Record>
void SelectSort(Record Array[], int n)
{
    int i, j, smallest;
    for(i = 0; i < n-1; i++)            // 依次选出第i小的记录
    {
        smallest = i;                   // 假设记录i就是最小
        for(j = i+1; j < n; j++)
            if(Array[j] < Array[smallest])  // 发现更小值
                smallest = j;
        int tmp = Array[i];
        Array[i] = Array[smallest];
        Array[smallest] = tmp;
    }
}



#include <iostream>

int main(int argc, char **argv)
{
    using namespace std;
    int Array[] = {45, 34, 78, 12, 34, 32, 29, 64};
    SelectSort(Array, sizeof(Array)/sizeof(int));
    for(auto i : Array)
        cout << i << " ";
    cout << endl;
    return 0;
}

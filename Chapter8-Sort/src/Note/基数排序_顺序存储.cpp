/******************************************************************************
 * File:           基数排序_顺序存储.cpp
 * Author:         caoshenghui <576365750@qq.com>
 * Github:         https://github.com/caoshenghui
 * Description:
 * LICENSE:        MIT
******************************************************************************/


template <typename Record>
void RadixSort(Record Array[], int n, int d, int r)
{
    Record *TempArray = new Record[n];                  // 辅助排序临时数组
    int *count = new int[r];                            // 桶容量计数器，count[i]存储第i个桶的记录数
    int i, j, k;
    int Radix = 1;                                      // 模保持进位，用来取Array[j]的第i位排序码
    for(i = 1; i <= d; i++)                             // 分别对第i个排序码进行分配
    {
        for(j = 0; j < r; j++)
            count[j] = 0;                               // 初始化计数器为0
        for(j = 0; j < n; j++)                          // 统计每个桶中的记录数
        {
            k = (Array[j] / Radix) % r;                 // 取Array[j]的第i位排序码
            count[k] ++;
        }
        for(j = 1; j < r; j++)                          // 将TempArray中的位置依次分配给r个桶
            count[j] = count[j-1] + count[j];
            // count[i]记录了i+1的开始位置，元素i应该从Array[count[i]-1]往前追溯
        for(j = n-1; j >= 0; j--)                       // 从数组尾部，把记录收集到相应的桶
        {
            k = (Array[j] / Radix) % r;                 // Array[j]应放到count[k]-1处
            TempArray[--count[k]] = Array[j];
        }
        for(j = 0; j < n; j++)                          // 复制内容到Array
            Array[j] = TempArray[j];
        Radix *= r;                                     // 左进一位，修改模
    }
    delete [] TempArray;
    delete [] count;
}

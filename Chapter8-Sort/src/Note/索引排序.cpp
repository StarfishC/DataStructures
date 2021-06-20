/******************************************************************************
 * File:           索引排序.cpp
 * Author:         caoshenghui <576365750@qq.com>
 * Github:         https://github.com/caoshenghui
 * Description:
 * LICENSE:        MIT
******************************************************************************/


// 采用简单插入的索引排序
template <typename Record>
void IndexSort(Record Array[], int IndexArray[], int n)
{
    int i, j;
    for(i = 0; i < n; i++)
        IndexArray[i] = i;                  // 初始化索引下标
    // 简单插入排序的地址排序过程
    for(i = 1; i < n; i++)
        for(j = i; j > 0; j--)
            if(Array[IndexArray[j]] < Array[IndexArray[j-1]])
            {
                // 交换
                int tmp = IndexArray[j];
                IndexArray[j] = IndexArray[j-1];
                IndexArray[j-1] = tmp;
            }
            else
                break;

    AdjustRecord(Array, IndexArray, n);
}

// 利用索引数字进行循环调整
template <typename Record>
void AdjustRecord(Record Array[], int IndexArray[], int n)
{
    Record TempRec;
    int i, j;
    for(i = 0; i < n; i++)                          // 循环n-1次，每次处理数组中第i个记录
    {
        j = i;
        TempRec = Array[i];
        while(IndexArray[j] != i)                   // 如果循环链中索引下标还不是i，则顺链循环调整
        {
            int k = IndexArray[j];
            Array[j] = Array[k];
            IndexArray[j] = j;
            j = k;
        }
        Array[j] = TempRec;
        IndexArray[j] = i;
    }
}

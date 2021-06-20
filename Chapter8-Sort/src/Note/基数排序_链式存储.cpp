/******************************************************************************
 * File:           基数排序_链式存储.cpp
 * Author:         caoshenghui <576365750@qq.com>
 * Github:         https://github.com/caoshenghui
 * Description:
 * LICENSE:        MIT
******************************************************************************/


// 结点类
class Node
{
    public:
        int key;
        int next;
};
// 静态队列类
class StaticQueue
{
    public:
        int head;
        int tail;
};

template <typename Record>
void RadixSort(Record* Array, int n, int d, int r)
{
    int i, first = 0;                               // first指向静态链中的第一个记录
    StaticQueue *queue = new StaticQueue[r];        // 存放r个桶的静态队列
    for(i = 0; i < n-1; i++)                        // 初始化建链，相邻记录的静态指针链接为单链表
        Array[i].next = i + 1;                      // 第i个记录的静态指针域设为i+1
    Array[n-1].next = -1;                           // 链尾为空
    for(i = 0; i < d; i++)                          // 堆第i个排序码进行分配和收集，一共d趟
    {
        Distrubute(Array, first, i, r, queue);
        Collect(Array, first, r, queue);
    }
    delete [] queue;
    AddSort(Array, n, first);                       // 线性时间整理静态链表，使得数组按下标有序
}

// 分配过程
template <typename Record>
void Distrubute(Record* Array, int first, int i, int r, StaticQueue* queue)
{
    int j, k, a, curr = first;
    for(j = 0; j < r; j++)
        queue[j].head = -1;                         // 初始化r个队列
    while(curr != -1)
    {
        k = Array[curr].key;                        // 取第i位排序码数字k
        for(a = 0; a < i; a++)
            k = k / r;
        k = k % r;
        // 把Array[curr]分配到第k个桶中
        if(queue[k].head == -1)                     // 如果桶空，Array[curr]就是第一个记录
            queue[k].head = curr;
        else
            Array[queue[k].tail].next = curr;
        queue[k].tail = curr;                       // 当前记录下标curr被标记为该桶的尾部
        curr = Array[curr].next;
    }
}

// 收集过程
template <typename Record>
void Collect(Record *Array, int& first, int r, StaticQueue* queue)
{
    int last, k = 0;
    while(queue[k].head == -1)                      // 找到第一个非空队列
        k++;
    first = queue[k].head;
    last = queue[k].tail;
    while(k < r-1)                                  // 继续收集下一个队列
    {
        k++;
        while(k < r-1 && queue[k].head == -1)       // 当前队列空，且不是最后一个队列
            k++;
        if(queue[k].head != -1)                     // 将这个非空序列与上一个非空序列连接起来
        {
            Array[last].next = queue[k].head;
            last = queue[k].tail;
        }
    }
    Array[last].next = -1;                          // 收集完毕
}

// 整理静态链表
template <typename Record>
void AddSort(Record *Array, int n, int first)
{
    int i, j;
    j = first;                                      // j待处理数据下标，第一次为first
    Record TempRec;
    for(i = 0; i < n-1; i++)
    {
        TempRec = Array[j];
        Array[j] = Array[i];
        Array[i] = TempRec;
        Array[i].next = j;
        j = TempRec.next;
        while(j <= i)
            j = Array[j].next;
    }
}

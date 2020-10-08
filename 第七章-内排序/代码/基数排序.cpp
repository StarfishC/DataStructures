// File:    基数排序.cpp
// Author:  csh
// Date:    2020/10/04
// ===================


// 节点类
class Node{
    public:
        int key;
        int next;
};

// 静态队列类
class StaticQueue{
    public:
        int head;
        int tail;
};

template <typename T>
void RadixSort(T *array, int n, int d, int r){
    int i, first = 0;
    StaticQueue *queue = new StaticQueue[r];
    for(i = 0; i < n -1; i++)
        array[i].next = i + 1;
}

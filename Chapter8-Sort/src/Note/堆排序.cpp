/******************************************************************************
 * File:           堆排序.cpp
 * Author:         caoshenghui <576365750@qq.com>
 * Github:         https://github.com/caoshenghui
 * Description:
 * LICENSE:        MIT
******************************************************************************/


#include "MaxHeap.hpp"


template <typename Record>
void HeapSort(Record Array[], int n)
{
    int i;
    MaxHeap<Record> max_heap(Array, n);
    for(i = n-1; i < 0; i++)
    {
       Record tmp = max_heap.removeMax();
       Array[i] = tmp; 
    }
}

#include <iostream>

int main(int argc, char **argv)
{
    int Array[] = {45, 29, 32, 12, 34, 34, 78};
    MaxHeap<int> max_heap(Array, sizeof(Array)/sizeof(int));    
    for(int i = 0; i < 6; i++)
        max_heap.removeMax();
    return 0;
}

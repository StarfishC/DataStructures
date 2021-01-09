// File:    选择排序.cpp
// Author:  csh
// Date:    2021/01/02
// ===================



// 直接选择排序
template <typename T>
void SelectSort(T array[], int n)
{
    int i, j, smallest;
    for(i = 0; i < n - 1; i++)
    {
        smallest = i;
        for(j = i+1; j < n; j++)
            if(array[j] < array[smallest])
                smallest = j;
        swap(array, i, smallest);
    }
}

template <typename T>
void swap(T arr, int i, int j)
{
    T tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}


// 用最大堆
// 最大元素移到最后一个位置，并将堆规模减一
template <typename T>
void SelectSort2(T array[], int n)
{
    MaxHeap<T> minHeap = MaxHeap<T>(arr, n, n);
    for(int i = 0; i < n-1; i++)
        minHeap.removeMax();            // 算法操作n-1次，最小元素不需要出堆
}

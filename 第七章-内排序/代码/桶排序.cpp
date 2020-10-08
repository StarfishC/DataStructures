// File:    桶排序.cpp
// Author:  csh
// Date:    2020/10/04
// ===================


template <typename T>
void BucketSort(T array[], int n, int max){
    T *tempArray = new T[n];
    int *count = new int[max];

    int i;
    for(i = 0; i < n; i++)
        tempArray[i] = array[i];
    for(i = 0; i < max; i++)
        count[i] = 0;
    for(i = 0; i < n; i++)
        count[array[i]]++;
    for(i = 1; i < max; i++)
        count[i] = count[i-1] + count[i];
    for(i = n-1; i >= 0; i--)
        array[--count[tempArray[i]]] = tempArray[i];
}

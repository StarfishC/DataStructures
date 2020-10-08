// File:    归并排序.cpp
// Author:  csh
// Date:    2020/10/04
// ===================


template <typename T>
void Merge(T array[], T tempArray[], int left, int right, int middle);

template <typename T>
void MergeSort(T array[], T tempArray[], int left, int right){
    int middle;
    if(left < right){
        middle = (left + right) / 2;
        MergeSort(array, tempArray, left, middle);
        MergeSort(array, tempArray, middle+1, right);
        Merge(array, tempArray, left, right, middle);
    }
}

template <typename T>
void Merge(T array[], T tempArray[], int left, int right, int middle){
    int i, j, index1, index2;
    for(j = left; j <= right; j++)
        tempArray[j] = array[j];
    index1 = left;
    index2 = middle + 1;
    i = left;
    while(index1 <= middle && index2 <= right){
        if(tempArray[index1] <= tempArray[index2])
            tempArray[i++] = tempArray[index1++];
        else
            tempArray[i++] = tempArray[index2++];
    }
    while(index1 <= middle)
        array[i+1] = tempArray[index1++];
    while(index2 <= middle)
        array[i+1] = tempArray[index2++];
}

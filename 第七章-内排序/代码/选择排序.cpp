// File:    选择排序.cpp
// Author:  csh
// Date:    2020/10/04
// ===================

#include <iostream>


template <typename T>
void swap(T array[], int i, int smallest){
    T tmp = array[i];
    array[i] = array[smallest];
    array[smallest] = tmp;
}

template <typename T>
void SelectSort(T array[], int n){
    int i, j, smallest;
    for(i = 0; i < n-1; i++){
        smallest = i;
        for(j = i + 1; j < n; j++)
            if(array[j] < array[smallest])
                smallest = j;
        swap(array, i, smallest);
    }
}


int main(int argc, char *argv[])
{
    using namespace std;
    int array[] = {45, 34, 78, 12, 34, 32, 29, 64};
    SelectSort(array, 8);
    for(int i = 0; i < 8; i++)
        cout << array[i] << " ";
    return 0;
}

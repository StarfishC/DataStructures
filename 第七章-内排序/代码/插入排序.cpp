// File:    插入排序.cpp
// Author:  csh
// Date:    2020/10/04
// ===================


#include <iostream>


template <typename T>
void InsertSort(T  array[], int n){
    T temp;
    int i, j;
    for(i = 1; i < n; i++){
        temp = array[i];
        for(j = i - 1; j >= 0 && temp < array[j]; j -= 1)
            array[j+1] = array[j];
        array[j+1] = temp;
    }
}


int main(int argc, char *argv[]){
    using namespace std;
    int array[] = {45, 34, 78, 12, 34, 32, 29, 64};
    InsertSort(array, 8);
    for(int i = 0; i < 8; i++)
        cout << array[i] << " ";
    cout << endl;
    return 0;
}

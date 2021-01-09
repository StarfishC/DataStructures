// File:    插入排序.cpp
// Author:  csh
// Date:    2021/01/02
// ===================


#include <iostream>


template <typename T>
void InsertSort(T array[], int n)
{
    using std::cout;
    T tmp;
    int i, j;
    for(int i = 1; i < n; i++)
    {
        tmp = array[i];
        for(j = i; j > 0 && array[j-1] > tmp; j--)
            array[j] = array[j-1];
        array[j] = tmp;
    }
}


int main(int argc, char *argv[])
{
    using namespace std;
    int array[] = {45, 34, 78, 12, 34, 32, 29, 64};
    int n = sizeof(array)/sizeof(int);
    InsertSort(array, n);
    for(const auto i : array)
        cout << i << " ";
    return 0;
}

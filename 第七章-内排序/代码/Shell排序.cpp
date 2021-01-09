// File:    Shell排序.cpp
// Author:  csh
// Date:    2021/01/02
// ===================


#include <iostream>

// 增量每次除以2的Shell排序
template <typename T>
void ShellSort(T array[], int n)
{
    T tmp;
    int i, delta, j;
    for(delta = n/2; delta > 0; delta /= 2)
        for(i = delta; i < n; i++)
        {
            tmp = array[i];
            for(j = i; j >= delta && array[j-delta] > tmp; j -= delta)
                array[j] = array[j-delta];
            array[j] = tmp;
        }
}


int main(int argc, char *argv[])
{
    using namespace std;
    int array[] = {45, 34, 78, 12, 34, 32, 29, 64};
    int n = 8;
    ShellSort(array, 8);
    for(const auto i : array)
        cout << i << " ";
    return 0;
}

// File:    冒泡排序.cpp
// Author:  csh
// Date:    2021/01/02
// ===================


template <typename T>
void BubbleSort(T array[], int n)
{
    bool NoSwap;            // 是否发生交换标识
    for(int i = 0; i < n-1; i++)
    {
        NoSwap = true;
        for(int j = n-1; j > i; j--)
        {
            if(array[j] < array[j-1]){
                NoSwap = false;
                T tmp = array[j];
                array[j] = array[j-1];
                array[j-1] = tmp;
            }
        }
        if(NoSwap) return;
    }
}


#include <iostream>

int main(int argc, char *argv[])
{
    using std::cout;
    int array[] = {45, 34, 78, 12, 34, 32, 29, 64};
    int n = 8;
    BubbleSort(array, 8);
    for(const auto i : array)
        cout << i << " ";
    return 0;
}

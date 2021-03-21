// File:    2-9.cpp
// Author:  csh
// Date:    2021/03/13
// ===================


#include <iostream>

template <typename T>
void SearchExchangeInsert(T A[], T x, int n)
{
    int low = 0, high = n-1, mid;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(A[mid] == x) break;
        else if(A[mid] < x)
            low = mid + 1;
        else high = mid - 1;
    }

    // 最后一个元素与x相等时不交换
    if(A[mid] == x && mid != n-1)
    {
        T t;
        t = A[mid];
        A[mid] = A[mid+1];
        A[mid+1] = t;
    }
    // 查找失败
    if(low > high)
    {
        int i;
        for(i = n-1; i > high; i--)
            A[i+1] = A[i];
        A[i+1] = x;
    }
}


int main()
{
    using namespace std;
    int A[10] = {1,3,5,7,9,10};
    SearchExchangeInsert<int>(A, 4, 6);
    for(auto x:A)
        cout << x << " ";
    return 0;
}

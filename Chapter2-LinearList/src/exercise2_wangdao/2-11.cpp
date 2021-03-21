// File:    2-11.cpp
// Author:  csh
// Date:    2021/03/13
// ===================


int M_Search(int A[], int B[], int n)
{
    // 分别表示A,B首位数、末位数和中位数
    int s1 = 0, d1 = n-1, m1;
    int s2 = 0, d2 = n-1, m2;
    while(s1 != d1 || s2 != d2)
    {
        m1 = (s1 + d1) / 2;
        m2 = (s2 + d2) / 2;
        if(A[m1] == B[m2])
            return A[m1];
        if(A[m1] < B[m2])
        {
            if((s1 + d1) % 2 == 0)  // 若元素个数为奇数
            {
                s1 = m1;            // 舍弃A中间点以前的部分且保留中间点
                d2 = m2;            // 舍弃B中间点以后的部分且保留中间点
            }
            else
            {
                s1 = m1 + 1;        // 舍弃A中间点以及中间点以前的部分
                d2 = m2;            // 舍弃B中间点以后的部分且保留中间点
            }
        }
        else // A[m1] > B[m2]
        {
            if((s2 + d2) % 2 == 0)
            {
                d1 = m1;            // 舍弃A中间点以前的部分且保留中间点
                s2 = m2;            // 舍弃B中间点以后的部分且保留中间点
            }
            else
            {
                d1 = m1;            // 舍弃A中间点以后的部分且保留中间点
                s2 = m2 + 1;        // 舍弃B中间点以及中间点以前的部分
            }    
        }
    }
    return A[s1] < B[s2] ? A[s1] : B[s2];
}


#include <iostream>

int main()
{
    using namespace std;
    int A[4] = {2,3,5,7};
    int B[4] = {3,5,7,10};
    cout << M_Search(A, B, 4) << endl;
    return 0;
}

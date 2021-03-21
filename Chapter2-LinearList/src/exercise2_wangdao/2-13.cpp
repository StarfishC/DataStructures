// File:    2-13.cpp
// Author:  csh
// Date:    2021/3/13
// ===================


int findMissMin(int A[], int n)
{
    int i, *B;
    B = new int[n]{0};
    for(i = 0; i < n; i++)
        if(A[i] > 0 && A[i] <= n)
            B[A[i]-1] = 1;
    for(i = 0; i < n; i++)
        if(B[i] == 0) break;
    return i + 1;
}

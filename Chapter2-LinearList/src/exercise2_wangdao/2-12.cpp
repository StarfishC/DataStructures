// File:    2-12.cpp
// Author:  csh
// Date:    2021/03/13
// ===================


int Majority(int A[], int n)
{
    // c保存主元，count计数
    int i, c, count = 1;
    c = A[0];               // 默认主元是A[0]
    for(i = 1; i < n; i++)
    {
        if(A[i] == c)       // 对A中候选主元计数
            count++;
        else
        {
            if(count > 0)   // 处理不是候选主元情况
                count--;
            else
            {
                c = A[i];   // 更换候选主元素，重新计数
                count = 1;
            }
        } 
    }
    if(count > 0)
        for(i=count=0; i < n; i++)      // 统计候选主元素的实际出现次数
            if(A[i] == c)
                count++;
    if(count > n/2) return c;
    return -1;
}


#include <iostream>

int main()
{
    using namespace std;
    int A[7] = {5,1,5,1,5,1,5};
    cout << Majority(A, 7) << endl;
    return 0;    
}

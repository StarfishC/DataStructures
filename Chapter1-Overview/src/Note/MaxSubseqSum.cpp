/******************************************************************************
 * File:           MaxSubseqSum.cpp
 * Author:         caoshenghui <576365750@qq.com>
 * Github:         https://github.com/caoshenghui
 * Description:
 * LICENSE:        MIT
******************************************************************************/

// 1. 暴力法
int MaxSubseqSum1(int A[], int N)
{
    int ThisSum, MaxSum = 0;
    for (int i = 0; i < N; i++) // i是子列左端位置
    {
        for (int j = i; j < N; j++) // j是子列右端位置
        {
            ThisSum = 0; // A[i]到A[j]的子列和
            for (int k = i; k <= j; k++)
                ThisSum += A[k];
            if (ThisSum > MaxSum)
                MaxSum = ThisSum;
        }
    }
    return MaxSum;
}

// 2. 暴力法（优化）
int MaxSubseqSum2(int A[], int N)
{
    int ThisSum, MaxSum = 0;
    for (int i = 0; i < N; i++)
    {
        ThisSum = 0;
        for (int j = i; j < N; j++)
        {
            ThisSum += A[j]; // 对于相同的i不同的j。只需要在j-1循环的基础上累加1项即可
            if (ThisSum > MaxSum)
                MaxSum = ThisSum;
        }
    }
    return MaxSum;
}

// 3. 分而治之

inline int Max3(int A, int B, int C)
{
    /* 返回3个整数中的最大值 */

    return A > B ? A > C ? A : C : B > C ? B :
                                           C;
}

int DivideAndConquer(int List[], int left, int right)
{
    /* 分治法求List[left]到List[right]的最大子列和 */

    int MaxLeftSum, MaxRightSum; // 左右两边的最大值
    int MaxLeftBorderSum, MaxRightBorderSum; // 存放跨分界线的结果

    int LeftBorederSum, RightBorderSum;
    int center, i;

    if (left == right)
    {
        // 递归终止条件：子列只有一个数字
        if (List[left] > 0)
            return List[left];
        else
            return 0;
    }

    // 找到中分点
    center = (left + right) / 2;
    // 递归求两边子列的最大和
    MaxLeftSum = DivideAndConquer(List, left, center);
    MaxRightSum = DivideAndConquer(List, center + 1, right);

    // 求跨分界线的最大子列和
    MaxLeftBorderSum = 0;
    LeftBorederSum = 0;
    for (i = center; i >= left; i--)
    {
        // 从中线向左扫描
        LeftBorederSum += List[i];
        if (LeftBorederSum > MaxLeftBorderSum)
            MaxLeftBorderSum = LeftBorederSum;
    } // 左边扫描结束
    // 同理右边扫描
    MaxRightBorderSum = 0;
    RightBorderSum = 0;
    for (i = center + 1; i <= right; i++)
    {
        RightBorderSum += List[i];
        if (RightBorderSum > MaxRightBorderSum)
            MaxRightBorderSum = RightBorderSum;
    }

    return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}

int MaxSubseqSum3(int A[], int N)
{
    return DivideAndConquer(A, 0, N - 1);
}

// 4. 在线处理
int MaxSubseqSum4(int A[], int N)
{
    int ThisSum = 0;
    int MaxSum = 0;
    for (int i = 0; i < N; i++)
    {
        ThisSum += A[i]; // 向右累加
        if (ThisSum > MaxSum)
            MaxSum = ThisSum;
        else if (ThisSum < 0) // 当前子列和为负，则不可能使后面的部分增大
            ThisSum = 0;
    }
    return MaxSum;
}

#include <iostream>

int main(int argc, char* argv[])
{
    using namespace std;
    int A[] = { 4, -3, 5, -2, -1, 2, 6, -2 };
    int N = 8;
    int ret1 = MaxSubseqSum1(A, N);
    int ret2 = MaxSubseqSum2(A, N);
    int ret3 = MaxSubseqSum3(A, N);
    int ret4 = MaxSubseqSum4(A, N);

    cout << "MaxSubseqSum1: " << ret1 << endl;
    cout << "MaxSubseqSum2: " << ret2 << endl;
    cout << "MaxSubseqSum3: " << ret3 << endl;
    cout << "MaxSubseqSum4: " << ret4 << endl;
    return 0;
}

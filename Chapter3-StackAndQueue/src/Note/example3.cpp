// File:    example3.cpp
// Author:  csh
// Date:    2021/02/21
// ===================


#include <iostream>

double w[10];

// 背包问题的递归算法
bool knap(int s, int n)
{
    using std::cout;
    if(s == 0)
        return true;
    if((s < 0) || (s > 0 && n < 1))
        return false;
    if(knap(s-w[n-1], n-1))
    {
        cout << w[n-1];
        return true;
    }
    else return knap(s, n-1);
}


// 背包问题的非递归实现
/*
   背包递归规则有两种
   规则1：若w[n-1]包含在解中，求解knap(s-w[n-1], n-1)
   规则2：若w[n-1]不包含在解中，求解knap(s, n-1)

   knap算法中有两处递归规则，因此加上递归出口返回地址共有3种情况：
   (1) 计算knap(s,n)完毕返回到调用本函数的其他函数
   (2) 计算knap(s-w[n-1], n-1)完毕，返回本调用函数继续计算
   (3) 计算knap(s, n-1)完毕，返回到本调用函数继续计算
   rd分别用0,1,2表示上述三种情况
*/

#include <stack>

using std::stack;
using std::cout;
using std::endl;
struct KnapNode
{
    int s;
    int rd;
};

KnapNode tmp, x;

stack<KnapNode> Stack;

bool nonRecKnap(int s, int n)
{
    int t, n0 = n;
    bool k = false;

    tmp.s = s;
    tmp.rd = 0;
    Stack.push(tmp);

    while(!Stack.empty())
    {
        t = Stack.size();
        tmp = Stack.top();
        while(tmp.s >= 0 && (tmp.s <= 0 || n0 > t))
        {   // 判断栈顶元素是否满足递归出口条件

            if(tmp.s == 0)
            {
                k = true;
                break;
            }else
            { // 尚未到达递归出口前，按规则1进行压栈
                x.s = tmp.s - w[n0 - 1 - t];
                x.rd = 1;
                Stack.push(x);
            }
            t = Stack.size();
            tmp = Stack.top();
        }
        while(!Stack.empty())
        {
            tmp = Stack.top();
            Stack.pop();
            t = Stack.size();
            if(tmp.rd == 0)                 // 算法结束
                return k;
            if(tmp.rd == 1){                // 从规则1返回
                if(k == true)
                    cout << w[n0 - 1 - t] << endl;
                else
                { // 否则回溯，采用规则2进栈
                    x = Stack.top();
                    tmp.s = x.s;
                    tmp.rd = 2;
                    Stack.push(tmp);
                    break;
                }
            }
            
        }
    }
    return k;
}

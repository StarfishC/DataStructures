// File:    2-2-13.cpp
// Author:  csh
// Date:    2020/06/12
// ===================



// 递归实现
int fib(int n){
    if(n > 1)
        return fib(n-1) + fib(n-2);
    else if(n == 1)
        return 1;
    else return 0;
}

// 非递归实现
#include <stack>

typedef struct elem{
    int rt, cn, tn, res;
}ELEM;
/*
   rt表示返回类型，若rt=1，表示调用了第一个递归fib(n-1)，若rt=2，
   表示调用了第二个递归fib(n-2)，若rt=3，表示求得fib(n)的值。
   cn表示当前n的值，tn暂存fib(n-1)的值（即第一个递归的值），res记录fib(cn)的值
*/

int fib2(int n){
    using std::stack;
    stack<ELEM> S;
    ELEM t1;

    // t1表明计算fib(n)，将它压栈
    t1.rt = 0;
    t1.cn = n;
    t1.tn = -1;
    t1.res = -1;
    S.push(t1);
    while(!S.empty()){
        t1 = S.top();
        S.pop();
        if(t1.rt == 0){
            if(t1.cn < 0)               // n不合法
                break;
            if(t1.cn <= 1){             // 表明n=1或n=0
                t1.res = t1.cn;         // fib(n)的结果
                t1.rt = 3;              // 表示已求得fib(n)的值
                S.push(t1);
            }else{
                t1.rt = 1;
                S.push(t1);
                // 调用第一个递归fib(cn-1)
                ELEM t2;
                t2.rt = 0;
                t2.cn = t1.cn - 1;
                t2.tn = -1;
                t2.res = -1;
                S.push(t2);
            }
            continue;
        }
        if(t1.rt == 3){
            if(S.empty())               // 栈空，表明应该返回结果
                return t1.res;
            ELEM t2 = S.top();
            S.pop();
            if(t2.rt == 1){             // t2.rt=1，表明t2调用的第一个递归fib(n-1)返回了结果
                t2.tn = t1.res;
                t2.rt = 2;
                S.push(t2);
                // 调用t2的第二个递归fib(cn-2)
                ELEM t3;
                t3.rt = 0;
                t3.cn = t2.cn - 2;
                t3.tn = -1;
                t3.res = -1;
                S.push(t3);
                continue;
            }
            if(t2.rt == 2){             // t2.rt=2，表明t2调用的第一个递归fib(n-2)返回了结果
                t2.rt = 3;
                t2.res = t2.tn + t1.res;
                S.push(t2);
                continue;
            }
        }
    }
    return -1;                          // 表示程序出错
}

// 非递归的循环迭代法
int fib3(int n){
    if(n < 0)
        return -1;
    if(n <= 1)
        return n;
    int a = 0, b = 1, c;
    for(int i = 1; i < n; i++){
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// File:    2-5-13.cpp
// Author:  csh
// Date:    2020/06/12
// ===================


#include <iostream>
#include <stack>


// 递归实现
int fib1(int n){
    if(n > 1)
        return fib1(n-1) + fib1(n-2);
    else if(n == 1)
        return 1;
    else return 0;
}

// 非递归栈实现
int fib2(int n){
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else{
        std::stack<int> st;
        // 除了f(0),f(1)压栈0,1以外，其余压栈为-1
        while(n > 1){
            st.push(-1);
            n--;
        }
        st.push(1); // f(1);
        st.push(0);
        // 出栈两个求和以及一个待求的数，压栈求和以及第二个出栈的数
        // 如求f(2)，弹出0,1以及一个-1，压栈0+1,1
        int tmp1, tmp2;
        while(st.size() > 2){
            tmp1 = st.top();
            st.pop();
            tmp2 = st.top();
            st.pop();
            st.pop();       // 弹出一个-1，即待求数的位置
            st.push(tmp1 + tmp2);
            st.push(tmp2);
        }
        // 最后剩两个数，栈底的数即为所求的结果
        st.pop();
        return st.top();
    }
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


int main(){
    using namespace std;
    int ret1, ret2, ret3;
    ret1 = fib1(6);
    ret2 = fib2(6);
    ret3 = fib3(6);
    cout << "ret1: " << ret1 << endl;
    cout << "ret2: " << ret3 << endl;
    cout << "ret3: " << ret3 << endl;
    return 0;
}

// File:    2-5-3.cpp
// Author:  csh
// Date:    2020/08/23
// ===================



#include <stack>
#include <iostream>
#include "../headers/queue.hpp"

using namespace std;

// (1) 使用额外两个栈
/*
    原栈s，s出栈到s1，s1再出栈到s2，s2再出栈给s
*/
void ReverseStack1(stack<int> &s){
    stack<int> s1, s2;
    while(!s.empty()){
        s1.push(s.top());
        s.pop();
    }
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
    while(!s2.empty()){
        s.push(s2.top());
        s2.pop();
    }
}


// (2) 使用额外一个队列
/*
   原栈s出栈到队列q，队列再出队入栈s
   导入的队列头文件出队的元素是出队函数的参数(引用)，故需要临时变量
   若队列出队有返回值，则不需要临时变量
*/
void ReverseStack2(stack<int> &s){
    ArrQueue<int> q = ArrQueue<int>(s.size());
    int tmp;
    while(!s.empty()){
        q.enQueue(s.top());
        s.pop();
    }
    while(!q.isEmpty()){
        q.deQueue(tmp);
        s.push(tmp);
    }
}


// (3) 使用额外一个栈，加一些非数组变量
/*
   用临时变量存储栈顶元素，剩下元素原栈s弹出并入栈s2，最后将临时变量入栈，
   即完成一次逆置，循环执行（每次出栈次数减一）
*/
void ReverseStack3(stack<int> &s){
    stack<int> s2 = stack<int>();
    int tmp;
    for(auto count = s.size(); count > 0; count--){
        tmp = s.top();
        s.pop();
        for(int i = 1; i < count; i++){
            s2.push(s.top());
            s.pop();
        }
        s.push(tmp);
        while(!s2.empty()){
            s.push(s2.top());
            s2.pop();
        }
    }
}


int main(){
    stack<int> s = stack<int>();
    s.push(1);
    s.push(3);
    s.push(5);
    ReverseStack3(s);
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    return 0; 
}

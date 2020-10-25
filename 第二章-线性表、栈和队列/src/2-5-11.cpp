// File:    2-3-11.cpp
// Author:  csh
// Date:    2020/07/18
// ===================


#include <iostream>

#define MAXSIZE 4

typedef struct{
    int data[MAXSIZE];
    int top;
}SqStack;


// 初始化顺序栈
void initStack(SqStack &st){
    st.top = -1;
}

// 判断栈空
bool Sempty(SqStack st){
    if(st.top == -1)
        return true;
    return false;
}

bool PUSH(SqStack &st, int x){
    if(st.top == MAXSIZE - 1)
        return false;
    else{
        st.data[++st.top] = x;
        return true;
    }
}

bool POP(SqStack &st,int &x){
    if(Sempty(st))
        return false;
    else{
        x = st.data[st.top--];
        return true;
    }
}

// 入队
// s1为入队栈，s2为出队栈
bool enqueue(SqStack &s1, SqStack &s2, int x){
    int tmp;
    if(s1.top == MAXSIZE -1){
        // 栈s1满，判断s2是否为空
        if(!Sempty(s2))         // s2非空，不能入栈
            return false;
        else{                   // s2为空，s1退栈，元素压栈s2，新元素在入栈s1
            while(!Sempty(s1)){
                POP(s1, tmp);
                PUSH(s2, tmp);
            }
            PUSH(s1,x);
            return true;
        }
    }else{
        PUSH(s1, x);
        return true;
    }
}


// 出队
bool dequeue(SqStack &s1, SqStack &s2, int &x){
    int y;
    if(!Sempty(s2)){
        POP(s2, x);
        return true;
    }else{
        if(Sempty(s1))      // s1空，s2空，无元素
            return false;
        else{
            while(!Sempty(s1)){
                POP(s1,y);
                PUSH(s2, y);
            }
            POP(s2, x);
            return true;
        }
    }
}

// 判断队列是否为空
bool queue_empty(SqStack s1, SqStack s2){
    if(Sempty(s1) && Sempty(s2))
        return true;
    else
        return false;
}

int main(){
    using std::cout;
    using std::endl;
    SqStack stack1, stack2;
    initStack(stack1);
    initStack(stack2);

    enqueue(stack1, stack2, 1);
    enqueue(stack1, stack2, 2);
    enqueue(stack1, stack2, 3);
    enqueue(stack1, stack2, 4);
    enqueue(stack1, stack2, 5);
    enqueue(stack1, stack2, 7);
    enqueue(stack1, stack2, 6);

    int x;
    dequeue(stack1, stack2, x);
    cout << x << endl;
    dequeue(stack1, stack2, x);
    cout << x << endl;
    return 0;
}

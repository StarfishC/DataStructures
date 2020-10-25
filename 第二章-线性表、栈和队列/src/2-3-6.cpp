// File:    2-3-6.cpp
// Author:  csh
// Date:    2020/08/23
// ===================


#include <iostream>
using namespace std;

class Stack{
    private:
        int lfirst;             // 左边数组标志
        int rfirst;             // 右边数组标志
        int *qu;
        int size;               // 数组最大长度
    public:
        Stack(int num);
        ~Stack();
        inline bool isEmpty();
        inline bool isFull();   // 是否已满
        bool lpush(int item);   // 左边入栈
        bool rpush(int item);   // 右边入栈
        bool lpop(int &item);   // 左边出栈
        bool rpop(int &item);   // 右边出栈
};

Stack::Stack(int num){
    size = num;
    qu = new int[size];
    lfirst = -1;
    rfirst = size;
}

Stack::~Stack(){
    delete [] qu;
}

bool Stack::isEmpty(){
    return (lfirst == -1 && rfirst == size);
}

bool Stack::isFull(){
    return lfirst + 1 == rfirst;
}

bool Stack::lpush(int item){
    if(isFull()){
        cout << "栈满，不能入栈" << endl;
        return false;
    }
    qu[++lfirst] = item;
    return true;
}

bool Stack::rpush(int item){
    if(isFull()){
        cout << "栈满，不能入栈" << endl;
        return false;
    }
    qu[--rfirst] = item;
    return true;
}

bool Stack::lpop(int &item){
    if(isEmpty()){
        cout << "栈空，不能出栈" << endl;
        return false;
    }
    item = qu[lfirst--];
    return true;
}

bool Stack::rpop(int &item){
    if(isEmpty()){
        cout << "栈空，不能出栈" << endl;
        return false;
    }
    item = qu[rfirst++];
    return true;
}


int main(){
    Stack q = Stack(5);
    q.lpush(1);
    q.lpush(2);
    q.rpush(3);
    q.rpush(4);
    q.rpush(5);

    int item;
    q.lpop(item);
    cout << "lpop1: " << item << endl;
    q.lpop(item);
    cout << "lpop2: " << item << endl;
    q.rpop(item);
    cout << "rpop1: " << item << endl;
    q.rpop(item);
    cout << "rpop2: " << item << endl;
    return 0;
}

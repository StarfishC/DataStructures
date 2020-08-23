// File:    2-5-6.cpp
// Author:  csh
// Date:    2020/08/23
// ===================


#include <iostream>
using namespace std;

class Queue{
    private:
        int lfirst;             // 左边数组标志
        int rfirst;             // 右边数组标志
        int *qu;
        int size;               // 数组最大长度
    public:
        Queue(int num);
        ~Queue();
        bool isEmpty();
        bool isFull();          // 是否已满
        bool lpush(int item);   // 左边入栈
        bool rpush(int item);   // 右边入栈
        bool lpop(int &item);   // 左边出栈
        bool rpop(int &item);   // 右边出栈
};

Queue::Queue(int num){
    size = num;
    qu = new int[size];
    lfirst = -1;
    rfirst = size;
}

Queue::~Queue(){
    delete [] qu;
}

bool Queue::isEmpty(){
    return (lfirst == -1 && rfirst == size);
}

bool Queue::isFull(){
    return lfirst + 1 == rfirst;
}

bool Queue::lpush(int item){
    if(isFull()){
        cout << "栈满，不能入栈" << endl;
        return false;
    }
    qu[++lfirst] = item;
    return true;
}

bool Queue::rpush(int item){
    if(isFull()){
        cout << "栈满，不能入栈" << endl;
        return false;
    }
    qu[--rfirst] = item;
    return true;
}

bool Queue::lpop(int &item){
    if(isEmpty()){
        cout << "栈空，不能出栈" << endl;
        return false;
    }
    item = qu[lfirst--];
    return true;
}

bool Queue::rpop(int &item){
    if(isEmpty()){
        cout << "栈空，不能出栈" << endl;
        return false;
    }
    item = qu[rfirst++];
    return true;
}


int main(){
    Queue q = Queue(5);
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

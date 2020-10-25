// File:    2-3-1.cpp
// Author:  csh
// Date:    2020/08/23
// ===================


#include <iostream>

using namespace std;

template <typename T>
class LoopQueue{
    private:
        int mSize;                  // 存放队列的数组大小
        int front;                  // 队首
        int rear;                   // 队尾
        T *qu;                      // 队列数组
    public:
        LoopQueue(int size){
            mSize = size + 1;
            qu = new T[mSize];
            front = rear = 0;
        }
        ~LoopQueue(){
            delete [] qu;
        }
        void clear(){               // 清空队列
            front = rear;
        }
        inline bool isEmpty();      // 队列是否为空
        inline bool isFull();       // 队列是否已满
        bool enQueue(const T &item);// 入队
        bool deQueue(T &item);      // 出队
        bool deRear(T &item);       // 队尾删除
        bool enFront(const T &item);// 队首插入
        void showAll();             // 显示队列所有元素
};


template <typename T>
bool LoopQueue<T>::isEmpty(){
    return front == rear;
}

template <typename T>
bool LoopQueue<T>::isFull(){
    return (rear + 1) % mSize == front;
}

template <typename T>
bool LoopQueue<T>::enQueue(const T &item){
    if(isFull()){
        cout << "队列满，不能入队" << endl;
        return false;
    }
    qu[rear] = item;
    rear = (rear + 1) % mSize;
    return true;
}

template <typename T>
bool LoopQueue<T>::deQueue(T &item){
    if(isEmpty()){
        cout << "队列空，不能出队" << endl;
        return false;
    }
    item = qu[front];
    front = (front + 1) % mSize;
    return true;
}

template <typename T>
bool LoopQueue<T>::deRear(T &item){
    if(isEmpty()){
        cout << "队列空，不能队尾出队" << endl;
        return false;
    }
    item = qu[rear-1];
    rear = (rear + mSize - 1) % mSize;
    return true;
}

template <typename T>
bool LoopQueue<T>::enFront(const T &item){
    if(isFull()){
        cout << "队列满，不能队首入队" << endl;
        return false;
    }
    front = (front + mSize - 1) % mSize;
    qu[front] = item;
    return true;
}

template <typename T>
void LoopQueue<T>::showAll(){
    int tmp = front;
    while(tmp != rear){
        cout << qu[tmp] << " ";
        tmp = (tmp + 1) % mSize;
    }
    cout << endl;
}


int main(){
    LoopQueue<int> lq = LoopQueue<int>(10);
    lq.enQueue(1);
    lq.enQueue(2);
    lq.enQueue(3);
    lq.enQueue(4);
    int item;
    lq.deQueue(item);
    lq.showAll();
    lq.enFront(0);
    lq.deRear(item);
    lq.showAll();
    return 0;
}

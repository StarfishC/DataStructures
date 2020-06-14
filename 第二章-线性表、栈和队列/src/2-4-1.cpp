// File:    2-4-1.cpp
// Author:  csh
// Date:    2020/06/14
// ===================

#include <cassert>
#include <cstdlib>
#include <iostream>

template <typename T>
class Queue{
    private:
        T *queue;                   // 队列数组
        int front;                  // 队首
        int rear;                   // 队尾
        int maxSize;                // 队列大小
    public:
        Queue(const int size){
            maxSize = size+1;
            queue = new T[maxSize];
            assert(queue != NULL);
            front = rear = 0;
        }
        ~Queue(){
            delete []queue;
        }
        bool deleteRear(T &value);  // 队尾删除
        bool insertFront(T value);  // 队首插入
        bool isEmpty();             // 判断队列是否为空
        bool isFull();              // 判断队列是否已满
        void showAll();             // 显示队列所有元素
};


template <typename T>
bool Queue<T>::deleteRear(T &value){
    if(isEmpty())
        return false;
    rear = (rear - 1 + maxSize) % maxSize;
    value = queue[rear];
    return true;
}

template <typename T>
bool Queue<T>::insertFront(T value){
    if(isFull())
        return false;
    front = (front - 1 + maxSize) % maxSize;
    queue[front] = value;
    return true;
}

template <typename T>
bool Queue<T>::isEmpty(){
    return rear == front;
}

template <typename T>
bool Queue<T>::isFull(){
    return (rear + 1) % maxSize == front;
}

template <typename T>
void Queue<T>::showAll(){
    using std::cout;
    using std::endl;
    if(isEmpty()){
        cout << "空队列" << endl;
        return;
    }
    int temp = front;
    while(temp != rear){
        cout << queue[temp] << endl; 
        temp = (temp + 1) % maxSize;
    }
}


int main(){
    using namespace std;
    Queue<int> q = Queue<int>(5);
    q.insertFront(1);
    q.insertFront(2);
    q.insertFront(3);
    int value;
    q.deleteRear(value);
    q.showAll();
    cout << "value:" << value << endl;
    return 0;
}

// File:    队列.cpp
// Author:  csh
// Date:    2020/05/24
// ===================


#include <iostream>
#include "../utils/linear.hpp"


// ****************************** 队列的顺序存储 *******************************//
template <typename T>
class ArrQueue{
    private:
        int mSize;                          // 存放队列的数组大小
        int front;                          // 表示队首的位置
        int rear;                           // 表示队尾的位置
        T *qu;                              // 存放队列元素的数组
    public:
        ArrQueue(int size);                 // 构造函数
        ~ArrQueue();                        // 析构函数
        void clear();                       // 清空队列
        bool enQueue(const T item);         // 入队
        bool deQueue(T &item);              // 出队
        bool getFront(T &item);             // 返回队首元素
        bool isEmpty();                     // 判断队列是否为空
        bool isFull();                      // 判断队列是否已满
        int length();                       // 队列长度
};

template <typename T>
ArrQueue<T>::ArrQueue(int size){
    mSize = size + 1;
    qu = new T[mSize];
    front = rear = 0;
}

template <typename T>
ArrQueue<T>::~ArrQueue(){
    delete [] qu;
}

template <typename T>
void ArrQueue<T>::clear(){
    front = rear;
}

template <typename T>
bool ArrQueue<T>::isFull(){
    if((rear+1) % mSize == front)
        return true;
    return false;
}

template <typename T>
bool ArrQueue<T>::isEmpty(){
    return front == rear;
}

template <typename T>
bool ArrQueue<T>::enQueue(const T item){
    using namespace std;
    if(isFull()){
        cout << "队列已满，不能入队" << endl;
        return false;
    }
    qu[rear] = item;
    rear = (rear+1) % mSize;
    return true;
}

template <typename T>
bool ArrQueue<T>::deQueue(T &item){
    using namespace std;
    if(isEmpty()){
        cout << "队列为空，不能出队" << endl;
        return false;
    }
    item = qu[front];
    front = (front+1) % mSize;
    return true;
}

template <typename T>
bool ArrQueue<T>::getFront(T &item){
    using namespace std;
    if(isEmpty()){
        cout << "队列为空，无元素" << endl;
        return false;
    }
    item = qu[front];
    return true;
}

template <typename T>
int ArrQueue<T>::length(){
    int len;
    if(isEmpty())
        len = 0;
    else if(front <= rear)
        len = rear - front;
    else
        len = mSize + rear - front;
}

// *****************************************************************************//


// ****************************** 队列的链式存储 *******************************//
template <typename T>
class LinkQueue{
    private:
        int size;                   // 队列的元素个数
        Link<T> *front;             // 队首指针
        Link<T> *rear;              // 队尾指针
    public:
        LinkQueue();
        ~LinkQueue();
        void clear();               // 清空队列元素
        bool enQueue(const T item); // 入队
        bool deQueue(T &item);      // 出队
        bool getFront(T &itme);     // 返回队首元素
        bool isEmpty();             // 队列是否为空
        int length();               // 队列长度
};

template <typename T>
LinkQueue<T>::LinkQueue(){
    size = 0;
    front = rear = NULL;
}

template <typename T>
LinkQueue<T>::~LinkQueue(){
    clear();
}

template <typename T>
void LinkQueue<T>::clear(){
    while(front != NULL){
        rear = front;
        front = front->next;
        delete rear;
    }
    rear = NULL;
    size = 0;
}

template <typename T>
bool LinkQueue<T>::enQueue(const T item){
    if(isEmpty())
        front = rear = new Link<T>(item, NULL);
    else{
        rear = new Link<T>(item, NULL);
        rear = rear->next;
    }
    size++;
    return true;
}

template <typename T>
bool LinkQueue<T>::deQueue(T &item){
    using namespace std;
    Link<T> *tmp;
    if(isEmpty()){
        cout << "队列为空，不能出队" << endl;
        return false;
    }
    item = front->data;
    tmp = front;
    front = front->next;
    delete tmp;
    if(front == NULL)
        rear = NULL;
    size--;
    return true;
}

template <typename T>
bool LinkQueue<T>::getFront(T &item){
    using namespace std;
    if(isEmpty()){
        cout << "队列为空，无元素" << endl;
        return false;
    }
    item = front->data;
    return true;
}

template <typename T>
bool LinkQueue<T>::isEmpty(){
    return size == 0;
}

template <typename T>
int LinkQueue<T>::length(){
    // return size;
    int len = 0;
    for(Link<T> *tmp = front; front != rear; tmp = tmp->next)
        len ++;
    return len;
}

// *****************************************************************************//

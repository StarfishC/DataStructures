// File:    队列.cpp
// Author:  csh
// Date:    2020/08/23
// ===================


#include <iostream>

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


// ****************************** 队列的链式存储 *******************************//
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

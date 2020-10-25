// File:    队列.cpp
// Author:  csh
// Date:    2020/08/23
// ===================


#ifndef _Queue_H
#define _Queue_H

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
        virtual ~ArrQueue();                // 析构函数
        void clear();                       // 清空队列
        bool enQueue(const T item);         // 入队
        bool deQueue(T &item);              // 出队
        bool getFront(T &item);             // 返回队首元素
        inline bool isEmpty();              // 判断队列是否为空
        inline bool isFull();               // 判断队列是否已满
        int length();                       // 队列长度
};

// *****************************************************************************//


// ****************************** 队列的链式存储 *******************************//
template <typename T>
class Link{
    public:
        T data;                         // 数字域
        Link<T> *next;                  // 指针域，指向后继结点的指针

        Link(const T info, Link<T>* nextLink=nullptr):
            data{info}, next{nextLink}{}
        Link(Link<T>* nextLink=nullptr): next{nextLink}{}
};


template <typename T>
class LinkQueue{
    private:
        int size;                   // 队列的元素个数
        Link<T> *front;             // 队首指针
        Link<T> *rear;              // 队尾指针
    public:
        LinkQueue();
        virtual ~LinkQueue();
        void clear();               // 清空队列元素
        bool enQueue(const T item); // 入队
        bool deQueue(T &item);      // 出队
        bool getFront(T &itme);     // 返回队首元素
        bool isEmpty();             // 队列是否为空
        int length();               // 队列长度
};


#include "queue.cpp"
#endif

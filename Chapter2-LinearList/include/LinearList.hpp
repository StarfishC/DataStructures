// File:    LinearList.hpp
// Author:  csh
// Date:    2021/02/20
// ===================


#ifndef __LINEARLIST_H_
#define __LINEARLIST_H_

// 顺序表
template <typename T>
class ArrList
{
    protected:
        T *List;                                    // 存储顺序表的数组
        int MaxSize;                                // 顺序表的最大长度
        int CurLen;                                 // 顺序表的当前长度
    public:
        ArrList(const int size):
            MaxSize(size), List(new T[size]), CurLen(0){}
        virtual ~ArrList()
        {
            delete [] List;
        }
        void clear();                               // 清除顺序表的内容，成为空表
        int length();                               // 返回顺序表的长度
        bool isEmpty();                             // 判断线性表是否为空
        bool isFull();                              // 判断线性表是否已满
        bool append(const T value);                 // 表尾添加一个元素
        bool insert(const int p, const T value);    // 位置p插入一个元素
        bool remove(const int p);                   // 移除位置p上的元素
        bool setValue(const int p, const T value);  // 修改位置p的元素值
        bool getValue(const int p, T &value);       // 返回位置p的元素给value
        bool getPos(const T value, int &p);         // 查找值为value的元素，并返回第1次出现的位置
        void showAll();                             // 显示所有元素
};


// 单链表
template <typename T>
class Link
{
    public:
        T Data;             // 数字域
        Link<T>* Next;      // 指针域

        Link(const T info, Link<T>* nextLink=nullptr):
            Data(info), Next(nextLink){}
        Link(Link<T>* nextLink=nullptr): Next(nextLink){}
};


// 单链表
template <typename T>
class LinkList
{
    protected:
        Link<T> *Head, *Tail;                   // 单链表的头尾结点
    public:
        LinkList(): Head(new Link<T>), Tail(Head){};
        virtual ~LinkList()
        {
            Link<T> *tmp;
            while(Head != nullptr)
            {
                tmp = Head;
                Head = Head->Next;
                delete tmp;
            }
        }

        Link<T> *SetPos(const int p);           // 返回链表指向第p个元素的指针
        bool isEmpty();                         // 判断链表是否为空
        void clear();                           // 清空链表内容
        int length();                           // 返回链表当前长度
        bool append(const T value);             // 表尾添加新元素
        bool insert(const int p, const T value);// 位置p插入新元素value
        bool remove(const int p);               // 移除位置p元素
        bool getValue(const int p, T &value);   // 返回位置p的元素给value
        bool getPos(int &p, const T value);     // 返回值为value的位置
        void showAll();                         // 显示链表的所有元素
};

#include "LinearList.cpp"
#endif

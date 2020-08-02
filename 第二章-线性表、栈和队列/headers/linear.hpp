// File:    linear.hpp
// Author:  csh
// Date:    2020/05/24
// ===================


#ifndef _Linear_H
#define _Linear_H

#include <stddef.h>

template <typename T>
class ArrList{
    private:
        T *aList;                                   // 存储顺序表的实例
        int maxSize;                                // 顺序表的最大长度
        int curLen;                                 // 顺序表的当前长度
    public:
        ArrList(const int size){                    // 创建一个大小为size的顺序表
            maxSize = size;
            aList = new T[maxSize];
            curLen = 0;
        }
        ~ArrList(){
            delete [] aList;
        }
        void clear();                               // 清除顺序表内容，成为空表
        int length();                               // 返回顺序表长度
        bool isEmpty();                             // 判断线性表是否为空
        bool isFull();                              // 判断线性表是否已满
        bool append(const T value);                 // 表尾添加一个元素value
        bool insert(const int p, const T value);    // 位置p上插入一个元素value
        bool remove(const int p);                   // 移除位置p上的元素
        bool setValue(const int p, const T value);  // 修改位置p的元素为value
        bool getValue(const int p, T &value);       // 把位置p的元素返回到变量value中
        bool getPos(int &p, const T value);         // 查找值为value的元素，返回第一次出现的位置
        void showAll();                             // 显示所有元素
};


// 链表节点
template <typename T>
class Link{
    public:
        T data;             // 数字域
        Link<T> *next;      // 指针域，指向后继结点的指针

        Link(const T info, Link<T>* nextLink=NULL){
            this->data = info;
            this->next = nextLink;
        }
        Link(Link<T>* nextLink=NULL){
            this->next = nextLink;
        }
};

// 单链表
template <typename T>
class LinkList{
    protected:
        Link<T> *head, *tail;                   // 单链表的头尾结点，添加尾结点是为了操作方便
        Link<T> *setPos(const int p);           // 返回线性表指向第p个元素的指针值
    public:
        LinkList();                             // 构造函数
        ~LinkList();                            // 析构函数
        bool isEmpty();                         // 判断链表是否为空
        void clear();                           // 将链表内容清除，成为空表
        int length();                           // 返回链表当前实际长度
        bool append(const T value);             // 表尾添加一个元素
        bool insert(const int p, const T value);// 在位置p上插入一个元素
        bool remove(const int p);               // 删除位置p上的元素
        bool getValue(const int p, T &value);   // 返回位置p的元素值，存放到value中
        bool getPos(int &p, const T value);     // 查找值为value的元素，并返回第一次出现的位置
        void showAll();                         // 显示链表的所有元素
};

#include "linear.cpp"
#endif

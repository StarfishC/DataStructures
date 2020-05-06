// File:    1-2-1.cpp
// Author:  csh
// Date:    2020/05/06
// ===================


#include <cstdlib>


template <typename T>
class ListNode{                 // 链表
    public:
       T data;                  // 链表元素
       ListNode<T> *next;       // 指向后一个节点指针
       ListNode(){next = NULL;} // 构造函数
};

template <typename T>
class ListAddr{                 // 用于存放地址的新链表
    public:
        ListNode<T> *address;   // 存放地址
        ListAddr<T> *next;      // 下一个地址指针 
        ListAddr(){next = NULL;}
};

template <typename T>
ListAddr<T>* findElem(T data, ListNode<T> *p){
    ListNode<T> *tmp = p;
    ListAddr<T> *ret;           // 存放结果
    ret->next = NULL;
    while(tmp != NULL){
        if(tmp->data == data){
            ret->next = new ListAddr<T>();
            ret->next->address = tmp;
            ret = ret->next;
            ret->next = NULL;
        }
        tmp = tmp->next;
    }
    return ret;
}

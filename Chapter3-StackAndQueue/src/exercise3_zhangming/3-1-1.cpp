// File:    3-1-1.cpp
// Author:  csh
// Date:    2020/05/30
// Update:  2021/02/27
// ===================


#include <iostream>
#include "../../include/LinearList.hpp"


using namespace std;

template <typename T>
class ListNode                              // 地址链表节点,不能使用原链表的节点，不然会破环原链表
{
    public:
        Link<T> *L;                         // 指向单链表节点的指针
        ListNode<T> *Next;                  // 指向下一个地址链表节点的指针

        ListNode(Link<T> *l = nullptr, ListNode<T> *next = nullptr):
            L(l), Next(next){}
};

template <typename T>
class LinkAddr                              // 存放地址的链表
{
    public:
        ListNode<T> *Head;                  // 地址链表头指针

        LinkAddr(): Head(new ListNode<T>()){}
        ~LinkAddr()
        {
            ListNode<T> *tmp;
            while(Head){
                tmp = Head;
                Head = Head->Next;
                delete tmp;
            }
        }
        void find(T a, LinkList<T> *X);     // 找到值为a的节点,并添加到链表
        void showAll();                     // 显示所有元素
};

template <typename T>
void LinkAddr<T>::find(T a, LinkList<T> *X){
    Link<T> *tmp = X->SetPos(0);    // 获取第一个结点
    while(tmp != nullptr)
    {
        if(tmp->Data == a)
        {
            ListNode<T> *q = new ListNode<T>();
            q->L = tmp;
            q->Next = Head->Next;
            Head->Next = q;
        }
        tmp = tmp->Next;
    }
}

template <typename T>
void LinkAddr<T>::showAll()
{
    ListNode<T> *tmp = Head->Next;
    while(tmp != nullptr)
    {
        cout << tmp->L << "  ";
        cout << (tmp->L)->Data << endl;
        tmp = tmp->Next;
    }
}


int main()
{
    LinkList<int> L = LinkList<int>();
    L.append(2);
    L.append(3);
    L.append(2);
    L.append(3);
    L.showAll();

    LinkAddr<int> Add;
    Add.find(3, &L);
    Add.showAll();
}

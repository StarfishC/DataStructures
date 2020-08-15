// File:    2-2-1.cpp
// Author:  csh
// Date:    2020/05/30
// ===================


#include "../headers/linear.hpp"            // 导入链表头文件
#include <iostream>


using namespace std;

template <typename T>
class ListNode{                             // 地址链表节点,不能使用原链表的节点，不然会破环原链表
    public:
        Link<T>* L;                         // 指向单链表节点的指针
        ListNode<T>* next;                  // 指向下一个地址链表节点的指针
};

template <typename T>
class LinkAddr{                             // 存放地址的链表
    public:
        ListNode<T> *head;                  // 地址链表头指针
        LinkAddr(){
            head = new ListNode<T>;
        };
        ~LinkAddr(){
            ListNode<T> *tmp;
            while(head){
                tmp = head;
                head = head->next;
                delete tmp;
                tmp = head;
            }
        }
        void find(T a, LinkList<T>* p);     // 找到值为a的节点,并添加到链表
        void showAll();                     // 显示所有元素
};

template <typename T>
void LinkAddr<T>::find(T a, LinkList<T>* p){
    Link<T> *tmp = p->getHead()->next;
    while(tmp != NULL){
        if(tmp->data == a){
            ListNode<T> *q = new ListNode<T>;
            q->L = tmp;
            q->next = head->next;
            head->next = q;
        }
        tmp = tmp->next;
    }
}

template <typename T>
void LinkAddr<T>::showAll(){
    ListNode<T> *tmp = head->next;
    while(tmp != NULL){
        cout << tmp->L << "  ";
        cout << (tmp->L)->data << endl;
        tmp = tmp->next;
    }
}


int main(){
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

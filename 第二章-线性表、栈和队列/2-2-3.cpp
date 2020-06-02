// File:    2-2-3.cpp
// Author:  csh
// Date:    2020/05/30
// ===================


#include <iostream>
#include "./utils/linear.hpp"


template <typename T>
class NewLink:public LinkList<T>{
    public:
        Link<T>* invert();                      // 置逆方法
        void showNewLink();                     // 显示置逆后结果
};

template <typename T>
Link<T>* NewLink<T>::invert(){
    Link<T>* tmp = LinkList<T>::getHead();      // 获取原链表头节点
    Link<T>* newHead;                           // 定义两个节点
    Link<T>* tail;
    newHead = NULL;                             // 置逆后链表的头节点
    while(tmp){
        tail = newHead;                         // tail指向置逆链表的头节点
        newHead = tmp;
        tmp = tmp->next;                        // 先移动，再反转newHead保存的当前节点
        newHead->next = tail;
    }
    return newHead;
}

template <typename T>
void NewLink<T>::showNewLink(){
    using namespace std;
    Link<T>* tmp = invert();
    while(tmp != NULL){
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}


int main(){
    using namespace std;
    NewLink<int> a = NewLink<int>();
    a.append(1);
    a.append(2);
    a.append(3);
    a.append(4);
    cout << "origin: ";
    a.showAll();
    cout << endl;
    cout << "invert: ";
    a.showNewLink();

}

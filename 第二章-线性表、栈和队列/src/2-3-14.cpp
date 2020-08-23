// File:    2-3-14.cpp
// Author:  csh
// Date:    2020/08/23
// ===================


#include <iostream>
#include "../headers/linear.hpp"

using namespace std;

template <typename T>
class LoopLink{
    private:
        Link<T> *head, *rear;
        int len;
    public:
        LoopLink();
        ~LoopLink();
        bool isEmpty();
        bool enQueue(T item);
        bool deQueue(T &item);
        void showAll();
};


template <typename T>
LoopLink<T>::LoopLink(){
    head = rear = new Link<T>();
    head->next = head;
    len = 0;
}

template <typename T>
LoopLink<T>::~LoopLink(){
    if(head == rear)
        delete head;
    else{
        Link<T> *tmp;
        tmp = head;
        while(tmp != rear){
            head = head->next;
            delete tmp;
            tmp = head;
        }
        delete tmp;
    }
}

template <typename T>
bool LoopLink<T>::isEmpty(){
    return head == rear;
}

template <typename T>
bool LoopLink<T>::enQueue(T item){
    Link<T> *tmp = new Link<T>(item);
    if(head == rear){
        head->next = tmp;
        tmp->next = head;
        rear = tmp;
        return true;
    }
    rear->next = tmp;
    rear = tmp;
    tmp->next = head;
    len++;
    return true;
}

template <typename T>
bool LoopLink<T>::deQueue(T &item){
    if(isEmpty()){
        cout << "队列空，不能出队" << endl;
        return false;
    }
    Link<T> *tmp;
    tmp = head->next;
    head->next = tmp->next;
    if(tmp == rear)             // 只有一个节点
        rear = head;
    item = tmp->data;
    len--;
    delete tmp;
    return true;
}

template <typename T>
void LoopLink<T>::showAll(){
    Link<T> *tmp;
    tmp = head->next;
    while(tmp != head){
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}


int main(){
    LoopLink<int> lp = LoopLink<int>();
    lp.enQueue(1);
    lp.enQueue(2);
    lp.enQueue(3);
    lp.enQueue(4);
    lp.enQueue(5);
    lp.showAll();
    int item;
    lp.deQueue(item);
    lp.deQueue(item);
    lp.showAll();
    return 0;
}

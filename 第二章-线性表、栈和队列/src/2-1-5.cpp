// File:    2-3-5.cpp
// Author:  csh
// Date:    2020/07/12
// ===================


#include <iostream>
#include "../headers/linear.hpp"

using namespace std;

// 创建一个循环链表类
template <typename T>
class LoopLink{
    protected:
        Link<T> *head;
    public:
        LoopLink(){
            head = new Link<T>;
            head->next = head;
        }
        ~LoopLink(){
            Link<T> *tmp, *next;
            tmp = head->next;           // 取第一个节点
            while(tmp != head){
                next = tmp->next;
                delete tmp; 
                tmp = next;
            }
            delete head;
        }
        bool add(T c){
            Link<T> *tmp;
            tmp = new Link<T>(c);
            // 找到循环链表最后一个节点
            Link<T> *p = head;
            while(p->next != head)
                p = p->next;
            tmp->next = p->next;
            p->next = tmp;
            return true;
        } 
        void showAll(){
            Link<T> *tmp;
            tmp = head->next;
            while(tmp->next != head){
                cout << tmp->data << "  ";
                tmp = tmp->next;
            }
            cout << endl;
        }
};

void split()

int main(){
    LoopLink<int> a;
    a.add(1);
    a.add(2);
    a.add(3);
    a.add(4);
    a.showAll();
    return 0;
}

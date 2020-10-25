// File:    2-3-5.cpp
// Author:  csh
// Date:    2020/07/12
// ===================


#include <iostream>
#include "../headers/linear.hpp"


// 创建一个循环链表类
// 若加入尾指针会更方便
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
        bool addLink(Link<T> *l){
            Link<T> *p = head;
            // 找到循环链表最后一个节点
            while(p->next != head)
                p = p->next;
            l->next = head;
            p->next = l;
            return true;
        }
        bool addValue(T c){
            Link<T> *tmp;
            tmp = new Link<T>(c);
            if(addLink(tmp))
                return true;
            return false;
        }
        void showAll(){
            using std::cout;
            using std::endl;
            Link<T> *tmp;
            tmp = head->next;
            while(tmp != head){
                cout << tmp->data << "  ";
                tmp = tmp->next;
            }
            cout << endl;
        }
};

template <typename T>
class LinkList2:public LinkList<T>{
    public:
        ~LinkList2(){
            Link<T> *tmp;
            while(this->head){
                tmp = this->head;
                this->head = this->head->next;
                delete tmp;
            }
        }
        Link<T>* getHead(){
            return this->head;
        }
        void setHead(){                         // 设置头节点下一个节点为nullptr，方便析构
            this->head->next = nullptr;
        }
};

void split(LinkList2<char>* L, LoopLink<char>* a, LoopLink<char>* d, LoopLink<char>* o){
    Link<char> *tmp = L->getHead()->next;
    L->setHead();
    Link<char> *save;
    while(tmp){
        save = tmp->next;
        if(tmp->data <= '9' && tmp->data >= '0')
            d->addLink(tmp);
        else if((tmp->data <= 'Z' && tmp->data >= 'A') || (tmp->data <= 'z' && tmp->data >= 'a'))
            a->addLink(tmp);
        else
            o->addLink(tmp);
        tmp = save;
    }
}

int main(){
    LinkList2<char> *a = new LinkList2<char>;
    LoopLink<char> *x = new LoopLink<char>();
    LoopLink<char> *y = new LoopLink<char>();
    LoopLink<char> *z = new LoopLink<char>();

    a->append('a');
    a->append('b');
    a->append('2');
    a->append('%');
    a->append('1');
    a->showAll();

    split(a, x, y, z);
    x->showAll();
    y->showAll();
    z->showAll();

    delete a;
    delete x;
    delete y;
    delete z;
    return 0;
}

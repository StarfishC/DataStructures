// File:    2-3-3.cpp
// Author:  csh
// Date:    2020/07/12
// ===================


#include "../headers/linear.hpp"


template <typename T>
class LinkList2:public LinkList<T>{
    public:
        bool deleteMiddleElem(int mink, int maxk);;

};

template <typename T>
bool LinkList2<T>::deleteMiddleElem(int mink, int maxk){
    Link<T> *p, *q, *prev=NULL; 
    if(mink > maxk) return false;
    p = this->getHead();
    prev = p;                   // prev指向头结点
    p = p->next;

    while(p && p->data < maxk){
        if(p->data <= mink){
            prev = p;
            p = p->next;
        }else{                  // 大于Mink
            prev->next = p->next;
            q = p;
            p = p->next;
            free(q);
        }
    }
    return true;
}


int main(){
    LinkList2<int> L = LinkList2<int>();
    L.append(1);
    L.append(3);
    L.append(5);
    L.append(7);
    L.append(9);
    L.deleteMiddleElem(3,9);
    L.showAll();
}

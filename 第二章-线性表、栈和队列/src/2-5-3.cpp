// File:    2-5-3.cpp
// Author:  csh
// Date:    2020/05/30
// ===================


#include "../headers/linear.hpp"


template <typename T>
class NewLink:public LinkList<T>{
    public:
        void invert();                      // 置逆方法
};

template <typename T>
void NewLink<T>::invert(){
    Link<T> *first, *last;
    first = this->head->next;               // first为第一个节点
    this->head->next = nullptr;
    while(first){
        last = first->next;
        first->next = this->head->next;
        this->head->next = first;
        first = last;
    }
}

int main(){
    using namespace std;
    NewLink<int> a = NewLink<int>();
    a.append(1);
    a.append(2);
    a.append(3);
    a.append(4);
    a.showAll();
    a.invert();
    a.showAll();

}

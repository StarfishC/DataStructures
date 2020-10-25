// File:    2-5-2.cpp
// Author:  csh
// Date:    2020/05/30
// ===================


#include <iostream>
#include "../headers/linear.hpp"


template <typename T>
class NewLink:public LinkList<T>{
    public:
        void insert(T value1, T value2){
            using namespace std;
            Link<T> *tmp = this->head;
            int count;
            while(tmp && tmp->next){
                if(tmp->next->data == value1){
                    Link<T> *p = new Link<T>(value2);
                    p->next = tmp->next;
                    tmp->next = p;
                    tmp = p;        // 因加入一个结点，需要指向该结点，才能指向下一个为访问结点
                    count++;
                }
                tmp = tmp->next;
            }
            if(count == 0)
                cout << "No such an element" << endl;
        }
};


int main(){
    NewLink<int> a = NewLink<int>();
    a.append(2);
    a.append(3);
    a.append(3);
    a.append(4);
    a.append(4);
    a.insert(3, 1000);
    a.showAll();
}

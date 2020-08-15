// File:    2-2-5.cpp
// Author:  csh
// Date:    2020/06/02
// ===================


#include "../headers/linear.hpp"
#include <iostream>

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
            tmp = head->next;
            while(tmp != head){
                next = tmp->next;
                delete tmp;
                tmp = next;
            }
            delete head;
        }
        bool addValue(T v){
            Link<T> *tmp;
            tmp = new Link<T>(v);
            // 找最后一个节点
            Link<T> *last = head;
            while(last->next != head)
                last = last->next;
            tmp->next = last->next;
            last->next = tmp;
            return true;
        }
        int length(){
            Link<T> *tmp;
            tmp = head;
            int count = 0;
            while(tmp->next != head){
                tmp = tmp->next;
                count ++;
            }
            return count;
        }
};



int main(){
    using namespace std;
    LoopLink<int> A = LoopLink<int>();
    A.addValue(1);
    A.addValue(2);
    A.addValue(3);

    cout << "A length: " << A.length() << endl;
    return 0;
}

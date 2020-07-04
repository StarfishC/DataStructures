// File:    2-2-2.cpp
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
            Link<T> *tmp = LinkList<T>::getHead();
            Link<T> *pre = NULL;                    // 存放当前节点的上一个节点
            int count;                              // 计数插入元素次数
            while(tmp != NULL){
                if(tmp->data == value1){            // 找到value1
                    Link<T> *q = new Link<T>(value2, NULL);
                    if(pre == NULL){                // 第一个节点就是value1时
                        q->next = tmp;
                        tmp = q;
                    }else{
                        q->next = tmp;
                        pre->next = q;
                    }
                    count ++;
                }
                pre = tmp;                          // 保存当前节点，作为下次循环的前一个节点
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

// File:    2-1-4.cpp
// Author:  csh
// Date:    2020/08/02
// ===================


/*
   思路：1、先按元素递增归并，再逆置链表
         2、先逆置两个单链表，再归并
*/


#include "../headers/linear.hpp"

template <typename T>
class LinkList2:public LinkList<T>{
    public:
        void ReverseList(){             // 逆置链表
            Link<T> *first, *middle, *last;
            first = this->head->next;   // 指向第一个结点

            while(first){
                middle = first->next;
                
            }
        }
};

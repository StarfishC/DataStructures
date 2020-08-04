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
        void reverseList(){                 // 逆置链表
            Link<T> *first, *last;
            first = this->head->next;       // 指向第一个结点
            this->head->next = NULL;        // 头节点的下一个节点指向null
            while(first){
                last = first->next;         // 存下下一个节点 
                first->next = this->head->next;     // 修改节点下一个节点
                this->head->next = first;   // 头指针指向最后逆置的节点
                first = last;               // 继续逆置
            }
        }
        Link<T>* gethead(){
            return this->head;
        }
        void MergeList(LinkList2<T>* LB){
            reverseList();
            LB->reverseList();
            Link<T> *pa, *pb, *tmp;
            pa = this->head->next;          // pa指向第一个节点
            pb = LB->gethead()->next;
            LB->gethead()->next = NULL;     // 指向空，方便析构函数释放空间
            this->head->next = NULL;
            tmp = this->head;
 
            while(pa != NULL && pb != NULL){
                if(pa->data >= pb->data){
                    tmp->next = pa;
                    tmp = pa;
                    pa = pa->next;
                }else{
                    tmp->next = pb;
                    tmp = pb;
                    pb = pb->next;
                }
            }
            if(pa)
                tmp->next = pa;             // 只剩原链表的节点
            else
                tmp->next = pb;             // 只剩LB链表的节点
        }
};



int main(){
    LinkList2<int> LA = LinkList2<int>();
    LA.append(1);
    LA.append(3);
    LA.append(5);
    LinkList2<int> LB = LinkList2<int>();
    LB.append(0);
    LB.append(2);
    LB.append(4);
    LB.append(7);
    LA.MergeList(&LB);
    LA.showAll();

    return 0;
}

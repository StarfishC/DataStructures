// File:    2-1-4.cpp
// Author:  csh
// Date:    2020/08/02
// ===================


#include "../headers/linear.hpp"


template <typename T>
class LinkList2:public LinkList<T>{
    public:
        virtual ~LinkList2(){
            Link<T> *tmp;
            while(this->head){
                tmp = this->head;
                this->head = this->head->next;
                delete tmp;
            }
        }
        Link<T>* getHead(){                 // 返回头节点
            return this->head;
        }
        void reverseList(){                 // 逆置链表
            Link<T> *first, *last;
            first = this->head->next;       // 指向第一个结点
            this->head->next = nullptr;        // 头节点的下一个节点指向null
            while(first){
                last = first->next;         // 存下下一个节点
                first->next = this->head->next;     // 修改节点下一个节点
                this->head->next = first;   // 头指针指向最后逆置的节点
                first = last;               // 继续逆置
            }
        }
        void mergeList(LinkList2<T>* LB){
            reverseList();
            LB->reverseList();
            Link<T> *pa, *pb, *tmp;
            pa = this->head->next;          // pa指向第一个节点
            pb = LB->getHead()->next;
            LB->getHead()->next = nullptr;  // 指向空，方便析构函数释放空间
            this->head->next = nullptr;
            tmp = this->head;

            while(pa && pb){
                if(pa->data == pb->data){
                    tmp->next = pa;
                    tmp = pb;               // 先释放空间再重新指向链表
                    pb = pb->next;
                    delete tmp;
                    tmp = pa;
                    pa = pa->next;
                }
                else if(pa->data > pb->data){
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
        // 头插法，不需要逆置，每次移动头指针
        void mergeList2(LinkList2<int> *LB){
            Link<T> *pa = this->head->next;
            Link<T> *pb = LB->getHead()->next;
            Link<T> *tmp;

            LB->getHead()->next = nullptr;
            this->head->next = nullptr;

            while(pa != nullptr && pb != nullptr){
                if(pa->data == pb->data){
                    tmp = pb;
                    pb = pb->next;
                    delete tmp;
                    tmp = pa->next;
                    pa->next = this->head->next;
                    this->head->next = pa;
                    pa = tmp;
                }
                else if(pa->data <= pb->data){
                    tmp = pa->next;
                    pa->next = this->head->next;
                    this->head->next = pa;
                    pa = tmp;
                }else{
                    tmp = pb->next;
                    pb->next = this->head->next;
                    this->head->next = pb;
                    pb = tmp;
                }
            }

            while(pa != nullptr){
                tmp = pa->next;
                pa->next = this->head->next;
                this->head->next = pa;
                pa = tmp;
            }
            while(pb != nullptr){
                tmp = pb->next;
                pb->next = this->head->next;
                this->head->next = pb;
                pb = tmp;
            }
        }
};



int main(){
    LinkList2<int> LA = LinkList2<int>();
    LA.append(1);
    LA.append(3);
    LA.append(5);
    LA.append(7);
    LinkList2<int> LB = LinkList2<int>();
    LB.append(2);
    LB.append(3);
    LB.append(4);
    LB.append(8);
    LA.mergeList2(&LB);
    LA.showAll();

    return 0;
}

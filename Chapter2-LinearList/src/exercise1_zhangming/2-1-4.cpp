// File:    2-1-4.cpp
// Author:  csh
// Date:    2020/08/02
// Update:  2021/02/20
// ===================


#include "../../include/LinearList.hpp"


template <typename T>
class LinkList2:public LinkList<T>
{
    public:
        Link<T>* getHead()
        {                 // 返回头节点
            return this->Head;
        }
        void reverseList()
        {                 // 逆置链表
            Link<T> *first, *last;
            first = this->Head->Next;       // 指向第一个结点
            this->Head->Next = nullptr;     // 头节点的下一个节点指向null
            while(first)
            {
                last = first->Next;         // 存下下一个节点
                first->Next = this->Head->Next;     // 修改节点下一个节点
                this->Head->Next = first;   // 头指针指向最后逆置的节点
                first = last;               // 继续逆置
            }
        }
        void mergeList(LinkList2<T>* LB)
        {
            reverseList();
            LB->reverseList();
            Link<T> *pa, *pb, *tmp;
            pa = this->Head->Next;          // pa指向第一个节点
            pb = LB->getHead()->Next;
            LB->getHead()->Next = nullptr;  // 指向空，方便析构函数释放空间
            this->Head->Next = nullptr;
            tmp = this->Head;

            while(pa && pb)
            {
                if(pa->Data == pb->Data)
                {
                    tmp->Next = pa;
                    tmp = pb;               // 先释放空间再重新指向链表
                    pb = pb->Next;
                    delete tmp;
                    tmp = pa;
                    pa = pa->Next;
                }
                else if(pa->Data > pb->Data)
                {
                    tmp->Next = pa;
                    tmp = pa;
                    pa = pa->Next;
                }else
                {
                    tmp->Next = pb;
                    tmp = pb;
                    pb = pb->Next;
                }
            }
            if(pa)
                tmp->Next = pa;             // 只剩原链表的节点
            else
                tmp->Next = pb;             // 只剩LB链表的节点
        }
        // 头插法，不需要逆置，每次移动头指针
        void mergeList2(LinkList2<int> *LB)
        {
            Link<T> *pa = this->Head->Next;
            Link<T> *pb = LB->getHead()->Next;
            Link<T> *tmp;

            LB->getHead()->Next = nullptr;
            this->Head->Next = nullptr;

            while(pa != nullptr && pb != nullptr)
            {
                if(pa->Data == pb->Data)
                {
                    tmp = pb;
                    pb = pb->Next;
                    delete tmp;
                    tmp = pa->Next;
                    pa->Next = this->Head->Next;
                    this->Head->Next = pa;
                    pa = tmp;
                }
                else if(pa->Data < pb->Data)
                {
                    tmp = pa->Next;
                    pa->Next = this->Head->Next;
                    this->Head->Next = pa;
                    pa = tmp;
                }else
                {
                    tmp = pb->Next;
                    pb->Next = this->Head->Next;
                    this->Head->Next = pb;
                    pb = tmp;
                }
            }

            while(pa != nullptr)
            {
                tmp = pa->Next;
                pa->Next = this->Head->Next;
                this->Head->Next = pa;
                pa = tmp;
            }
            while(pb != nullptr)
            {
                tmp = pb->Next;
                pb->Next = this->Head->Next;
                this->Head->Next = pb;
                pb = tmp;
            }
        }
};



int main()
{
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

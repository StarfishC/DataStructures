// File:    2-26.cpp
// Author:  csh
// Date:    2021/3/20
// ===================


#include "LinearList.cpp"


template <typename T>
class LinkList2: public LinkList<T>
{
    public:
        void MergeList(LinkList<T> &Lb)
        {
            Link<T> *r;
            Link<T> *pa = this->Head->Next;
            Link<T> *pb = Lb.SetPos(-1)->Next;  // SetPos(-1)是获取头结点
            this->Head->Next = nullptr;         // La作为结果链表的头指针，先将结果链表初始化为空

            while(pa && pb)
            {
                if(pa->Data <= pb->Data)
                {
                    r = pa->Next;
                    pa->Next = this->Head->Next;
                    this->Head->Next = pa;
                    pa = r;
                }
                else
                {
                    r = pb->Next;
                    pb->Next = this->Head->Next;
                    this->Head->Next = pb;
                    pb = r;
                }
            }
            if(pa)
                pb = pa;            // 通常情况下会剩余一个链表非空
            while(pb)
            {
                r = pb->Next;
                pb->Next = this->Head->Next;
                this->Head->Next = pb;
                pb = r;
            }

            Lb.SetPos(-1)->Next = nullptr; // 让析构函数释放Lb空间
        }        
};



int main()
{
    LinkList2<int> La, Lb;
    La.append(1);
    La.append(5);
    La.append(8);
    La.append(22);
    Lb.append(2);
    Lb.append(4);
    Lb.append(9);
    Lb.append(12);
    La.showAll();
    Lb.showAll();
    La.MergeList(Lb);
    La.showAll();
    return 0;
}

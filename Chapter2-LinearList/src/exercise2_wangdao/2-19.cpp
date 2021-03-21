// File:    2-19.cpp
// Author:  csh
// Date:    2021/3/14
// ===================


#include "LinearList.cpp"


template <typename T>
class LinkList2: public LinkList<T>
{
    public:
        void Sort();
};

template <typename T>
void LinkList2<T>::Sort()
{
    Link<T> *p = this->Head->Next, *pre;
    Link<T> *r = p->Next;
    p->Next = nullptr;
    p = r;
    while(p != nullptr)
    {
        r = p->Next;
        pre = this->Head;
        while(pre->Next != nullptr && pre->Next->Data < p->Data)
            pre = pre->Next;
        p->Next = pre->Next;
        pre->Next = p;
        p = r;
    }
}



int main()
{
    LinkList2<int> L;
    L.append(1);
    L.append(7);
    L.append(5);
    L.append(4);
    L.append(13);
    L.append(10);
    L.showAll();
    L.Sort();
    L.showAll();
    return 0;
}

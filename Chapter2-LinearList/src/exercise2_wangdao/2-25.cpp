// File:    2-25.cpp
// Author:  csh
// Date:    2021/3/20
// ===================


#include "LinearList.cpp"


template <typename T>
class LinkList2: public LinkList<T>
{
    public:
        using LinkList<T>::LinkList;
        void Del_Same();
};

template <typename T>
void LinkList2<T>::Del_Same()
{
    Link<T> *p = this->Head->Next, *q;
    if(p == nullptr)
        return;
    while(p->Next != nullptr)
    {
        q = p->Next;
        if(p->Data == q->Data)
        {
            p->Next = q->Next;
            delete q;
        }
        else
            p = p->Next;
    }
}


int main()
{
    LinkList2<int> L;
    L.append(7);
    L.append(10);
    L.append(10);
    L.append(21);
    L.append(30);
    L.append(43);
    L.append(43);
    L.append(43);
    L.append(53);
    L.showAll();
    L.Del_Same();
    L.showAll();
    return 0;
}

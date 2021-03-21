// File:    2-15.cpp
// Author:  csh
// Date:    2021/3/14
// ===================


#include "LinearList.cpp"


template <typename T>
class LinkList2: public LinkList<T>
{
    public:
        void Del_x(T x);
};

template <typename T>
void LinkList2<T>::Del_x(T x)
{
    Link<T> *p = this->Head->Next;
    Link<T> *pre = this->Head;
    Link<T> *q;
    while(p != nullptr)
    {
        if(p->Data == x)
        {
            q = p;
            p = p->Next;
            pre->Next = p;
            delete q;
        }
        else
        {
            pre = p;
            p = p->Next;
        }
    }
}



int main()
{
    LinkList2<int> L;
    L.append(1);
    L.append(2);
    L.append(3);
    L.append(2);
    L.append(4);
    L.showAll();
    L.Del_x(2);
    L.showAll();
    return 0;
}

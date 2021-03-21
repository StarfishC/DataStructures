// File:    2-20.cpp
// Author:  csh
// Date:    2021/3/14
// ===================


#include "LinearList.cpp"


template <typename T>
class LinkList2: public LinkList<T>
{
    public:
        void RangeDelete(int min, int max);
};


template <typename T>
void LinkList2<T>::RangeDelete(int min, int max)
{
    Link<T> *pre = this->Head;
    Link<T> *p = pre->Next;
    while(p != nullptr)
    {
        if(p->Data > min && p->Data < max)
        {
            pre->Next = p->Next;
            delete p;
            p = pre->Next;
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
    L.append(4);
    L.append(3);
    L.append(7);
    L.append(2);
    L.append(6);
    L.showAll();
    L.RangeDelete(3, 7);
    L.showAll();
    return 0;
}

// File:    2-17.cpp
// Author:  csh
// Date:    2021/3/14
// ===================


#include "LinearList.cpp"


template <typename T>
class LinkList2: public LinkList<T>
{
    public:
        void Delete_Min();
};

template <typename T>
void LinkList2<T>::Delete_Min()
{
    Link<T> *minpre = this->Head, *minp = minpre->Next;    // 保存最小结点以及其前驱
    Link<T> *pre = minp, *p = minp->Next;                  // p为工作指针，pre是指向其前驱
    while(p)
    {
        if(p->Data < minp->Data)
        {
            minp = p;
            minpre = pre;
        }
        pre = p;
        p = p->Next;
    }
    minpre->Next = minp->Next;
    delete minp;
    return;
}


int main()
{
    LinkList2<int> L;
    L.append(2); 
    L.append(3); 
    L.append(1); 
    L.append(4); 
    L.showAll();
    L.Delete_Min();
    L.showAll();
    return 0;
}

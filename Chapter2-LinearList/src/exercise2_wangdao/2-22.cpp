// File:    2-22.cpp
// Author:  csh
// Date:    2021/3/20
// ===================


#include "LinearList.cpp"


template <typename T>
class LinkList2: public LinkList<T>
{
    public:
        using LinkList<T>::LinkList;
        void Min_Delete();
};

template <typename T>
void LinkList2<T>::Min_Delete()
{
    Link<T> *pre, *p;
    while(this->Head->Next != nullptr)
    {
        pre = this->Head;           // pre为最小元素结点的前驱结点的指针
        p = pre->Next;              // p为工作指针
        while(p->Next != nullptr)
        {
            if(p->Next->Data < pre->Next->Data)
                pre = p;
            p = p->Next;
        }
        std::cout << pre->Next->Data << " ";
        Link<T> *tmp = pre->Next;
        pre->Next = tmp->Next;
        delete tmp;
    }
    delete this->Head;
    this->Head = nullptr;
}


int main()
{
    LinkList2<int> L;
    L.append(3);
    L.append(2);
    L.append(4);
    L.append(1);
//     L.showAll();
    L.Min_Delete();
    return 0;
}

// File:    2-18.cpp
// Author:  csh
// Date:    2021/3/14
// ===================


#include "LinearList.cpp"


template <typename T>
class LinkList2: public LinkList<T>
{
    public:
        void Rverse_1();        // 头插法
        void Rverse_2();        // 移动指针逆置
};

template <typename T>
void LinkList2<T>::Rverse_1()
{
    Link<T> *p, *r;
    p = this->Head->Next;
    this->Head->Next = nullptr;
    while(p)
    {
        r = p->Next;
        p->Next = this->Head->Next;
        this->Head->Next = p;
        p = r;
    }
    return;
}

template <typename T>
void LinkList2<T>::Rverse_2()
{
    Link<T> *p = this->Head->Next;  // p是工作结点
    Link<T> *pre;                   // pre是前驱结点
    Link<T> *r = p->Next;           // r是后继结点
    p->Next = nullptr;              // 处理第一个结点
    while(r != nullptr)
    {
        pre = p;
        p = r;
        r = r->Next;
        p->Next = pre;
    }
    this->Head->Next = p;
    return;
}


int main()
{
    LinkList2<int> L;
    L.append(1);
    L.append(2);
    L.append(3);
    L.append(4);
    L.showAll();
    L.Rverse_1();
    L.showAll();
    L.Rverse_2();
    L.showAll();
    return 0;
}

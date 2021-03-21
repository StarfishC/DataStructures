// File:    2-1-3.cpp
// Author:  csh
// Date:    2020/08/02
// Update:  2021/02/20
// ===================


#include "LinearList.cpp"


template <typename T>
class LinkList2:public LinkList<T>
{
    public:
        bool deleteMiddleElem(int mink, int maxk);
};

template <typename T>
bool LinkList2<T>::deleteMiddleElem(int mink, int maxk)
{
    Link<T> *pre;               // 存放mink前一个结点
    Link<T> *cur;               // 存放当前结点
    Link<T> *tmp;               // 存放待释放结点
    if(mink > maxk) return false;
    pre = this->Head;
    cur = pre->Next;            // cur指向第一个结点

    while(cur && cur->Data < maxk)
    {
        if(cur->Data <= mink)
        {
            pre = cur;
            cur = cur->Next;
        }else
        {
            pre->Next = cur->Next;      // 跳过待删除结点
            tmp = cur;
            cur = cur->Next;
            delete tmp;
        }
    }
    return true;
}


int main()
{
    LinkList2<int> L = LinkList2<int>();
    L.append(1);
    L.append(3);
    L.append(5);
    L.append(7);
    L.append(9);
    L.deleteMiddleElem(3,9);
    L.showAll();
}

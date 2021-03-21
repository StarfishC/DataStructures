// File:    2-28.cpp
// Author:  csh
// Date:    2021/3/20
// ===================


#include "LinearList.cpp"


template <typename T>
void Union(LinkList<T> &La, LinkList<T> &Lb)
{
    Link<T> *pa = La.SetPos(0);
    Link<T> *pb = Lb.SetPos(0);
    Link<T> *pc = La.SetPos(-1);            // 获取头结点
    Link<T> *u;                             // 存放待删结点
    while(pa && pb)
    {
        if(pa->Data == pb->Data)
        {
            pc->Next = pa;
            pc = pa;
            pa = pa->Next;
            u = pb;
            pb = pb->Next;
            delete u;
        }
        else if(pa->Data < pb->Data)
        {
            u = pa;
            pa = pa->Next;
            delete u;
        }
        else
        {
            u = pb;
            pb = pb->Next;
            delete u;
        }
    }
    while(pa)                               // B遍历完，A未完
    {
        u = pa;
        pa = pa->Next;
        delete u;
    }
    while(pb)
    {
        u = pb;
        pb = pb->Next;
        delete u;
    }
    pc->Next = nullptr;                     // 置结果链表尾指针为nullprt
    
    pb = Lb.SetPos(-1);                     // 头指针置为nullprt,头结点空间由析构函数释放
    pb->Next = nullptr;
}


int main()
{
    LinkList<int> A, B;
    A.append(1);
    A.append(2);
    A.append(3);
    A.append(4);
    A.append(5);
    B.append(3);
    B.append(5);
    Union(A, B);
    A.showAll();
    return 0;
}

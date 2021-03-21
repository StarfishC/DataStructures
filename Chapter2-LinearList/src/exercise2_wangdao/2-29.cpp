// File:    2-29.cpp
// Author:  csh
// Date:    2021/3/20
// ===================


#include "LinearList.cpp"


template <typename T>
int Pattern(LinkList<T> &La, LinkList<T> &Lb)
{
    Link<T> *pa = La.SetPos(0);
    Link<T> *pb = Lb.SetPos(0);
    Link<T> *pre = pa;                  // pre记住每趟比较A链表的开始结点
    while(pa && pb)
    {
        if(pa->Data == pb->Data)
        {
            pa = pa->Next;
            pb = pb->Next;
        }
        else
        {
            pre = pre->Next;
            pa = pre;
            pb = Lb.SetPos(0);
        }
    }
    if(pb == nullptr)                   // 表明B全部比较成功
        return 1;
    else
        return 0;
}


int main()
{
    LinkList<int> A, B;
    A.append(1);
    A.append(2);
    A.append(3);
    A.append(4);
    A.append(5);
    A.append(6);
    B.append(3);
    B.append(4);
    B.append(5);
    std::cout << Pattern(A, B) << std::endl;
    B.append(10);
    std::cout << Pattern(A, B) << std::endl;
    return 0;
}

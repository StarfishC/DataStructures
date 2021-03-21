// File:    2-27.cpp
// Author:  csh
// Date:    2021/3/20
// ===================


#include "LinearList.cpp"


template <typename T>
void Get_Common(LinkList<T> &A, LinkList<T> &B, LinkList<T> &C)
{
    Link<T> *pa = A.SetPos(0);
    Link<T> *pb = B.SetPos(0);
    Link<T> *r, *s;
    while(pa && pb)
    {
        if(pa->Data < pb->Data)
            pa = pa->Next;
        else if(pa->Data > pb->Data)
            pb = pb->Next;
        else
        {
            C.append(pa->Data);
            pa = pa->Next;
            pb = pb->Next;
        }
    }
}


int main()
{
    LinkList<int> A, B, C;
    A.append(1);    
    A.append(3);    
    A.append(5);    
    A.append(8);    

    B.append(3);
    B.append(8);
    B.append(9);
    Get_Common(A,B,C);
    C.showAll();
    return 0;
}

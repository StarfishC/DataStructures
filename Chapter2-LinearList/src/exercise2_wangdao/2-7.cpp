// File:    2-7.cpp
// Author:  csh
// Date:    2021/03/07
// ===================


#include "LinearList.cpp"


template <typename T>
class SeqList: public ArrList<T>
{
    public:
        using ArrList<T>::ArrList;
        
        template <typename N>
        friend bool Merge(SeqList<N> &A, SeqList<N> &B, SeqList<N> &C);
};

template <typename T>
bool Merge(SeqList<T> &A, SeqList<T> &B, SeqList<T> &C)
{
    if(A.CurLen + B.CurLen > C.MaxSize)
       return false;
    int i = 0, j = 0, k = 0; 
    while(i < A.CurLen && j < B.CurLen)
    {
        if(A.List[i] < B.List[j])
            C.List[k++] = A.List[i++];
        else
            C.List[k++] = B.List[j++];
    }
    while(i < A.CurLen)
        C.List[k++] = A.List[i++];
    while(j < B.CurLen)
        C.List[k++] = B.List[j++];
    C.CurLen = k;
    return true;
}


int main()
{
    SeqList<int> A(5);
    SeqList<int> B(5);
    SeqList<int> C(10);
    A.append(1);
    A.append(12);
    A.append(15);
    A.append(17);
    A.append(40);
    B.append(2);
    B.append(4);
    B.append(18);
    Merge<int>(A, B, C);
    C.showAll();
    return 0;
}

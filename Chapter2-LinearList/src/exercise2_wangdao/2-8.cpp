// File:    2-8.cpp
// Author:  csh
// Date:    2021/03/11
// ===================


#include "LinearList.cpp"


template <typename T>
class SqList: public ArrList<T>
{
    public:
        using ArrList<T>::ArrList;
        void Reverse(int left, int right, int arraySize);   // 逆置
        void Exchange(int m, int n, int arraySize);
};

template <typename T>
void SqList<T>::Reverse(int left, int right, int arraySize)
{
    if(left >= right || right >= arraySize)
        return;
    int mid = (right + left) / 2;
    for(int i = 0; i <= mid - left; i++)
    {
        T tmp = this->List[left + i];
        this->List[left + i] = this->List[right - i];
        this->List[right - i] = tmp;
    }
}

template <typename T>
void SqList<T>::Exchange(int m, int n, int arraySize)
{
    Reverse(0, m+n-1, arraySize);
    Reverse(0, n-1, arraySize);
    Reverse(n, m+n-1, arraySize);
}


int main()
{
    SqList<int> l(10);
    l.append(1);
    l.append(2);
    l.append(3);
    l.append(4);
    l.append(5);
    l.append(6);
    l.append(7);
    l.append(8);
    l.append(9);
    l.append(10);
    l.showAll();
    l.Exchange(4, 6, 10);
    l.showAll();
    return 0;
}

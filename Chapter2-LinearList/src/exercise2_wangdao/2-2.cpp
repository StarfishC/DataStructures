// File:    2-2.cpp
// Author:  csh
// Date:    2021/03/06
// ===================


#include "LinearList.cpp"


template <typename T>
class SqLsit: public ArrList<T>
{
    public:
        using ArrList<T>::ArrList;
        void Reverse();
};

template <typename T>
void SqLsit<T>::Reverse()
{
    T tmp;
    for(int i = 0; i < this->CurLen/2; i++)
    {
        tmp = this->List[i];
        this->List[i] = this->List[this->CurLen - i - 1];
        this->List[this->CurLen - i - 1] = tmp;
    }
}


int main()
{
    SqLsit<int> l(10);
    l.append(1);
    l.append(2);
    l.append(3);
    l.append(4);
    l.append(5);
    l.showAll();
    l.Reverse();
    l.showAll();
}

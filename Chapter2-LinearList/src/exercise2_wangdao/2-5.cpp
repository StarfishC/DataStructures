// File:    2-5.cpp
// Author:  csh
// Date:    2021/03/07
// ===================


#include "LinearList.cpp"


template <typename T>
class SqList: public ArrList<T>
{
    public:
        using ArrList<T>::ArrList;
        bool DelRange(const T &s, const T &t);
};

template <typename T>
bool SqList<T>::DelRange(const T &s, const T &t)
{
    int i, k = 0;
    if(this->CurLen == 0 || s >= t)
        return false;
    for(i = 0; i < this->CurLen; i++)
    {
        if(this->List[i] >= s && this->List[i] <= t)
            k++;
        else
            this->List[i-k] = this->List[i];
    }
    this->CurLen -= k;
    return true;
}

int main()
{
    SqList<int> l(10);
    l.append(1);
    l.append(2);
    l.append(3);
    l.append(2);
    l.append(6);
    l.append(5);
    l.append(3);
    l.DelRange(2, 4);
    l.showAll();
    return 0;
}

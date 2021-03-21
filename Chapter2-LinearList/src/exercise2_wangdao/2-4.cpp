// File:    2-4.cpp
// Author:  csh
// Date:    2021/03/07
// ===================


#include <iostream>
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
    int i, j;
    if(s >= t || this->CurLen == 0)
        return false;
    for(i = 0; i < this->CurLen && this->List[i] <= s; i++);    // 寻找大于s的第一个元素
    if(i >= this->CurLen)                                       // 所有元素值均小于s
        return false;
    for(j = i; j < this->CurLen && this->List[j] < t; j++);    // 寻找值大于t的第一个元素
    for(;j < this->CurLen; i++, j++)
        this->List[i] = this->List[j];
    this->CurLen = i;
    return true;
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
    l.DelRange(2,5);
    l.showAll();
    return 0;
}

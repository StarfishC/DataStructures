// File:    2-1.cpp
// Author:  csh
// Date:    2021/03/06
// ===================


#include "LinearList.cpp"


template <typename T>
class SqList: public ArrList<T>
{
    public:
        using ArrList<T>::ArrList;
        bool DelMin(T &value);
};

template <typename T>
bool SqList<T>::DelMin(T &value)
{
    if(this->CurLen == 0)
        return false;
    value = this->List[0];
    int pos = 0;
    for(int i = 1; i < this->CurLen; i++)
    {
        if(this->List[i] < value)
        {
            value = this->List[i];
            pos = i;
        }
    }
    this->List[pos] = this->List[this->CurLen - 1];
    this->CurLen --;
    return true;
}

int main()
{
    SqList<int> t(10);
    t.append(2);
    t.append(1);
    t.append(3);
    t.append(4);
    t.append(3);
    t.showAll();
    int value;
    t.DelMin(value);
    t.showAll();
    return 0;
}

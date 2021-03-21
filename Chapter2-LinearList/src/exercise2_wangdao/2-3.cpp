// File:    2-3.cpp
// Author:  csh
// Date:    2021/03/06
// ===================


#include "LinearList.cpp"


template <typename T>
class SqList: public ArrList<T>
{
    public:
        using ArrList<T>::ArrList;
        void Del_x_1(const T &x);
        void Del_x_2(const T &x);
};

template <typename T>
void SqList<T>::Del_x_1(const T &x)
{
    int k = 0;                  // 记录值不等于x的元素个数
    for(int i = 0; i < this->CurLen; i++)
    {
        if(this->List[i] != x)
        {
            this->List[k] = this->List[i];
            k++;
        }
    }
    this->CurLen = k;
}

template <typename T>
void SqList<T>::Del_x_2(const T &x)
{
    int k = 0, i = 0;
    while(i < this->CurLen)
    {
        if(this->List[i] == x)
            k++;
        else
            this->List[i-k] = this->List[i];
        i++;
    }
    this->CurLen = this->CurLen - k;
}


int main()
{
    SqList<int> l(10);
    l.append(2);
    l.append(3);
    l.append(2);
    l.append(3);
    l.append(5);
    l.append(5);
    l.showAll();
    l.Del_x_1(3);
    l.showAll();
    l.Del_x_2(5);
    l.showAll();
    return 0;
}

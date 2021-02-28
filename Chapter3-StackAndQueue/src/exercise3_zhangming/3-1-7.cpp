// File:    3-1-7.cpp
// Author:  csh
// Date:    2020/06/02
// Update:  2021/02/27
// ===================

#include <cassert>
#include "../../include/LinearList.hpp"

template <typename T>
class AList:public ArrList<T>
{
    public:
        AList(const int size):ArrList<T>(size){}

        T remove(int ith)
        {
            assert((this->CurLen != 0) && (ith >= 0) && (ith < this->CurLen));    // 必须存在一个可删除元素
            T tmp = this->List[ith-1];
            for(int i = ith-1; i < this->CurLen-1; i++)
                this->List[i] = this->List[i+1];
            this->CurLen--;
            return tmp;
        }
};


int main()
{
    AList<int> L = AList<int>(10);
    L.append(1);
    L.append(2);
    L.append(3);
    L.append(4);
    L.showAll();
    L.remove(1);
    L.showAll();
    return 0;
}

// File:    2-5-7.cpp
// Author:  csh
// Date:    2020/06/02
// ===================

#include <cassert>
#include "../headers/linear.hpp"

template <typename T>
class AList:public ArrList<T>{
    public:
        AList(const int size):ArrList<T>(size){}
        T remove(int ith){
            assert((this->curLen != 0) && (ith >= 0) && (ith < this->curLen));    // 必须存在一个可删除元素
            T tmp = this->aList[ith];
            for(int i = ith; i < this->curLen-1; i++){
                // 向前移动
                this->aList[i] = this->aList[i+1];
            }
            this->curLen--;
            return tmp;
        }
};


int main(){
    AList<int> L = AList<int>(10);
    L.append(1);
    L.append(2);
    L.append(3);
    L.append(4);
    L.showAll();
    L.remove(0);
    L.showAll();
    return 0;
}

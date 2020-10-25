// File:    2-1-6.cpp
// Author:  csh
// Date:    2020/07/12
// ===================


#include "../headers/linear.hpp"
#include <iostream>


// 当k比较大时，默认i后面元素全部删除，若要求第i+k元素必须存在，则需要判断是否越界
template <typename T>
class SqList:public ArrList<T>{
    public:
        SqList(const int size):ArrList<T>(size){}
        bool deleteRange(int i, int k){
            using std::cout;
            using std::endl;
            if(i < 1 || i > this->curLen)
                cout << "删除位置不合法" << endl;
            for(int j = i-1; j <= this->curLen-1; j++)
                this->aList[j] = this->aList[j+k];
            this->curLen -= k;
            return true;
        }
};


int main(){
    SqList<int> L = SqList<int>(5);
    L.append(1);
    L.append(2);
    L.append(3);
    L.append(4);
    L.append(5);
    L.deleteRange(1, 3);
    L.showAll();
    return 0;
}

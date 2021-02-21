// File:    2-1-6.cpp
// Author:  csh
// Date:    2020/07/12
// Update:  2020/02/20
// ===================


#include <iostream>
#include "../../include/LinearList.hpp"


// 当k比较大时，默认i后面元素全部删除，若要求第i+k元素必须存在，则需要判断是否越界
template <typename T>
class SqList:public ArrList<T>
{
    public:
        SqList(const int size):ArrList<T>(size){}
        bool deleteRange(int i, int k)
        {
            using std::cout;
            if(i < 1 || i > this->CurLen)
                cout << "删除位置不合法!\n";
            // 当k较大时
            if(i+k > this->CurLen){
                this->CurLen = i-1;
                return true;
            }
            for(int j = i-1; j <= this->CurLen-1; j++){
                if(j+k >= this->CurLen)
                    break;
                this->List[j] = this->List[j+k];
            }
            this->CurLen -= k;
            return true;
        }
};


int main()
{
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

// File:    2-6.cpp
// Author:  csh
// Date:    2021/03/07
// ===================


#include "LinearList.cpp"


template <typename T>
class SeqList: public ArrList<T>
{
    public:
        using ArrList<T>::ArrList;
        bool DeleteSame()
        {
            if(this->CurLen == 0)
                return false;
            int i, j;
            for(i = 0, j = 1; j < this->CurLen; j++)
                if(this->List[i] != this->List[j])
                    this->List[++i] = this->List[j];
            this->CurLen = i + 1;
            return true;
        }
};


int main()
{
    SeqList<int> sl(10);
    sl.append(1);
    sl.append(1);
    sl.append(3);
    sl.append(4);
    sl.append(6);
    sl.append(6);
    sl.append(7);
    sl.append(8);
    sl.DeleteSame();
    sl.showAll();
    return 0;
}

// File:    2-5-18.cpp
// Author:  csh
// Date:    2020/06/13
// ===================


#include <cstdlib>


template <typename T>
class Queue{
    private:
        T **Qrank;                      // 二维数组存放各级队列
        const int rankNum  = 3;         // 当前的最大优先级数
        int *CurrNum;                   // 一维数组存放各级队列的当前元素个数
        int maxNum;                     // 记录每一级队列的最大元素个数
    public:
        Queue(int maxNumber){
            for(auto i = 0; i < rankNum; i++){
                if((Qrank[i] = new T[maxNumber]) == NULL)
                    exit(0);
            }
            maxNum = maxNumber;
            CurrNum = new int[rankNum];
        }
        ~Queue(){
            for(int i = 0; i < rankNum; i++)
                delete []Qrank[i];
            delete [] CurrNum;
        }
        void enQueue(T data, int dataRank){
            if(dataRank >= rankNum || CurrNum[dataRank] >= maxNum)
                return;
            Qrank[dataRank][CurrNum[dataRank]] = data;
            CurrNum[dataRank]++;
        }
};

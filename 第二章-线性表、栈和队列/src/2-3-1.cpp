// File:    2-3-1.cpp
// Author:  csh
// Date:    2020/06/13
// ===================


#include <iostream>

using namespace std;

template <typename T>
class List{
    private:
        T *aList;               // 存储顺序表的实例
        int maxSize;            // 顺序表的最大长度
        int curLen;             // 顺序表的当前长度
    public:
        List(const int size){
            maxSize = size;
            aList = new T[maxSize];
            curLen = 0;
        }
        ~List(){
            delete []aList;
        }
        bool insert(const T value){
            int left, right, mid;
            left = 0;
            right = curLen-1;
            if(curLen >= maxSize){
                cout << "顺序表已满" << endl;
                return false;
            }
            // 若当前无元素或最后一个元素小于value, 直接加入新元素
            if(curLen == 0 || aList[curLen-1] <= value){
                aList[curLen++] = value;
                return true;
            }
            // 否则用二分查找合适位置
            while(left < right){
                mid = (right - left)/2 + left;
                if(aList[mid] < value)
                    left = mid+1;
                else if(aList[mid] > value)
                    right = mid-1;
                else
                    break;
            }
            // mid后的所有元素后移一个位置
            for(int i = curLen-1; i >= mid; i--)
                aList[i+1] = aList[i];
            aList[mid] = value;
            curLen ++;
            return true;
        }
        void showAll(){
            for(int i = 0; i < curLen; i++)
                cout << aList[i] << " ";
            cout << endl;
        }
};


int main(){
    List<int> a = List<int>(10);
    a.insert(1);
    a.insert(3);
    a.insert(5);
    a.insert(7);
    a.insert(9);
    a.insert(6);
    a.showAll();
}

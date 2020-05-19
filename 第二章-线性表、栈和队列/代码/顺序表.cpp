// File:    顺序表.cpp
// Author:  csh
// Date:    2020/05/16
// ===================

#include <iostream>

template <typename T>
class ArrList{
    private:
        T *aList;                                   // 存储顺序表的实例
        int maxSize;                                // 顺序表的最大长度
        int curLen;                                 // 顺序表的当前长度
        int position;                               // 当前处理位置
    public:
        ArrList(const int size){                    // 创建一个大小为size的顺序表
            maxSize = size;
            aList = new T[maxSize];
            curLen = position= 0;
        }
        ~ArrList(){
            delete [] aList;
        }
        void clear();                               // 清除顺序表内容，成为空表
        int length();                               // 返回顺序表长度
        bool append(const T value);                 // 表尾添加一个元素value
        bool insert(const int p, const T value);    // 位置p上插入一个元素value
        bool remove(const int p);                   // 移除位置p上的元素
        bool setValue(const int p, const T value);  // 修改位置p的元素为value
        bool getValue(const int p, T &value);       // 把位置p的元素返回到变量value中
        bool getPos(int &p, const T value);         // 查找值为value的元素，返回第一次出现的位置
        void showAll();                             // 显示所有元素
};

template <typename T>
void ArrList<T>::clear(){
    delete []aList;
    curLen = position = 0;
    aList = new T[maxSize];
}

template <typename T>
int ArrList<T>::length(){
    return curLen;
}

template <typename T>
bool ArrList<T>::append(const T value){
    using std::cout;
    using std::endl;
    if(curLen >= maxSize){
        cout << "The list is overflow" << endl;
        return false;
    }
    aList[curLen-1] = value;
    curLen++;
    return true;
}

template <typename T>
bool ArrList<T>::getValue(const int p, T &value){
    using std::cout;
    using std::endl;
    if(p < 0 || p > curLen-1){      // 判断p位置是否合法
        cout << "Location is illegal" << endl;
        return false;
    }
    value = aList[p];
    return true;
}

template <typename T>
bool ArrList<T>::setValue(const int p, const T value){
    using std::cout;
    using std::endl;
    if(p < 0 || p > curLen-1){      // 判断p位置是否合法
        cout << "Location is illegal" << endl;
        return false;
    }
    aList[p] = value;
    return true;
}

template <typename T>
bool ArrList<T>::insert(const int p, const T value){
    using std::cout;
    using std::endl;
    if(curLen >= maxSize){          // 检查顺序表是否溢出
        cout << "The list is overflow" << endl;
        return false;
    }
    if(p < 0 || p > curLen){        // 检查位置是否合法
        cout << "Insertion point is illegal" << endl;
        return false;
    }
    for(int i = curLen; i > p; i--)
        aList[i] = aList[i-1];      // 将p位置以及之后的元素后移一位
    aList[p] = value;
    curLen++;
    return true;
}

template <typename T>
bool ArrList<T>::remove(const int p){
    using std::cout;
    using std::endl;
    if(curLen < 0){
        cout << "No element to remove" << endl;
        return false;
    }
    if(p < 0 || p > curLen-1){
        cout << "remove is illegal" << endl;
        return false;
    }
    for(int i = p; i < curLen-1; i++)
        aList[p] = aList[i+1];
    curLen--;
    return true;
}

template <typename T>
bool ArrList<T>::getPos(int &p, const T value){
    for(int i = 0; i < this->maxSize-1; i++){
        if(value == aList[i]){
            p = i;
            return true;
        }
    }
    return false;
}

template <typename T>
void ArrList<T>::showAll(){
    using std::cout;
    using std::endl;
    if(curLen == 0)
        cout << "No element in the list" << endl;
    for(int i = 0; i < curLen; i++)
        cout << aList[i] << " ";
    cout << endl;
    return;
}


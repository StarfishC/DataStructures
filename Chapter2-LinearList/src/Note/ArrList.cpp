// File:    ArrList.cpp
// Author:  csh
// Date:    2021/02/20
// ===================


#include <cstdlib>
#include <iostream>


template <typename T>
class ArrList
{
    private:
        T *List;                                    // 存储顺序表的数组
        int MaxSize;                                // 顺序表的最大长度
        int CurLen;                                 // 顺序表的当前长度
    public:
        ArrList(const int size):
            MaxSize(size), List(new T[MaxSize]), CurLen(0){}
        ~ArrList()
        {
            delete [] List;
        }
        void clear();                               // 清除顺序表的内容，成为空表
        int length();                               // 返回顺序表的长度
        bool isEmpty();                             // 判断线性表是否为空
        bool isFull();                              // 判断线性表是否已满
        bool append(const T value);                 // 表尾添加一个元素
        bool insert(const int p, const T value);    // 位置p插入一个元素
        bool remove(const int p);                   // 移除位置p上的元素
        bool setValue(const int p, const T value);  // 修改位置p的元素值
        bool getValue(const int p, T &value);       // 返回位置p的元素给value
        bool getPos(const T value, int &p);         // 查找值为value的元素，并返回第1次出现的位置
        void showAll();                             // 显示所有元素
};

template <typename T>
inline void ArrList<T>::clear()
{
    CurLen = 0;
}

template <typename T>
inline int ArrList<T>::length()
{
    return CurLen;
}

template <typename T>
inline bool ArrList<T>::isEmpty()
{
    return CurLen == 0;
}

template <typename T>
inline bool ArrList<T>::isFull()
{
    return CurLen >= MaxSize;
}

template <typename T>
bool ArrList<T>::append(const T value)
{
    using namespace std;
    if(CurLen >= MaxSize)
    {
        cout << "The list is overflow" << endl;
        return false;
    }
    List[CurLen++] = value;
    return true;
}

template <typename T>
bool ArrList<T>::insert(const int p, const T value)
{
    using namespace std;
    if(isEmpty())               // 检查是否溢出
    {
        cout << "The list is overflow" << endl;
        return false;
    }
    if(p < 0 || p > CurLen)     // 检查位置是否合法
    {
        cout << "Insertion point is illegal" << endl;
        return false;
    }
    for(int i = CurLen; i > p; i--)
        List[i] = List[i-1];
    List[p] = value;
    CurLen++;
    return true;
}

template <typename T>
bool ArrList<T>::remove(const int p)
{
    using namespace std;
    if(isEmpty())
    {
        cout << "No element to remove" << endl;
        return false;
    }
    if(p < 0 || p >= CurLen)
    {
        cout << "Remove point is illegal" << endl;
        return false;
    }
    for(int i = p; i < CurLen-1; i++)
        List[i] = List[i+1];
    CurLen--;
    return true;
}

template <typename T>
bool ArrList<T>::setValue(const int p, const T value)
{
    using namespace std;
    if(p < 0 || p >= CurLen)
    {
        cout << "Location is illegal" << endl;
        return false;
    }
    List[p] = value;
    return true;
}

template <typename T>
bool ArrList<T>::getValue(const int p, T &value)
{
    using namespace std;
    if(p < 0 || p >= CurLen)
    {
        cout << "Location is illegal" << endl;
        return false;
    }
    value = List[p];
    return true;
}

template <typename T>
bool ArrList<T>::getPos(const T value, int &p)
{
    for(int i = 0; i < CurLen; i++)
    {
        if(value == List[i])
        {
            p = i;
            return true;
        }
    }
    return false;
}

template <typename T>
void ArrList<T>::showAll()
{
    using namespace std;
    if(CurLen == 0)
        cout << "No element in the list" << endl;
    for(int i = 0; i < CurLen; i++)
        cout << List[i] << " ";
    cout << endl;
    return;
}

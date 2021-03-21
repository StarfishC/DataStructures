// File:    LinearList.hpp
// Author:  csh
// Date:    2021/02/20
// ===================


#ifndef __LINEARLIST_H_
#define __LINEARLIST_H_

#include <iostream>


// 顺序表
template <typename T>
class ArrList
{
    protected:
        T *List;                                    // 存储顺序表的数组
        int MaxSize;                                // 顺序表的最大长度
        int CurLen;                                 // 顺序表的当前长度
    public:
        ArrList(const int size):
            MaxSize(size), List(new T[size]), CurLen(0){}
        virtual ~ArrList()
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
        T getValue(const int p);                    // 返回位置p的元素
        bool getPos(const T value, int &p);         // 查找值为value的元素，并返回第1次出现的位置
        void showAll();                             // 显示所有元素
};


// 单链表
template <typename T>
class Link
{
    public:
        T Data;             // 数字域
        Link<T>* Next;      // 指针域

        Link(const T info, Link<T>* nextLink=nullptr):
            Data(info), Next(nextLink){}
        Link(Link<T>* nextLink=nullptr): Next(nextLink){}
};


// 单链表
template <typename T>
class LinkList
{
    protected:
        Link<T> *Head, *Tail;                   // 单链表的头尾结点
    public:
        LinkList(): Head(new Link<T>), Tail(Head){};
        virtual ~LinkList()
        {
            Link<T> *tmp;
            while(Head != nullptr)
            {
                tmp = Head;
                Head = Head->Next;
                delete tmp;
            }
        }

        Link<T> *SetPos(const int p);           // 返回链表指向第p个元素的指针
        bool isEmpty();                         // 判断链表是否为空
        void clear();                           // 清空链表内容
        int length();                           // 返回链表当前长度
        bool append(const T value);             // 表尾添加新元素
        bool insert(const int p, const T value);// 位置p插入新元素value
        bool remove(const int p);               // 移除位置p元素
        bool getValue(const int p, T &value);   // 返回位置p的元素给value
        bool getPos(int &p, const T value);     // 返回值为value的位置
        void showAll();                         // 显示链表的所有元素
};


// 顺序表
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
T ArrList<T>::getValue(const int p)
{
    T tmp;
    getValue(p, tmp);
    return tmp;
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


// 单链表
template <typename T>
Link<T>* LinkList<T>::SetPos(const int p)
{
    using std::cout;
    int count = 0;
    if(p == -1)                         // -1定位到头结点
        return Head;
    Link<T> *tmp = Head->Next;
    while(tmp != nullptr && count < p)  // 0则定位第一个结点
    {
        tmp = tmp->Next;
        count++;
    }
    return tmp;
}

template <typename T>
inline bool LinkList<T>::isEmpty()
{
    return Head == Tail;
    // return Head->Next == nullptr;
}

template <typename T>
void LinkList<T>::clear()
{
    Link<T> *tmp;
    while(Head != nullptr)
    {
        tmp = Head;
        Head = Head->Next;
        delete tmp;
    }
    Head = Tail = new Link<T>;
}

// 求长度可以增加一个记录长度的属性
template <typename T>
int LinkList<T>::length()
{
    int count = 0;
    Link<T> *tmp = Head->Next;
    while(tmp)
    {
        count ++;
        tmp = tmp->Next;
    }
    return count;
}

template <typename T>
bool LinkList<T>::append(const T value)
{
    Link<T> *tmp;
    tmp = new Link<T>(value);
    if(Head == Tail)
    {
        Head->Next = tmp;
        Tail = tmp;
    }else
    {
        Tail->Next = tmp;
        Tail = tmp;
    }
    return true;
}

template <typename T>
bool LinkList<T>::insert(const int p, const T value)
{
    using std::cout;
    Link<T> *pre, *tmp;
    if((pre = SetPos(p-1)) == nullptr)  // pre是第p个结点的前驱
    {
        cout << "Insertion point is illegal\n";
        return false;
    }
    tmp = new Link<T>(value, pre->Next);
    pre->Next = tmp;
    if(pre == Tail)
        Tail = tmp;
    return true;
}

template <typename T>
bool LinkList<T>::remove(const int p)
{
    using std::cout;
    Link<T> *pre, *cur;
    pre = SetPos(p-1);
    if(pre == nullptr || pre == Tail)
    {
        cout << "Removal point is illegal\n";
        return false;
    }
    cur = pre->Next;
    if(cur == Tail)
    {
        Tail = pre;
        pre->Next = nullptr;
        delete cur;
    }else if(cur != nullptr)
    {
        pre->Next = cur->Next;
        delete cur;
    }
    return true;
}

template <typename T>
bool LinkList<T>::getValue(const int p, T &value)
{
    using std::cout;
    Link<T> *tmp;
    if((tmp = SetPos(p)) == nullptr)
    {
        cout << "Location is illegal\n";
        return false;
    }
    value = tmp->Data;
    return true;
}

template <typename T>
bool LinkList<T>::getPos(int &p, const T value)
{
    Link<T> *tmp = Head->Next;
    int count = -1;
    while(tmp)
    {
        count ++;
        if(tmp->Data == value)
        {
            p = count;
            return true;
        }
        tmp = tmp->Next;
    }
    return false;
}

template <typename T>
void LinkList<T>::showAll()
{
    using std::cout;
    using std::endl;

    Link<T> *tmp = Head->Next;
    while(tmp != nullptr)
    {
        cout << tmp->Data << " ";
        tmp = tmp->Next;
    }
    cout << endl;
}


#endif

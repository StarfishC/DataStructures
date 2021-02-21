// File:    LinkList.cpp
// Author:  csh
// Date:    2021/02/20
// ===================


#include <cstdlib>
#include <iostream>


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
    private:
        Link<T> *Head, *Tail;                   // 单链表的头尾结点
        Link<T> *SetPos(const int p);           // 返回链表指向第p个元素的指针
    public:
        LinkList(): Head(new Link<T>), Tail(Head){};
        ~LinkList()
        {
            Link<T> *tmp;
            while(Head != nullptr)
            {
                tmp = Head;
                Head = Head->Next;
                delete tmp;
            }
        }

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


int main(int argc, char *argv[])
{
    using namespace std;
    LinkList<int> a;
    a.append(1);
    a.append(2);
    a.append(4);
    a.append(5);
    a.showAll();
    return 0;
}

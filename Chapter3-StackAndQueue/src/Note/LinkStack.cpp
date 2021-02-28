// File:    LinkStack.cpp
// Author:  csh
// Date:    2021/02/21
// ===================


#include <iostream>


template <typename T>
class Link
{
    public:
        T Data;                         // 数据域
        Link<T>* Next;                  // 指针域，指向后继结点

        Link(const T info, Link<T>* nextLink=nullptr):
            Data(info), Next(nextLink){}
        Link(Link<T>* nextLink=nullptr): Next(nextLink){}
};


template <typename T>
class LinkStack
{
    private:
        Link<T> *Top;                   // 指向栈顶指针
        int Size;                       // 存放栈顶元素的个数
    public:
        LinkStack(): Top(new Link<T>), Size(0){}
        ~LinkStack()
        {
            clear();
            delete Top;
        }

        void clear();                   // 清空栈内容
        bool push(const T item);        // 入栈
        bool pop(T &item);              // 出栈
        bool peek(T &item);             // 返回栈顶元素
        bool isEmpty();                 // 判断是否栈空
};

template <typename T>
void LinkStack<T>::clear()
{
    Link<T>* tmp = Top->Next;
    while(tmp)
    {
        Link<T> *t = tmp;
        tmp = tmp->Next;
        delete t;
    }
    Top->Next = nullptr;
    Size = 0;
}

template <typename T>
bool LinkStack<T>::push(const T item)
{
    Link<T> *tmp = new Link<T>(item, Top->Next);
    Top->Next = tmp;
    Size++;
    return true;
}

template <typename T>
bool LinkStack<T>::pop(T &item)
{
    using std::cout;
    Link<T> *tmp;
    if(isEmpty())
    {
        cout << "栈空，不能出栈\n";
        return false;
    }
    tmp = Top->Next;
    Top->Next = tmp->Next;
    item = tmp->Data;
    delete tmp;
    Size--;
    return true;
}

template <typename T>
bool LinkStack<T>::peek(T &item)
{
    using std::cout;
    if(isEmpty())
    {
        cout << "栈空，栈顶无元素\n";
        return false;
    }
    item = Top->Next->Data;
    return true;
}

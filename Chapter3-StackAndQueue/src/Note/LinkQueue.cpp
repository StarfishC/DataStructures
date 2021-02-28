// File:    LinkQueue.cpp
// Author:  csh
// Date:    2021/02/21
// ===================


#include <iostream>


template <typename T>
class Link
{
    public:
        T Data;                         // 数据域
        Link<T> *Next;                  // 指针域，指向后继结点
        
        Link(const T info, Link<T>* nextLink=nullptr):
            Data(info), Next(nextLink){}
        Link(Link<T>* nextLink=nullptr): Next(nextLink){}
};


template <typename T>
class LinkQueue
{
    private:
        int Size;                       // 队列元素个数
        Link<T>* Front;                 // 队首指针
        Link<T>* Rear;                  // 队尾指针
    public:
        // 注，这里没有给Front和Rear申请空间，与Stack的方式不同
        LinkQueue(): Size(0), Front(nullptr), Rear(nullptr){}
        ~LinkQueue()
        {
            clear();
        }

        void clear();                   // 清空队列元素
        bool enQueue(const T item);     // 入队
        bool deQueue(T &item);          // 出队
        bool getFront(T &item);         // 返回队首元素
        bool isEmpty();                 // 队列是否为空
        int length();                   // 队列长度
};

template <typename T>
void LinkQueue<T>::clear()
{
    while(Front != nullptr)
    {
        Rear = Front;
        Front = Front->Next;
        delete Rear;
    }
    Rear = NULL;
    Size = 0;
}

template <typename T>
bool LinkQueue<T>::enQueue(const T item)
{
    if(isEmpty())
        Front = Rear = new Link<T>(item, nullptr);
    else
    {
        Rear->Next = new Link<T>(item);
        Rear = Rear->Next;
    }
    Size++;
    return true;
}

template <typename T>
bool LinkQueue<T>::deQueue(T &item)
{
    using std::cout;
    Link<T> *tmp;
    if(isEmpty())
    {
        cout << "队列空，不能出队\n";
        return false;
    }
    item = Front->Data;
    tmp = Front;
    Front = Front->Next;
    delete tmp;
    if(Front == nullptr)
        Rear = nullptr;
    Size--;
    return true;
}

template <typename T>
bool LinkQueue<T>::getFront(T &item)
{
    using std::cout;
    Link<T> *tmp;
    if(isEmpty())
    {
        cout << "队列空，不能出队\n";
        return false;
    }
    item = Front->Data;
    return true;
}

template <typename T>
inline bool LinkQueue<T>::isEmpty()
{
    return Size == 0;
}

template <typename T>
int LinkQueue<T>::length()
{
    // return Size;
    int len = 0;
    for(Link<T>* tmp = Front; Front != Rear; tmp = tmp->Next)
        len++;
    return len;
}

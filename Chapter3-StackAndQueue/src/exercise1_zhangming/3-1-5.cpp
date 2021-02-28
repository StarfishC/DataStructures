// File:    3-1-5.cpp
// Author:  csh
// Date:    2020/08/23
// Update:  2021/02/27
// ===================


#include <iostream>

using namespace std;

template <typename T>
class Link
{
    public:
        T Data;
        Link<T> *Next;

        Link(const T &info, Link<T> *nextlink=nullptr):
            Data(info), Next(nextlink){}
        Link(Link<T> *nextlink=nullptr): Next(nextlink){}
};

template <typename T>
class LoopLink
{
    private:
        Link<T> *Rear;
        int Len;
    public:
        LoopLink();
        ~LoopLink();
        bool isEmpty();
        bool enQueue(const T &item);
        bool deQueue(T &item);
        void showAll();
};

template <typename T>
LoopLink<T>::LoopLink()
{
    Rear = new Link<T>();
    Rear->Next = Rear;
    Len = 0;
}

template <typename T>
LoopLink<T>::~LoopLink()
{
    Link<T> *tmp = Rear->Next;
    Rear->Next = nullptr;
    while(tmp)
    {
        Rear = tmp->Next;
        delete tmp;
        tmp = Rear;
    }
}

template <typename T>
inline bool LoopLink<T>::isEmpty()
{
    return Rear->Next == Rear;
}

template <typename T>
bool LoopLink<T>::enQueue(const T &item)
{
    Link<T> *tmp = Rear->Next;
    Link<T> *Node = new Link<T>(item);
    Rear->Next = Node;
    Node->Next = tmp;
    Rear = Node;
    Len++;
    return true;
}

template <typename T>
bool LoopLink<T>::deQueue(T &item)
{
    if(isEmpty())
    {
        cout << "队列空" << endl;
        return false;
    }
    Link<T> *tmp = Rear->Next->Next;
    if(tmp == Rear)
    {
        cout << "只有一个元素" << endl;
        item = tmp->Data;
        Rear = Rear->Next;
        Rear->Next = Rear;
        Len--;
        return true;
    }
    Rear->Next->Next = tmp->Next;
    item = tmp->Data;
    delete tmp;
    Len--;
    return true;
}


template <typename T>
void LoopLink<T>::showAll(){
    Link<T> *head = Rear->Next;
    Link<T> *tmp = head->Next;
    while(tmp != head)
    {
        cout << tmp->Data << " "; 
        tmp = tmp->Next;
    }
    cout << endl;
}


int main()
{
    LoopLink<int> lp = LoopLink<int>();
    int item;
    lp.enQueue(1);
    lp.deQueue(item);
    cout << item << endl;
    lp.enQueue(2);
    lp.enQueue(3);
    lp.enQueue(4);
    lp.enQueue(5);
    lp.showAll();
    lp.deQueue(item);
    lp.deQueue(item);
    lp.showAll();
    return 0;
}

// File:    3-1-6.cpp
// Author:  csh
// Date:    2020/08/23
// Update:  2020/02/27
// ===================


#include <iostream>
using namespace std;

template <typename T>
class Stack
{
    private:
        int Lfirst;                     // 左边数组标志
        int Rfirst;                     // 右边数组标志
        int Size;                       // 数组最大长度
        T *Qu;
    public:
        Stack(const int &num):
            Lfirst(-1), Rfirst(num), Size(num), Qu(new T[num]){}
        ~Stack()
        {
            delete [] Qu;
        }

        bool isEmpty();
        bool isFull();                  // 是否已满
        bool lpush(const int &item);    // 左边入栈
        bool rpush(const int &item);    // 右边入栈
        bool lpop(T &item);             // 左边出栈
        bool rpop(T &item);             // 右边出栈
};


template <typename T>
inline bool Stack<T>::isEmpty()
{
    return (Lfirst == -1 && Rfirst == Size);
}

template <typename T>
inline bool Stack<T>::isFull()
{
    return Lfirst + 1 == Rfirst;
}

template <typename T>
bool Stack<T>::lpush(const int &item)
{
    if(isFull())
    {
        cout << "栈满，不能入栈" << endl;
        return false;
    }
    Qu[++Lfirst] = item;
    return true;
}

template <typename T>
bool Stack<T>::rpush(const int &item)
{
    if(isFull())
    {
        cout << "栈满，不能入栈" <<endl;
        return false;
    }
    Qu[--Rfirst] = item;
    return true;
}


template <typename T>
bool Stack<T>::lpop(T &item)
{
    if(Lfirst == -1)
    {
        cout << "栈空，不能出栈" << endl;
        return false;
    }
    item = Qu[Lfirst--];
    return true;
}

template <typename T>
bool Stack<T>::rpop(T &item)
{
    if(Rfirst == Size)
    {
        cout << "栈空，不能出栈" << endl;
        return false;
    }
    item = Qu[Rfirst++];
    return true;
}


int main()
{
    Stack<int> q = Stack<int>(5);
    q.lpush(1);
    q.lpush(2);
    q.rpush(3);
    q.rpush(4);
    q.rpush(5);

    int item;
    q.lpop(item);
    cout << "lpop1: " << item << endl;
    q.lpop(item);
    cout << "lpop2: " << item << endl;
    q.rpop(item);
    cout << "rpop1: " << item << endl;
    q.rpop(item);
    cout << "rpop2: " << item << endl;
    return 0;
}

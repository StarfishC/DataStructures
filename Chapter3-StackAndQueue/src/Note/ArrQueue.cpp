// File:    ArrQueue.cpp
// Author:  csh
// Date:    2021/02/21
// ===================


#include <iostream>

template <typename T>
class ArrQueue
{
    private:
        int MSize;                      // 存放队列的数组大小
        int Front;                      // 表示队首位置
        int Rear;                       // 表示队尾位置
        T *Qu;                          // 存放队列元素的数组
    public:
        ArrQueue(const int size):
            MSize(size+1), Front(0), Rear(0), Qu(new T[MSize]){}
        ~ArrQueue()
        {
            delete [] Qu;
        }

        void clear();                   // 清空队列
        bool isEmpty();                 // 判断队列是否为空
        bool isFull();                  // 判断队列是否已满
        bool enQueue(const T item);     // 入队
        bool deQueue(T& item);          // 出队
        bool getFront(T& item);         // 返回队首元素
        int length();                   // 队列长度
};

template <typename T>
inline void ArrQueue<T>::clear()
{
    Front = Rear = 0;
}

template <typename T>
inline bool ArrQueue<T>::isEmpty()
{
    return Front == Rear;
}

template <typename T>
inline bool ArrQueue<T>::isFull()
{
    return (Rear + 1) % MSize == Front;
}

template <typename T>
bool ArrQueue<T>::enQueue(const T item)
{
    using std::cout;
    if(isFull())
    {
        cout << "队列满\n";
        return false;
    }
    Qu[Rear] = item;
    Rear = (Rear + 1) % MSize;
    return true;
}

template <typename T>
bool ArrQueue<T>::deQueue(T &item)
{
    using std::cout;
    if(isEmpty())
    {
        cout << "队列空\n";
        return false;
    }
    item = Qu[Front];
    Front = (Front + 1) % MSize;
    return true;
}

template <typename T>
bool ArrQueue<T>::getFront(T &item)
{
    using std::cout;
    if(isEmpty())
    {
        cout << "队列空，无元素\n";
        return false;
    }
    item = Qu[Front];
    return true;
}

template <typename T>
int ArrQueue<T>::length()
{
    int len;
    if(isEmpty())
        len = 0;
    else if(Front <= Rear)
        len = Rear - Front;
    else
        len = MSize + Rear - Front;
    return len;
}

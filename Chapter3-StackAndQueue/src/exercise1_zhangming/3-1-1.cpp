// File:    3-1-1.cpp
// Author:  csh
// Date:    2020/08/23
// Update:  2020/02/21
// ===================


#include <iostream>


template <typename T>
class LoopQueue
{
    private:
        int MSize;                  // 存放队列的数组大小
        int Front;                  // 队首
        int Rear;                   // 队尾
        T *Qu;                      // 队列数组
    public:
        LoopQueue(int size):
            MSize(size+1), Front(0), Rear(0), Qu(new T[MSize]){}
        ~LoopQueue()
        {
            delete [] Qu;
        }
        void clear();               // 清空队列
        bool isEmpty();             // 队列是否为空
        bool isFull();              // 队列是否已满
        bool enQueue(const T &item);// 入队
        bool deQueue(T &item);      // 出队
        bool deRear(T &item);       // 队尾删除
        bool enFront(const T &item);// 队首插入
        void showAll();             // 显示队列所有元素
};

template <typename T>
inline void LoopQueue<T>::clear()
{
    Front = Rear = 0;
}

template <typename T>
inline bool LoopQueue<T>::isEmpty()
{
    return Front == Rear;
}

template <typename T>
bool LoopQueue<T>::isFull()
{
    return (Rear + 1) % MSize == Front;
}

template <typename T>
bool LoopQueue<T>::enQueue(const T &item)
{
    using std::cout;
    using std::endl;
    if(isFull())
    {
        cout << "队列满，不能入队" << endl;
        return false;
    }
    Qu[Rear] = item;
    Rear = (Rear + 1) % MSize;
    return true;
}

template <typename T>
bool LoopQueue<T>::deQueue(T &item)
{
    using std::cout;
    using std::endl;
    if(isEmpty())
    {
        cout << "队列空，不能出队" << endl;
        return false;
    }
    item = Qu[Front];
    Front = (Front + 1) % MSize;
    return true;
}

template <typename T>
bool LoopQueue<T>::deRear(T &item)
{
    using std::cout;
    using std::endl;
    if(isEmpty())
    {
        cout << "队列空，不能队尾出队" << endl;
        return false;
    }
    item = Qu[Rear-1];
    Rear = (Rear + MSize - 1) % MSize;
    return true;
}

template <typename T>
bool LoopQueue<T>::enFront(const T &item)
{
    using std::cout;
    using std::endl;
    if(isFull())
    {
        cout << "队列满，不能队首入队" << endl;
        return false;
    }
    Front = (Front + MSize - 1) % MSize;
    Qu[Front] = item;
    return true;
}

template <typename T>
void LoopQueue<T>::showAll()
{
    using std::cout;
    using std::endl;
    int tmp = Front;
    while(tmp != Rear)
    {
        cout << Qu[tmp] << " ";
        tmp = (tmp + 1) % MSize;
    }
    cout << endl;
}


int main()
{
    LoopQueue<int> lq = LoopQueue<int>(10);
    lq.enQueue(1);
    lq.enQueue(2);
    lq.enQueue(3);
    lq.enQueue(4);
    int item;
    lq.deQueue(item);
    lq.showAll();
    lq.enFront(0);
    lq.deRear(item);
    lq.showAll();
    return 0;
}

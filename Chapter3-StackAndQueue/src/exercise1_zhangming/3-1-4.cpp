// File:    3-1-4.cpp
// Author:  csh
// Date:    2020/10/24
// ===================


#include <stack>
#include <iostream>


template <typename T>
class QueueUsingStack
{
    private:
        std::stack<T> s1;           // 入队使用
        std::stack<T> s2;           // 出队使用
    public:
        QueueUsingStack(){}
        ~QueueUsingStack(){}
        bool isEmpty();
        bool enQueue(const T &item);
        bool deQueue(T &item);
};

template <typename T>
inline bool QueueUsingStack<T>::isEmpty()
{
    return s1.empty() && s2.empty();
}

template <typename T>
inline bool QueueUsingStack<T>::enQueue(const T &item)
{
    s1.push(item);
    return true;
}

template <typename T>
bool QueueUsingStack<T>::deQueue(T &item)
{
    using std::cout;
    using std::endl;
    if(isEmpty())
    {
        cout << "栈空，不能出栈" << endl;
        return false;
    }
    if(s2.empty())
    {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }
    item = s2.top();
    s2.pop();
    return true;
}


int main()
{
    using namespace std;
    QueueUsingStack<int> tem;
    tem.enQueue(100);
    tem.enQueue(101);
    tem.enQueue(200);
    tem.enQueue(201);
    tem.enQueue(300);
    int ret;
    while(!tem.isEmpty())
    {
        tem.deQueue(ret);
        cout << ret << endl;
    }
    return 0;
}

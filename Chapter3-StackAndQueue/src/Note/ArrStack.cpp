// File:    ArrStack.cpp
// Author:  csh
// Date:    2021/02/21
// ===================


#include <iostream>

template <typename T>
class ArrStack
{
    private:
        int MSize;                          // 栈的大小
        int Top;                            // 栈顶位置
        T *St;                              // 栈的数组
    public:
        ArrStack(int size): MSize(size), Top(-1), St(new T[size]){}
        ~ArrStack()
        {
            delete [] St;
        }

        void clear();                       // 清空栈元素
        bool push(const T item);            // 入栈
        bool pop(T &item);                  // 出栈
        bool peek(T &item);                 // 返回栈顶元素
        bool isEmpty();                     // 判断栈空
        bool isFull();                      // 判断栈满
};

template <typename T>
void ArrStack<T>::clear()
{
    Top = -1;
}

template <typename T>
bool ArrStack<T>::push(const T item)
{
    using std::cout;
    if(isFull())
    {
        cout << "栈满\n";
        return false;
    }
    St[++Top] = item;
    return true;
}

template <typename T>
bool ArrStack<T>::pop(T &item)
{
    using std::cout;
    if(isEmpty())
    {
        cout << "栈空，不能出栈\n";
        return false;
    }
    item = St[Top--];
    return true;
}

template <typename T>
bool ArrStack<T>::peek(T &item)
{
    using std::cout;
    if(isEmpty())
    {
        cout << "栈顶无元素，无法出栈\n";
        return true;
    }
    item = St[Top];
    return true;
}

template <typename T>
inline bool ArrStack<T>::isEmpty()
{
    return Top == -1;
}

template <typename T>
inline bool ArrStack<T>::isFull()
{
    return Top == MSize - 1;
}

// File:    3-1-3.cpp
// Author:  csh
// Date:    2020/05/30
// Update:  2020/02/27
// ===================


#include "../../include/LinearList.hpp"


template <typename T>
class NewLink:public LinkList<T>
{
    public:
        void invert();                      // 置逆方法
};

template <typename T>
void NewLink<T>::invert()
{
    Link<T> *middle, *trail;
    middle = this->Head->Next;               // first为第一个节点
    this->Head->Next = nullptr;
    while(middle)
    {
        trail = middle->Next;
        middle->Next = this->Head->Next;
        this->Head->Next = middle;
        middle = trail;
    }
}

int main()
{
    using namespace std;
    NewLink<int> a = NewLink<int>();
    a.append(1);
    a.append(2);
    a.append(3);
    a.append(4);
    a.showAll();
    a.invert();
    a.showAll();

}

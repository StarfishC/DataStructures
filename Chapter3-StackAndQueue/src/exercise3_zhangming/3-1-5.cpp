// File:    3-1-5.cpp
// Author:  csh
// Date:    2020/06/02
// Update:  2021/02/27
// ===================


#include <iostream>
#include "../../include/LinearList.hpp"

template <typename T>
class LoopLink
{
    protected:
        Link<T> *Head;
    public:
        LoopLink(): Head(new Link<T>())
        {
            Head->Next = Head; 
        }
        ~LoopLink()
        {
            Link<T> *tmp, *Next;
            tmp = Head->Next;
            while(tmp != nullptr){
                Next = tmp->Next;
                delete tmp;
                tmp = Next;
            }
            delete Head;
        }


        bool addValue(const T &value);
        int length() const;
};

template <typename T>
bool LoopLink<T>::addValue(const T &value)
{
    Link<T> *last = Head;
    while(last->Next != Head)
        last = last->Next;
    Link<T> *tmp = new Link<T>(value);
    tmp->Next = last->Next;
    last->Next = tmp;
    return true;
}

template <typename T>
int LoopLink<T>::length() const
{
    Link<T> *tmp = Head;
    int count = 0;
    while(tmp->Next != Head)
    {
        tmp = tmp->Next;
        count++;
    }
    return count;
}


int main()
{
    using namespace std;
    LoopLink<int> A = LoopLink<int>();
    A.addValue(1);
    A.addValue(2);
    A.addValue(3);

    cout << "A length: " << A.length() << endl;
    return 0;
}

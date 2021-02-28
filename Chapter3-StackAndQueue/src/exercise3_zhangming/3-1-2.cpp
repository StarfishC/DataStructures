// File:    3-1-2.cpp
// Author:  csh
// Date:    2020/05/30
// Update:  2021/02/27
// ===================


#include <iostream>
#include "../../include/LinearList.hpp"


template <typename T>
class NewLink:public LinkList<T>
{
    public:
        void insert(const T &value1, const T &value2)
        {
            using namespace std;
            Link<T> *tmp = this->Head;
            int count;
            while(tmp && tmp->Next)
            {
                if(tmp->Next->Data == value1)
                {
                    Link<T> *p = new Link<T>(value2);
                    p->Next = tmp->Next;
                    tmp->Next = p;
                    tmp = p;        // 因加入一个结点，需要指向该结点，才能指向下一个为访问结点
                    count++;
                }
                tmp = tmp->Next;
            }
            if(count == 0)
                cout << "No such an element" << endl;
        }
};


int main()
{
    NewLink<int> a = NewLink<int>();
    a.append(2);
    a.append(3);
    a.append(3);
    a.append(4);
    a.append(4);
    a.insert(3, 1000);
    a.showAll();
}

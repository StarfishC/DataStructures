// File:    2-1-7.cpp
// Author:  csh
// Date:    2020/07/12
// Update:  2020/02/20
// ===================


#include "../../include/LinearList.hpp"


template <typename T>
class LinkList2:public LinkList<T>
{
    public:
        bool removeSame()
        {
            Link<T> *pre, *cur;
            pre = this->Head->Next;
            cur = pre->Next;
            while(cur){
                if(pre->Data == cur->Data)
                {
                    pre->Next = cur->Next;
                    delete cur;
                    cur = pre->Next;
                }else
                {
                    pre = pre->Next;
                    cur = pre->Next;
                }
            }
            return true;
        }
};


int main()
{
    LinkList2<int> a = LinkList2<int>();
    a.append(2);
    a.append(2);
    a.append(2);
    a.append(2);
    a.append(3);
    a.removeSame();
    a.showAll();
    return 0;
}

// File:    2-3-5.cpp
// Author:  csh
// Date:    2020/07/12
// Update:  2020/02/20
// ===================


#include <iostream>
#include "../../include/LinearList.hpp"


// 创建一个循环链表类
// 若加入尾指针会更方便
template <typename T>
class LoopLink
{
    protected:
        Link<T> *Head;
    public:
        LoopLink()
        {
            Head = new Link<T>;
            Head->Next = Head;
        }
        ~LoopLink()
        {
            Link<T> *tmp, *next;
            tmp = Head->Next;           // 取第一个节点
            while(tmp != Head)
            {
                next = tmp->Next;
                delete tmp;
                tmp = next;
            }
            delete Head;
        }
        bool addLink(Link<T> *l)
        {
            Link<T> *p = Head;
            // 找到循环链表最后一个节点
            while(p->Next != Head)
                p = p->Next;
            l->Next = Head;
            p->Next = l;
            return true;
        }
        bool addValue(const T c)
        {
            Link<T> *tmp;
            tmp = new Link<T>(c);
            if(addLink(tmp))
                return true;
            return false;
        }
        void showAll()
        {
            using std::cout;
            using std::endl;
            Link<T> *tmp;
            tmp = Head->Next;
            while(tmp != Head)
            {
                cout << tmp->Data << "  ";
                tmp = tmp->Next;
            }
            cout << endl;
        }
};

template <typename T>
class LinkList2:public LinkList<T>
{
    public:
        Link<T>* getHead()
        {
            return this->Head;
        }
        void resetHead()
        {                         // 设置头节点下一个节点为nullptr，方便析构
            this->Head->Next = nullptr;
        }
};

void split(LinkList2<char>* L, LoopLink<char>* a, LoopLink<char>* d, LoopLink<char>* o)
{
    Link<char> *tmp = L->getHead()->Next;
    L->resetHead();
    Link<char> *save;
    while(tmp)
    {
        save = tmp->Next;
        if(tmp->Data <= '9' && tmp->Data >= '0')
            d->addLink(tmp);
        else if((tmp->Data <= 'Z' && tmp->Data >= 'A') || (tmp->Data <= 'z' && tmp->Data >= 'a'))
            a->addLink(tmp);
        else
            o->addLink(tmp);
        tmp = save;
    }
}

int main()
{
    LinkList2<char> *a = new LinkList2<char>;
    LoopLink<char> *x = new LoopLink<char>();
    LoopLink<char> *y = new LoopLink<char>();
    LoopLink<char> *z = new LoopLink<char>();

    a->append('a');
    a->append('b');
    a->append('2');
    a->append('%');
    a->append('1');
    a->showAll();

    split(a, x, y, z);
    x->showAll();
    y->showAll();
    z->showAll();

    delete a;
    delete x;
    delete y;
    delete z;
    return 0;
}

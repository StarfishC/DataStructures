// File:    2-14.cpp
// Author:  csh
// Date:    2021/03/14
// ===================



typedef int T;
typedef struct LNode* LinkList;
struct LNode
{
    T data;
    struct LNode* next;
};


void Del_x(LinkList L, T x)
{
    LinkList p;             // 指向待删结点
    if(L == nullptr)
        return;
    if(L->data == x)
    {
        p = L;
        L = L->next;
        delete p;
        Del_x(L, x);
    }
    else
        Del_x(L->next, x);
}



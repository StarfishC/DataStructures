// File:    2-24.cpp
// Author:  csh
// Date:    2021/3/20
// ===================


typedef int ElementType;
typedef struct LNode* LinkList;
struct LNode
{
    ElementType data;
    struct LNode* next;
};


LinkList DisCreat_2(LinkList &A)
{
    LinkList B = new struct LNode;
    B->next = nullptr;
    LNode *p = A->next;
    LNode *ra = A;
    LNode *q;
    while(p != nullptr)
    {
        ra->next = p;
        ra = p;
        p = p->next;
        if(p != nullptr)
            q = p->next;         // 头插法，*p断链，因此用q记录后继
        p->next = B->next;
        B->next = p;
        p = q;
    }
    ra->next = nullptr;
    return B;
}

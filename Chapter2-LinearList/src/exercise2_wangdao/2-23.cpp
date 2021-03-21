// File:    2-23.cpp
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


LinkList DisCreat_1(LinkList &A)
{
    int i = 0;                  // 记录表A中的结点序号
    LinkList B = (LinkList) new struct LNode;
    B->next = nullptr;
    LNode *ra = A;
    LNode *rb = B;

    LNode *p = A->next;
    A->next = nullptr;
    while(p != nullptr)
    {
        i++;
        if(i % 2 == 0)          // 序号为偶数时
        {
            rb->next = p;
            rb = p;
        }
        else
        {
            ra->next = p;
            ra = p;
        }
        p = p->next;
    }
    ra->next = nullptr;
    rb->next = nullptr;
    return B;
}

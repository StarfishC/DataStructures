// File:    2-38.cpp
// Author:  csh
// Date:    2021/3/20
// ===================


typedef struct node
{
    int data;
    struct node *next;
}NODE;

void change_list(NODE *h)
{
    NODE *p, *q, *r, *s;
    p = q = h;
    while(q->next != nullptr)
    {
        p = p->next;                            // p走一步
        q = q->next;                            // q走两步
        if(q->next != nullptr) q = q->next;
    }
    q = p->next;                                // q为后半段链表的首结点
    p->next = nullptr;
    while(q != nullptr)                         // 后半段逆置
    {
        r = q->next;
        q->next = p->next;
        p->next = q;
        q = r;
    }
    s = h->next;                                // s为前半段第一个数据结点
    q = p->next;                                // q为后半段第一个数据结点
    p->next = nullptr;
    while(q != nullptr)
    {
        r = q->next;
        q->next = s->next;
        s = q->next;
        q = r;
    }
}

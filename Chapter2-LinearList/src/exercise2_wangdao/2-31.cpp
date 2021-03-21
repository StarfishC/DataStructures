// File:    2-31.cpp
// Author:  csh
// Date:    2021/3/20
// ===================


LinkList Link(LinkList &h1, LinkList &h2)
{
    LNode *p, *q;               // 分别指向两个链表的尾结点
    p = h1;
    while(p->next != h1)
        p = p->next;
    q = h2;
    while(p->next != h2)
        q = q->next;
    p->next = h2;
    q->next = h1;
    return h1;
}

// File:    2-33.cpp
// Author:  csh
// Date:    2021/3/20
// ===================


DLinkList Locate(DLinkList &L, ElementType x)
{
    DNode *p = L->next, *q;         // p为工作指针，q是p的前驱，用于查找插入位置
    while(p && p->data != x)
        p = p->next;
    if(!p)
    {
        cout << "不存在值为x的结点“" << endl;
        exit(0);
    }
    else
    {
        p->freq++;                  // 令元素值为x的结点的freq域加1
        if(p->next != nullptr)
            p->next->pred = p->pred;
        p->pred->next = p->next;    // p结点从链表摘下
        q = p->pred;
        while(q != L && q->freq <= p->freq)
            q = q->pred;
        p->next = q->next;
        q->next->pred = p;          // 将p结点插入
        p->pred = q;
        q->next = p;
    }
    return p;
}

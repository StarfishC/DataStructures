// File:    2-32.cpp
// Author:  csh
// Date:    2021/3/20
// ===================


void Del_All(LinkList &L)
{
    LNode *p, *pre, *minp, *minpre;
    while(L->Next != L)
    {
        p = L->next;
        pre = L;
        minp = p;
        minpre = pre;
        while(p != L)           // 循环一遍，查找最小值结点
        {
            if(p->data < minp->data)
            {
                minp = p;
                minpre = pre;
            }
            pre = p;
            p = p->next;
        }
        cout << minp->data << " ";
        minpre->next = minp->next;  // 最小直接点从原链表断开
        delete minpre;
    }
    delete L;
}

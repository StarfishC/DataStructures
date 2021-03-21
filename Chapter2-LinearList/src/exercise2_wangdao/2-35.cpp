// File:    2-35.cpp
// Author:  csh
// Date:    2021/3/21
// ===================


typedef struct Node
{
    char data;
    struct Node *next;
}SNode;

int listlen(SNode *head)
{
    int len = 0;
    while(head->next != nullptr)
    {
        len ++;
        head = head->next;
    }
    return len;
}


SNode* find_addr(SNode *str1, SNode *str2)
{
    int m, n;
    SNode *p, *q;
    m = listlen(str1);
    n = listlen(str2);
    for(p = str1; m > n; m--)           // 若m>n;使p指向链表中的第m-n+1个结点
        p = p->next;
    for(q = str2; m < n; n--)           // 若m<n,使q指向链表中的第n-m+1个结点
        q = q->next;
    while(p->next != nullptr && p->next != q->next)
    {
        p = p->next;
        q = q->next;
    }
    return p->next;
}

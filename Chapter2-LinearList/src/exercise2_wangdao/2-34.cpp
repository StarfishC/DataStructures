// File:    2-34.cpp
// Author:  csh
// Date:    2021/3/20
// ===================


#include <iostream>

typedef int ElementType;
typedef struct LNode
{
    ElementType data;
    struct LNode *link;
}LNode, *LinkList;


int Search_k(LinkList list, int k)
{
    LNode *p = list->link;
    LNode *q = list->link;
    int count = 0;
    while(p != nullptr)             // 遍历直到最后一个结点
    {
        if(count < k) count++;
        else q = q->link;
        p = p->link;
    }
    if(count < k)
        return 0;
    else
    {
        std::cout << q->data << " ";
        return 1;
    }
}

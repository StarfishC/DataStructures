// File:    2-21.cpp
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

int Length(LinkList);

LinkList Search_1st_Command(LinkList L1, LinkList L2)
{
    int len1 = Length(L1), len2 = Length(L2);       // 计算两个链表的表长
    LinkList longList, shortList;                   // 分别指向较长和较短的链表
    int dist;
    if(len1 > len2)
    {
        longList = L1->next;
        shortList = L2->next;
        dist = len1 - len2;
    }
    else
    {
        longList = L2->next;
        shortList = L1->next;
        dist = len2 - len1;
    }
    while(dist--)           // 表长的链表先遍历到第dist个结点
        longList = longList->next;
    while(longList != nullptr)
    {
        if(longList == shortList)
            return longList;
        else
        {
            longList = longList->next;
            shortList = shortList->next;
        }
    }
    return nullptr;
}

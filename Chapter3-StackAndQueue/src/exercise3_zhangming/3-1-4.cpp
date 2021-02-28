// File:    3-1-4.cpp
// Author:  csh
// Date:    2020/06/02
// ===================


typedef int Elem;
typedef struct DbListNode* DbList;

// 双链表节点
struct DbListNode
{
    Elem data;              // 数字域
    DbList rlink;           // 右(后)指针
    DbList llink;           // 左(前)指针
};

// 双链表结构
struct List
{
    DbList first, last;
};


void Insert(DbList F, DbList P, List *X)
{
    // 先判断P是否是头节点
    if(P == X->first)
    {
        F->rlink = P;
        P->llink = F;
        X->first = F;
    }else
    {
        // F->rlink = P;
        F->llink = P->llink;    // F左边的指针指向P左边的指针
        P->llink->rlink = F;    // P左边节点的右指针指向F
        P->llink = F;
    }
}

// File:    LinkList.c
// Author:  csh
// Date:    2021/02/20
// ===================


#include <stdio.h>
#include <stdlib.h>


typedef int ElementType;

typedef struct LNode* List;
struct LNode
{
    ElementType Data;
    List Next;
};

// 求表长
int Length(List Ptrl)
{
    List P = Ptrl;
    int count;
    while(P)
    {
        P = P->Next;
        count++;
    }
    return count;
}

// 按序号查找元素
List FindKth(int K, List Ptrl)
{
    List P = Ptrl;
    int i = 1;
    while(P != NULL && i < K)
    {
        P = P->Next;
        i++;
    }
    if(i == K) return P;
    else return NULL;
}

// 按值查找
List Find(ElementType X, List Ptrl)
{
    List P = Ptrl;
    while(P != NULL && P->Data != X)
        P = P->Next;
    return P;
}

// 插入
List Insert(ElementType X, int i, List Ptrl)
{
    List p, s;
    if(i == 1)                  // 第一个结点插入表头
    {
        s = (List)malloc(sizeof(struct LNode));
        s->Data = X;
        s->Next = Ptrl;
        return s;
    }
    p = FindKth(i-1, Ptrl);     // 找到第i-1个结点
    if(p == NULL)
    {
        printf("参数i错误");
        return NULL;
    }else
    {
        s = (List)malloc(sizeof(struct LNode));
        s->Data = X;
        s->Next = p->Next;
        p->Next = s;
        return Ptrl;
    }
}

// 删除
List Delete(int i, List Ptrl)
{
    List p, s;
    if(i == 1)                  // 删除的是第一个结点
    {
        s = Ptrl;
        if(Ptrl != NULL) Ptrl = Ptrl->Next;
        else return NULL;
        free(s);
        return Ptrl;
    }
    p = FindKth(i-1, Ptrl);
    if(p == NULL)
    {
        printf("第%d个结点不存在\n", i-1);
        return NULL;
    }else if(p->Next == NULL)
    {
        printf("第%d个结点不存在\n", i);
        return NULL;
    }else
    {
        s = p->Next;
        p->Next = s->Next;
        free(s);
        return Ptrl;
    }
}

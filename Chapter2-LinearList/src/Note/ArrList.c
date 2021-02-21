// File:    ArrList.c
// Author:  csh
// Date:    2021/02/20
// ===================


#include <stdlib.h>
#include <stdio.h>

#define MAXSIZE 100

typedef int ElementType;

typedef struct LNode* List;
struct LNode
{
    ElementType Data[MAXSIZE];
    int Last;   // 线性表最后一个元素
};

// 建立空表
List MakeEmpty()
{
    List Ptrl;
    Ptrl = (List)malloc(sizeof(struct LNode));
    Ptrl->Last = -1;
    return Ptrl;
}

// 查找元素
int Find(ElementType X, List Ptrl)
{
    int i = 0;
    while(i <= Ptrl->Last && Ptrl->Data[i] != X)
        i++;
    if(i > Ptrl->Last) return -1;       // 没找到返回-1
    else return i;                      // 返回的是存储位置
}

// 第i个位置上插入元素
void Insert(ElementType X, int i, List Ptrl)
{
    int j;
    if(Ptrl->Last == MAXSIZE)
    {
        printf("表满，无法插入新元素!\n");
        return;
    }
    if(i < 1 || i > Ptrl->Last+2)
    {
        printf("位置不合法!\n");
        return;
    }
    for(int j = Ptrl->Last; j >= i-1; j--)
        Ptrl->Data[j+1] = Ptrl->Data[j];
    Ptrl->Data[i-1] = X;
    Ptrl->Last++;
    return;
}

// 删除第i个位置的元素
void Delete(int i, List Ptrl)
{
    if(i < 1 || i > Ptrl->Last+1)
    {
        printf("不存在第%d个元素\n", i);
        return;
    }
    for(int j = i; j <= Ptrl->Last; j++)
        Ptrl->Data[j-1] = Ptrl->Data[j];
    Ptrl->Last--;
    return;
}

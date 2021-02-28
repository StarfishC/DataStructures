// File:    ArrStack.c
// Author:  csh
// Date:    2021/02/21
// ===================


#include <stdlib.h>
#include <stdio.h>

#define MaxSize 100
#define ERROR -100

typedef int ElementType;

typedef struct SNode* Stack;
struct SNode
{
    ElementType Data[MaxSize];
    int Top;
};

Stack CreateStack()
{
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Top = -1;
    return S;
}

void Push(Stack PtrS, ElementType item)
{
    if(PtrS->Top == MaxSize - 1)
    {
        printf("栈满\n");
        return;
    }else
    {
        PtrS->Data[++(PtrS->Top)] = item;
        return;
    }
}

ElementType Pop(Stack PtrS)
{
    if(PtrS->Top == -1)
    {
        printf("栈空");
        return ERROR;           // ERROR是ElementType特殊值，标志错误
    }else
    {
        return (PtrS->Data[PtrS->Top--]);
    }
}

// File:    example1.c
// Author:  csh
// Date:    2021/02/21
// ===================


#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100
#define ERROR -100

typedef int ElementType;

struct DStack
{
    ElementType Data[MaxSize];
    int Top1;           // 栈1的栈顶指针
    int Top2;           // 栈2的栈顶指针
};

struct DStack* CreateStack()
{
    struct DStack *S = (struct DStack*)malloc(sizeof(struct DStack));
    S->Top1 = -1;
    S->Top2 = MaxSize;
    return S;
}

// 入栈
void Push(struct DStack *PtrS, ElementType item, int Tag)
{
    // Tag区分栈1,2
    if(PtrS->Top2 - PtrS->Top1 == 1)
    {
        printf("栈满");
        return;
    }
    if(Tag == 1)
        PtrS->Data[++PtrS->Top1] = item;
    else
        PtrS->Data[--PtrS->Top2] = item;
}

// 出栈
ElementType Pop(struct DStack *PtrS, int Tag)
{
    if(Tag == 1)
    {
        if(PtrS->Top1 == -1)
        {
            printf("栈1空\n");
            return ERROR;
        }
        return PtrS->Data[PtrS->Top1--];
    }else
    {
        if(PtrS->Top2 == MaxSize)
        {
            printf("栈2空\n");
            return ERROR;
        }
        return PtrS->Data[PtrS->Top2--];
    }
}

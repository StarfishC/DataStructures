// File:    LinkStack.c
// Author:  csh
// Date:    2021/02/21
// ===================


#include <stdlib.h>
#include <stdio.h>

typedef int ElementType;

typedef struct SNode* Stack;
struct SNode
{
    ElementType Data;
    Stack Next;
};

// 建立空栈
Stack CreateStack()
{
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Next = NULL;
    return S;
}

// 判断栈空
int IsEmpty(Stack S)
{
    return S->Next == NULL;
}

// 入栈
void Push(ElementType item, Stack S)
{
    Stack TmpCell;
    TmpCell = (Stack)malloc(sizeof(struct SNode));
    TmpCell->Data = item;
    TmpCell->Next = S->Next;
    S->Next = TmpCell;
}

// 出栈
ElementType Pop(Stack S)
{
    Stack FirstCell;
    ElementType TopData;
    if(IsEmpty(S))
    {
        printf("栈空");
        return NULL;
    }else
    {
        FirstCell = S->Next;
        S->Next = FirstCell->Next;
        TopData = FirstCell->Data;
        free(FirstCell);
        return TopData;
    }
}

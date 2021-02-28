// File:    LinkQueue.c
// Author:  csh
// Date:    2021/02/21
// ===================


#include <stdlib.h>
#include <stdio.h>

#define ERROR -999
typedef int ElementType;

struct Node
{
    ElementType Data;
    struct Node* Next;
};

typedef struct QNode* Queue;
struct QNode
{
    struct Node* rear;
    struct Node* front;
};

void AddQ(Queue PtrQ, ElementType item)
{
    struct Node* TmpNode;
    if(PtrQ->front == NULL)
    {
        // 队列没有元素
        TmpNode = (struct Node*)malloc(sizeof(struct Node));
        TmpNode->Data = item;
        TmpNode->Next = NULL;
        PtrQ->front = PtrQ->rear = TmpNode;
    }else
    {
        // 队列已有元素
        TmpNode = (struct Node*)malloc(sizeof(struct Node));
        TmpNode->Data = item;
        TmpNode->Next = PtrQ->rear;
        PtrQ->rear = TmpNode;
    }
}

ElementType DeleteQ(Queue PtrQ)
{
    struct Node* FrontCell;
    ElementType FrontElem;

    if(PtrQ->front == NULL)
    {
        printf("队列空");
        return ERROR;
    }
    FrontCell = PtrQ->front;
    if(PtrQ->front == PtrQ->rear)
        // 只有一个元素
        PtrQ->front = PtrQ->rear = NULL;
    else
        PtrQ->front = PtrQ->front->Next;
    FrontElem = FrontCell->Data;
    free(FrontCell);
    return FrontElem;
}

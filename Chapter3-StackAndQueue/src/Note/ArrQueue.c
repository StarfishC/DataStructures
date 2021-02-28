// File:    ArrQueue.c
// Author:  csh
// Date:    2021/02/21
// ===================


#include <stdio.h>
#include <stdlib.h>

#define ERROR -999
#define MaxSize 100

typedef int ElementType;

typedef struct QNode* Queue;
struct QNode
{
    ElementType Data[MaxSize];
    int rear;
    int front;
};

Queue CreateQueue()
{
    Queue Q = (Queue)malloc(sizeof(struct QNode));
    Q->front = Q->rear = 0;
    return Q;
}

void AddQ(Queue PtrQ, ElementType item)
{
    if((PtrQ->rear + 1) % MaxSize == PtrQ->front)
    {
        printf("队列满\n");
        return;
    }
    PtrQ->Data[PtrQ->rear] = item;
    PtrQ->rear = (PtrQ->rear + 1) % MaxSize;
}

ElementType DeleteQ(Queue PtrQ)
{
    if(PtrQ->front == PtrQ->rear)
    {
        printf("队列空");
        return ERROR;
    }else
    {
        ElementType item = PtrQ->Data[PtrQ->front];
        PtrQ->front = (PtrQ->front+1) % MaxSize;
        return item;
    }
}

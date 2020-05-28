// File:    队列.c
// Author:  csh
// Date:    2020/05/28
// ===================

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
typedef int bool;

// ************************** 队列的顺序存储 ********************************* //
#define MAXSIZE 1000
typedef int ElementType;
typedef struct ArrList* ArrQueue;

struct ArrList{
    ElementType queue[MAXSIZE+1];
    int front;
    int rear;
};

ArrQueue InitArrQueue();                                // 初始化一个队列
void DestoryArrQueue(ArrQueue q);                       // 销毁一个队列
void clearArrQueue(ArrQueue q);                         // 清空队列
bool isEmptyArrQueue(ArrQueue q);                       // 判断队列是否为空
bool isFullArrQueue(ArrQueue q);                        // 判断队列是否满
bool enArrQueue(ArrQueue q, const ElementType item);    // 入队
bool deArrQueue(ArrQueue q, ElementType *item);         // 出队
bool peekArrQueue(ArrQueue q, ElementType *item);       // 返回队首元素
int sizeArrQueue(ArrQueue q);                           // 队列的大小

ArrQueue InitArrQueue(){
    ArrQueue q;
    q = (ArrQueue)malloc(sizeof(struct ArrList));
    q->front = q->rear = 0;
    return q;
}

void DestoryArrQueue(ArrQueue q){
    free(q);
}

void clearArrQueue(ArrQueue q){
    q->front = q->rear;
}

bool isFullArrQueue(ArrQueue q){
    if((q->rear + 1) % MAXSIZE == q->front)
        return TRUE;
    return FALSE;
}

bool isEmptyArrQueue(ArrQueue q){
    if(q->front == q->rear)
        return TRUE;
    return FALSE;
}

bool enArrQueue(ArrQueue q, const ElementType item){
    if(isFullArrQueue(q)){
        printf("队列满，不能入栈\n");
        return FALSE;
    }else{
        q->queue[q->rear] = item;
        q->rear = (q->rear + 1) % MAXSIZE;
        return TRUE;
    }
}

bool deArrQueue(ArrQueue q, ElementType *item){
    if(isEmptyArrQueue(q)){
        printf("队列空，不能出栈\n");
        return FALSE;
    }else{
        *item = q->queue[q->front];
        q->front = (q->front + 1) % MAXSIZE;
        return TRUE;
    }
}

bool peekArrQueue(ArrQueue q, ElementType *item){
    if(isEmptyArrQueue(q)){
        printf("队列空，队首无元素\n");
        return FALSE;
    }else{
        *item = q->queue[q->front];
        return TRUE;
    }
}

int sizeArrQueue(ArrQueue q){
    if(isEmptyArrQueue(q)){
        return 0;
    }
    int count = 1;
    int tmp = q->front;
    while((tmp + 1) % MAXSIZE != q->rear){
        count ++;
        tmp ++;
    }
    return count;
}
// *************************************************************************** //


// ************************** 队列的顺序存储 ********************************* //
typedef struct QueueNode* LinkQueue;
typedef struct QNode* LNode;
typedef int T;

struct QNode{
    T data;
    LNode next;
};

struct QueueNode{
    LNode front;
    LNode rear;
};

LinkQueue InitLinkQueue();                                // 初始化一个队列
void DestoryLinkQueue(LinkQueue q);                       // 销毁一个队列
void clearLinkQueue(LinkQueue q);                         // 清空队列
bool isEmptyLinkQueue(LinkQueue q);                       // 判断队列是否为空
bool enLinkQueue(LinkQueue q, const ElementType item);    // 入队
bool deLinkQueue(LinkQueue q, ElementType *item);         // 出队
bool peekLinkQueue(LinkQueue q, ElementType *item);       // 返回队首元素
int sizeLinkQueue(LinkQueue q);                           // 队列的大小

LinkQueue InitLinkQueue(){
    LinkQueue q;
    q = (LinkQueue)malloc(sizeof(struct QueueNode));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void clearLinkQueue(LinkQueue q){
    LNode tmp = q->front;
    while(tmp){
        q->front = q->front->next;
        free(tmp);
        tmp = q->front;
    }
    q->front = NULL;
    q->rear = NULL;
}

void DestoryLinkQueue(LinkQueue q){
    clearLinkQueue(q);
    free(q);
}

bool isEmptyLinkQueue(LinkQueue q){
    return q->front == NULL;
}

int sizeLinkQueue(LinkQueue q){
    int count = 0;
    if(q->front != NULL){
        LNode tmp = q->front;
        while(tmp != NULL){
            count ++;
            tmp = tmp->next;
        }
    }
    return count;
}

bool enLinkQueue(LinkQueue q, const  T item){
    LNode tmp;
    tmp = (LNode)malloc(sizeof(struct QNode));
    tmp->data = item;
    if(!q->rear){
        q->rear = q->front = tmp;
        tmp->next = NULL;
    }else{
        q->rear->next = tmp;
        q->rear = tmp;
    }
    return TRUE;
}

bool deLinkQueue(LinkQueue q, T *item){
    if(isEmptyLinkQueue(q)){
        printf("队列空，不能出栈\n");
        return FALSE;
    }else{
        *item = q->front->data;
        q->front = q->front->next;
        return TRUE;
    }
}

bool peekLinkQueue(LinkQueue q, T *item){
    if(isEmptyLinkQueue(q)){
        printf("队列空，队首无元素\n");
        return FALSE;
    }else{
        *item = q->front->data;
        return TRUE;
    }
}

// *************************************************************************** //

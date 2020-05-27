// File:    栈.c
// Author:  csh
// Date:    2020/05/24
// ===================


#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
typedef int bool;

// ************************** 栈的顺序存储 *********************************//
#define maxSize 1000
typedef int ElementType;
typedef struct AStack* ArrStack;

struct AStack{
    ElementType data[maxSize];                      // 栈的数组
    int size;                                       // 栈的大小
};

ArrStack InitArrStack();                            // 创建一个队列
bool clearArrStack(ArrStack S);                     // 清空栈
bool DestroyArrStack(ArrStack S);                   // 销毁一个栈
bool isEmptyArrStack(ArrStack S);                   // 判断是否栈空
bool isFullArrStack(ArrStack S);                    // 判断是否栈满
bool pushArrStack(ArrStack S, ElementType item);    // 入栈
bool peekArrStack(ArrStack S, ElementType *item);   // 返回栈顶元素
bool popArrStack(ArrStack S, ElementType *item);    // 出栈

ArrStack InitArrStack(){
    ArrStack s;
    s = (ArrStack)malloc(sizeof(struct AStack));
    s->size = 0;
    return s;
}

bool DestroyArrStack(ArrStack S){
    free(S);
    return TRUE;
}

bool clearArrStack(ArrStack S){
    S->size = 0;
    return TRUE;
}

bool isEmptyArrStack(ArrStack S){
    return S->size == 0;
}

bool isFullArrStack(ArrStack S){
    return S->size == maxSize;
}

bool pushArrStack(ArrStack S, ElementType item){
    if(isFullArrStack(S)){
        printf("栈满，不能入栈\n");
        return FALSE;
    }
    S->data[(S->size)++] = item;
    return TRUE;
}

bool popArrStack(ArrStack S, ElementType *item){
    if(isEmptyArrStack(S)){
        printf("栈空，不能出栈\n");
        return FALSE;
    }else{
        *item = S->data[--(S->size)];
        return TRUE;
    }
}

bool peekArrStack(ArrStack S, ElementType *item){
    if(isEmptyArrStack(S)){
        printf("栈空，栈顶无元素\n");
        return FALSE;
    }else{
        *item = S->data[(S->size)-1];
        return TRUE;
    }
}
// *************************************************************************//

// ************************** 栈的链式存储 *********************************//
typedef int T;
typedef struct List* LinkStack;

struct List{
    T data;
    LinkStack next;
};

LinkStack InitLinkStack();                            // 创建一个队列
bool clearLinkStack(LinkStack s);                     // 清空栈
bool isEmptyLinkStack(LinkStack s);                   // 判断是否栈空
bool pushLinkStack(LinkStack *s, T item);             // 入栈
bool peekLinkStack(LinkStack s, T *item);             // 返回栈顶元素
bool popLinkStack(LinkStack *s, T *item);             // 出栈

LinkStack InitLinkStack(){
    LinkStack s;
    s = NULL;
    return s;
}

bool clearLinkStack(LinkStack s){
    LinkStack tmp = s;
    s = NULL;
    while(tmp){
        free(tmp);
        tmp = tmp->next;
    }
    return TRUE;
}

bool isEmptyLinkStack(LinkStack s){
    return s == NULL;
}

bool pushLinkStack(LinkStack *s, T item){
    LinkStack tmp;
    tmp = (LinkStack)malloc(sizeof(struct List));
    tmp->data = item;
    tmp->next = *s;
    *s = tmp;
    return TRUE;
}

bool popLinkStack(LinkStack *s, T *item){
    if(isEmptyLinkStack(*s)){
        printf("栈空，不能出栈\n");
        return FALSE;
    }else{
        LinkStack tmp;
        tmp = *s;
        *s = tmp->next;
        *item = tmp->data;
        free(tmp);
        return FALSE;
    } 
}

bool peekLinkStack(LinkStack s, T *item){
    if(isEmptyLinkStack(s)){
        printf("栈空，栈顶无元素\n");
        return FALSE;
    }else{
        *item = s->data;
        return TRUE;
    }
}

// *************************************************************************//

int main(){
    LinkStack a = InitLinkStack();
    pushLinkStack(&a, 1);
    printf("isempty: %d\n", isEmptyLinkStack(a));
    T item;
    popLinkStack(&a, &item);
    pushLinkStack(&a, 100);
    peekLinkStack(a, &item);
    printf("isempty: %d\n", isEmptyLinkStack(a));
    printf("%d\n", item);
}

// File:    线性表.c
// Author:  csh
// Date:    2020/05/23
// ===================


#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define OK 1

typedef int bool;


// ************************** 线性表的顺序存储 *********************************//
#define MAXSIZE 10000
typedef int ElemetType;

typedef struct Node *ArrList;
struct Node{
    ElemetType Data[MAXSIZE];
    int length;
};


// 初始化一个线性表
ArrList InitArrList(){
    ArrList Ptrl;
    Ptrl = malloc(sizeof(struct Node));
    if(!Ptrl) exit(-1);
    Ptrl->length = 0;
    return Ptrl;
}

// 清空线性表所有元素
void clearArrList(ArrList Ptrl){
    for(int i = 0; i < Ptrl->length; i++)
        Ptrl->Data[i] = 0;
    Ptrl->length = 0;
}

// 显示所有元素
void showAllArrList(ArrList Ptrl){
    for(int i = 0; i < Ptrl->length; i++)
        printf("%d ", Ptrl->Data[i]);
    printf("\n");
}

// 线性表的长度
int lenArrList(ArrList Ptrl){
    return Ptrl->length;
}

// 表尾添加一个元素
bool appendArrList(ArrList Ptrl, const ElemetType value){
    if(Ptrl->length >= MAXSIZE){
        printf("OVERFLOW!");
        return FALSE;
    }
    Ptrl->Data[(Ptrl->length)++] = value;
    return TRUE;
}

// 位置i插入一个元素
bool insertArrList(ArrList Ptrl, const int i, const ElemetType value){
    if(i < 1 || i > Ptrl->length+1){
        printf("Insertion point is illegal");
        return FALSE;
    }
    if(Ptrl->length == MAXSIZE){
        printf("List Full");
        return FALSE;
    }
    for(int j = Ptrl->length-1; j >= i-1; j--){
        Ptrl->Data[j+1] = Ptrl->Data[j];
    }
    Ptrl->Data[i-1] = value;
    Ptrl->length ++;
    return TRUE;
}

// 移除位置i的元素
bool removeArrList(ArrList Ptrl, const int i){
    if(i < 1|| i > Ptrl->length){
        printf("Removal point is illegal");
        return FALSE;
    }
    for(int j = i; j <= Ptrl->length-1; j++)
        Ptrl->Data[j-1] = Ptrl->Data[j];
    Ptrl->length --;
    return TRUE;
}

// 获取位置i的元素值
bool getValueArrList(ArrList Ptrl, const int i, ElemetType *value){
    if(i < 1 || i > Ptrl->length){
        printf("Location is illegal");
        return FALSE;
    }
    *value = Ptrl->Data[i-1];
    return TRUE;
}

// 获取位置元素值对应的位置
bool getPosArrList(ArrList Ptrl, ElemetType *p, const ElemetType value){
    int i = 0;
    while(i < Ptrl->length && Ptrl->Data[i] != value)
        i++;
    if(i >= Ptrl->length)
        return FALSE;
    *p = i+1;
    return TRUE;
}

// *********************************************************************//


// ************************** 线性表的链式存储 *********************************//

   /*
   这里和C++写法不同，没有定义尾指针，所以添加元素等操作都有所不同，显示所有
   元素时可发现是逆序显示
   */

typedef int T;
typedef struct List* LinkList;

struct List
{
    T data;
    LinkList next;
};

LinkList InitLinkList()
{
    LinkList L;
    L = NULL;                   // 这里没有malloc，和C++链表写法有思想上差异
    return L;
}

void clearLinkList(LinkList Ptrl){
    if(!(Ptrl))
        return;
    else{
        LinkList tmp = (Ptrl)->next;
        while(tmp){
            free(tmp);
            tmp = tmp->next;
        }
    }
}

void showAllLinkList(LinkList Ptrl){
    LinkList tmp = Ptrl;
    while(tmp){
        T value = tmp->data;
        tmp = tmp->next;
        printf("%d \t", value);
    }
    printf("\n");
}

int lenLinkList(LinkList Ptrl){
    int count = 0;
    LinkList tmp = Ptrl;
    while(tmp){
        tmp = tmp->next;
        count ++;
    }
    return count;
}

bool getListLinkList(LinkList Ptrl, const int i, LinkList *L){
    LinkList tmp = Ptrl;
    int count = 1;
    while(count < i && tmp){
        tmp = tmp->next;
        count++;
    }
    if(i == count && Ptrl){
        *L = tmp;
        return TRUE;
    }else{
        return FALSE;
    }
}

bool appendLinkList(LinkList *Ptrl, const T value){
    LinkList tmp;
    tmp = (LinkList)malloc(sizeof(struct List));
    if(!tmp)
        return FALSE;
    tmp->data = value;
    tmp->next = *Ptrl;
    *Ptrl = tmp;
    return TRUE;
}

bool insertLinkList(LinkList *Ptrl, const int i, const T value){
    if(i < 1 || i > lenLinkList(*Ptrl)+1){
        printf("Insertion point is illegal");
        return FALSE;
    }
    LinkList p, s;
    if(i == 1){
        p = (LinkList)malloc(sizeof(struct List));
        p->data = value;
        p->next = *Ptrl;
        *Ptrl = p;
    } 
    else{
        getListLinkList(*Ptrl, i-1, &s);
        p = (LinkList)malloc(sizeof(struct List));
        p->data = value;
        p->next = s->next;
        s->next = p;
    }
    return TRUE;
}

bool removeLinkList(LinkList *Ptrl, const int i){
    LinkList previous, current;
    current = *Ptrl;
    if(!current){
        printf("Removal is illegal");
        return FALSE;
    }
    if(i == 1){
        *Ptrl = (*Ptrl)->next;
        free(current);
    }else{
        int status = getListLinkList(*Ptrl, i-1, &previous);
        if(status){
            current = previous->next;
            previous->next = current->next;
            free(current);
        }
    }
    return TRUE;
}

bool getPosLinkList(LinkList Ptrl, T value, int *p){
    int count = 1;
    LinkList tmp = Ptrl;
    while(tmp){
        if(tmp->data == value){
            *p = count;
            return TRUE;
        }else{
            tmp = tmp->next;
            count++;
        }
    }
    return FALSE;
}

bool getValueLinkList(LinkList Ptrl, const int i, T *value){
    LinkList tmp = Ptrl;
    int count = 1;
    while(count < i && tmp){
        tmp = tmp->next;
        count++;
    }
    if(i == count && Ptrl){
        *value = tmp->data;
        return TRUE;
    }else{
        return FALSE;
    }
}

// *********************************************************************//

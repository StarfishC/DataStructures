// File:    2-3-8.cpp
// Author:  csh
// Date:    2020/07/18
// ===================



#include <stdio.h>
#include <stdlib.h>
#define INITSIZE 20         // 初始分配量
#define LISTINCREMENT 5     // 分配增量

typedef int ElemType;
typedef struct{
    ElemType *elem;
    int length;
    int listsize;
}SqList;


// 创建一个表长为n的顺序表
void InitList(SqList &L, int n){
    ElemType *p;
    L.elem = (ElemType *)malloc(INITSIZE*sizeof(ElemType));
    if(!L.elem)
        printf("分配失败");
    printf("请一次输入顺序表的元素:\n");
    for(p = L.elem; p < L.elem+n; p++)
        scanf("%d", p);
    L.length = n;
    L.listsize = INITSIZE;
}

// 输出顺序表
void PrintList(SqList L){
    ElemType *p;
    printf("输出顺序表中的元素\n");
    for(p = L.elem; p < L.elem+L.length; p++)
        printf("%d\t", *p);
    printf("\n");
}


// 建立一个空的顺序表
void InitList_Null(SqList &L){
    L.elem = (ElemType *)malloc(INITSIZE*sizeof(ElemType));
    if(!L.elem)
        printf("分配失败");
    L.length = 0;
    L.listsize = INITSIZE;
}

// 在表中的第i个位置插入元素
void ListInsert(SqList &L, int i, ElemType e){
    ElemType *p,*q,*newbase;
    q = L.elem + i - 1;
    if(i < 1 || i > L.length + 1){
        printf("插入元素位置不合法\n");
        return;
    }
    if(L.length >= L.listsize){
        newbase = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT)*sizeof(ElemType));
        if(!newbase)
            printf("分配失败");
        L.elem = newbase;
        L.listsize += LISTINCREMENT;
    }
    for(p = L.elem+L.length-1; p >= q; p--)
        *(p+1) = *p;
    *q = e;
    ++L.length;
};


void find_intersection(SqList La, SqList Lb, SqList &Lc){
    int i = 0;
    ElemType *pa, *pb;
    for(pa = La.elem; pa < La.elem+La.length; pa++){
        for(pb = Lb.elem; pb < Lb.elem+Lb.length; pb++){
            if(*pb == *pa){
                i++;
                ListInsert(Lc, i, *pa);
            }
        }
    }
}


int main(){
    int n1, n2;
    SqList La, Lb, Lc;
    printf("请输入要建立的顺序表La的长度n1:\n");
    scanf("%d",&n1);
    printf("顺序表La\n");
    InitList(La,n1);
    printf("请输入要建立的顺序表Lb的长度n2:\n");
    scanf("%d",&n2);
    printf("顺序表Lb\n");
    InitList(Lb,n2);
    InitList_Null(Lc);
    find_intersection(La,Lb,Lc);
    PrintList(Lc);
    return 0;
}

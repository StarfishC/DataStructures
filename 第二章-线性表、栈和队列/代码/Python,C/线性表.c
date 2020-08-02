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
typedef int T;

typedef struct Node *List;
struct Node{
    T Data[MAXSIZE];
    int length;
};

List InitList();                                            // 创建一个空表
int lenList(List Ptrl);                                     // 线性表大小
bool clearList(List Ptrl);                                  // 清空线性表
bool isEmptyList(List Ptrl);                                // 判断线性表是否为空
bool isFullList(List Ptrl);                                 // 判断线性表是否已满
bool appendList(List Ptrl, const T value);                  // 表尾添加元素
bool insertList(List Ptrl, const int p, const T value);     // 第P个位置插入元素value
bool removeList(List Ptrl, const int p);                    // 移除第p个元素
bool setValueList(List Ptrl, const int p, const T value);   // 设置第p个位置的元素
bool getValueList(List Ptrl, const int p, T *value);        // 获取第p个元素
bool getPosList(List Ptrl, const T value, int *p);          // 获取元素为value的位置
void showAllList(List Ptrl);

List InitList(){
    List Ptrl;
    Ptrl = malloc(sizeof(struct Node));
    if(!Ptrl) exit(-1);
    Ptrl->length = 0;
    return Ptrl;
}

int lenList(List Ptrl){
    return Ptrl->length;
}

bool clearList(List Ptrl){
    Ptrl->length = 0;
    return TRUE;
}

bool isEmptyList(List Ptrl){
    return Ptrl->length == 0;
}

bool isFullList(List Ptrl){
    return Ptrl->length == MAXSIZE;
}

bool appendList(List Ptrl, const T value){
    if(Ptrl->length >= MAXSIZE){
        printf("OVERFLOW!");
        return FALSE;
    }
    Ptrl->Data[(Ptrl->length)++] = value;
    return TRUE;
}

bool insertList(List Ptrl, const int p, const T value){
    if(p < 1 || p > Ptrl->length+1){
        printf("Insertion point is illegal");
        return FALSE;
    }
    if(Ptrl->length == MAXSIZE){
        printf("List Full");
        return FALSE;
    }
    for(int j = Ptrl->length-1; j >= p-1; j--)
        Ptrl->Data[j+1] = Ptrl->Data[j];
    Ptrl->Data[p-1] = value;
    Ptrl->length ++;
    return TRUE;
}

bool removeList(List Ptrl, const int p){
    if(p < 1|| p > Ptrl->length){
        printf("Removal point is illegal");
        return FALSE;
    }
    for(int j = p; j <= Ptrl->length-1; j++)
        Ptrl->Data[j-1] = Ptrl->Data[j];
    Ptrl->length --;
    return TRUE;
}

bool getValueList(List Ptrl, const int p, T *value){
    if(p < 1 || p > Ptrl->length){
        printf("Location is illegal");
        return FALSE;
    }
    *value = Ptrl->Data[p-1];
    return TRUE;
}

void showAllList(List Ptrl){
    for(int i = 0; i < Ptrl->length; i++)
        printf("%d ", Ptrl->Data[i]);
    printf("\n");
}

bool getPosList(List Ptrl, const T value, int *p){
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

typedef struct LinkNode* Link;

struct LinkNode{
    T data;
    Link next;
};

Link InitLink();                                            // 创建一个空表
int lenLink(Link Ptrl);                                     // 线性表大小
Link setPos(const int p, Link Ptrl);                        // 找到第p个位置的结点
bool clearLink(Link Ptrl);                                  // 清空线性表
bool isEmptyLink(Link Ptrl);                                // 判断线性表是否为空
bool appendLink(Link Ptrl, const T value);                  // 表尾添加元素
bool insertLink(Link Ptrl, const int p, const T value);     // 第P个位置插入元素value
bool removeLink(Link Ptrl, const int p);                    // 移除第p个元素
bool setValueLink(Link Ptrl, const int p, const T value);   // 设置第p个位置的元素
bool getValueLink(Link Ptrl, const int p, T *value);        // 获取第p个元素
bool getPosLink(Link Ptrl, const T value, int *p);          // 获取元素为value的位置
void showAllLink(Link Ptrl);

// *********************************************************************//

int main(){
    return 0;
}

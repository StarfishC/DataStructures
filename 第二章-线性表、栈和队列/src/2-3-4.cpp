// File:    2-3-4.cpp
// Author:  csh
// Date:    2020/07/12
// ===================


#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

typedef char ElemType;

typedef struct Node{
    ElemType data;
    struct Node *next;

}Node, *LinkList;


LinkList CreateList(){
    LinkList L;
    ElemType c;
    L  = new Node;
    L->next = NULL;
    Node *p, *tail;
    tail = L;
    c = getchar();
    while(c != '#'){
        p = new Node;
        p->data = c;
        tail->next = p;
        tail = p;
        c = getchar();
    }
    tail->next = NULL;
    return L;
}

void ShowList(LinkList L){
    Node *p;
    p = L->next;
    while(p != NULL){
        cout << p->data << " ";
        p = p ->next;
    }
    cout << endl;
}

void ReverseList(LinkList L){
    Node *p, *q;
    p = L->next;
    L->next = NULL;
    while(p != NULL){
        q = p->next;
        p->next = L->next;
        L->next = p;
        p = q;
    }
}


// 归并成按元素递增线性表
LinkList MergeList1(LinkList LA, LinkList LB){
    LinkList LC;
    Node *pa, *pb, *r;
    pa = LA->next;
    pb = LB->next;
    LC = LA;
    LC->next = NULL;
    r = LC;
    while(pa != NULL && pb != NULL){
        if(pa->data <= pb->data){           // pa小于pb时
            r->next = pa;
            r = pa;
            pa = pa->next;
        }else{
            r->next = pb;
            r = pb;
            pb = pb->next;
        }
        if(pa){             // 只剩链表a的结点
            r->next = pa;
        }else{
            r->next = pb;
        }
    }
    return LC;
}


// 题意：归并成按元素递减线性表
/* 先逆置线性表，在归并, 或先按递增排，在逆置 */
LinkList MergeList2(LinkList LA, LinkList LB){
    ReverseList(LA);
    ReverseList(LB);
    LinkList LC;
    Node *pa, *pb, *r;
    pa = LA->next;
    pb = LB->next;
    LC = LA;
    LC->next = NULL;
    free(LB);               // 释放掉LB头结点
    r = LC;
    while(pa != NULL && pb != NULL){
        if(pa->data <= pb->data){           // pa小于pb时
            r->next = pa;
            r = pa;
            pa = pa->next;
        }else{
            r->next = pb;
            r = pb;
            pb = pb->next;
        }
        if(pa){             // 只剩链表a的结点
            r->next = pa;
        }else{
            r->next = pb;
        }
    }
    return LC;
};

// 不逆置，头插法
LinkList MergeList3(LinkList LA, LinkList LB){
    Node *pa = LA->next;
    Node *pb = LB->next;
    Node *r;

    LA->next = NULL;        // 新链表使用LA头结点
    free(LB);               // 释放掉LB头结点

    while(pa != NULL && pb != NULL){
        if(pa->data < pb->data){    // 将pa插入链表头部
            r = pa->next;
            pa->next = LA->next;
            LA->next = pa;
            pa = r;
        }else{
            r = pb->next;
            pb->next = LA->next;
            LA->next = pb;
            pb = r;
        }
    }

    while(pa != NULL){
        r = pa->next;
        pa->next = LA->next;
        LA->next = pa;
        pa = r;
    }

    while(pb != NULL){
        r = pb->next;
        pb->next = LA->next;
        LA->next = pb;
        pb = r;
    }
    return LA;
};


int main(){
    LinkList LA;
    LA = CreateList();
    getchar();
    LinkList LB;
    LB = CreateList();

    cout << "LA: " << endl;
    ShowList(LA);

    cout << "LB: " << endl;
    ShowList(LB);

    LinkList LC;
    LC = MergeList3(LA, LB);
    cout << "MergeList: " << endl;
    ShowList(LC);
    return 0;
}

// File:    2-3-7.cpp
// Author:  csh
// Date:    2020/07/12
// ===================


#include <cstdlib>

typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;


void remove(LinkList &L){
    LinkList p, s;
    p = L;
    while(p->next){
        s = p->next;
        if(s->data == p->data){
            p->next = s->next;
            free(s);
        }else
            p = p->next;
    }
}

// File:    2-3-5.cpp
// Author:  csh
// Date:    2020/07/12
// ===================


// C语言实现
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#define Elemtype char

typedef struct SCList{
    Elemtype ch;
    struct SCList *next;
}Node;


Node* _buynode(Elemtype ch);                    // 申请一个新结点，返回这个结点的指针
void initital(Node **head);                     // 初始化单循环链表
void push_back(Node *head, Elemtype ch);        // 单循环链表的尾部插入一个新的结点
void show(Node *head);                          // 显示单循环链表的数据元素
void function(Node *ha, Node *hb, Node *hc);    // 分割三类字符数据元素


int main(){
    Node *ha;
    initital(&ha);

    printf("请构造字符类型的单循环链表，要三种字符，以@结束\n");
    char ch;
    while(1){
        scanf("%c", &ch);
        if(ch == '@')
            break;
        push_back(ha, ch);
    }
    printf("构造完成的链表>>");
    show(ha);

    Node *hb,*hc;
    initital(&hb);
    initital(&hc);
    function(ha, hb, hc);
    printf("分割后的单循环链表\n");
    show(ha);
    show(hb);
    show(hc);
    return 0;
}


Node* _buynode(Elemtype ch){
    Node *s = (Node*)malloc(sizeof(Node));
    assert(s != NULL);
    s->ch = ch;
    s->next = NULL;
    return s;
}

void initital(Node **head){
    *head = (Node*)malloc(sizeof(Node));
    assert(*head != NULL);
    (*head)->next = *head;
    (*head)->ch = 0;        // 表长为0
}

void push_back(Node *head, Elemtype ch){
    Node *s = _buynode(ch);
    Node *p = head;
    while(p->next != head)
        p = p->next;
    s->next = p->next;
    p->next = s;
    head->ch++;
}

void show(Node *head){
    if(head->ch == 0)
        return;
    Node *p = head;
    while(p->next != head){
        printf("%c-->", p->next->ch);
        p = p->next;
    }
    printf("head.\n");
}

void function(Node *ha, Node *hb, Node *hc){
    Node *pa = ha;
    while(pa->next != ha){
        if(pa->next->ch <= '9' && pa->next->ch >= '0'){
            Node *q = pa->next;
            pa->next = q->next;
            Node *pb = hb->next;
            while(pb->next != hb)
                pb = pb->next;
            q->next = pb->next;
            pb->next = q;
            hb->ch++;
        }else if(pa->next->ch < 'Z' && pa->next->ch >= 'A' || pa->next->ch <= 'z' && pa->next->ch >= 'a'){
            Node *q = pa->next;
            pa->next = q->next;
            Node *pc = hc->next;
            while(pc->next != hc)
                pc = pc->next;
            q->next = pc->next;
            pc->next = q;
            hc->ch++;
        }else
            pa = pa->next;
    }

}

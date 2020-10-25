// File:    2-5-6.cpp
// Author:  csh
// Date:    2020/06/02
// ===================


#include <iostream>

typedef int ELEM;
typedef struct Node* ListNode;

struct Node{
    ELEM data;
    ListNode next;
    ListNode pre;
};

// 循环链表结构，假设用new申请头节点空间
typedef struct {
    ListNode first;
    ListNode last;
}CLL;


// 考虑循环单链表
void deleteFirstNode1(CLL *pCLL){
    using namespace std;
    ListNode tmp;
    if(pCLL->first == pCLL->last){              // 循环链表为空
        cout << "The List is NULL, no fist node" << endl;
        return;
    }else if(pCLL->first->next == pCLL->last){  // 只有一个节点时
        tmp = pCLL->first->next;
        pCLL->first->next = tmp->next;
        pCLL->last = pCLL->first;
    }else{                                      // 正常情况
        tmp = pCLL->first->next;
        pCLL->first->next = tmp->next;
    }
    delete tmp;
}

// 考虑循环双链表
void deleteFirstNode2(CLL *pCLL){
    using namespace std;
    ListNode tmp;
    if(pCLL->first == pCLL->last){
        cout << "The List is NULL, no first node" << endl;
        return;
    }else if(pCLL->first->next == pCLL->last){
        tmp = pCLL->first->next;
        pCLL->last = pCLL->first;
        pCLL->first->next = pCLL->first;
        pCLL->first->pre = pCLL->first;
    }else{
        tmp = pCLL->first->next;
        pCLL->first->next = tmp->next;
        tmp->next->pre = pCLL->first;
    }
    delete tmp;
}

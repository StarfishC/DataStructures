// File:    2-2-5.cpp
// Author:  csh
// Date:    2020/06/02
// ===================


typedef int ELEM;
typedef struct ListNode* List;

struct ListNode{
    ELEM data;
    List next;
};


int Length(List first){         // first为循环链表的头节点
    List p;
    p = first;
    int count = 0;              // 计数
    while(p->next != first){    // 再次遇见fist代表到达尾节点
        p = p->next;
        count ++;
    }
    return count;
}

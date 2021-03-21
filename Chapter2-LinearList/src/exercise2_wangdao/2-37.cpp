// File:    2-37.cpp
// Author:  csh
// Date:    2021/3/21
// ===================


LNode* FindLoopStart(LNode *head)
{
    LNode *fast = head, *slow = head;
    while(slow != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) break;
    }
    if(slow == NULL || fast->next == NULL)
        return NULL;                // 没有环，返回NULL
    LNode *p1 = head, *p2 = slow;
    while(p1 != p2)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1;
}

// File:    2-1-9.cpp
// Author:  csh
// Date:    2020/08/15
// ===================


#include "../headers/linear.hpp" 

void Solution(LinkList<int>* A, LinkList<int>* B, LinkList<int>* C){
    Link<int>* tmpA;
    Link<int>* tmpB;
    
    tmpA = A->getHead()->next;          // 指向A的第一个节点
    tmpB = B->getHead()->next;          // 指向B的第一个节点

    while(tmpA && tmpB){
        if(tmpA->data == tmpB->data){
            C->append(tmpA->data);
            tmpA = tmpA->next;
            tmpB = tmpB->next;
        }else if(tmpA->data > tmpB->data)
            tmpB = tmpB->next;
        else
            tmpA = tmpA->next;
    }
}


int main(){
    LinkList<int> A = LinkList<int>();
    LinkList<int> B = LinkList<int>();
    LinkList<int> C = LinkList<int>();

    A.append(1);
    A.append(2);
    A.append(4);
    A.append(6);
    A.append(7);
    A.showAll();

    B.append(2);
    B.append(4);
    B.append(5);
    B.append(7);
    B.append(8);
    B.showAll();

    Solution(&A, &B, &C);
    C.showAll();
    return 0;
}

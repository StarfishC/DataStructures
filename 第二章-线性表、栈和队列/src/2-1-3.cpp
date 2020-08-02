// File:    2-3-3.cpp
// Author:  csh
// Date:    2020/08/02
// ===================


#include "../headers/linear.hpp"


template <typename T>
class LinkList2:public LinkList<T>{
    public:
        bool deleteMiddleElem(int mink, int maxk);
};

template <typename T>
bool LinkList2<T>::deleteMiddleElem(int mink, int maxk){
    Link<T> *pre;               // 存放mink前一个结点
    Link<T> *cur;               // 存放当前结点
    Link<T> *tmp;               // 存放待释放结点
    if(mink > maxk) return false;
    pre = this->head;
    cur = pre->next;            // cur指向第一个结点

    while(cur && cur->data < maxk){
        if(cur->data <= mink){
            pre = cur;
            cur = cur->next;
        }else{
            pre->next = cur->next;      // 跳过待删除结点
            tmp = cur;
            cur = cur->next;
            free(tmp);
        }
    }
    return true;
}


int main(){
    LinkList2<int> L = LinkList2<int>();
    L.append(1);
    L.append(3);
    L.append(5);
    L.append(7);
    L.append(9);
    L.deleteMiddleElem(3,9);
    L.showAll();
}

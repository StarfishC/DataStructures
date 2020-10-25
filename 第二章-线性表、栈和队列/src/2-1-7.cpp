// File:    2-1-7.cpp
// Author:  csh
// Date:    2020/07/12
// ===================


#include "../headers/linear.hpp"


template <typename T>
class LinkList2:public LinkList<T>{
    public:
        bool removeSame(){
            Link<T> *pre, *cur;
            pre = this->head->next;
            cur = pre->next;
            while(cur){
                if(pre->data == cur->data){
                    pre->next = cur->next;
                    delete cur;
                    cur = pre->next;
                }else{
                    pre = pre->next;
                    cur = pre->next;
                }
            }
            return true;
        }
};


int main(){
    LinkList2<int> a = LinkList2<int>();
    a.append(1);
    a.append(2);
    a.append(2);
    a.append(2);
    a.append(3);
    a.removeSame();
    a.showAll();
    return 0;
}

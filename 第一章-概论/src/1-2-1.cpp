// File:    1-2-1.cpp
// Author:  csh
// Date:    2020/07/20
// ===================


#include <iostream>
#include <string>

using namespace std;


// 1. 用链表
class strings{
    public:
        string str;             // 数据域
        strings *pNext;         // 指针域
        strings();
        strings(string s){str = s;};
};

/* 链表类 */
class LinkList{
    private:
        strings *head;
        int curlen;
    public:
        LinkList(){
            curlen = 0;
            head = NULL;
        }
        int length(){return curlen;};       // 链表长度
        bool compare(string a, string b);   // 比较a,b字符串
        void append(strings *s);            // 添加元素并排序
        void showAll();                     // 显示所有元素
};

bool LinkList::compare(string a, string b){
    // 返回false表示a在前，b在后
    auto i = a.begin();
    auto j = b.begin();
    while(i != a.end() && j != b.end()){
        // 1.字符相等情况
        if(*i == *j){
            i++;
            j++;
            continue;
        }

        // 2.字符均为A-Z或均为0-9情况
        if((*i - 'A' >= 0 && (*j - 'A' >= 0)) || ((*i - 'A' < 0) && (*j - 'A' < 0))){
            if(*i - *j < 0)     // 如B-A>0,A在B前
                return false;
            else
                return true;
        }else{
        // 3.一个字符A-Z，一个0-9
            if(*i - *j > 0)     // 如A-5>0,A在5前
                return false;
            else return true;
        }
        i++;
        j++;
    }
    if(*i)      // 如果a没有迭代完，b迭代完了，b在a前
        return true;
    else
        return false;
}

void LinkList::append(strings *s){
    strings *current = head;
    strings *previous = NULL;
    bool stop = false;
    while(current != NULL && not stop){
        if(compare(current->str, s->str))
            stop = true;
        else{
            previous = current;
            current = current->pNext;
        }
    }
    if(previous == NULL){
        // previous没找到，即插入第一个
        s->pNext = head;
        head = s;
    }else{
        //在previos和current之间插入
        s->pNext = current;
        previous->pNext = s;
    }
}

void LinkList::showAll(){
    strings *tmp = head;
    while(tmp){
        cout << tmp->str << " --> ";
        tmp = tmp->pNext;
    }
}


int main(){
    strings a[8] = {strings("PAB"), strings("5C"), strings("PABC"), strings("CXY"),
                    strings("CRSI"), strings("7"), strings("B899"), strings("B9")};
    LinkList list = LinkList();
    for(int i = 0; i < 8; i++){
        list.append(&a[i]);
    }
    list.showAll();
    return 0;
}

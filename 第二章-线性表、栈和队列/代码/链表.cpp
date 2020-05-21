// File:    链表.cpp
// Author:  csh
// Date:    2020/05/20
// ===================

#include <cstdlib>
#include <iostream>

/********************************* 单链表  *****************************/
template <typename T>
class Link{
    public:
        T data;             // 数字域
        Link<T> *next;      // 指针域，指向后继结点的指针

        Link(const T info, Link<T>* nextLink=NULL){
            this->data = info;
            this->next = nextLink;
        }
        Link(Link<T>* nextLink=NULL){
            this->next = nextLink;
        }
};

// 单链表
template <typename T>
class LnkList{
    private:
        Link<T> *head, *tail;                   // 单链表的头尾结点，添加尾结点是为了操作方便
        Link<T> *setPos(const int p);           // 返回线性表指向第p个元素的指针值
    public:
        LnkList();                              // 构造函数
        ~LnkList();                             // 析构函数
        bool isEmpty();                         // 判断链表是否为空
        void clear();                           // 将链表内容清除，成为空表
        int length();                           // 返回链表当前实际长度
        bool append(const T value);             // 表尾添加一个元素
        bool insert(const int p, const T value);// 在位置p上插入一个元素
        bool remove(const int p);               // 删除位置p上的元素
        bool getValue(const int p, T &value);   // 返回位置p的元素值，存放到value中
        bool getPos(int &p, const T value);     // 查找值为value的元素，并返回第一次出现的位置
        void showAll();                         // 显示链表的所有元素
};

template <typename T>
LnkList<T>::LnkList(){
    head = tail = new Link<T>();
}

template <typename T>
LnkList<T>::~LnkList(){
    Link<T> *tmp;
    while(head != NULL){
        tmp = head;
        head = head->next;
        delete tmp;
    }
}

template <typename T>
Link<T>* LnkList<T>::setPos(const int p){
    int count = 0;
    if(p == 0){
        return head;
    }
    Link<T> *tmp = new Link<T>(head->next);
    while(tmp != NULL && count < p){
        tmp = tmp->next;
        count++;
    }
    return tmp;
}

template <typename T>
void LnkList<T>::clear(){
    Link<T> *tmp;
    while(head != NULL){
        tmp = head;
        head = head->next;
        delete tmp;
    }
    head = tail = new Link<T>;
}

template <typename T>
int LnkList<T>::length(){
    int count = 0;
    Link<T> *tmp = head->next;
    while(tmp != NULL){
        count ++;
        tmp = tmp->next;
    }
    return count;
}

template <typename T>
bool LnkList<T>::append(const T value){
    Link<T> *tmp;
    tmp = new Link<T>(value, NULL);
    if(head == tail){                           // 没有元素
        head->next = tmp;
        tail = tmp;
    }else{
        tail->next = tmp;
        tail = tmp;
    }
    return true;
}

template <typename T>
bool LnkList<T>::insert(const int p, const T value){
    using std::cout;
    using std::endl;
    Link<T> *pre, *q;
    if((pre = setPos(p-1)) == NULL){            // p是第i个节点的前驱
        cout << "Insertion point is illegal" << endl;
        return false;
    }
    cout << pre->data << endl;
    q = new Link<T>(value, pre->next);
    pre->next = q;
    if(pre == tail)
        tail = q;
    return true;
}

template <typename T>
bool LnkList<T>::remove(const int p){
    using std::cout;
    using std::endl;
    Link<T> *pre, *q;
    if((pre = setPos(p-1)) == NULL || pre == tail){
        cout << "Removal point is illegal" << endl;
        return false;
    }
    q = pre->next;                      // 待删节点
    if(q == this->tail){                      // 待删节点为尾节点
        this->tail = pre;
        pre->next = NULL;
        delete q;
    }else if(q != NULL){
        pre->next = q->next;
        delete q;
    }
    return true;
}

template <typename T>
bool LnkList<T>::getPos(int &p, const T value){
    Link<T> *tmp = head->next;
    int count = 0;
    while(tmp != NULL){
        count ++;
        if(tmp->data == value){
            p = count;
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}

template <typename T>
bool LnkList<T>::getValue(const int p, T &value){
    using std::cout;
    using std::endl;
    Link<T> *tmp;
    if((tmp = setPos(p)) == NULL){
        cout << "Location is illegal" << endl;
        return false;
    }
    value = tmp->data;
    return true;
}

template <typename T>
void LnkList<T>::showAll(){
    using std::cout;
    using std::endl;
    Link<T> *tmp = head->next;
    while(tmp != NULL){
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}



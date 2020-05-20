// File:    链表.cpp
// Author:  csh
// Date:    2020/05/20
// ===================

#include <cstdlib>

/********************************* 单链表  *****************************/
template <typename T>
class Link{
    public:
        T data;             // 数字域
        Link<T> *next;      // 指针域，指向后继结点的指针

        Link(const T info, const Link<T>* nextLink=NULL){
            this->data = info;
            this->next = nextLink;
        }
        Link(const Link<T>* nextLink=NULL){
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
    head = tail = new Link<T>;
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
    if(p == -1)                                 // i为-1则定位头节点
        return head;
    Link<T> *tmp = new Link<T>(head->next);
    while(tmp != NULL && count < p){
        tmp = tmp->next;
        count++;
    }
    return tmp;
}

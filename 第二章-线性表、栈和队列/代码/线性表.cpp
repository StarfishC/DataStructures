// File:    线性表.cpp
// Author:  csh
// Date:    2020/05/24
// ===================

#include <cstdlib>
#include <iostream>


// ************************** 线性表的顺序存储 *********************************//

template <typename T>
class ArrList{
    private:
        T *aList;                                   // 存储顺序表的实例
        int maxSize;                                // 顺序表的最大长度
        int curLen;                                 // 顺序表的当前长度
    public:
        ArrList(const int size){                    // 创建一个大小为size的顺序表
            maxSize = size;
            aList = new T[maxSize];
            curLen = 0;
        }
        ~ArrList(){
            delete [] aList;
        }
        void clear();                               // 清除顺序表内容，成为空表
        int length();                               // 返回顺序表长度
        bool isEmpty();                             // 判断线性表是否为空
        bool isFull();                              // 判断线性表是否已满
        bool append(const T value);                 // 表尾添加一个元素value
        bool insert(const int p, const T value);    // 位置p上插入一个元素value
        bool remove(const int p);                   // 移除位置p上的元素
        bool setValue(const int p, const T value);  // 修改位置p的元素为value
        bool getValue(const int p, T &value);       // 把位置p的元素返回到变量value中
        bool getPos(int &p, const T value);         // 查找值为value的元素，返回第一次出现的位置
        void showAll();                             // 显示所有元素
};

template <typename T>
void ArrList<T>::clear(){
    curLen = 0;
}

template <typename T>
bool ArrList<T>::isEmpty(){
    return curLen == 0;
}

template <typename T>
bool ArrList<T>::isFull(){
    return curLen == maxSize;
}

template <typename T>
int ArrList<T>::length(){
    return curLen;
}

template <typename T>
bool ArrList<T>::append(const T value){
    using std::cout;
    using std::endl;
    if(curLen >= maxSize){
        cout << "The list is overflow" << endl;
        return false;
    }
    aList[curLen] = value;
    curLen++;
    return true;
}

template <typename T>
bool ArrList<T>::getValue(const int p, T &value){
    using std::cout;
    using std::endl;
    if(p < 0 || p > curLen-1){      // 判断p位置是否合法
        cout << "Location is illegal" << endl;
        return false;
    }
    value = aList[p];
    return true;
}

template <typename T>
bool ArrList<T>::setValue(const int p, const T value){
    using std::cout;
    using std::endl;
    if(p < 0 || p > curLen-1){      // 判断p位置是否合法
        cout << "Location is illegal" << endl;
        return false;
    }
    aList[p] = value;
    return true;
}

template <typename T>
bool ArrList<T>::insert(const int p, const T value){
    using std::cout;
    using std::endl;
    if(curLen >= maxSize){          // 检查顺序表是否溢出
        cout << "The list is overflow" << endl;
        return false;
    }
    if(p < 0 || p > curLen){        // 检查位置是否合法
        cout << "Insertion point is illegal" << endl;
        return false;
    }
    for(int i = curLen; i > p; i--)
        aList[i] = aList[i-1];      // 将p位置以及之后的元素后移一位
    aList[p] = value;
    curLen++;
    return true;
}

template <typename T>
bool ArrList<T>::remove(const int p){
    using std::cout;
    using std::endl;
    if(curLen <= 0){
        cout << "No element to remove" << endl;
        return false;
    }
    if(p < 0 || p > curLen-1){
        cout << "remove is illegal" << endl;
        return false;
    }
    for(int i = p; i < curLen-1; i++)
        aList[i] = aList[i+1];
    curLen--;
    return true;
}

template <typename T>
bool ArrList<T>::getPos(int &p, const T value){
    for(int i = 0; i < this->maxSize-1; i++){
        if(value == aList[i]){
            p = i;
            return true;
        }
    }
    return false;
}

template <typename T>
void ArrList<T>::showAll(){
    using std::cout;
    using std::endl;
    if(curLen == 0)
        cout << "No element in the list" << endl;
    for(int i = 0; i < curLen; i++)
        cout << aList[i] << " ";
    cout << endl;
    return;
}

// *****************************************************************************//


// ************************** 线性表的链式存储 *********************************//

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
class LinkList{
    private:
        Link<T> *head, *tail;                   // 单链表的头尾结点，添加尾结点是为了操作方便
        Link<T> *setPos(const int p);           // 返回线性表指向第p个元素的指针值
    public:
        LinkList();                             // 构造函数
        ~LinkList();                            // 析构函数
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
LinkList<T>::LinkList(){
    head = tail = new Link<T>;
}

template <typename T>
LinkList<T>::~LinkList(){
    Link<T> *tmp;
    while(head != NULL){
        tmp = head;
        head = head->next;
        delete tmp;
    }
}

template <typename T>
Link<T>* LinkList<T>::setPos(const int p){
    int count = 0;
    if(p == 0){                                // 0定位到头结点
        return head;
    }
    Link<T> *tmp = new Link<T>(head);          // 1则定位第一个结点
    while(tmp != NULL && count <= p){
        tmp = tmp->next;
        count++;
    }
    return tmp;
}

template <typename T>
void LinkList<T>::clear(){
    Link<T> *tmp;
    Link<T> *next;
    tmp = head->next;
    while(tmp){
        next = tmp->next;
        delete tmp;
        tmp = next;
    }
    head = tail = new Link<T>;
}

template <typename T>
int LinkList<T>::length(){
    int count = 0;
    Link<T> *tmp = head->next;
    while(tmp != NULL){
        count ++;
        tmp = tmp->next;
    }
    return count;
}

template <typename T>
bool LinkList<T>::append(const T value){
    Link<T> *tmp;
    tmp = new Link<T>(value);
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
bool LinkList<T>::insert(const int p, const T value){
    using std::cout;
    using std::endl;
    Link<T> *pre, *q;
    if((pre = setPos(p-1)) == NULL){            // p是第i个节点的前驱
        cout << "Insertion point is illegal" << endl;
        return false;
    }
    q = new Link<T>(value, pre->next);
    pre->next = q;
    if(pre == tail)
        tail = q;
    return true;
}

template <typename T>
bool LinkList<T>::remove(const int p){
    using std::cout;
    using std::endl;
    Link<T> *pre, *cur;
    if((pre = setPos(p-1)) == NULL || pre == tail){
        cout << "Removal point is illegal" << endl;
        return false;
    }
    cur = pre->next;                            // 待删节点
    if(cur == this->tail){                      // 待删节点为尾节点
        this->tail = pre;
        pre->next = NULL;
        delete cur;
    }else if(cur != NULL){
        pre->next = cur->next;
        delete cur;
    }
    return true;
}

template <typename T>
bool LinkList<T>::getPos(int &p, const T value){
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
bool LinkList<T>::getValue(const int p, T &value){
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
void LinkList<T>::showAll(){
    using std::cout;
    using std::endl;
    Link<T> *tmp = head->next;
    while(tmp != NULL){
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}



/********************************* 双链表  *****************************/

template <typename T>
class DLink{
    public:
        T data;
        DLink<T> *prev;                 // 指向前驱节点的指针
        DLink<T> *next;                 // 指向后继节点的指针
        DLink(const T info, DLink<T> *preValue=NULL, DLink<T> *nextValue=NULL){
            data = info;
            prev = preValue;
            next = nextValue;
        }
        DLink(DLink<T> *preValue=NULL, DLink<T> *nextValue=NULL){
            next = nextValue;
            prev = preValue;
        }
};


template <typename T>
class DLinkList{
    private:
        DLink<T> *head, tail;
        DLink<T> *setPos(const int p);          // 指向第p个元素的指针
    public:
        DLinkList(){
            head = tail = new DLink<T>(NULL, NULL);
        }
};
// *****************************************************************************//

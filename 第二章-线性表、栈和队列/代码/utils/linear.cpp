// File:    线性表.cpp
// Author:  csh
// Date:    2020/05/24
// ===================

#include <cstdlib>
#include <iostream>
#include "linear.h"


// ************************** 线性表的顺序存储 *********************************//

template <typename T>
void ArrList<T>::clear(){
    delete []aList;
    curLen = position = 0;
    aList = new T[maxSize];
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
    aList[curLen-1] = value;
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
    if(curLen < 0){
        cout << "No element to remove" << endl;
        return false;
    }
    if(p < 0 || p > curLen-1){
        cout << "remove is illegal" << endl;
        return false;
    }
    for(int i = p; i < curLen-1; i++)
        aList[p] = aList[i+1];
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

// *****************************************************************************//

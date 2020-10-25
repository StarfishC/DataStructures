// File:    栈.cpp
// Author:  csh
// Date:    2020/05/24
// ===================


#include <iostream>


// ****************************** 栈的顺序存储 *********************************//
// *****************************************************************************//
template <typename T>
class ArrStack{
    private:
        int mSize;                              // 栈的大小
        int top;                                // 栈顶位置
        T *st;                                  // 栈的数组
    public:
        ArrStack(int size);                     // 构造函数
        ~ArrStack();                            // 析构函数
        void clear();                           // 清空栈元素
        bool push(const T item);                // 入栈
        bool pop(T &item);                      // 出栈并返回栈顶元素
        bool peek(T &item);                     // 只返回栈顶内容
        inline bool isEmpty();                  // 判断栈空
        inline bool isFull();                   // 判断栈满
};

template <typename T>
ArrStack<T>::ArrStack(int size){
    mSize = size;
    top = -1;
    st = new T[mSize];
}

template <typename T>
ArrStack<T>::~ArrStack(){
    delete []st;
}

template <typename T>
void ArrStack<T>::clear(){
    top = -1;
}

template <typename T>
bool ArrStack<T>::isFull(){
    return top == mSize-1;
}

template <typename T>
bool ArrStack<T>::isEmpty(){
    return top == -1;
}

template <typename T>
bool ArrStack<T>::push(const T item){
    using namespace std;
    if(isFull()){
        cout << "栈满溢出" << endl;
        return false;
    }else{
        st[++top] = item;
        return true;
    }
}

template <typename T>
bool ArrStack<T>::pop(T &item){
    using namespace std;
    if(isEmpty()){
        cout << "栈空,不能出栈" << endl;
        return false;
    }else{
        item = st[top--];
        return true;
    }
}

template <typename T>
bool ArrStack<T>::peek(T &item){
    using namespace std;
    if(isEmpty()){
        cout << "栈空,栈顶无元素" << endl;
        return false;
    }else{
        item = st[top];
        return true;
    }
}

// *****************************************************************************//


// ****************************** 栈的链式存储 *********************************//

template <typename T>
class Link{
    public:
        T data;                         // 数字域
        Link<T> *next;                  // 指针域，指向后继结点的指针

        Link(const T info, Link<T>* nextLink=nullptr):
            data{info}, next{nextLink}{}
        Link(Link<T>* nextLink=nullptr): next{nextLink}{}
};

template <typename T>
class LinkStack{
    private:
        Link<T> *top;                   // 指向栈顶指针
        int size;                       // 存放栈元素的个数
    public:
        LinkStack();                    // 构造函数
        virtual ~LinkStack();                   // 析构函数
        void clear();                   // 清空栈内容
        bool push(const T item);        // 入栈
        bool pop(T &item);              // 出栈
        bool peek(T &item);             // 返回栈顶元素
};

template <typename T>
LinkStack<T>::LinkStack(): top{nullptr}, size{0}{}

template <typename T>
LinkStack<T>::~LinkStack(){
    clear();
}

template <typename T>
void LinkStack<T>::clear(){
    while(top){
        Link<T> *tmp = top;
        top = top->next;
        delete tmp;
    }
    size = 0;
}

template <typename T>
bool LinkStack<T>::push(const T item){
    Link<T>* tmp = new Link<T>(item, top);
    top = tmp;
    size++;
    return true;
}

template <typename T>
bool LinkStack<T>::pop(T &item){
    using namespace std;
    Link<T> *tmp;
    if(size == 0){
        cout << "栈空，不能出栈" << endl;
        return false;
    }
    item = top->data;
    tmp = top;
    top = top->next;
    delete tmp;
    size --;
    return true;
}

template <typename T>
bool LinkStack<T>::peek(T &item){
    using namespace std;
    if(size == 0){
        cout << "栈空，栈顶无元素" << endl;
        return false;
    }
    item = top->data;
    return true;
}

// *****************************************************************************//

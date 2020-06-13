// File:    2-2-9.cpp
// Author:  csh
// Date:    2020/06/11
// ===================


#include <cassert>
#include <cstddef>
#include <iostream>


class Stack{
    private:
        int *Elmlist;
        int Left, Right;
        int maxsize;
    public:
        Stack(int size=10);                 // 构造函数
        bool isFull(){                      // 判断是否栈满
            return Left + 1 == Right;
        }
        bool lEmpty(){                      // S1是否为空
            return Left == -1;
        }
        bool rEmpty(){
            return Right == maxsize;        // S2是否为空
        }
        void lPush(const int item);         // S1入栈
        void rPush(const int item);         // S2入栈
        void lpop(int &item);               // S1出栈
        void rpop(int &item);               // S2出栈
        void ltop(int &item);               // S1栈顶元素
        void rtop(int &item);               // S2栈顶元素
};

Stack::Stack(int size){
    maxsize = size;
    Elmlist = new int[size];
    assert(Elmlist != NULL);
    Left = -1;
    Right = size;
}

void Stack::rPush(const int item){
    assert(!isFull());
    Elmlist[--Right] = item;
}

void Stack::lPush(const int item){
    assert(!isFull());
    Elmlist[++Left] = item;
}

void Stack::lpop(int &item){
    assert(!lEmpty());
    item = Elmlist[Left--];
}

void Stack::rpop(int &item){
    assert(!rEmpty());
    item = Elmlist[Right++];
}

void Stack::ltop(int &item){
    assert(!lEmpty());
    item = Elmlist[Left];
}

void Stack::rtop(int &item){
    assert(!rEmpty());
    item = Elmlist[Right];
}


int main(){
    using namespace std;
    Stack s = Stack(5);
    s.lPush(1);
    s.lPush(3);
    s.rPush(4);
    s.rPush(5);
    s.rPush(6);
    int item1, item2;
    s.ltop(item1);
    s.rtop(item2);
    cout << item1 << endl;
    cout << item2 << endl;
}

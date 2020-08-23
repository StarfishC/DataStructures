// File:    2-3-15.cpp
// Author:  csh
// Date:    2020/08/23
// ===================

#include <iostream>
#include <stack>
#include "../headers/queue.hpp"

using namespace std;


void Revert(ArrQueue<int> &Q){
    stack<int> S = stack<int>();
    int item;
    while(!Q.isEmpty()){
        Q.deQueue(item);
        S.push(item);
    }
    while(!S.empty()){
        item = S.top();
        S.pop();
        Q.enQueue(item);
    }
}

int main(){
    ArrQueue<int> Q = ArrQueue<int>(10);
    Q.enQueue(1);
    Q.enQueue(2);
    Q.enQueue(3);

    Revert(Q);
    int item;
    while(!Q.isEmpty()){
        Q.deQueue(item);
        cout << item << " ";
    }
    cout << endl;
    return 0;
}

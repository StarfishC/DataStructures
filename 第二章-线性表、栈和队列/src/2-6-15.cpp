// File:    2-6-15.cpp
// Author:  csh
// Date:    2020/10/25
// ===================


#include <iostream>
#include <stack>
#include <queue>

using namespace std;

template <typename T>
void Revert(queue<T> &Q){
    stack<T> s;
    while(!Q.empty()){
        s.push(Q.front());
        Q.pop();
    }
    while(!s.empty()){
        Q.push(s.top());
        s.pop();
    }
}


int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    Revert(q);
    while(!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }
    return 0;
}

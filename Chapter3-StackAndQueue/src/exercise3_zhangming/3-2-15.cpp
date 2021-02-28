// File:    2-3-15.cpp
// Author:  csh
// Date:    2020/08/23
// ===================

#include <iostream>
#include <stack>
#include <queue>

using namespace std;


template <typename T>
void Revert(queue<T> &Q)
{
    stack<T> s;
    int item;
    while(!Q.empty())
    {
        s.push(Q.front());
        Q.pop();
    }
    while(!s.empty())
    {
        Q.push(s.top());
        s.pop();
    }
}

int main()
{
    queue<int> Q;
    Q.push(1);
    Q.push(2);
    Q.push(3);

    Revert(Q);
    int item;
    while(!Q.empty())
    {
        item = Q.front();
        cout << item << " ";
        Q.pop();
    }
    cout << endl;
    return 0;
}

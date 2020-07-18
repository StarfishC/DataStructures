// File:    test.cpp
// Author:  csh
// Date:    2020/07/18
// ===================


#include <iostream>
#include <stack>
using namespace std;


void test(int &sum){
    int x;
    cin >> x;
    if(x == 0)
        sum = 0;
    else{
        test(sum);
        sum += x;
    }
    cout << sum;
}

void test2(int &sum){
    int x;
    stack<int> s;
    stack<int> s2;
    cin >> x;
    while(x != 0){
        s.push(x);
        cin >> x;
    }
    while(!s.empty()){
        sum += s.top();
        s.pop();
        s2.push(sum);
    }
    s2.push(0);
    while(!s2.empty()){
        cout << s2.top() << "  ";
        s2.pop();
    }
    cout << endl;
}

int main(){
    int sum = 0;
    test2(sum);
    return 0;
}

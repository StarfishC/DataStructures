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

void test2(){
    int x;
    stack<int> s1;
    cin >> x;
    while(x != 0){
        s1.push(x);
        cin >> x;
    }
    s1.push(0);
    int sum = 0;
    while(!s1.empty()){
        sum += s1.top();
        s1.pop();
        cout << sum << endl;
    }
    cout << endl;
}

int main(){
    int sum = 0;
    test2();
    return 0;
}

// File:    3-2-12.cpp
// Author:  csh
// Date:    2020/10/25
// ===================


#include <iostream>
#include <stack>

using namespace std;

void test(int &sum)
{
    int x;
    cin >> x;
    if(x == 0)
        sum = 0;
    else
    {
        test(sum);
        sum += x;
    }
    cout << sum << endl;
}

void test2()
{
    int x;
    stack<int> s1;
    cin >> x;
    while(x != 0)
    {
        s1.push(x);
        cin >> x;
    }
    s1.push(0);
    int sum = 0;
    while(!s1.empty())
    {
        sum += s1.top();
        s1.pop();
        cout << sum << endl;
    }
    cout << endl;
}


int main()
{
    int sum = 100;
    test(sum);
    cout << "test2: " << endl;
    test2();
    return 0;
}

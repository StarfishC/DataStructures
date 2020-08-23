// File:    2-3-16.cpp
// Author:  csh
// Date:    2020/08/23
// ===================


#include <iostream>

using namespace std;

int Ack(int m, int n){
    if(m == 0)
        return n + 1;
    else if(n == 0)
        return Ack(m-1, 1);
    else
        return Ack(m-1, Ack(m, n-1));
}

int main(){
    cout << Ack(2, 1) << endl;
    return 0;
}

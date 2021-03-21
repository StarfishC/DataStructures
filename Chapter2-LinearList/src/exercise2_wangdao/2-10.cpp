// File:    2-10.cpp
// Author:  csh
// Date:    2021/03/13
// ===================



void Reverse(int R[], int from, int to)
{
    int i, temp;
    for(i = 0; i < (to-from+1)/2; i++)
    {
        temp = R[from+i];
        R[from+i] = R[to-i];
        R[to-i] = temp;
    }
}

void Converse(int R[], int n, int p)
{
    Reverse(R, 0, p-1);
    Reverse(R, p, n-1);
    Reverse(R, 0, n-1);
}


#include <iostream>

int main()
{
    using namespace std;
    int R[10] = {1,2,3,4,5,6,7,8,9,10};
    Converse(R, 10, 5);
    for(auto x : R)
        cout << x << " ";
    cout << endl;
    return 0;
}

// File:    2-1-2.cpp
// Author:  csh
// Date:    2020/07/12
// ===================


#include <iostream>


// An是A[]的长度，Bn是B[]的长度
template <typename T>
int compare(T A[], int An, T B[], int Bn){
    // 过滤掉公共前缀
    int i = 0;
    while(i < An && i < Bn && A[i] == B[i])
            i++;
    if(i >= An && i >= Bn)      // A,B均为空，下标i大于数组中的元素
        return 0;
    else if((i >= An && i < Bn) || A[i] < B[i])     // A空B不空或A’有元素小与B'首元素
        return -1;
    else
        return 1;
}


int main(){
    using namespace std;
    int A[] = {4, 5, 6, 3, 8};
    int B[] = {4, 5, 6, 3, 9};
    int An = 5;
    int Bn = 5;
    int r = compare(A, An, B, Bn);
    cout << r << endl;
    return 0;
}

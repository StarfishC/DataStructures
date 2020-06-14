// File:    KMP.cpp
// Author:  csh
// Date:    2020/06/14
// ===================


#include <string>
#include <cassert>
#include <iostream>

using namespace std;

// 与findNext一样，但未经优化
void prefix_table(char pattern[], int prefix[], int n){
    prefix[0] = 0;
    int len = 0;
    int i = 1;
    while(i < n){
        if(pattern[i] == pattern[len]){
            len++;
            prefix[i] = len;
            i++;
        }else{
            if(len > 0)
                len = prefix[len-1];
            else
                prefix[i] = len;            // 此时len=0
        }
    }

    // 前缀表最后一项可以不需要，结果后移一位，第一位改成-1
    for(int i = n-1; i > 0; i++)
        prefix[i] = prefix[i-1];
    prefix[0] = -1;
}

int *findNext(string P){
    int i = 0;
    int k = -1;
    int m = P.length();
    assert(m > 0);
    int *next = new int[m];
    next[0] = -1;
    while(i < m){
        while(k >= 0 && P[i] != P[k])
            k = next[k];
        i++;
        k++;
        if(i == m)
            break;
        if(P[i] == P[k])
            next[i] = next[k];          // P[i]和P[k]相等，优化
        else
            next[i] = k;                // 不需要优化
    }
    return next;
}


int KMPStrMatching(const string &T, const string &P, int *N){
    int i = 0;                      // 模式下标变量
    int j = 0;                      // 目标下标变量
    int pLen = P.length();          // 模式长度
    int tLen = T.length();          // 目标长度
    if(tLen < pLen)                 // 模式长度大于目标，匹配失败
        return -1;
    while(i < pLen && j < tLen){
        if(i == -1 || T[j] == P[i])
            i++, j++;
        else
            i = N[i];
    }
    if(i >= pLen)
        return j-pLen;
    else return -1;
}


int main(){
    string target = "abaacababcac";
    string pattern = "ababc";
    int *N = findNext(pattern);
    int pos = KMPStrMatching(target, pattern, N);
    cout << pos << endl;
    return 0;
}

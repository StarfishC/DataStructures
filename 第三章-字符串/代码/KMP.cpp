// File:    KMP.cpp
// Author:  csh
// Date:    2020/06/14
// ===================


#include <string>
#include <cstring>
#include <cassert>
#include <iostream>

using namespace std;

// 下列两个来自B站
void prefix_table(char pattern[], int prefix[], int n);
void KMP(char text[], char pattern[]);


// 以下两个来自教材
int *findNext(string P);
int KMPStrMatching(const string &T, const string &P, int *N);


int main(){
    string target = "abaacababcacababcabaas";
    string pattern = "ababcabaa";
    char target2[] = "abaacababcacababcabaas";
    char pattern2[] = "ababcabaa";
    KMP(target2, pattern2);
    int *N = findNext(pattern);
    int pos = KMPStrMatching(target, pattern, N);
    cout << pos << endl;

    return 0;
}


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
            i++;
        }
    }

    // 前缀表最后一项可以不需要，结果后移一位，第一位改成-1
    for(int i = n-1; i > 0; i--)
        prefix[i] = prefix[i-1];
    prefix[0] = -1;
    cout << "prefix_table: ";
    for(int i = 0; i < n; i++)
        cout << prefix[i] << " ";
    cout << endl;
}

void KMP(char text[], char pattern[]){
    int m = strlen(text);
    int n = strlen(pattern);
    int *next = (int*)malloc(sizeof(int)*n);
    prefix_table(pattern, next, n);

    int i = 0;
    int j = 0;
    while(i < m){
        if(j == n-1 && text[i] == pattern[j]){
            cout << "Found pattern at " << i - j << endl;
            j = next[j];
        }
        if(text[i] == pattern[j])
            i++,j++;
        else{
            j = next[j];
            if(j == -1){
                i++;
                j++;
            }
        }
    }
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
    cout << "findnext: ";
    for(int i = 0; i < m; i++)
        cout << next[i] << " ";
    cout << endl;
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

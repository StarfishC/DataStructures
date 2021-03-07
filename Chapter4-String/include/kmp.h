// File:    kmp.h
// Author:  csh
// Date:    2021/03/07
// ===================


#ifndef __KMP_H_
#define __KMP_H_

#include <string>

using std::string;

// 下列两个来自B站
void prefix_table(char pattern[], int prefix[], int n);
void KMP(char text[], char pattern[]);


// 以下两个来自教材
int* findNext(string P);
int KMPStrMatching(const string &T, const string &P, int *N);


#endif

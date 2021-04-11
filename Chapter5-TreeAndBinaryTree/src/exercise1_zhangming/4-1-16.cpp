// File:    4-1-16.cpp
// Author:  csh
// Date:    2020/09/12
// ===================

#include <iostream>


int printRange(BinaryTreeNode *root, int min, int max){
    using namespace std;
    if(root->value() < min)
        return 0;
    else if(root->value() == min){
        cout << root->value() << endl;
        return printRange(root->rightChild(), min ,max) + 1;
    }else if(root->value() <= max){
        cout << root->value() << endl;
        return printRange(root->leftChild(), min, max) + printRange(root->rightChild(), min, max) + 1;
    }else if(root->value() > max)
        return printRange(printRange(root->leftChild(), min, max), int min, int max)
}

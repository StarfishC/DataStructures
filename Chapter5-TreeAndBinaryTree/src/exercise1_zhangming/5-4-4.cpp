// File:    5-4-4.cpp
// Author:  csh
// Date:    2020/12/05
// ===================


#include "BinaryTreeNode.hpp"


template <typename T>
bool rootPath(BinaryTreeNode<T> *root, T value, T *PathRoot, int &sum)
{
    if(root == nullptr) return false;
    if(root->value() == value) return true;
    if(rootPath(root->leftChild(), value, PathRoot, sum))
    {
        PathRoot[sum] = root->rightChild()->value;
        sum += 1;
        return true;
    }
    if(rootPath(root->rightChild(), value, PathRoot, sum))
    {
        PathRoot[sum] = root->rightChild()->value;
        sum += 1;
        return true;
    }
    return false;
}

template <typename T>
bool solution(BinaryTreeNode<T> *root, T value)
{
    int sum = 0;
    T PathRoot[100];
    bool ret = rootPath(root, value, PathRoot, sum);
    return ret;
}

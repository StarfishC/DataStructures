// File:    5-4-6.cpp
// Author:  csh
// Date:    2020/12/05
// ===================


#include <queue>
#include "BinaryTreeNode.hpp"


using std::queue;

template <typename T>
bool isFullBT(BinaryTreeNode<T> *root)
{
    queue<BinaryTreeNode<T> *> Q;
    BinaryTreeNode<T> *temp;
    if(!root)
        return true;
    Q.push(root);
    while(!Q.empty())
    {
        temp = Q.front();
        Q.pop();
        if(temp->leftChild() && temp->rightChild())
        {
            Q.push(temp->leftChild());
            Q.push(temp->rightChild());
        }else if(temp->leftChild() == nullptr && temp->rightChild() == nullptr)
            continue;
        else
            return false;
    }
}

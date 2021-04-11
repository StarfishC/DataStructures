// File:    5-1-6.cpp
// Author:  csh
// Date:    2020/09/27
// ===================


#include "../headers/treeNode.hpp"


// 解法一：递归1
template <typename T>
int nodeCount1(TreeNode<T> *root){
    if(root == nullptr)
        return 0;
    return 1 + nodeCount1(root->leftMostChild()) + nodeCount1(root->rightSibling());
}

// 解法二：递归2
template <typename T>
int nodeCount2(TreeNode<T> *root){
    int sum = 0;
    while(root != nullptr){
        sum ++;                     // 加上本节点
        sum += nodeCount2(root->leftMostChild());
        root = root->rightSibling();
    }
    return sum;
}

// 解法三：非递归（略）

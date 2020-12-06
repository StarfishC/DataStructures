// File:    5-5-10.cpp
// Author:  csh
// Date:    2020/12/06
// ===================


#include "../headers/treeNode.hpp"

template <typename T>
int height(TreeNode<T> *root){
    if(root == nullptr)
        return 0;
    else{
        int leftHeight = height(root->leftMostChild()) + 1;
        int rightHeight = height(root->rightSibling() + 1);
        return leftHeight > rightHeight ? leftHeight : rightHeight;
    }
}

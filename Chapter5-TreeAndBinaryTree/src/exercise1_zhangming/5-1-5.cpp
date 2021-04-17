// File:    5-1-5.cpp
// Author:  csh
// Date:    2020/09/12
// Update:  2021/04/17
// ===================



template <typename T>
int BinaryTree<T>::leafNumber(BinaryTreeNode<T> *node)
{
    if(node == nullptr) return 0;
    if(node->isLeaf()) return 1;
    return leafNumber(node->leftChild()) + leafNumber(node->rightChild());
}


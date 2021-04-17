// File:    5-1-6.cpp
// Author:  csh
// Date:    2020/09/12
// Update:  2021/04/17
// ===================


template <typename T>
int BinaryTree<T>::height(BinaryTreeNode<T> *node)
{
    if(node == nullptr)
        return 0;
    int h1 = height(node->leftChild()) + 1;
    int h2 = height(node->rightChile()) + 1;
    return h1 > h2 ? h1:h2;
}

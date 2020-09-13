// File:    4-1-5.cpp
// Author:  csh
// Date:    2020/09/12
// ===================



template <typename T>
int BinaryTree<T>::leftNumber(BinaryTreeNode<T> *node){
    if(node == nullptr) return 0;
    if(node->isLeaf()) return 1;
    return leftNumber(node->leftChild()) + leftNumber(node->rightChild());
}


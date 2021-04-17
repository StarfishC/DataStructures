// File:    5-1-7.cpp
// Author:  csh
// Date:    2020/09/12
// ===================


template <typename T>
void BinaryTree<T>::changePos(BinaryTreeNode<T> *node)
{
    BinaryTreeNode<T> *temppoint;
    if(node != nullptr)
    {
        // 交换当前结点左右孩子的位置
        temppoint = node->leftChild();
        node->leftChild = node->rightChild(); 
        node->rightChild() = temppoint;
        changePos(node->leftChild());
        changePos(node->rightChild());
    }
}

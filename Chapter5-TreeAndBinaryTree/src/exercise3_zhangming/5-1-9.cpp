// File:    5-1-9.cpp
// Author:  csh
// Date:    2020/09/27
// ===================


template <typename T>
BinaryTree<T>* ToBinaryTree(TreeNode<T> *treeRoot)
{
    BinaryTree *Btree = new BinaryTree();       // 申请空二叉树
    if(!treeRoot) return Btree;                 // 为空则返回
    Btree->root = ChangeSubTree(treeRoot);
    return Btree;
}

template <typename T>
BinaryTreeNode<T>* ChangeSubTree(TreeNode<T> *treeRoot)
{
    BinaryTreeNode<T> *pointer;
    if(treeRoot == NULL)
        return NULL;
    pointer = new BinaryTreeNode(treeRoot->value());
    // 设置左节点
    pointer->setLeftChild(ChangeSubTree<T>(tree->leftMostChild()));
    // 设置右节点
    pointer->setRightChild(ChangeSubTree<T>(tree->rightSibling()));
    return pointer;
}

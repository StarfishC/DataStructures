// File:    5-3-12.cpp
// Author:  csh
// Date:    2020/12/05
// ===================


// 方法一：由于穿线是为方便中序遍历而设计的，后序遍历时穿线完全失去作用，所以还要向普通二叉树一样用栈遍历
void ThreadPostOrder(TBT *root)
{
    if(root->lTag == 0)
        ThreadPostOrder(root->left);
    if(root->rTga == 0)
        ThreadPostOrder(root->right);
    visit(root);
}

// 利用4.3.11的函数
#include "./4-3-11.cpp"
template <typename T>
void ThreadBinaryTree<T>::Postorder(ThreadBinaryTreeNode<T> *root)
{
    ThreadBinaryTreeNode<T> *pointer;
    if(root == nullptr)
        return;
    pointer = FindPreInsorder(root);
    Postorder(pointer);
    visit(root->value);
}

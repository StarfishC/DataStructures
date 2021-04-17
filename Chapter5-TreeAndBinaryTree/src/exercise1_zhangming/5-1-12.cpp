// File:    5-1-12.cpp
// Author:  csh
// Date:    2020/09/12
// ===================


template <typename T>
void BinarySearchTree<T>::DeleteNodeEx(BinaryTreeNode<T> *pointer)
{
    if(pointer == NULL)
        return;
    BinaryTreeNode<T> *temppointer;                                     // 用于保存替换结点
    BinaryTreeNode<T> *tempparent;                                      // 用于保存替换结点的父结点
    BinaryTreeNode<T> *parent = Parent(pointer);                        // 用于保存待删除结点的父结点
    if(pointer->leftchild() == NULL)                                    // 如果待删除结点的左子树为空
        temppointer = pointer->rightchild();                            // 替换结点赋值为其右子树的根
    else
    {
        temppointer = pointer->leftchild();
        while(temppointer->rightchild() != NULL)                        // 寻找左子树最大结点
        {
            tempparent = temppointer;
            temppointer = temppointer->rightchild();                    // 向右下降
        }
        if(tempparent == NULL)                                          // 如果替换结点是被删结点的左子结点
            pointer->left = temppointer->leftchild();                   // 替换结点左子树挂接到被删结点的左子树
        else tempparent->right = temppointer->leftchild();              // 替换结点的左子树作为其父结点右子树
        temppointer->left = pointer->leftchild();                       // 继承pointer的左子树
        temppointer->right = pointer->rightchild();                     // 继承pointer的右子树
    }

    // 下面用替换结点代替待删除结点
    if(parent == NULL)
        root = temppointer;
    else if(parent->leftchild == pointer)
        parent->left = temppointer;
    else parent->right = temppointer;
    delete pointer;
    pointer = NULL;
    return;
};

template <typename T>
void BinarySearchTree<T>::deleteNode(BinaryTreeNode<T> *root, T num)
{
    if(root == NULL)
        return;
    if(root.value < num)
        deleteNode(root->leftchild(), num);
    else if(root.value > num)
        deleteNode(root->rightchild(), num);
    else
        deleteEx(root);
}


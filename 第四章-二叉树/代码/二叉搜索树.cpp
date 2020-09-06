// File:    二叉搜索树.cpp
// Author:  csh
// Date:    2020/07/04
// ===================


#include <cstddef>
#include "../headers/binaryTreeNode.hpp"


template <typename T>
class BinarySearchTree{
    private:
        BinaryTreeNode<T> *root;
    public:
        void InsertNode(BinaryTreeNode<T> *newPointer);                 // 插入新结点newPointer
        void DeleteNodeEx(BinaryTreeNode<T> *pointer);                  // 删除结点
        BinaryTreeNode<T>* parent(BinaryTreeNode<T> *current);          // 当前结点的父结点
};

template <typename T>
void BinarySearchTree<T>::InsertNode(BinaryTreeNode<T> *newPointer){
    BinaryTreeNode<T> *pointer = NULL;
    if(root == NULL){
        root = newPointer;                                              // 空树则指针newPointer为新树根
        return;
    }else pointer = root;
    while(pointer != NULL){
        if(newPointer->value() == pointer->value())                     // 元素相等不用插入
            return;
        else if(newPointer->value() < pointer->value()){                // 插入结点小于关键码值，进入左子树
            if(pointer->leftchild() == NULL){                           // pointer没有左孩子
                pointer->setLeftchild(newPointer);
                return;
            }else pointer = pointer->leftchild();                       // 向左下降
        }
        else{                                                           // 插入结点大于关键码值，进入右子树
            if(pointer->rightchild() == NULL){
                pointer->setRightchild(newPointer);
                return;
            }else pointer = pointer->rightchild();
        }
    }
}

template <typename T>
void BinarySearchTree<T>::DeleteNodeEx(BinaryTreeNode<T> *pointer){
    if(pointer == NULL)
        return;
    BinaryTreeNode<T> *temppointer;                                     // 用于保存替换结点
    BinaryTreeNode<T> *tempparent;                                      // 用于保存替换结点的父结点
    BinaryTreeNode<T> *parent = Parent(pointer);                        // 用于保存待删除结点的父结点
    if(pointer->leftchild() == NULL){                                   // 如果待删除结点的左子树为空
        temppointer = pointer->rightchild();                            // 替换结点赋值为其右子树的根
    }else{
        temppointer = pointer->leftchild();
        while(temppointer->rightchild() != NULL){                       // 寻找左子树最大结点
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

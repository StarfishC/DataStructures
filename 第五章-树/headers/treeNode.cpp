// File:    treeNode.cpp
// Author:  csh
// Date:    2020/09/27
// ===================


#include "./treeNode.hpp"

template <typename T>
TreeNode<T>::TreeNode(const T &value){
    m_value = value;
    pChild = nullptr;
    pRight = nullptr;
}

template <typename T>
bool TreeNode<T>::isLeaf(){
    if(pChild == nullptr)
        return true;
    return false;
}

template <typename T>
void TreeNode<T>::setValue(const T &value){
    m_value = value;
}

template <typename T>
void TreeNode<T>::InsertFirst(TreeNode<T> *node){
    if(pChild == nullptr)           // 没有子结点
        pChild = node;
    else{
        node->setSibling(pChild);
        pChild = node;
    }
}


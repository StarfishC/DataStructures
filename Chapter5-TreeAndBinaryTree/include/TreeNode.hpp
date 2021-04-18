// File:    TreeNode.hpp
// Author:  csh
// Date:    2021/4/18
// ===================


#pragma once

template <typename T>
class TreeNode
{
    private:
        T m_value;
        TreeNode<T> *pChild;                    // 左子结点
        TreeNode<T> *pSibling;                  // 右兄弟指针
    public:
        TreeNode(const T &value);
        virtual ~TreeNode(){}
        bool isLeaf();                          // 判断是否为叶结点
        T value();                              // 返回结点的值
        TreeNode<T>* leftMostChild();           // 返回第一个左节点
        TreeNode<T>* rigthSibling();            // 返回右兄弟
        void setValue(const T &value);          // 设置当前节点的值
        void setChild(TreeNode<T> *pointer);    // 设置左子结点
        void setSibling(TreeNode<T> *pointer);  // 设置右兄弟
        void insertFirst(TreeNode<T> *node);    // 以第一个结点身份插入结点
        void insertNext(TreeNode<T> *node);     // 以有兄弟身份插入结点
};

template <typename T>
TreeNode<T>::TreeNode(const T &value):m_value(value), pChild(nullptr), pSibling(nullptr){}

template <typename T>
bool TreeNode<T>::isLeaf()
{
    return pChild == nullptr;
}

template <typename T>
T TreeNode<T>::value()
{
    return m_value;
}

template <typename T>
TreeNode<T>* TreeNode<T>::leftMostChild()
{
    return pChild;
}

template <typename T>
TreeNode<T>* TreeNode<T>::rigthSibling()
{
    return pSibling;
}

template <typename T>
void TreeNode<T>::setValue(const T &value)
{
    m_value = value;
}

template <typename T>
void TreeNode<T>::setChild(TreeNode<T> *pointer)
{
    pChild = pointer;
}

template <typename T>
void TreeNode<T>::setSibling(TreeNode<T> *pointer)
{
    pSibling = pointer;
}

template <typename T>
void TreeNode<T>::insertFirst(TreeNode<T> *node)
{
    if(pChild == nullptr)               // 如果没有子结点
        pChild = node;
    else
    {
        node->setSibling(pChild);       // 有子结点，原来子结点置为node的右兄弟
        pChild = node;
    }
}

template <typename T>
void TreeNode<T>::insertNext(TreeNode<T> *node)
{
    if(!pSibling)
        pSibling = node;
    TreeNode<T> *temppointer = pSibling;
    while(temppointer->rigthSibling())  // 找到最右边右兄弟
        temppointer = temppointer->rigthSibling();
    temppointer->setSibling(node);
}

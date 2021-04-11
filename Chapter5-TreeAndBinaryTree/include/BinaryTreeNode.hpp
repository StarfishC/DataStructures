// File:    BinaryTree.hpp
// Author:  csh
// Date:    2021/4/10
// ===================


#pragma once

template <typename T>
class BinaryTreeNode
{
    private:
        T info;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
    public:
        BinaryTreeNode();
        BinaryTreeNode(const T &ele);
        BinaryTreeNode(const T &ele, BinaryTreeNode<T> *l, BinaryTreeNode<T> *r);
        T value() const;                                                      // 返回当前结点的数据
        BinaryTreeNode<T>* leftChild() const;                           // 返回当前结点的左子树
        BinaryTreeNode<T>* rightChild() const;                          // 返回当前结点的右子树
        void setLeftChild(BinaryTreeNode<T> *pointer);                  // 设置当前结点的左子树
        void setRightChild(BinaryTreeNode<T> *pointer);                 // 设置当前结点的右子树
        void setValue(const T &value);                                  // 设置当前结点的数据
        bool isLeaf() const;                                            // 判断当前结点是否为叶结点
        BinaryTreeNode<T>& operator=(const BinaryTreeNode<T> &node);    // 重载赋值操作符
};

template <typename T>
BinaryTreeNode<T>::BinaryTreeNode():BinaryTreeNode<T>(0, nullptr, nullptr){}

template <typename T>
BinaryTreeNode<T>::BinaryTreeNode(const T &ele):BinaryTreeNode<T>(ele, nullptr, nullptr){}

template <typename T>
BinaryTreeNode<T>::BinaryTreeNode(const T &ele, BinaryTreeNode<T> *l, BinaryTreeNode<T> *r):
        info(ele), left(l), right(r){}

template <typename T>
inline T BinaryTreeNode<T>::value() const
{
    return info;
}

template <typename T>
inline BinaryTreeNode<T>* BinaryTreeNode<T>::leftChild() const
{
    return left;
}

template <typename T>
inline BinaryTreeNode<T>* BinaryTreeNode<T>::rightChild() const
{
    return right;
}

template <typename T>
inline void BinaryTreeNode<T>::setLeftChild(BinaryTreeNode<T> *pointer)
{
    left = pointer;
}

template <typename T>
inline void BinaryTreeNode<T>::setRightChild(BinaryTreeNode<T> *pointer)
{
    right = pointer;
}

template <typename T>
inline void BinaryTreeNode<T>::setValue(const T &value)
{
    info = value;
}

template <typename T>
bool BinaryTreeNode<T>::isLeaf() const
{
    return left == nullptr && right == nullptr;
}

template <typename T>
BinaryTreeNode<T>& BinaryTreeNode<T>::operator=(const BinaryTreeNode<T> &node)
{
    info = node.value();
    left = node.leftChild();
    right = node.rightChild();
    return *this;
}


// File:    binaryTreeNode.cpp
// Author:  csh
// Date:    2020/09/19
// ===================


#include "binaryTreeNode.hpp"


template <typename T>
BinaryTreeNode<T>::BinaryTreeNode():BinaryTreeNode<T>(0, nullptr, nullptr){}

template <typename T>
BinaryTreeNode<T>::BinaryTreeNode(const T &ele):BinaryTreeNode<T>(ele, nullptr, nullptr){}

template <typename T>
BinaryTreeNode<T>::BinaryTreeNode(const T &ele, BinaryTreeNode<T> *l, BinaryTreeNode<T> *r):
    info(ele), left(l), right(r){}

template <typename T>
T BinaryTreeNode<T>::value(){
    return info;
}

template <typename T>
BinaryTreeNode<T>* BinaryTreeNode<T>::leftChild()const{
    return left;
}

template <typename T>
BinaryTreeNode<T>* BinaryTreeNode<T>::rightChild() const{
    return right;
}

template <typename T>
void BinaryTreeNode<T>::setLeftChild(BinaryTreeNode<T> *pointer){
    left = pointer;
}

template <typename T>
void BinaryTreeNode<T>::setRightChild(BinaryTreeNode<T> *pointer){
    right = pointer;
}

template <typename T>
void BinaryTreeNode<T>::setValue(const T &val){
    info = val;
}

template <typename T>
bool BinaryTreeNode<T>::isLeaf() const{
    return left == nullptr && right == nullptr;
}

template <typename T>
BinaryTreeNode<T>& BinaryTreeNode<T>::operator=(const BinaryTreeNode<T> &node){
    this->info = node.value();
    this->left = node.leftChild();
    this->right = node.rightChild();
    return this;
}

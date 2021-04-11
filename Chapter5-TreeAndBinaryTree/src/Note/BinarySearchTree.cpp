// File:    BinarySearchTree.cpp
// Author:  csh
// Date:    2021/4/11
// ===================


#include <stack>
#include <iostream>
#include "BinaryTreeNode.hpp"


template <typename T>
class BinarySearchTree
{
    private:
        BinaryTreeNode<T> *root;
    public:
        BinarySearchTree(){ root = nullptr; }
        ~BinarySearchTree();
        void deleteSearchTree();
        void deleteSearchTree(BinaryTreeNode<T> *node);     // 删除指定二叉搜索树
        BinaryTreeNode<T>* find(const T &val);              // 查找元素
        void insertNode(BinaryTreeNode<T> *newPointer);     // 插入结点
        void insertNode(const T &val);                      // 插入值
        void deleteNode(BinaryTreeNode<T> *pointer);        // 删除结点
        BinaryTreeNode<T>* parent(BinaryTreeNode<T> *current);  // 返回当前结点父结点

        // 测试用
        void inOrder();                                     // 中序遍历
        void inOrder(BinaryTreeNode<T> *node);
};

template <typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
    deleteSearchTree();
}

template <typename T>
inline void BinarySearchTree<T>::deleteSearchTree()
{
    deleteSearchTree(root);
}

template <typename T>
void BinarySearchTree<T>::deleteSearchTree(BinaryTreeNode<T> *node)
{
    if(node)
    {
        deleteSearchTree(node->leftChild());
        deleteSearchTree(node->rightChild());
        delete node;
    }
}

template <typename T>
BinaryTreeNode<T>* BinarySearchTree<T>::find(const T &val)
{
    BinaryTreeNode<T> *pointer = root;
    while(pointer)
    {
        if(val > pointer->value())
            pointer = pointer->rightChild();
        else if(val < pointer->value())
            pointer = pointer->leftChild();
        else
            return pointer;
    }
    return nullptr;
}

template <typename T>
void BinarySearchTree<T>::insertNode(BinaryTreeNode<T> *newPointer)
{
    if(root == nullptr)
    {
        root = newPointer;
        return;
    }
    BinaryTreeNode<T> *pointer = root;
    while(pointer)
    {
        if(newPointer->value() == pointer->value())             // 元素相等不插入
            return;
        else if(newPointer->value() < pointer->value())         // 待插入结点小于当前关键码值
        {
            if(pointer->leftChild() == nullptr)                 // 左孩子为空，则插入
            {
                pointer->setLeftChild(newPointer);
                return;
            }
            else
                pointer = pointer->leftChild();                 // 左孩子不为空，继续查找
        }
        else
        {
            if(pointer->rightChild() == nullptr)
            {
                pointer->setRightChild(newPointer);
                return;
            }
            else
                pointer = pointer->rightChild();
        }
    }
}

template <typename T>
void BinarySearchTree<T>::insertNode(const T &val)
{
    BinaryTreeNode<T> *pointer = new BinaryTreeNode<T>(val);
    insertNode(pointer);
}

template <typename T>
void BinarySearchTree<T>::deleteNode(BinaryTreeNode<T> *pointer)
{
    if(pointer == nullptr)
        return;
    BinaryTreeNode<T> *temppointer;                         // 用于保存替换结点
    BinaryTreeNode<T> *tempparent = nullptr;                // 用于保存替换结点的父结点
    BinaryTreeNode<T> *pointerparent = parent(pointer);     // 用于保存待删除结点的父结点
    if(pointer->leftChild() == nullptr)                     // 待删除结点的左子树为空
        temppointer = pointer->rightChild();                // 替换结点为右子树的根
    else                                                    // 待删除结点左子树不空，则寻找左子树最大结点
    {
        temppointer = pointer->leftChild();
        while(temppointer->rightChild())
        {
            tempparent = temppointer;
            temppointer = temppointer->rightChild();
        }
        if(tempparent == nullptr)                           // 如果替换结点是被删结点的左子结点
            pointer->setLeftChild(temppointer->leftChild());
        else
            tempparent->setRightChild(temppointer->leftChild());   // 替换结点的左子树作为其父结点右子树

        temppointer->setLeftChild(pointer->leftChild());    // 继承pointer的左子树
        temppointer->setRightChild(pointer->rightChild());  // 继承pointer的右子树
    }

    if(pointerparent == nullptr)                            // 父结点不存在，即删除根结点
        root = temppointer;
    else if(pointerparent->leftChild() == pointer)          // 删除的结点在父结点左边
        pointerparent->setLeftChild(temppointer);
    else
        pointerparent->setRightChild(temppointer);
    delete pointer;
    pointer = nullptr;
    return;
}

template <typename T>
BinaryTreeNode<T>* BinarySearchTree<T>::parent(BinaryTreeNode<T> *current)
{
    using std::stack;
    stack<BinaryTreeNode<T>* > aStack;
    BinaryTreeNode<T> *pointer = root;
    if(current == nullptr || current == root) return nullptr;
    aStack.push(nullptr);
    while(pointer)
    {
        if(current == pointer->leftChild() || current == pointer->rightChild())
            return pointer;
        if(pointer->rightChild())
            aStack.push(pointer->rightChild());
        if(pointer->leftChild())
            pointer = pointer->leftChild();
        else
        {
            pointer = aStack.top();
            aStack.pop();
        }
    }
}

template <typename T>
void BinarySearchTree<T>::inOrder()
{
    inOrder(root);
    std::cout << std::endl;
}

template <typename T>
void BinarySearchTree<T>::inOrder(BinaryTreeNode<T> *node)
{
    using std::cout;
    using std::endl;
    if(node)
    {
        inOrder(node->leftChild());
        cout << node->value() << " ";
        inOrder(node->rightChild());
    }
}


int main()
{
    using namespace std;
    BinarySearchTree<int> bst;
    int arr[] = {50, 19, 35, 55, 20, 5, 100, 52, 88, 53, 92};
    BinaryTreeNode<int> *delpointer;
    for(auto i = 0; i < 10; i++)
    {
        BinaryTreeNode<int> *pointer = new BinaryTreeNode<int>(arr[i]);
        bst.insertNode(pointer);
    }
    bst.inOrder();
    delpointer = bst.find(55);
    cout << delpointer->value() << endl;
    bst.deleteNode(delpointer);
    bst.inOrder();
    return 0;
}

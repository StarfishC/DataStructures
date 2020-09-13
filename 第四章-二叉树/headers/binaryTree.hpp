// File:    binaryTree.cpp
// Author:  csh
// Date:    2020/07/04
// ===================


#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_


#include <iostream>
#include <stack>
#include <queue>

template <typename T>
class BinaryTree;


// 二叉树结点类
template <typename T>
class BinaryTreeNode{
    friend class BinaryTree<T>;                             // 声明二叉树类为友元类，以便访问私有数据成员
    private:
        T info;
        BinaryTreeNode<T> *left;                            // 指向左子树指针
        BinaryTreeNode<T> *right;                           // 指向右子树指针
    public:
        BinaryTreeNode();                                   // 默认构造函数
        BinaryTreeNode(const T& ele);                       // 给定数据的构造函数
        BinaryTreeNode(const T& ele, BinaryTreeNode<T> *l, BinaryTreeNode<T> *r);       // 子树构造函数
        T value();                                          // 返回当前结点的数据
        BinaryTree<T>* leftchild() const;                   // 返回当前结点的左子树
        BinaryTree<T>* rightchild() const;                  // 返回当前结点的右子树
        void setLeftchild(BinaryTreeNode<T>* l);            // 设置当前结点的左子树
        void setRightchild(BinaryTreeNode<T>* r);           // 设置当前结点的右子树
        void setValue(const T& val);                        // 设置当前结点的数字域
        bool isLeaf() const;                                // 判断当前结点是否为叶结点
        BinaryTreeNode<T> &operator=(const BinaryTreeNode<T> &Node);        // 重载赋值操作符
};


// 二叉树类
template <typename T>
class BinaryTree{
    private:
        BinaryTreeNode<T> *root;                            // 二叉树根结点
    public:
        BinaryTree(){root = NULL;};                         // 默认构造函数
        ~BinaryTree(){DeleteBinaryTree(root);}              // 析构函数
        void DeleteBinaryTree(BinaryTreeNode<T> *node);     // 删除给定的二叉树
        bool IsEmpty() const;                               // 判断二叉树是否为空
        BinaryTreeNode<T>* Root(){return root;};            // 返回二叉树根结点
        BinaryTreeNode<T>* Parent(BinaryTreeNode<T> *cur);  // 返回当前结点父结点
        BinaryTreeNode<T>* LeftSibling(BinaryTreeNode<T> *cur);     // 返回当前结点左兄弟
        BinaryTreeNode<T>* RightSibling(BinaryTreeNode<T> *cur);    // 返回当前结点右兄弟
        void CreateTree(const T &info, BinaryTree<T> &leftTree, BinaryTree<T> &rightTree);
                                                            // 构造新树
        inline void Visit(T &value);                        // 访问结点值
        void PreOrder(BinaryTreeNode<T> *node=NULL);        // 前序周游给定二叉树
        void InOrder(BinaryTreeNode<T> *node=NULL);         // 中序周游给定二叉树
        void PostOrder(BinaryTreeNode<T> *node=NULL);       // 后序周游给定二叉树
        void PreOrderWithoutRecursion();                    // 前序周游非递归
        void InOrderWithoutRecursion();                     // 中序周游非递归
        void PostOrderWithoutRecursion();                   // 后序周游非递归
        void LevelOrder();                                  // 层次周游给定二叉树(BFS)
};



#endif

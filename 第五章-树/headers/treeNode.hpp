// File:    treeNode.hpp
// Author:  csh
// Date:    2020/09/27
// ===================


#ifndef _TREENODE_H_
#define _TREENODE_H_

template <typename T>
class TreeNode{
    private:
        T m_value;                                          // 树结点的值
        TreeNode<T> *pChild;                                // 左子结点指针
        TreeNode<T> *pRight;                                // 右兄弟指针
    public:
        TreeNode(const T &value);                           // 构造函数
        virtual ~TreeNode(){};                              // 析构函数
        bool isLeaf();                                      // 判断当前结点是否为叶结点
        T value();                                          // 返回当前结点的值
        TreeNode<T> *leftMostChild();                       // 返回第一个左子结点
        TreeNode<T> *rightSibling();                        // 返回右兄弟
        void setValue(const T &value);                      // 设置当前结点的值
        void setChild(TreeNode<T> *pointer);                // 设置左子结点
        void setSibling(TreeNode<T> *pointer);              // 设置右兄弟
        void InsertFirst(TreeNode<T> *node);                // 以第一个左子结点身份插入结点
        void InsertNext(TreeNode<T> *node);                 // 以右兄弟的身份插入结点
};

#include "./treeNode.cpp"

#endif

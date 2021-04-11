// File:    BinaryTree.cpp
// Author:  csh
// Date:    2021/4/10
// ===================


#include <stack>
#include <queue>
#include <iostream>


template <typename T>
class BinaryTree;


template <typename T>
class BinaryTreeNode
{
    friend class BinaryTree<T>;
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
class BinaryTree
{
    private:
        BinaryTreeNode<T> *treeRoot;
    public:
        BinaryTree();
        ~BinaryTree(){ deleteBinaryTree(); }
        void deleteBinaryTree();                                            // 释放整个二叉树空间
        void deleteBinaryTree(BinaryTreeNode<T> *root);                     // 删除给定的二叉树
        bool isEmpty() const;                                               // 判定二叉树是否为空
        BinaryTreeNode<T>* root();                                          // 返回二叉树根结点
        BinaryTreeNode<T>* parent(BinaryTreeNode<T> *current);              // 返回当前结点的父结点
        BinaryTreeNode<T>* leftSibling(BinaryTreeNode<T> *current);         // 返回当前结点的左兄弟
        BinaryTreeNode<T>* rightSibling(BinaryTreeNode<T> *current);        // 返回当前结点的右兄弟
        void create(const T &info, BinaryTree<T> &leftTree, BinaryTree<T> &rightTree);  // 构造新树
        void visit(const T &val) const;                                     // 访问结点值
        void preOrder();                                                    // 先序周游二叉树
        void preOrder(BinaryTreeNode<T> *root);                             // 先序周游给定二叉树
        void inOrder();                                                     // 中序周游二叉树
        void inOrder(BinaryTreeNode<T> *root);                              // 中序周游给定二叉树
        void postOrder();                                                   // 后序周游二叉树
        void postOrder(BinaryTreeNode<T> *root);                            // 后序周游给定二叉树
        void levelOrder();                                                  // 层次周游二叉树
        void preOrderWithoutRecursion();                                    // 先序周游二叉树，非递归
        void inOrderWithoutRecursion();                                     // 中序周游二叉树，非递归
        void postOrderWithoutRecursion();                                   // 后序周游二叉树，非递归
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



template <typename T>
BinaryTree<T>::BinaryTree(): treeRoot(nullptr){}

template <typename T>
void BinaryTree<T>::deleteBinaryTree()
{
    deleteBinaryTree(treeRoot);
}

template <typename T>
void BinaryTree<T>::deleteBinaryTree(BinaryTreeNode<T> *root)
{
    if(root)
    {
        deleteBinaryTree(root->leftChild());
        deleteBinaryTree(root->rightChild());
        delete root;
    }
}

template <typename T>
void BinaryTree<T>::create(const T &info, BinaryTree<T> &leftTree, BinaryTree<T> &rightTree)
{
    treeRoot = new BinaryTreeNode<T>(info, leftTree.root(), rightTree.root());
    leftTree.root() = rightTree.root() = nullptr;
}

template <typename T>
inline bool BinaryTree<T>::isEmpty() const
{
    return treeRoot == nullptr;
}

template <typename T>
inline BinaryTreeNode<T>* BinaryTree<T>::root()
{
    return treeRoot;
}

template <typename T>
BinaryTreeNode<T>* BinaryTree<T>::parent(BinaryTreeNode<T> *current)
{
    // 采用先序周游思想
    using std::stack;
    stack<BinaryTreeNode<T>* > aStack;
    BinaryTreeNode<T> *pointer = treeRoot;
    if(current == nullptr || current == treeRoot) return nullptr;
    aStack.push(nullptr);               // 栈底监视哨
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
BinaryTreeNode<T>* BinaryTree<T>::leftSibling(BinaryTreeNode<T> *current)
{
    BinaryTreeNode<T> *ret = parent(current);
    if(ret)
        return ret->leftChild();
    return nullptr;
}

template <typename T>
BinaryTreeNode<T>* BinaryTree<T>::rightSibling(BinaryTreeNode<T> *current)
{
    BinaryTreeNode<T> *ret = parent(current);
    if(ret)
        return ret->rightChild();
    return nullptr;
}

template <typename T>
void BinaryTree<T>::visit(const T &val) const
{
    using std::cout;
    cout << val << " ";
}

template <typename T>
void BinaryTree<T>::preOrder()
{
    preOrder(treeRoot);
}

template <typename T>
void BinaryTree<T>::preOrder(BinaryTreeNode<T> *root)
{
    if(root)
    {
        visit(root->value());
        preOrder(root->leftChild());
        preOrder(root->rightChild());
    }
}

template <typename T>
void BinaryTree<T>::inOrder()
{
    inOrder(treeRoot);
}

template <typename T>
void BinaryTree<T>::inOrder(BinaryTreeNode<T> *root)
{
    if(root)
    {
        inOrder(root->leftChild());
        visit(root->value());
        inOrder(root->rightChild());
    }
}

template <typename T>
void BinaryTree<T>::postOrder()
{
    postOrder(treeRoot);
}

template <typename T>
void BinaryTree<T>::postOrder(BinaryTreeNode<T> *root)
{
    if(root)
    {
        postOrder(root->leftChild());
        postOrder(root->rightChild());
        visit(root->value());
    }
}

template <typename T>
void BinaryTree<T>::preOrderWithoutRecursion()
{
    using std::stack;
    stack<BinaryTreeNode<T>* > aStack;
    BinaryTreeNode<T> *pointer = treeRoot;
    aStack.push(nullptr);               // 栈底监视哨
    while(pointer)
    {
        visit(pointer->value());
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
void BinaryTree<T>::inOrderWithoutRecursion()
{
    using std::stack;
    stack<BinaryTreeNode<T>* > aStack;
    BinaryTreeNode<T> *pointer = treeRoot;
    while(!aStack.empty() || pointer)
    {
        if(pointer)
        {
            aStack.push(pointer);
            pointer = pointer->leftChild();
        }
        else
        {
            pointer = aStack.top();
            aStack.pop();
            visit(pointer->value());
            pointer = pointer->rightChild();
        }
    }
}

enum class Tags{Left, Right};
template <typename T>
class StackElement
{
    public:
        BinaryTreeNode<T> *pointer;
        Tags tag;
};
template <typename T>
void BinaryTree<T>::postOrderWithoutRecursion()
{
    using std::stack;
    stack<StackElement<T>* > aStack;
    StackElement<T> element;
    BinaryTreeNode<T> *pointer = treeRoot;
    while(!aStack.empty() || pointer)
    {
        while(pointer)                  // 当前指针非空则压栈并下降到最左子结点
        {
            element.pointer = pointer;
            element.tag = Tags::Left;   // 标记为Left
            aStack.push(element);
            pointer = pointer->leftChild();
        }
        element = aStack.top();
        aStack.pop();
        pointer = element.pointer;
        if(element.tag == Tags::Left)   // 标记是Left，表示右子树未压栈
        {
            element.tag = Tags::Right;  // 置标记为Right
            aStack.push(element);
            pointer = pointer->rightChild();
        }
        else
        {
            visit(pointer->value());
            pointer = nullptr;
        }
    }
}

template <typename T>
void BinaryTree<T>::levelOrder()
{
    using std::queue;
    queue<BinaryTreeNode<T>* > aQueue;
    BinaryTreeNode<T> *pointer = treeRoot;
    if(pointer)
        aQueue.push(pointer);
    while(!aQueue.empty())
    {
        pointer = aQueue.front();
        aQueue.pop();
        visit(pointer->value());
        if(pointer->leftChild())
            aQueue.push(pointer->leftChild());
        if(pointer->rightChild())
            aQueue.push(pointer->rightChild());
    }
}

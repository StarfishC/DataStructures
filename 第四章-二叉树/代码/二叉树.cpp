// File:    二叉树.cpp
// Author:  csh
// Date:    2020/07/04
// ===================


#include <cstdio>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

template <typename T>
class BinaryTreeNode;

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
        void PreOrder();                                    // 前序周游给定二叉树
        void InOrder();                                     // 中序周游给定二叉树
        void PostOrder();                                   // 后序周游给定二叉树
        void LevelOrder();                                  // 层次周游给定二叉树(BFS)

        void PreOrderWithoutRecursion();                    // 前序周游非递归
        void InOrderWithoutRecursion();                     // 中序周游非递归
        void PostOrderWithoutRecursion();                   // 后序周游非递归
};


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


template <typename T>
void BinaryTree<T>::CreateTree(const T &info, BinaryTree<T> &leftTree, BinaryTree<T> &rightTree){
    root = new BinaryTreeNode<T>(info, leftTree.root, rightTree.root);
    leftTree.root = rightTree.root = NULL;                  // 置空，避免非法访问
}

template <typename T>
void BinaryTree<T>::DeleteBinaryTree(BinaryTreeNode<T> *node){
    if(node != NULL){
        DeleteBinaryTree(node->left);
        DeleteBinaryTree(node->right);
        delete root;
    }
}

template <typename T>
BinaryTreeNode<T>* BinaryTree<T>::Parent(BinaryTreeNode<T> *cur){
    stack<BinaryTreeNode<T> *> aStack;
    BinaryTreeNode<T> *pointer = root;
    if(root != NULL && cur != NULL){
        while(!aStack.empty() || pointer){
            if(pointer != NULL){
                if(cur == pointer->leftchild() || cur == pointer->rightchild())
                    return pointer;
                aStack.push(pointer);
                pointer = pointer->leftchild();
            }else{
                pointer = aStack.top();                     // 左子树访问完毕,访问右子树
                aStack.pop();
                pointer = pointer->rightchild();
            }
        }
    }
}

template <typename T>
bool BinaryTree<T>::IsEmpty() const{
    return (root != NULL ? false: true);
}

template <typename T>
void BinaryTree<T>::PreOrder(){
    if(root != NULL){
        cout << root->value() << " ";
        PreOrder(root->leftchild());
        PreOrder(root->rightchild());
    }
    cout << endl;
}

template <typename T>
void BinaryTree<T>::InOrder(){
    if(root != NULL){
        InOrder(root->leftchild());
        cout << root->value() << " ";
        InOrder(root->rightchild());
    }
    cout << endl;
}

template <typename T>
void BinaryTree<T>::PostOrder(){
    if(root != NULL){
        PostOrder(root->leftchild());
        PostOrder(root->rightchild());
        cout << root->value() << " ";
    }
    cout << endl;
}

template <typename T>
void BinaryTree<T>::PreOrderWithoutRecursion(){
    stack<BinaryTreeNode<T> *> aStack;
    BinaryTreeNode<T> *pointer = root;
    aStack.push(NULL);                              // 栈底监视哨
    while(pointer){
        cout << pointer << " ";
        if(pointer->rightchild() != NULL)           // 右孩子入栈
            aStack.push(pointer->rightchild());
        if(pointer->leftchild() != NULL)            // 转到左子树
            pointer = pointer->leftchild();
        else{                                       // 左子树访问完毕
            pointer = aStack.top();
            aStack.pop();
        }
    }
}

template <typename T>
void BinaryTree<T>::InOrderWithoutRecursion(){
    stack<BinaryTreeNode<T> *> aStack;
    BinaryTreeNode<T> *pointer = root;
    while(!aStack.empty() || pointer){
        if(pointer){
            aStack.push(pointer);                   // 当前指针入栈
            pointer = pointer->leftchild();
        }else{                                      // 左子树访问完毕
            pointer = aStack.top();
            aStack.top();
            cout << pointer->value() << " ";
            pointer = pointer->rightchild();
        }
    }
    cout << endl;
}

enum Tags{Left, Right};
template <typename T>
class StackElement{
    public:
        BinaryTreeNode<T> *pointer;                 // 指向二叉树结点的指针
        Tags tag;                                   // 表示是否进入了右子树
};

template <typename T>
void BinaryTree<T>::PostOrderWithoutRecursion(){
    StackElement<T> element;
    stack<StackElement<T>> aStack;
    BinaryTreeNode<T> *pointer;
    if(root == NULL)
        return;
    else pointer = root;
    while(!aStack.empty() || pointer){
        while(pointer != NULL){                     // 当前指针非空则压栈并下降到最左子结点
            element.pointer = pointer;
            element.tag = Left;                     // 表示进入左子树
            aStack.push(element);
            pointer = pointer->leftchild();
        }
        element = aStack.top();
        aStack.pop();
        pointer = element.pointer;
        if(element.tag == Left){                    // 从左子树返回，那么标志位设为Right在压栈
            element.tag = Right;
            aStack.push(element);
            pointer = pointer->rightchild();
        }else{
            cout << pointer->value() << " ";
            pointer = NULL;                         // 置空，继续弹栈
        }
    }
    cout << endl;
}

template <typename T>
void BinaryTree<T>::LevelOrder(){
    queue<BinaryTreeNode<T> *> aQueue;
    BinaryTreeNode<T> *pointer = root;
    if(pointer)
        aQueue.push(pointer);
    while(!aQueue.empty()){
        pointer = aQueue.front();                   // 获得队首结点
        aQueue.pop();
        cout << pointer->value() << " ";
        if(pointer->leftchild() != NULL)
            aQueue.push(pointer->leftchild());
        if(pointer->rightchild() != NULL)
            aQueue.push(pointer->rightchild());
    }
}

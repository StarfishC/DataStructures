// File:    binaryTree.cpp
// Author:  csh
// Date:    2020/09/12
// ===================


#include "binaryTree.hpp"

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
        delete node;
    }
}

template <typename T>
BinaryTreeNode<T>* BinaryTree<T>::Parent(BinaryTreeNode<T> *cur){
    using std::stack;
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
    return NULL;
}

template <typename T>
bool BinaryTree<T>::IsEmpty() const{
    return root == NULL;
}

template <typename T>
void BinaryTree<T>::PreOrder(BinaryTreeNode<T> *node){
    if(node == NULL){
        if(root){
            Visit(root->value());
            PreOrder(root->leftchild());
            PreOrder(root->rightchild());
        }
    }else{
        if(node){
            Visit(node->value());
            PreOrder(node->leftchild());
            PreOrder(node->rightchild());
        }
    }
}

template <typename T>
void BinaryTree<T>::InOrder(BinaryTreeNode<T> *node){
    if(node == NULL){
        if(root){
            InOrder(root->leftchild());
            Visit(root->value());
            InOrder(root->rightchild());
        }
    }else{
        if(node){
            InOrder(node->leftchild());
            Visit(node->value());
            InOrder(node->rightchild());
        }
    }
}

template <typename T>
void BinaryTree<T>::PostOrder(BinaryTreeNode<T> *node){
    if(node == NULL){
        if(root){
            PostOrder(root->leftchild());
            PostOrder(root->rightchild());
            Visit(root->value());
        }
    }else{
        if(node){
            PostOrder(node->leftchild());
            PostOrder(node->rightchild());
            Visit(node->value());
        }
    }
}

template <typename T>
void BinaryTree<T>::PreOrderWithoutRecursion(){
    using std::stack;
    stack<BinaryTreeNode<T> *> aStack;
    BinaryTreeNode<T> *pointer = root;
    aStack.push(NULL);                              // 栈底监视哨
    while(pointer){
        Visit(pointer->value());
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
    using std::stack;
    using std::cout;
    using std::endl;
    stack<BinaryTreeNode<T> *> aStack;
    BinaryTreeNode<T> *pointer = root;
    while(!aStack.empty() || pointer){
        if(pointer){
            aStack.push(pointer);                   // 当前指针入栈
            pointer = pointer->leftchild();
        }else{                                      // 左子树访问完毕
            pointer = aStack.top();
            aStack.top();
            Visit(pointer->value());
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
    using std::stack;
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
            Visit(pointer->value());
            pointer = NULL;                         // 置空，继续弹栈
        }
    }
}

template <typename T>
void BinaryTree<T>::LevelOrder(){
    using std::queue;
    using std::cout;
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

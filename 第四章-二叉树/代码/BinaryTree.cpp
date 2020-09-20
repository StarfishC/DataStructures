// File:    BinaryTree.cpp
// Author:  csh
// Date:    2020/09/19
// ===================


#include <stack>
#include <queue>
#include <iostream>

template <typename T>
class BinaryTree;


template <typename T>
class BinaryTreeNode{
    friend class BinaryTree<T>;
    private:
        T info;                                                                     // 二叉树结点数字域
        BinaryTreeNode<T> *left;                                                    // 左子树指针
        BinaryTreeNode<T> *right;                                                   // 右子树指针
    public:
        BinaryTreeNode();                                                           // 默认构造函数
        BinaryTreeNode(const T &ele);                                               // 给定数据的构造函数
        BinaryTreeNode(const T &ele, BinaryTreeNode<T> *l, BinaryTreeNode<T> *r);   // 子树构造结点
        T value();                                                                  // 返回当前结点的数据
        BinaryTreeNode<T>* leftChild() const;                                       // 返回当前结点的左子树
        BinaryTreeNode<T>* rightChild() const;                                      // 返回当前结点的右子树
        void setLeftChild(BinaryTreeNode<T> *pointer);                              // 设置当前结点的左子树
        void setRightChild(BinaryTreeNode<T> *pointer);                             // 设置当前结点的右子树
        void setValue(const T &val);                                                // 设置当前结点的数据
        bool isLeaf() const;                                                        // 判断当前结点是否为叶结点
        BinaryTreeNode<T>& operator=(const BinaryTreeNode<T> &node);                // 重载赋值操作符
};

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


template <typename T>
class BinaryTree{
    private:
        BinaryTreeNode<T> *treeRoot;                                                // 二叉树根结点
    public:
        BinaryTree(BinaryTreeNode<T> *root = nullptr);
        ~BinaryTree(){deleteBinaryTree();}                                          // 析构函数
        void deleteBinaryTree(BinaryTreeNode<T> *root);                             // 删除给定的二叉树
        void deleteBinaryTree();                                                    // 删除二叉树
        inline bool isEmpty() const;                                                // 判断二叉树是否为空数
        BinaryTreeNode<T>* root();                                                  // 返回二叉树根结点
        BinaryTreeNode<T>* parent(BinaryTreeNode<T> *current);                      // 返回当前结点的父结点
        BinaryTreeNode<T>* leftSibling(BinaryTreeNode<T> *current);                 // 返回当前结点的左兄弟
        BinaryTreeNode<T>* rightSibling(BinaryTreeNode<T> *current);                // 返回当前结点的右兄弟
        void create(const T &info, BinaryTree<T> &leftTree, BinaryTreeNode<T> &rightTree);      // 构造新树
        void visit(T val);                                                          // 访问结点值
        void preOrder();                                                            // 先序周游二叉树
        void preOrder(BinaryTreeNode<T> *root);                                     // 先序周游给定二叉树
        void inOrder();                                                             // 中序周游二叉树
        void inOrder(BinaryTreeNode<T> *root);                                      // 中序周游给定二叉树
        void postOrder();                                                           // 后序周游二叉树
        void postOrder(BinaryTreeNode<T> *root);                                    // 后序周游给定二叉树
        void preOrderWithoutRecursion();                                            // 非递归前序周游
        void inOrderWithoutRecursion();                                             // 非递归中序周游
        void postOrderWithoutRecursion();                                           // 非递归后序周游
        void levelOrder();                                                          // 层次周游二叉树

        void insertLeft(BinaryTreeNode<T> *node);                                   // 插入左结点
        void insertLeft(const T &val);
        void insertRight(BinaryTreeNode<T> *node);                                  // 插入右结点
        void insertRight(const T &val);
};

template <typename T>
BinaryTree<T>::BinaryTree(BinaryTreeNode<T> *root): treeRoot(root){
}

template <typename T>
void BinaryTree<T>::deleteBinaryTree(){
    deleteBinaryTree(treeRoot);
}

template <typename T>
void BinaryTree<T>::deleteBinaryTree(BinaryTreeNode<T> *root){
    if(root){
        deleteBinaryTree(root->leftChild());
        deleteBinaryTree(root->rightChild());
        delete root;
    }
}

template <typename T>
void BinaryTree<T>::create(const T &info, BinaryTree<T> &leftTree, BinaryTreeNode<T> &rightTree){
    treeRoot = new BinaryTreeNode<T>(info, leftTree.root(), rightTree.root());
    leftTree.root() = rightTree.root() == nullptr;
}

template <typename T>
bool BinaryTree<T>::isEmpty() const{
    return treeRoot == nullptr;
}

template <typename T>
BinaryTreeNode<T>* BinaryTree<T>::root(){
    return treeRoot;
}

template <typename T>
BinaryTreeNode<T>* BinaryTree<T>::parent(BinaryTreeNode<T> *current){
    // 采用先序周游思想
    using std::stack;
    stack<BinaryTreeNode<T>* > aStack;
    BinaryTreeNode<T> *pointer = treeRoot;
    if(current == nullptr || current == treeRoot) return nullptr;
    aStack.push(nullptr);                   // 栈底监视哨
    while(pointer){
        if(current == pointer->leftChild() || current == pointer->rightChild())
            return pointer;
        if(pointer->rightChild())
            aStack.push(pointer->rightChild());
        if(pointer->leftChild())
            pointer = pointer->leftChild();
        else{
            pointer = aStack.top();
            aStack.pop();
        }
    }
}

template <typename T>
BinaryTreeNode<T>* BinaryTree<T>::leftSibling(BinaryTreeNode<T> *current){
    BinaryTreeNode<T>* ret = parent(current);
    if(ret)
        return ret->leftChild();
    return nullptr;
}

template <typename T>
BinaryTreeNode<T>* BinaryTree<T>::rightSibling(BinaryTreeNode<T> *current){
    BinaryTreeNode<T>* ret = parent(current);
    if(ret)
        return ret->rightChild();
    return nullptr;
}

template <typename T>
void BinaryTree<T>::visit(T val){
    using std::cout;
    cout << val << " ";
}

template <typename T>
void BinaryTree<T>::preOrder(){
    preOrder(treeRoot);
}

template <typename T>
void BinaryTree<T>::preOrder(BinaryTreeNode<T> *root){
    if(root){
        visit(root->value());
        preOrder(root->leftChild());
        preOrder(root->rightChild());
    }
}

template <typename T>
void BinaryTree<T>::inOrder(){
    inOrder(treeRoot);
}

template <typename T>
void BinaryTree<T>::inOrder(BinaryTreeNode<T> *root){
    if(root){
        inOrder(root->leftChild());
        visit(root->value());
        inOrder(root->rightChild());
    }
}

template <typename T>
void BinaryTree<T>::postOrder(){
    postOrder(treeRoot);
}

template <typename T>
void BinaryTree<T>::postOrder(BinaryTreeNode<T> *root){
    if(root){
        postOrder(root->leftChild());
        postOrder(root->rightChild());
        visit(root->value());
    }
}

template <typename T>
void BinaryTree<T>::preOrderWithoutRecursion(){
    using std::stack;
    stack<BinaryTreeNode<T>* > aStack;
    BinaryTreeNode<T> *pointer = treeRoot;
    aStack.push(NULL);                      // 栈底监视哨
    while(pointer){
        visit(pointer->value());
        if(pointer->rightChild())
            aStack.push(pointer->rightChild());
        if(pointer->leftChild())
            pointer = pointer->leftChild();
        else{
            pointer = aStack.top();
            aStack.pop();
        }
    }
}

template <typename T>
void BinaryTree<T>::inOrderWithoutRecursion(){
    using std::stack;
    stack<BinaryTreeNode<T>* > aStack;
    BinaryTreeNode<T> *pointer = treeRoot;
    while(!aStack.empty() || pointer){
        if(pointer){
            aStack.push(pointer);
            pointer = pointer->leftChild();
        }else{
            pointer = aStack.top();
            aStack.pop();
            visit(pointer->value());
            pointer = pointer->rightChild();
        }
    }
}

enum Tags{Left, Right};
template <typename T>
class StackElement{
    public:
        BinaryTreeNode<T> *pointer;
        Tags tag;
};
template <typename T>
void BinaryTree<T>::postOrderWithoutRecursion(){
    using std::stack;
    stack<StackElement<T> *> aStack;
    StackElement<T> element;
    BinaryTreeNode<T> *pointer = treeRoot;
    while(!aStack.empty() || pointer){
        while(pointer){             // 当前指针非空则压栈并下降到最左子结点
            element.pointer = pointer;
            element.tag = Left;     // 标记为Left
            aStack.push(element);
            pointer = pointer->leftChild();
        }
        element = aStack.top();     // 获得栈顶元素
        aStack.pop();
        pointer = element.pointer;
        if(element.tag == Left){    // 标记是Left，表示右子树未压栈
            element.tag = Right;    // 置标记为Right
            aStack.push(element);
            pointer = pointer->rightChild();
        }else{
            visit(pointer->value());
            pointer = nullptr;
        }
    }
}

template <typename T>
void BinaryTree<T>::levelOrder(){
    using std::queue;
    queue<BinaryTreeNode<T>* > aQueue;
    BinaryTreeNode<T> *pointer = treeRoot;
    if(pointer)
        aQueue.push(pointer);
    while(!aQueue.empty()){
        pointer = aQueue.front();
        aQueue.pop();
        visit(pointer->value());
        if(pointer->leftChild())
            aQueue.push(pointer->leftChild());
        if(pointer->rightChild())
            aQueue.push(pointer->rightChild());
    }
}

template <typename T>
void BinaryTree<T>::insertLeft(BinaryTreeNode<T> *node){
    if(!treeRoot){
        treeRoot = node;
        return;
    }
    BinaryTreeNode<T> *pointer = treeRoot;
    while(pointer->leftChild())
        pointer = pointer->leftChild();
    pointer->setLeftChild(node);
}

template <typename T>
void BinaryTree<T>::insertLeft(const T &val){
    BinaryTreeNode<T> *pointer = new BinaryTreeNode<T>(val);
    insertLeft(pointer);
}

template <typename T>
void BinaryTree<T>::insertRight(BinaryTreeNode<T> *node){
    if(!treeRoot){
        treeRoot = node;
        return;
    }
    BinaryTreeNode<T> *pointer = treeRoot;
    while(pointer->rightChild())
        pointer = pointer->rightChild();
    pointer->setRightChild(node);
}

template <typename T>
void BinaryTree<T>::insertRight(const T &val){
    BinaryTreeNode<T> *pointer = new BinaryTreeNode<T>(val);
    insertLeft(pointer);
}


int main(int argc, char *argv[]){
    using namespace std;
    BinaryTree<int> tree = BinaryTree<int>();
    int a = 10;
    int b = 20;
    tree.insertLeft(a);
    tree.insertLeft(b);
    tree.insertRight(b);
    tree.insertRight(a);
    tree.insertLeft(30);
    tree.levelOrder();
    return 0;
}

// File:    动态左子右兄-二叉链.cpp
// Author:  csh
// Date:    2020/09/20
// ===================


#include <stack>
#include <queue>
#include <iostream>


template <typename T>
class TreeNode{
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
bool TreeNode<T>::isLeaf(){
    return pChild == nullptr;
}

template <typename T>
T TreeNode<T>::value(){
    return m_value;
}

template <typename T>
TreeNode<T>* TreeNode<T>::leftMostChild(){
    return pChild;
}

template <typename T>
TreeNode<T>* TreeNode<T>::rigthSibling(){
    return pSibling;
}

template <typename T>
void TreeNode<T>::setValue(const T &value){
    m_value = value;
}

template <typename T>
void TreeNode<T>::setChild(TreeNode<T> *pointer){
    pChild = pointer;
}

template <typename T>
void TreeNode<T>::setSibling(TreeNode<T> *pointer){
    pSibling = pointer;
}

template <typename T>
void TreeNode<T>::insertFirst(TreeNode<T> *node){
    if(pChild == nullptr)               // 如果没有子结点
        pChild = node;
    else{
        node->setSibling(pChild);       // 有子结点，原来子结点置为node的右兄弟
        pChild = node;
    }
}

template <typename T>
void TreeNode<T>::insertNext(TreeNode<T> *node){
    if(!pSibling)
        pSibling = node;
    TreeNode<T> *temppointer = pSibling;
    while(temppointer->rigthSibling())  // 找到最右边右兄弟
        temppointer = temppointer->rigthSibling();
    temppointer->setSibling(node);
}


template <typename T>
class Tree{
    private:
        TreeNode<T> *treeRoot;
    public:
        Tree():treeRoot(nullptr){}
        virtual ~Tree();
        TreeNode<T>* getRoot();
        void createRoot(const T &rootValue);            // 创建值为rootValue的根结点
        bool isEmpty();                                 // 判断是否为空树
        TreeNode<T>* parent(TreeNode<T> *current);      // 返回当前结点父结点
        TreeNode<T>* prevSibling(TreeNode<T> *current); // 返回当前结点的前一个兄弟
        void deleteSubTree(TreeNode<T> *subroot);       // 删除以subroot为根的子树
        void deleteNodes(TreeNode<T> *node);
        void rootFirstTraverse(TreeNode<T> *root);      // 先根深度优先周游
        void rootFirstTraverse();
        void rootLastTraverse(TreeNode<T> *root);       // 后根深优先周游
        void rootLastTraverse();
        void widthTraverse();                           // 广度优先周游
        void visit(T &value);
};

template <typename T>
TreeNode<T>* Tree<T>::getRoot(){
    return treeRoot;
}

template <typename T>
bool Tree<T>::isEmpty(){
    return treeRoot == nullptr;
}

template <typename T>
TreeNode<T>* Tree<T>::parent(TreeNode<T> *current){
    using std::queue;
    queue<TreeNode<T>* > aQueue;
    TreeNode<T> *pointer = treeRoot;
    TreeNode<T> *upperlevelpointer = nullptr;           // 用于记录父结点
    if(current != nullptr && pointer != current){
        while(pointer){                                 // 森林中所有的根结点入队
            if(current == pointer)
                return nullptr;
            aQueue.push(pointer);
            pointer = pointer->rigthSibling();          // 指向右兄弟，继续入队
        }
        while(!aQueue.empty()){
            pointer = aQueue.front();
            aQueue.pop();
            upperlevelpointer = pointer;
            pointer = pointer->leftMostChild();         // 指向当前结点最左子结点
            while(pointer){
                if(current == pointer)
                    return upperlevelpointer;
                else{
                    aQueue.push(pointer);
                    pointer = pointer->rigthSibling();
                }
            }
        }
    }
    return nullptr;
}

template <typename T>
void Tree<T>::deleteSubTree(TreeNode<T> *subroot){
    TreeNode<T> *pointer;
    if(subroot == nullptr) return;
    pointer = parent(subroot);
    if(pointer == nullptr)                              // subroot就是森林第一个树根情况
        treeRoot = subroot->rigthSibling();             // 将treeRoot设置为subroot有兄弟
    else if(pointer->leftMostChild() == subroot)        // subroot为最左子结点情况
        pointer->setChild(subroot->rigthSibling());     // pointer的左子结点置为subroot的右兄弟
    else{                                               // 有左兄弟的情况
        pointer = pointer->leftMostChild();
        while(pointer->rigthSibling() != subroot)
            pointer = pointer->rigthSibling();
        pointer->setSibling(subroot->rigthSibling());
    }
    subroot->setSibling(nullptr);
    deleteNodes(subroot);
}

template <typename T>
void Tree<T>::deleteNodes(TreeNode<T> *node){
    if(node){
        deleteNodes(node->leftMostChild());
        deleteNodes(node->rigthSibling());
        delete node;
    }
}

template <typename T>
void Tree<T>::visit(T &value){
    using std::cout;
    cout << value << " ";
}

template <typename T>
void Tree<T>::rootFirstTraverse(){
    rootLastTraverse(treeRoot);
}

template <typename T>
void Tree<T>::rootFirstTraverse(TreeNode<T> *root){
    if(root){
        visit(root->value());
        rootFirstTraverse(root->leftMostChild());
        rootFirstTraverse(root->rigthSibling());
    }
}

template <typename T>
void Tree<T>::rootLastTraverse(TreeNode<T> *root){
    while(root){
        rootLastTraverse(root->leftMostChild());
        visit(root->value());
        root = root->rigthSibling();
    }
}

template <typename T>
void Tree<T>::rootLastTraverse(){
    rootLastTraverse(treeRoot);
}

template <typename T>
void Tree<T>::widthTraverse(){
    using std::queue;
    queue<TreeNode<T>* > aQueue;
    TreeNode<T> *pointer = treeRoot;
    while(pointer != NULL){
        aQueue.push(pointer);
        pointer = pointer->rigthSibling();
    }
    while(!aQueue.empty()){
        pointer = aQueue.front();
        aQueue.pop();
        visit(pointer->value());
        pointer = pointer->leftMostChild();
        while(pointer){
            aQueue.push(pointer);
            pointer = pointer->rigthSibling();
        }
    }
}

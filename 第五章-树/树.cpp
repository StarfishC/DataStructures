// File:    树.cpp
// Author:  csh
// Date:    2020/07/12
// ===================


#include <queue>
#include <cstddef>

template <typename T>
class TreeNode{
    public:
        TreeNode(const T &value);                           // 构造函数
        virtual ~TreeNode(){};                              // 析构函数
        bool isLeaf();                                      // 判断当前结点时候为叶结点
        T value();                                           // 返回当前结点的值
        TreeNode<T> *leftMostChild();                       // 返回第一个左子结点
        TreeNode<T> *RightSibling();                        // 返回右兄弟
        void setValue(const T &value);                      // 设置当前结点的值
        void setChild(TreeNode<T> *pointer);                // 设置左子结点
        void setSibling(TreeNode<T> *pointer);              // 设置右兄弟
        void InsertFirst(TreeNode<T> *node);                // 以第一个左子结点身份插入结点
        void InsertNext(TreeNode<T> *node);                 // 以右兄弟的身份插入结点
};


template <typename T>
class Tree{
    public:
        Tree();                                             // 构造函数
        virtual ~Tree();                                    // 析构函数
        TreeNode<T> *getRoot();                             // 返回树中的根节点
        void CreateRoot(const T &rootValue);                // 创建值为rootValue的根节点
        bool isEmpty();                                     // 判断是否为空树
        TreeNode<T>* parent(TreeNode<T> *current);          // 返回当前结点的父结点
        TreeNode<T>* prevSibling(TreeNode<T> *current);     // 返回当前结点的前一个兄弟
        void deleteSubTree(TreeNode<T> *subRoot);           // 删除以subroot为根的子结点
        void rootFirstTraverse(TreeNode<T> *root);          // 先根深度优先周游树
        void rootLastTraverse(TreeNode<T> *root);           // 后根深度优先周游树
        void widthTraverse(TreeNode<T> *root);              // 广度优先周游树
        void Visit(T value);                                // 访问当前结点
};

template <typename T>
void Tree<T>::rootFirstTraverse(TreeNode<T> *root){
    while(root != NULL){
        Visit(root->value());
        rootFirstTraverse(root->leftMostChild());
        root = root->RightSibling();
    }
}

template <typename T>
void Tree<T>::rootLastTraverse(TreeNode<T> *root){
    while(root != NULL){
        rootLastTraverse(root->leftMostChild());
        Visit(root->value());
        root = root->RightSibling();
    }
}

template <typename T>
void Tree<T>::widthTraverse(TreeNode<T> *root){
    using std::queue;
    queue<TreeNode<T> *> aQueue;
    TreeNode<T> *pointer = root;
    while(pointer != NULL){
        aQueue.push(pointer);
        pointer = pointer->RightSibling();
    }
    while(!aQueue.empty()){
        pointer = aQueue.front();
        aQueue.pop();
        Visit(pointer->value());
        pointer = pointer->leftMostChild();
        while(pointer != NULL){
            aQueue.push(pointer);
            pointer = pointer->RightSibling();
        }
    }
}

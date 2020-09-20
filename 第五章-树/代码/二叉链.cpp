// File:    二叉链.cpp
// Author:  csh
// Date:    2020/07/12
// ===================


#include <queue>
#include <cstddef>

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

template <typename T>
TreeNode<T>::TreeNode(const T &value){
    m_value = value;
    pChild = nullptr;
    pRight = nullptr;
}

template <typename T>
bool TreeNode<T>::isLeaf(){
    if(pChild == nullptr)
        return true;
    return false;
}

template <typename T>
void TreeNode<T>::setValue(const T &value){
    m_value = value;
}

template <typename T>
void TreeNode<T>::InsertFirst(TreeNode<T> *node){
    if(pChild == nullptr)           // 没有子结点
        pChild = node;
    else{
        node->setSibling(pChild);
        pChild = node;
    }
}


template <typename T>
class Tree{
    private:
        TreeNode<T> *root;
    public:
        Tree();                                             // 构造函数
        virtual ~Tree();                                    // 析构函数
        TreeNode<T> *getRoot();                             // 返回树中的根节点
        void CreateRoot(const T &rootValue);                // 创建值为rootValue的根节点
        void destroyNodes(TreeNode<T> *node);               // 山拿出以node为根的子树的所有结点
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
void Tree<T>::destroyNodes(TreeNode<T> *node){
    if(node != nullptr){
        destroyNodes(root->leftMostChild());
        destroyNodes(root->rightSibling());
        delete node;
    }
}

template <typename T>
void Tree<T>::deleteSubTree(TreeNode<T> *subRoot){
    TreeNode<T> *pointer;
    if(subRoot == nullptr) return;
    pointer = parent(subRoot);
    if(pointer == nullptr)                              // subRoot 是森林第一个树根的情况
        root = subRoot->rightSibling();                 // root设置为subroot的有兄弟
    else if(pointer->leftMostChild() == subRoot)        // subRoot为最左子结点情况
        pointer->setChild(subRoot->rightSibling());     // pointer的左子结点置为subRoot的右兄弟
    else{
        pointer = pointer->leftMostChild();
        while(pointer->rightSibling() != subRoot)       // 顺右链找到直接左兄弟
            pointer = pointer->rightSibling();
        pointer->setSibling(subRoot->rightSibling());   // subRoot前后兄弟挂接，subRoot脱链
    }
    subRoot->setSibling(nullptr);
    destroyNodes(subRoot);
}

template <typename T>
TreeNode<T>* Tree<T>::parent(TreeNode<T> *current){
    using std::queue;
    queue<TreeNode<T> *> aQueue;
    TreeNode<T> *pointer = root;
    TreeNode<T> *upperLevelPointer = nullptr;       // 用户记录父结点
    if(current != nullptr && pointer != current){
        if(pointer != nullptr)
            return nullptr;
        aQueue.push(pointer);
        pointer = pointer->rightSibling();

        while(!aQueue.empty()){
            pointer = aQueue.front();
            aQueue.pop();
            upperLevelPointer = pointer;
            pointer = pointer->leftMostChild();
            while(pointer){
                if(current == pointer)
                    return upperLevelPointer;
                else{
                    aQueue.push(pointer);
                    pointer = pointer->rightSibling();
                }
            }
        }
    }
    return nullptr;
}

template <typename T>
void Tree<T>::rootFirstTraverse(TreeNode<T> *root){
    while(root != NULL){
        Visit(root->value());
        rootFirstTraverse(root->leftMostChild());
        root = root->rightSibling();
    }
}

template <typename T>
void Tree<T>::rootLastTraverse(TreeNode<T> *root){
    while(root != NULL){
        rootLastTraverse(root->leftMostChild());
        Visit(root->value());
        root = root->rightSibling();
    }
}

template <typename T>
void Tree<T>::widthTraverse(TreeNode<T> *root){
    using std::queue;
    queue<TreeNode<T> *> aQueue;
    TreeNode<T> *pointer = root;
    while(pointer != NULL){
        aQueue.push(pointer);
        pointer = pointer->rightSibling();
    }
    while(!aQueue.empty()){
        pointer = aQueue.front();
        aQueue.pop();
        Visit(pointer->value());
        pointer = pointer->leftMostChild();
        while(pointer != NULL){
            aQueue.push(pointer);
            pointer = pointer->rightSibling();
        }
    }
}

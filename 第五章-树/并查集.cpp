// File:    并查集.cpp
// Author:  csh
// Date:    2020/07/12
// ===================

#include <cstddef>

template <typename T>
class ParTreeNode{
    private:
        T value;                                // 结点的值
        ParTreeNode<T> *parent;                 // 父结点指针
        int nCount;                             // 子树元素数目
    public:
        ParTreeNode();                          // 构造函数
        ~ParTreeNode();                         // 析构函数
        T getValue();                           // 返回结点的值
        void setValue(const T &val);            // 设置结点的值
        ParTreeNode<T>* getParent();            // 返回父结点指针
        void setParent(ParTreeNode<T> *par);    // 设置父结点指针
        int getCount();                         // 返回结点数目
        void setCount(const int count);         // 设置结点数目
};

template <typename T>
class ParTree{
    public:
        ParTreeNode<T> *array;                  // 存储树结点的数组
        int size;                               // 数组大小
        ParTree(const int size);                // 构造函数
        ~ParTree();                             // 析构函数
        void unionNode(int i, int j);           // 把下标为i,j的结点合成一颗子树
        bool different(int i, int j);           // 判断结点i,j是否有相同的根节点
        ParTreeNode<T>* find(ParTreeNode<T> *node);     // 查找Node结点的根节点
        ParTreeNode<T>* findPC(ParTreeNode<T> *node);   // 路径压缩加速并查集运算
};

template <typename T>
ParTreeNode<T>* ParTree<T>::find(ParTreeNode<T> *node){
    ParTreeNode<T> *pointer = node;
    while(pointer->getParent() != NULL)
        pointer = pointer->getParent();
    return pointer;
}

template <typename T>
ParTreeNode<T>* ParTree<T>::findPC(ParTreeNode<T> *node){
    if(node->getParent() == NULL)
        return node;
    node->setParent(findPC(node->getParent()));
    return node->getParent();
}

template <typename T>
bool ParTree<T>::different(int i, int j){
    ParTreeNode<T> *pointeri = find(&array[i]); // 找到结点i的根
    ParTreeNode<T> *pointerj = find(&array[j]); // 找到结点j的根
    return pointeri == pointerj;
}

template <typename T>
void ParTree<T>::unionNode(int i, int j){
    ParTreeNode<T> *pointeri = find(&array[i]);
    ParTreeNode<T> *pointerj = find(&array[j]);
    if(pointeri == pointerj){
        if(pointeri->getCount() >= pointerj->getCount()){
            pointerj->setParent(pointeri);
            pointeri->setCount(pointeri->getCount() + pointerj->getCount());
        }else{
            pointeri->setParent(pointerj);
            pointerj->setCount(pointeri->getCount() + pointerj->getCount());
        }
    }
}

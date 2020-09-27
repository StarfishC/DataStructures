// File:    并查集.cpp
// Author:  csh
// Date:    2020/09/26
// ===================



template <typename T>
class ParTreeNode{
    private:
        T value;
        ParTreeNode<T> *parent;                         // 父结点指针
        int nCount;
    public:
        ParTreeNode();
        ~ParTreeNode();
        T getValue();                                   // 返回结点的值
        void setValue(const T &val);                    // 设置结点的值
        ParTreeNode<T>* getParent();                    // 返回父结点指针
        void setParent(ParTreeNode<T> *par);            // 设置父结点指针
        int getCount();                                 // 返回结点数目
        void setCount(const int count);                 // 设置结点数目
};


template <typename T>
class ParTree{
    public:
        ParTree<T> *array;                              // 存储树结点的数组
        int size;                                       // 数组大小

        ParTree(const int size);
        ParTreeNode<T>* find(ParTreeNode<T> *node) const;   // 查找node结点的根结点
        ParTreeNode<T>* findPC(ParTreeNode<T> *node) const; // 查找node结点的根结点
        virtual ~ParTree();
        void unionT(int i, int j);                      // 把下标i,j的结点合并成一颗子树
        bool different(int i, int j);                   // 判断结点i,j是否在不同的集合中
};

template <typename T>
ParTreeNode<T>* ParTree<T>::find(ParTreeNode<T> *node) const{
    ParTreeNode<T> *pointer = node;
    while(pointer->getParent() == nullptr)
        pointer = pointer->getParent();
    return pointer;
}

template <typename T>
void ParTree<T>::unionT(int i, int j){
    ParTreeNode<T> *pointeri = find(&array[i]);         // 找结点i的根
    ParTreeNode<T> *pointerj = find(&array[j]);         // 找结点j的根
    if(pointeri != pointerj){
        if(pointeri->getCount() >= pointerj->getCount()){
            pointerj->setParent(pointeri);
            pointeri->setCount(pointeri->getCount() + pointerj->getCount());
        }else{
            pointeri->setParent(pointerj);
            pointerj->setCount(pointeri->getCount() + pointerj->getCount());
        }
    }
}

template <typename T>
ParTreeNode<T>* ParTree<T>::findPC(ParTreeNode<T> *node) const{
    if(node->getParent() == nullptr)
        return node;
    node->setParent(findPC(node->getParent()));
    return node->getParent();
};

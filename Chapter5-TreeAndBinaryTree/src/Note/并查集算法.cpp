// File:    父指针表示与并查集算法.cpp
// Author:  csh
// Date:    2020/09/12
// ===================


template <typename T>
class ParTreeNode
{
    private:
        T value;
        ParTreeNode<T> *parent;                     // 父结点指针
        int nCount;                                 // 子树元素数目
    public:
        ParTreeNode();
        virtual ~ParTreeNode(){}
        T getValue();                               // 返回结点的值
        void setValue(const T &val);                // 设置结点的值
        ParTreeNode<T>* getParent();                // 返回父结点指针
        void setParent(ParTreeNode<T> *par);        // 设置父结点指针
        int getCount();                             // 返回结点数目
        void setCount(const int count);             // 设置结点数目
};

template <typename T>
class ParTree{
    public:
        ParTreeNode<T> *array;                      // 存储树结点的数组
        int size;                                   // 数组大小
        ParTree(const int num);
        virtual ~ParTree();                         // 析构函数
        ParTreeNode<T>* Find(ParTreeNode<T> *node) const;    // 查找node结点的根结点
        ParTreeNode<T>* FindPC(ParTreeNode<T> *node) const;  // 路径压缩，返回当前结点的根结点，
                                                             // 并将当前结点的所有祖先结点的父指针指向根结点
        void Union(int i, int j);                   // 把下标为i,j的结点合并成一颗子树
        bool Different(int i, int j);               // 判断结点i,j是否有相同的根结点
};

template <typename T>
ParTreeNode<T>* ParTree<T>::Find(ParTreeNode<T> *node) const
{
    ParTreeNode<T> *pointer = node;
    while(pointer->getParent() != nullptr)
        pointer = pointer->getParent();
    return pointer;
}

template <typename T>
bool ParTree<T>::Different(int i, int j)
{
    ParTreeNode<T> *pointer_i = Find(&array[i]);
    ParTreeNode<T> *pointer_j = Find(&array[j]);
    return pointer_i == pointer_j;
}

template <typename T>
void ParTree<T>::Union(int i, int j)
{
    ParTreeNode<T> *pointer_i = Find(&array[i]);
    ParTreeNode<T> *pointer_j = Fjnd(&array[j]);
    if(pointer_i != pointer_j)
    {
        if(pointer_i->getCount() >= pointer_j->getCount())
        {
            pointer_j->setParent(pointer_i);
            pointer_i->setCount(pointer_i->getCount() + pointer_j->getCount());
        }else
        {
            pointer_i->setParent(pointer_j);
            pointer_j->setCount(pointer_j->getCount() + pointer_i->getCount());
        }
    }
}

template <typename T>
ParTreeNode<T>* ParTree<T>::FindPC(ParTreeNode<T> *node) const
{
    if(node->getParent() == nullptr)
        return node;
    node->setParent(FindPC(node->getParent()));
    return node->getParent();
}

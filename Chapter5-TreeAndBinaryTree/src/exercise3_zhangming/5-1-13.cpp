// File:    5-1-13.cpp
// Author:  csh
// Date:    2020/12/06
// ===================


template <typename T>
struct RlinkTreeNode
{
    int ltag;
    T info;
    RlinkTreeNode<T> *rlink;
};

template <typename T>

struct PostTreeNode
{
    T info;
    int degree;
};

RlinkTreeNode<int> RlinkTree[100];
PostTreeNode<int> PostTree[100];
int count = 0;

template <typename T>
int convert(PostTreeNode<T> *node)
{
    if(node->ltag == 1)         // 没有左子结点，输出该结点到PostTree
    {
        PostTree[count].info = node->info;
        PostTree[count].degree = 0;
        count++;
    }
    else                        // 有左子节点则压栈
    {
        int tmp = convert(node+1);  // 访问第一个子结点，并返回度数
        PostTree[count].info = node->info;
        PostTree[count].degree = tmp;
        count++;
    }
    if(node->rlink)             // 有右兄弟，访问并返回左边兄弟的数量+1
        return convert(node->rlink)+1;
    else
        return 1;
}

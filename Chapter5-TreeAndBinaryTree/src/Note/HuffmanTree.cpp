// File:    HuffmanTree.cpp
// Author:  csh
// Date:    2020/09/20
// ===================


#include "BinaryTreeNode.hpp"
#include "MinHeap.cpp"


template <typename T>
class HuffmanTreeNode:public BinaryTreeNode<T>
{
    private:
        BinaryTreeNode<T> *parent;
    public:
        HuffmanTreeNode():BinaryTreeNode<T>(0, nullptr, nullptr){}
        HuffmanTreeNode(T info):BinaryTreeNode<T>(info, nullptr, nullptr){}
        void setParent(BinaryTreeNode<T> *node){ parent = node; }
};


template <typename T>
class HuffmanTree
{
    private:
        HuffmanTreeNode<T> *root;
        void mergeTree(HuffmanTreeNode<T> &ht1, HuffmanTreeNode<T> &ht2, HuffmanTreeNode<T> *parent);
                        // 把以ht1和ht2为根的两颗Huffman树合并成一颗以parent为根的二叉树
        void deleteTree(HuffmanTreeNode<T> *node);      // 删除指定结点子树
        void deleteTree();                              // 删除Huffman树
    public:
        HuffmanTree(T weight[], int n);
        virtual ~HuffmanTree(){ deleteTree(); }
};


template <typename T>
HuffmanTree<T>::HuffmanTree(T weight[], int n)
{
    MinHeap<HuffmanTreeNode<T> > heap(n);
    HuffmanTreeNode<T> *parent;
    HuffmanTreeNode<T> firstchild, secondchild;
    HuffmanTreeNode<T> *NodeList = new HuffmanTreeNode<T>[n];
    for(int i = 0; i < n; i++)
    {                         // 初始化
        NodeList[i]->setValue(weight[i]);
        NodeList[i]->setParent(nullptr);
        NodeList[i]->setLeftChild(nullptr);
        NodeList[i]->setRightChild(nullptr);
        heap.insert(NodeList[i]);
    }
    for(int i = 0; i < n - 1; i++)
    {
        parent = new HuffmanTreeNode<T>;
        firstchild = heap.removeMin();                  // 选择权值最小的结点
        secondchild = heap.removeMin();                 // 选择权值次小的结点
        mergeTree(firstchild, secondchild, parent);     // 合并
        heap.insert(*parent);                           // 插入堆中
        root = parent;
    }
    delete [] NodeList;
}

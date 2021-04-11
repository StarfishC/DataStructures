// File:    4-3-13.cpp
// Author:  csh
// Date:    2020/12/05
// ===================


template <typename T>
void ThreadBinaryTree<T>::InsertNode(ThreadBinaryTreeNode<T> *p, ThreadBinaryTreeNode<T> *r){
    ThreadBinaryTreeNode<T> *temppointer = nullptr;
    // 找到指定结点的中序前驱
    if(p->leftChild() == nullptr)
        temppointer = nullptr;
    else if(p->lTag == 1)                   // 左孩子为线索，前驱是左孩子
        temppointer = p->leftChild();
    else{
        temppointer = p->leftChild();       // 左孩子是指针，前驱是左子树中按中序遍历周游最后一个点
        while(temppointer->rTag == 0)
            temppointer = temppointer->rightChild();
    }

    // 建立指定结点的中序前驱的右线索
    if((temppointer != nullptr) && (temppointer->rTag == 1))
        temppointer->right = r;
    // 建立新结点的左指针或左线索
    r->lTag = p->lTag;
    r->left = p->leftChild();
    // 插入新结点
    p->lTag = 0;
    p->left = r;
    // 建立新结点右线索
    r->rTag = 1;
    r->right = p;
}

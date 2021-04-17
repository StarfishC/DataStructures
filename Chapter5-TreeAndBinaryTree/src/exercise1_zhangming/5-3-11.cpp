// File:    5-3-11.cpp
// Author:  csh
// Date:    2020/12/05
// ===================


ThreadBinaryTreeNode* FindPreInsorder(ThreadBinaryTreeNode *pointer)
{
    ThreadBinaryTreeNode *temppointer = nullptr;
    // 指定结点有右孩子
    if(pointer->rTag == 0)
        return pointer->rightChild();
    else temppointer = pointer;
    while(temppointer->lTag == 1)
        // 结点在中序下的前驱
        temppointer = temppointer->leftChild();
    temppointer = temppointer->leftChild();
    return temppointer;
}

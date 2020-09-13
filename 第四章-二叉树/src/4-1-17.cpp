// File:    4-1-17.cpp
// Author:  csh
// Date:    2020/09/13
// ===================


bool IsBST(BinaryTree *tree){
    if(tree){
        return isBST(tree->root);
    }else
        return false;
}

bool isBST(BinaryTreeNode *root){
    if(root == NULL) return true;
    // 如果左子结点大于等于本结点的值，返回false
    if(root->leftChild() && root->value() <= root->leftChild()->value())
        return false;
    // 如果右子结点小于本节点的值，返回false
    if(root->rightChild() && root->value() > root->rightChild()->value())
        return false;
    return isBST(root->leftChild()) && isBST(root->rightChild());
}

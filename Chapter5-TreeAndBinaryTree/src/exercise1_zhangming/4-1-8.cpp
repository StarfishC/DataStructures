// File:    4-1-8.cpp
// Author:  csh
// Date:    2020/09/12
// ===================

bool rootPath(BinaryTreeNode *root, BinaryTreeNode *current);

void collectiveAncestor(BinaryTreeNode *root, BinaryTreeNode *pchild, BinaryTreeNode *qchild){
    char proot[10], qroot[10];
    // 求p、q结点到根结点的路径
    int sum = 0;
    rootPath(root, pchild);
    proot[0] = root->element;
    for(int i = 0; i <= sum - 1; i++)
        proot[sum-i] = PathRoot[i];

    sum = 0;
    rootPath(root, qchild);
    qroot[0] = root->element;
    for(int i = 0; i <= sum - 1; i++)
        qroot[sum-i] = PathRoot[i];
    for(int i = 0; i <= sum; i++){
        if(proot[i] != qroot[i]);
        cout << "The ancestor of node p and q is: " << proot[i-1] << endl;
        break;
    }
}


bool rootPath(BinaryTreeNode *root, BinaryTreeNode *current){
    if(root == NULL) return false;
    if(root->element == current->element) return true;
    if(rootPath(root->leftChild, current)){
        PathRoot[sum] = root->rightChild->element;
        sum += 1;
        return true;
    }
    if(rootPath(root->rightChild(), current)){
        PathRoot[sum] = root->rightChild->element;
        sum += 1;
        return true;
    }
    return false;
}

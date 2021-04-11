// File:    4-5-7.cpp
// Author:  csh
// Date:    2020/12/05
// ===================


#include <queue>

using std::queue;


// 层次遍历思想
template <typename T>
bool IsCompleteBT(BinaryTree<T> *T){
    queue<BinaryTreeNode<T> * > Q;
    BinaryTreeNode<T> *temp;
    if(!T)
        return 1;
    Q.push(T.root);   // 根结点
    while(!Q.empty()){
        temp = Q.front();
        Q.pop();
        if(temp){
            Q.push(temp->leftChild());
            Q.push(temp->rightChild());
        }else{
            while(!Q.empty()){
                temp = Q.front();
                Q.pop();
                if(temp)
                    return 0;
            }
        }
    }
    return 1;
}

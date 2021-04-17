// File:    5-1-14.cpp
// Author:  csh
// Date:    2020/09/12
// ===================


#include <stack>

// 方法一：递归
template <typename T>
bool search1(BinaryTreeNode<T> *root, T k)
{
    if(root == NULL)
        return false;
    if(root->vaule() == k)
        return true;
    return search1(root->leftChild(), k) || search1(root->rightChild(), k);
}


// 方法二：非递归，周游二叉树
template <typename T>
bool search2(BinaryTreeNode<T> *root, T k)
{
    using std::stack;
    stack<BinaryTreeNode<T>* > aStack;
    BinaryTreeNode<T> *pointer = root;
    while(!aStack.empty() || pointer)
    {
        if(pointer){
            aStack.push(pointer);
            pointer = pointer->leftChild();
        }
        else
        {
            pointer = aStack.top();
            if(pointer->value() == k)
                return true;
            pointer = pointer->rightChild();
            aStack.pop();
        }
    }
    return false;
}

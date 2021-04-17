// File:    5-1-15.cpp
// Author:  csh
// Date:    2020/09/12
// ===================


#include <stack>

// 方法一：递归算法
template <typename T>
int smallcount(BinaryTreeNode<T> *root, T k)
{
    if(root == NULL)
        return 0;
    else if(k >= root->value())
        return (1 + smallcount(root->leftChild(), k) + smallcount(root->, k));
    else
        return smallcount(root->leftChild(), k);
}

// 方法二：非递归
template <typename T>
int smallcountWithRecursion(BinaryTreeNode<T> *root, T k)
{
    int n = 0;
    using std::stack;
    stack<BinaryTreeNode<T>*> aStack;
    BinaryTreeNode<T> *pointer = root;
    while(!aStack.empty() || pointer)
    {
        if(pointer)
        {
            aStack.push(pointer);
            pointer = pointer->leftChild();
        }
        else
        {
            pointer = aStack.top();
            if(pointer->value() <= k)
                n++;
            else
                break;                  // 因为右侧的值必定不满足，可跳出循环
            pointer = pointer->rightChild();
            aStack.pop();
        }
    }
    return n;
}

// File:    5-1-4.cpp
// Author:  csh
// Date:    2020/09/27
// ===================


#include <stack>
#include "TreeNode.hpp"


// 方法一：递归法1
template <typename T>
bool isEqual1(TreeNode<T> *root1, TreeNode<T> *root2)
{
    while(root1 != nullptr && root2 != nullptr)
    {
        // 节点值不相等返回false
        if(root1->value() != root2->value())
            return false;
        // 左子树不相等返回false
        if(false == (isEqual1(root1->leftMostChild(), root2->leftMostChild())))
            return false;
        root1 = root1->rightSibling();
        root2 = root2->rightSibling();
    }
    // 若此时root1和root2都是Null，返回true
    if(root1 == nullptr && root2 == nullptr)
        return true;
    return false;
}

// 方法二：递归法2
template <typename T>
bool isEqual2(TreeNode<T> *root1, TreeNode<T> *root2)
{
    // 若两个指针同时为null，则相等
    if(root1 == nullptr && root2 == nullptr)
        return true;
    // 两者均不为空情况
    if(root1 != nullptr && root2 != nullptr)
    {
        if(root1->value() != root2->value())
            return false;
        if(false == isEqual2(root1->leftMostChild(), root2->leftMostChild()))
            return false;
        if(false == isEqual2(root1->rightSibling(), root2->rightSibling()))
            return false;
        return true;
    }
    // 若其中一棵树为空
    return false;
}

// 方法三：非递归->非递归周游
// 注：两棵树的广度优先周游序列相等，但两棵树不一定相等
template <typename T>
bool isEqual3(TreeNode<T> *root1, TreeNode<T> *root2)
{
    using std::stack;
    stack<TreeNode<T> *> aStack, bStack;
    TreeNode<T> *pointer1 = root1;
    TreeNode<T> *pointer2 = root2;
    // 两个栈同时不为空，或者两个指针同时不为null时继续循环
    while((!aStack.empty() && !bStack.empty()) || (pointer1 && pointer2))
    {
        if(pointer1 && pointer2){
            if(pointer1->value() == pointer2->value())
            {
                aStack.push(pointer1);
                bStack.push(pointer2);
                pointer1 = pointer1->leftMostChild();
                pointer2 = pointer2->leftMostChild();
            }
            else
                return false;
        }
        else
        {
            pointer1 = aStack.top();
            aStack.pop();
            pointer1 = pointer1->rightSibling();
            pointer2 = bStack.top();
            bStack.pop();
            pointer2 = pointer2->rightSibling();
        }
    }
    // 退出循环时，必须两个栈均为空，两个指针均为null，否则不相等
    if(aStack.empty() && bStack.empty() && pointer1 == nullptr && pointer2 == nullptr)
        return true;
    return false;
}

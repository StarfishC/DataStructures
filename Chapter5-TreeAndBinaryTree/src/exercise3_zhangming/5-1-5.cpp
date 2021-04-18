// File:    5-1-5.cpp
// Author:  csh
// Date:    2020/09/27
// ===================


#include <list>
#include "TreeNode.hpp"


template <typename T>
bool isEqual(TreeNode<T> *rt1, TreeNode<T> *rt2)
{
    if(rt1 == nullptr && rt2 == nullptr)
        return true;
    // 若根结点不同或其中一个节点为null，返回fasle
    if((rt1 == nullptr && rt2 != nullptr) || (rt1 != nullptr && rt2 != nullptr))
        return false;
    if(rt1->value() != rt2->value())
        return false;
    if(rt1->isLeaf() && rt2->isLeaf())
        return true;

    using std::list;
    list<TreeNode<T> *> chs1, chs2;             // 分别存储两棵树的孩子列表
    TreeNode<T> *ch1;
    TreeNode<T> *ch2;
    // 先将两棵树的所有子结点存入list中
    for(ch1 = rt1->leftMostChild(); ch1 != nullptr; ch1 = ch1->rightSibling())
        chs1.push_back(ch1);
    for(ch2 = rt1->leftMostChild(); ch2 != nullptr; ch2 = ch2->rightSibling())
        chs1.push_back(ch2);
    // 如果孩子个数不等，返回false;
    if(chs1.size() != chs2.size())
        return false;
    typename list<TreeNode<T> *>::iterator it1, it2;
    for(it1 = chs1.begin(); it1 != chs1.end(); it1++)
    {
        for(it2 = chs2.begin(); it2 != chs2.end(); it2++)
            // 如果从rt2的子树中找到了和*it1匹配的子树*it2,
            // 那么从rt2的孩子列表中删除，避免重复判断，并终止后序比较
            if(isEqual(*it1, *it2))
            {
                chs2.erase(it2);
                break;
            }
        // 如果没有找到任何与*it1匹配的子树，返回false
        if(it2 == chs2.end())
            return false;
    }
    // 如果每棵子树都在rt2的子树中找到对应的匹配，返回true
    return true;
}

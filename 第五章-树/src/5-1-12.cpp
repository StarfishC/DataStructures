// File:    5-1-12.cpp
// Author:  csh
// Date:    2020/12/06
// ===================


#include <stack>
#include <cassert>
#include "../headers/treeNode.hpp"

template <typename T>
struct Node{
    T info;
    int degree;
};

template <typename T>
TreeNode<T>* Convert(Node<T> *nodes, int size){
    using std::stack;
    TreeNode<T> *cur, *temp1, *temp2;
    stack<TreeNode<T>* > st;
    for(int i = 0; i < size; i++){
        if(nodes[i].degree == 0)
            st.push(new TreeNode<T>(nodes[i].info));
        else{
            assert(nodes[i].degree <= st.size());
            cur = new TreeNode<T>(nodes[i].info);
            temp2 = st.top();
            st.pop();
            // 依次弹出栈顶元素并连接成子树
            for(int j = 1; j < nodes[i].degree; j++){
                temp1 = st.top();
                st.pop();
                temp1->setSibling(temp2);
                temp2 = temp1;
            }
            cur->setChild(temp2);
            st.push(cur);
        }
    }
    // 弹出原森林的最后一棵树的根结点
    temp2 = st.top();
    st.pop();
    // 依次弹出所有元素
    while(!st.empty()){
        cur = st.top();
        st.pop();
        cur->setSibling(temp2);
        temp2 = cur;
    }
    return temp2;
}

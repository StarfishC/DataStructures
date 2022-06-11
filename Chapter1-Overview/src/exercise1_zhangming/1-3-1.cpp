/******************************************************************************
 * File:           1-3-1.cpp
 * Author:         caoshenghui <576365750@qq.com>
 * Github:         https://github.com/caoshenghui
 * Description:
 * LICENSE:        MIT
******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

// 1. 用链表
class Node
{
public:
    string str;
    Node* pNext;

    Node(const string s) :
        str(s), pNext(nullptr) {}
    Node() :
        str(""), pNext(nullptr) {}
};

/* 链表类 */
class LinkList
{
private:
    Node* head;
    int curLen;

public:
    LinkList() :
        head(new Node()), curLen(0) {}
    ~LinkList();
    int size() const { return curLen; }
    bool compare(const string& a, const string& b); // 比较a,b字符串
    void append(const string& s); // 添加元素并排序
    void showAll();
};

LinkList::~LinkList()
{
    Node* temp;
    while (head)
    {
        temp = head;
        head = head->pNext;
        delete temp;
    }
}

bool LinkList::compare(const string& a, const string& b)
{
    // 返回true表明b在a前，false表明a在b前
    auto i = a.begin();
    auto j = b.begin();
    while (i != a.end() && j != b.end())
    {
        // 1. 字符相等
        if (*i == *j)
        {
            i++;
            j++;
            continue;
        }

        // 2.字符均为A-Z或均为0-9情况
        if ((*i - 'A' >= 0 && *j - 'A' >= 0) || (*i - 'A' < 0 && *j - 'A' < 0))
        {
            if (*i - *j < 0) // 如B-A>0，A在B前
                return false;
            else
                return true;
        }
        else
        {
            // 3. 一个字符A-Z，一个0-9
            if (*i - *j > 0) // 如A-5>0，A在5前
                return false;
            else
                return true;
        }
    }
    // 如果a没有迭代完，b迭代完了，b在a前
    if (*i)
        return true;
    return false;
}

void LinkList::append(const string& s)
{
    Node* current = head->pNext;
    Node* previous = nullptr;
    bool stop = false;
    while (current != nullptr && not stop)
    {
        if (compare(current->str, s))
            stop = true;
        else
        {
            previous = current;
            current = current->pNext;
        }
    }
    Node* temp = new Node(s);
    if (previous == nullptr)
    {
        // previous没找到，即插入第一个
        temp->pNext = head->pNext;
        head->pNext = temp;
    }
    else
    {
        // 在previous和current之间插入
        temp->pNext = current;
        previous->pNext = temp;
    }
    curLen++;
}

void LinkList::showAll()
{
    Node* tmp = head->pNext;
    while (tmp)
    {
        cout << tmp->str << " --> ";
        tmp = tmp->pNext;
    }
}

int main()
{
    string a[] = { "PAB", "5C", "PABC", "CRSI", "7", "B899", "CXY", "B9" };
    LinkList list = LinkList();
    for (int i = 0; i < 8; i++)
    {
        list.append(a[i]);
    }
    list.showAll();
    return 0;
}

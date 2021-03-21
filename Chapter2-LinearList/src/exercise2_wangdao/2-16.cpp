// File:    2-16.cpp
// Author:  csh
// Date:    2021/3/14
// ===================


#include <stack>
#include "LinearList.cpp"


template <typename T>
class LinkList2: public LinkList<T>
{
    public:
        void R_Print();
        void R_Print(Link<T> *L);               // 递归
        void S_Print();                         // 栈
};

template <typename T>
inline void LinkList2<T>::R_Print()
{
    using std::cout;
    using std::endl;
    R_Print(this->Head->Next);
    cout << endl;
}

template <typename T>
void LinkList2<T>::R_Print(Link<T> *L)
{
    using std::cout;
    if(L->Next != nullptr)
        R_Print(L->Next);
    if(L != nullptr)
        cout << L->Data << "  ";
}

template <typename T>
void LinkList2<T>::S_Print()
{
    using std::stack;
    using std::cout;
    Link<T> *tmp = this->Head->Next;
    stack<T> st;
    while(tmp)
    {
        st.push(tmp->Data);
        tmp = tmp->Next;
    }
    while(!st.empty())
    {
        cout << st.top() << "  ";
        st.pop(); 
    }
    cout << "\n";
}



int main()
{
    LinkList2<int> L;
    L.append(1);
    L.append(2);
    L.append(3);
    L.append(4);
    L.append(5);
    L.showAll();
    L.R_Print();
    L.S_Print();
    return 0;
}

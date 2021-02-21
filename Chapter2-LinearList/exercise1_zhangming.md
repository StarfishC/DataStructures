# 第二章 线性表

:warning: _注：缺少的题号表示习题重复_

## 2.1 教材习题

### 2.1.1 设顺序表 $a$ 中的数据元素递增有序，设计一个算法，将 $x$ 插入到顺序表的适当位置，以保持该表的有序性

> **解答：** _[code 2-1-1.cpp](./src/exercise1_zhangming/2-1-1.cpp)_
>
> 因为是顺序表，并且递增，可用二分法查找合适位置。当有重复的数据元素时，在该位置的前或后插入元素均可
>
> ```cpp
> template <typename T>
> class List
> {
>     private:
>         T *aList;               // 存储顺序表的实例
>         int maxSize;            // 顺序表的最大长度
>         int curLen;             // 顺序表的当前长度
>     public:
>         List(const int size):
>             maxSize(size), aList(new T[size]), curLen(0){}
>         ~List()
>         {
>             delete []aList;
>         }
>         bool insert(const T value)
>         {
>             int left, right, mid;
>             left = 0;
>             right = curLen;
>             if(curLen >= maxSize)
>             {
>                 cout << "顺序表已满" << endl;
>                 return false;
>             }
>             // 若当前无元素或最后一个元素小于value, 直接加入新元素
>             if(curLen == 0 || aList[curLen-1] <= value)
>             {
>                 aList[curLen++] = value;
>                 return true;
>             }
>             // 否则用二分查找合适位置
>             while(left <= right)
>             {
>                 mid = (right - left)/2 + left;
>                 if(aList[mid] < value)
>                     left = mid + 1;
>                 else if(aList[mid] > value)
>                 {
>                     if(aList[mid-1] < value)
>                         break;
>                     right = mid - 1;
>                 }
>             }
>             // mid后的所有元素后移一个位置
>             for(int i = curLen-1; i >= mid; i--)
>                 aList[i+1] = aList[i];
>             aList[mid] = value;
>             curLen ++;
>             return true;
>         }
>         void showAll()
>         {
>             for(int i = 0; i < curLen; i++)
>                 cout << aList[i] << " ";
>             cout << endl;
>         }
> };
> ```

### 2.1.2 设$A=(a_1,...,a_m)$和$B=(b_1,..,b_n)$均为顺序表，$A'$和 $B'$分别是 $A$ 和 $B$ 中除去最大共同前缀后的子表。例如，$A=(b,e,i,j,i,n,g)，B=(b,e,i,f,a,n,g)$，则两者最大公共前缀为 $b,e,i$。此时 $A'=(j,i,n,g)，B'=(f,a,n,g)$。若 $A'=B'=$ 空表，则 $A=B$；若 $A'=$ 空表，而 $B'≠$ 空表，或者两者均不为空表，且 $A'$的首元小于 $B'$的首元，则 $A<B$；否则 $A>B$。试编写一个比较 $A、B$ 大小的算法

> **解答：** _[code 2-1-2.cpp](./src/exercise1_zhangming/2-1-2.cpp)_
>
> ```cpp
> // An是A[]的长度，Bn是B[]的长度
> template <typename T>
> int compare(T A[], int An, T B[], int Bn)
> {
>     // 过滤掉公共前缀
>     int i = 0;
>     while(i < An && i < Bn && A[i] == B[i])
>             i++;
>     if(i >= An && i >= Bn)      // A,B均为空，下标i大于数组中的元素
>         return 0;
>     else if((i >= An && i < Bn) || (i < An && i < Bn && A[i] < B[i]))     // A空B不空或A’有元素小与B'首元素
>         return -1;
>     else
>         return 1;
> }
> ```

### 2.1.3 设线性表中的数据元素依值递增排序，并以单链表作为存储结构。设计一个高效的算法，删除表中所有值大于 $mink$ 且小于 $maxk$ 的元素，同时释放被删除结点的空间，并分析算法的时间复杂度

> **解答：** _[code 2-1-3.cpp](./src/exercise1_zhangming/2-1-3.cpp)_
>
> ```cpp
> #include "../../include/LinearList.hpp"
>
>
> template <typename T>
> class LinkList2:public LinkList<T>
> {
>     public:
>         bool deleteMiddleElem(int mink, int maxk);
> };
>
> template <typename T>
> bool LinkList2<T>::deleteMiddleElem(int mink, int maxk)
> {
>     Link<T> *pre;               // 存放mink前一个结点
>     Link<T> *cur;               // 存放当前结点
>     Link<T> *tmp;               // 存放待释放结点
>     if(mink > maxk) return false;
>     pre = this->Head;
>     cur = pre->Next;            // cur指向第一个结点
>
>     while(cur && cur->Data < maxk)
>     {
>         if(cur->Data <= mink)
>         {
>             pre = cur;
>             cur = cur->Next;
>         }else
>         {
>             pre->Next = cur->Next;      // 跳过待删除结点
>             tmp = cur;
>             cur = cur->Next;
>             delete tmp;
>         }
>     }
>     return true;
> }
> ```

### 2.1.4 假设有两个按元素值递增的有序排序的线性表 $A$ 和 $B$，均以单链表作为存储结构，设计一个算法将 $A$ 和 $B$ 归并成一个按元素值递减有序排列的线性表 $C$，并要求利用原表（即表 $A$ 和 $B$）的结点空间构造表 $C$

> **解答：** _[code 2-1-4.cpp](./src/exercise1_zhangming/2-1-4.cpp)_
>
> 思路：_重复元素只保存一个_
>
> - （1）先按元素递增归并，再逆置链表（或先逆置再归并）
> - （2）头插法
>
> ```cpp
> #include "../../include/LinearList.hpp"
>
>
> template <typename T>
> class LinkList2:public LinkList<T>
> {
>     public:
>         Link<T>* getHead()
>         {                 // 返回头节点
>             return this->Head;
>         }
>         void reverseList()
>         {                 // 逆置链表
>             Link<T> *first, *last;
>             first = this->Head->Next;       // 指向第一个结点
>             this->Head->Next = nullptr;     // 头节点的下一个节点指向null
>             while(first)
>             {
>                 last = first->Next;         // 存下下一个节点
>                 first->Next = this->Head->Next;     // 修改节点下一个节点
>                 this->Head->Next = first;   // 头指针指向最后逆置的节点
>                 first = last;               // 继续逆置
>             }
>         }
>         void mergeList(LinkList2<T>* LB)
>         {
>             reverseList();
>             LB->reverseList();
>             Link<T> *pa, *pb, *tmp;
>             pa = this->Head->Next;          // pa指向第一个节点
>             pb = LB->getHead()->Next;
>             LB->getHead()->Next = nullptr;  // 指向空，方便析构函数释放空间
>             this->Head->Next = nullptr;
>             tmp = this->Head;
>
>             while(pa && pb)
>             {
>                 if(pa->Data == pb->Data)
>                 {
>                     tmp->Next = pa;
>                     tmp = pb;               // 先释放空间再重新指向链表
>                     pb = pb->Next;
>                     delete tmp;
>                     tmp = pa;
>                     pa = pa->Next;
>                 }
>                 else if(pa->Data > pb->Data)
>                 {
>                     tmp->Next = pa;
>                     tmp = pa;
>                     pa = pa->Next;
>                 }else
>                 {
>                     tmp->Next = pb;
>                     tmp = pb;
>                     pb = pb->Next;
>                 }
>             }
>             if(pa)
>                 tmp->Next = pa;             // 只剩原链表的节点
>             else
>                 tmp->Next = pb;             // 只剩LB链表的节点
>         }
>         // 头插法，不需要逆置，每次移动头指针
>         void mergeList2(LinkList2<int> *LB)
>         {
>             Link<T> *pa = this->Head->Next;
>             Link<T> *pb = LB->getHead()->Next;
>             Link<T> *tmp;
>
>             LB->getHead()->Next = nullptr;
>             this->Head->Next = nullptr;
>
>             while(pa != nullptr && pb != nullptr)
>             {
>                 if(pa->Data == pb->Data)
>                 {
>                     tmp = pb;
>                     pb = pb->Next;
>                     delete tmp;
>                     tmp = pa->Next;
>                     pa->Next = this->Head->Next;
>                     this->Head->Next = pa;
>                     pa = tmp;
>                 }
>                 else if(pa->Data < pb->Data)
>                 {
>                     tmp = pa->Next;
>                     pa->Next = this->Head->Next;
>                     this->Head->Next = pa;
>                     pa = tmp;
>                 }else
>                 {
>                     tmp = pb->Next;
>                     pb->Next = this->Head->Next;
>                     this->Head->Next = pb;
>                     pb = tmp;
>                 }
>             }
>
>             while(pa != nullptr)
>             {
>                 tmp = pa->Next;
>                 pa->Next = this->Head->Next;
>                 this->Head->Next = pa;
>                 pa = tmp;
>             }
>             while(pb != nullptr)
>             {
>                 tmp = pb->Next;
>                 pb->Next = this->Head->Next;
>                 this->Head->Next = pb;
>                 pb = tmp;
>             }
>         }
> };
> ```

### 2.1.5 已知由一个链表表示的线性表中含有 $3$ 类字符的数据元素（字母字符、数字字符和其他字符），设计一个算法将该线性表分割为 $3$ 个循环链表，其中每个循环链表均只含一类字符

> **解答：** _[code 2-1-5.cpp](./src/exercise1_zhangming/2-1-5.cpp)_
>
> ```cpp
> #include <iostream>
> #include "../../include/LinearList.hpp"
>
>
> // 创建一个循环链表类
> // 若加入尾指针会更方便
> template <typename T>
> class LoopLink
> {
>     protected:
>         Link<T> *Head;
>     public:
>         LoopLink()
>         {
>             Head = new Link<T>;
>             Head->Next = Head;
>         }
>         ~LoopLink()
>         {
>             Link<T> *tmp, *next;
>             tmp = Head->Next;           // 取第一个节点
>             while(tmp != Head)
>             {
>                 next = tmp->Next;
>                 delete tmp;
>                 tmp = next;
>             }
>             delete Head;
>         }
>         bool addLink(Link<T> *l)
>         {
>             Link<T> *p = Head;
>             // 找到循环链表最后一个节点
>             while(p->Next != Head)
>                 p = p->Next;
>             l->Next = Head;
>             p->Next = l;
>             return true;
>         }
>         bool addValue(const T c)
>         {
>             Link<T> *tmp;
>             tmp = new Link<T>(c);
>             if(addLink(tmp))
>                 return true;
>             return false;
>         }
>         void showAll()
>         {
>             using std::cout;
>             using std::endl;
>             Link<T> *tmp;
>             tmp = Head->Next;
>             while(tmp != Head)
>             {
>                 cout << tmp->Data << "  ";
>                 tmp = tmp->Next;
>             }
>             cout << endl;
>         }
> };
>
> template <typename T>
> class LinkList2:public LinkList<T>
> {
>     public:
>         Link<T>* getHead()
>         {
>             return this->Head;
>         }
>         void resetHead()
>         {                         // 设置头节点下一个节点为nullptr，方便析构
>             this->Head->Next = nullptr;
>         }
> };
>
> void split(LinkList2<char>* L, LoopLink<char>* a, LoopLink<char>* d, LoopLink<char>* o)
> {
>     Link<char> *tmp = L->getHead()->Next;
>     L->resetHead();
>     Link<char> *save;
>     while(tmp)
>     {
>         save = tmp->Next;
>         if(tmp->Data <= '9' && tmp->Data >= '0')
>             d->addLink(tmp);
>         else if((tmp->Data <= 'Z' && tmp->Data >= 'A') || (tmp->Data <= 'z' && tmp->Data >= 'a'))
>             a->addLink(tmp);
>         else
>             o->addLink(tmp);
>         tmp = save;
>     }
> }
> ```

### 2.1.6 设计一个算法，从一个顺序表中删除第 $i$ 个元素开始的 $k$ 个元素

> **解答：** _[code 2-1-6.cpp](./src/exercise1_zhangming/2-1-6.cpp)_
>
> ```cpp
> #include <iostream>
> #include "../../include/LinearList.hpp"
>
>
> // 当k比较大时，默认i后面元素全部删除，若要求第i+k元素必须存在，则需要判断是否越界
> template <typename T>
> class SqList:public ArrList<T>
> {
>     public:
>         SqList(const int size):ArrList<T>(size){}
>         bool deleteRange(int i, int k)
>         {
>             using std::cout;
>             if(i < 1 || i > this->CurLen)
>                 cout << "删除位置不合法!\n";
>             // 当k较大时
>             if(i+k > this->CurLen){
>                 this->CurLen = i-1;
>                 return true;
>             }
>             for(int j = i-1; j <= this->CurLen-1; j++){
>                 if(j+k >= this->CurLen)
>                     break;
>                 this->List[j] = this->List[j+k];
>             }
>             this->CurLen -= k;
>             return true;
>         }
> };
> ```

### 2.1.7 已知线性表中元素依值递增有序排列，并以单链表作为存储结构。设计一个算法，删除表中值相同的多余元素，使得操作后表中的所有元素值均不相同，同时释放被删除的结点空间

> **解答：** _[code 2.1-7.cpp](./src/exercise1_zhangming/2-1-7.cpp)_
>
> ```cpp
> #include "../../include/LinearList.hpp"
>
>
> template <typename T>
> class LinkList2:public LinkList<T>
> {
>     public:
>         bool removeSame()
>         {
>             Link<T> *pre, *cur;
>             pre = this->Head->Next;
>             cur = pre->Next;
>             while(cur){
>                 if(pre->Data == cur->Data)
>                 {
>                     pre->Next = cur->Next;
>                     delete cur;
>                     cur = pre->Next;
>                 }else
>                 {
>                     pre = pre->Next;
>                     cur = pre->Next;
>                 }
>             }
>             return true;
>         }
> };
> ```

### 2.1.8 已知两个依元素递增的有序排列的顺序表 $A$ 和 $B$，且同一表中的元素值各不相同，构造一个线性表 $C$，其元素为 $A$ 和 $B$ 中元素的交集，且表 $C$ 中的元素也依值有序递增排列。设计对 $A,B,C$ 都是顺序表的情况的算法

> **解答：** _[code 2.1-8.cpp](./src/exercise1_zhangming/2-1-8.cpp)_
>
> ```cpp
> #include "../../include/LinearList.hpp"
>
>
> void Solution(ArrList<int>* A, ArrList<int>* B, ArrList<int>* C)
> {
>     int lenA = A->length();
>     int lenB = B->length();
>
>     for(int i = 0, j = 0; i < lenA && j < lenB; )
>     {
>         int valueA,valueB;
>         A->getValue(i, valueA);
>         B->getValue(j, valueB);
>
>         if(valueA == valueB)
>         {
>             C->append(valueA);
>             i++, j++;
>         }
>         else if(valueA > valueB)        // A大B小,j++
>             j++;
>         else
>             i++;
>     }
> }
> ```

### 2.1.9 要求同第 $8$ 题，设计对 $A,B,C$ 都是单链表的情况的算法

> **解答：** [code 2-1-9.cpp](./src/exercise1_zhangming/2-1-9.cpp)
>
> ```cpp
> #include "../../include/LinearList.hpp"
>
>
> void Solution(LinkList<int>* A, LinkList<int>* B, LinkList<int>* C){
>     Link<int>* tmpA;
>     Link<int>* tmpB;
>
>     tmpA = A->SetPos(0);          // 指向A的第一个节点
>     tmpB = B->SetPos(0);          // 指向B的第一个节点
>
>     while(tmpA && tmpB){
>         if(tmpA->Data == tmpB->Data){
>             C->append(tmpA->Data);
>             tmpA = tmpA->Next;
>             tmpB = tmpB->Next;
>         }else if(tmpA->Data > tmpB->Data)
>             tmpB = tmpB->Next;
>         else
>             tmpA = tmpA->Next;
>     }
> }
> ```

### 2.1.10 设表达式以字符形式已存入数组 $E[n]$中，"#"为表达式的结束符，试设计判断表达式中括号（"("和")"）是否匹配的算法

> **解答：** _[code 2-1-10.cpp](./src/exercise1_zhangming/2-1-10.cpp)_
>
> ```cpp
> #include <stack>
> #include <iostream>
>
> typedef char Elem;
>
> bool isMatch(Elem *E, int length)
> {
>     using std::stack;
>     stack<Elem> s;
>     for(int i = 0; i < length; i++)
>     {
>         if(E[i] == '#') break;
>         if(E[i] == '(')
>             s.push(E[i]);
>         else if(E[i] == ')')
>         {
>             // 栈为空且碰到了右括号则匹配失败
>             if(s.empty())  return false;
>             else{
>                 s.pop();
>             }
>         }
>     }
>     // 遍历完毕后栈空，那么匹配成功
>     if(s.empty()) return true;
>     return false;
> }
> ```

## 2.2 教材上机题

### 2.2.1 试设计一个非递归算法在 $O(n)$时间内将一个含有 $n$ 个元素的单链表逆置，要求其辅助空间为常量

### 2.2.2 给定一个单向链表，试设计一个既节省时间又节省空间的算法来找出该链表的倒数第 $m$ 个元素。实现这个算法，并对可能出现的特殊情况做相应的处理。自行设计链表的数据结构。（“倒数第 $m$ 个元素”的含义：当 $m=0$ 时，链表的最后一个元素将被返回）

### 2.2.3 设有 $n$ 个人围坐在一个圆桌周围，现从第 $s$ 个人开始报数，数到第 $m$ 的人出列，然后从出列的下一个人重新开始报数，数到第 $m$ 的人又出列，如此反复直到所有的人全部出列位置。$Jpsephus$ 问题是：对于任意给定的 $n、s、m$，求出按出列次序得到的 $n$ 个人员的序列。试在计算机上模拟 $Josephus$ 问题的求解过程

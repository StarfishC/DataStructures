# 第三章 栈和队列

:warning: _注：缺少的题号表示习题重复_

## 3.1 教材习题

### 3.1.1 如果允许在循环队列的两端都可以进行插入和删除操作。要求

**（1）写出循环队列的类型定义**  
**（2）写出“从队尾删除”和“从队头插入”的算法**

> **解答：** _[code 3-1-1.cpp](./src/exercise1_zhangming/3-1-1.cpp)_
>
> ```cpp
> #include <iostream>
>
>
> template <typename T>
> class LoopQueue
> {
>     private:
>         int MSize;                  // 存放队列的数组大小
>         int Front;                  // 队首
>         int Rear;                   // 队尾
>         T *Qu;                      // 队列数组
>     public:
>         LoopQueue(int size):
>             MSize(size+1), Front(0), Rear(0), Qu(new T[MSize]){}
>         ~LoopQueue()
>         {
>             delete [] Qu;
>         }
>         void clear();               // 清空队列
>         bool isEmpty();             // 队列是否为空
>         bool isFull();              // 队列是否已满
>         bool enQueue(const T &item);// 入队
>         bool deQueue(T &item);      // 出队
>         bool deRear(T &item);       // 队尾删除
>         bool enFront(const T &item);// 队首插入
>         void showAll();             // 显示队列所有元素
> };
>
> template <typename T>
> inline void LoopQueue<T>::clear()
> {
>     Front = Rear = 0;
> }
>
> template <typename T>
> inline bool LoopQueue<T>::isEmpty()
> {
>     return Front == Rear;
> }
>
> template <typename T>
> bool LoopQueue<T>::isFull()
> {
>     return (Rear + 1) % MSize == Front;
> }
>
> template <typename T>
> bool LoopQueue<T>::enQueue(const T &item)
> {
>     using std::cout;
>     using std::endl;
>     if(isFull())
>     {
>         cout << "队列满，不能入队" << endl;
>         return false;
>     }
>     Qu[Rear] = item;
>     Rear = (Rear + 1) % MSize;
>     return true;
> }
>
> template <typename T>
> bool LoopQueue<T>::deQueue(T &item)
> {
>     using std::cout;
>     using std::endl;
>     if(isEmpty())
>     {
>         cout << "队列空，不能出队" << endl;
>         return false;
>     }
>     item = Qu[Front];
>     Front = (Front + 1) % MSize;
>     return true;
> }
>
> template <typename T>
> bool LoopQueue<T>::deRear(T &item)
> {
>     using std::cout;
>     using std::endl;
>     if(isEmpty())
>     {
>         cout << "队列空，不能队尾出队" << endl;
>         return false;
>     }
>     item = Qu[Rear-1];
>     Rear = (Rear + MSize - 1) % MSize;
>     return true;
> }
>
> template <typename T>
> bool LoopQueue<T>::enFront(const T &item)
> {
>     using std::cout;
>     using std::endl;
>     if(isFull())
>     {
>         cout << "队列满，不能队首入队" << endl;
>         return false;
>     }
>     Front = (Front + MSize - 1) % MSize;
>     Qu[Front] = item;
>     return true;
> }
>
> template <typename T>
> void LoopQueue<T>::showAll()
> {
>     using std::cout;
>     using std::endl;
>     int tmp = Front;
>     while(tmp != Rear)
>     {
>         cout << Qu[tmp] << " ";
>         tmp = (tmp + 1) % MSize;
>     }
>     cout << endl;
> }
> ```

### 3.1.2 如果用一个循环数组 $q[0...m-1]$表示队时，该队列只有一个队列头指针 $front$，不设队列尾指针 $rear$，而设置计数器 $count$ 用以记录队列中结点的个数。试编写算法实现队列的 $3$ 个基本运算：判空，入队，出队

> **解答：** _[code 3-1-2.cpp](./src/exercise1_zhangming/3-1-2.cpp)_
>
> ```cpp
> #include <iostream>
>
>
> template <typename T>
> class Queue
> {
>     private:
>         int front;
>         int count;
>         int msize;
>         T *qu;
>     public:
>         Queue(int size):
>             msize(size), qu(new T[size]), count(0), front(0){}
>         ~Queue()
>         {
>             delete [] qu;
>         }
>
>         inline bool isEmpty()
>         {
>             return count == 0;
>         }
>         bool enQueue(const int &item)
>         {
>             using std::cout;
>             using std::endl;
>             if(count == msize)
>             {
>                 cout << "队列满，不能入队" << endl;
>                 return false;
>             }
>             int rear;       // 待入队位置
>             rear = (front + count) % msize;
>             qu[rear] = item;
>             count++;
>             return true;
>         }
>         bool deQueue(int &item)
>         {
>             using std::cout;
>             using std::endl;
>             if(count == 0)
>             {
>                 cout << "队列空，不能出队" << endl;
>                 return false;
>             }
>             item = qu[front];
>             front = (front + 1) % msize;
>             count --;
>             return false;
>         }
> };
> ```

### 3.1.3 试按以下的要求把栈 $S$ 中的元素逆置

**（1）使用额外的两个栈**  
**（2）使用额外的一个队列**  
**（3）使用额外的一个栈，外加一些非数组的变量**

**解答：** _[code 3-1-3.cpp](./src/exercise1_zhangming/3-1-3.cpp)_

> ```cpp
> #include <stack>
> #include <iostream>
> #include <queue>
>
> using namespace std;
>
> // (1) 使用额外两个栈
> /*
>     原栈s，s出栈到s1，s1再出栈到s2，s2再出栈给s
> */
> void ReverseStack1(stack<int> &s)
> {
>     stack<int> s1, s2;
>     while(!s.empty())
>     {
>         s1.push(s.top());
>         s.pop();
>     }
>     while(!s1.empty())
>     {
>         s2.push(s1.top());
>         s1.pop();
>     }
>     while(!s2.empty())
>     {
>         s.push(s2.top());
>         s2.pop();
>     }
> }
>
>
> // (2) 使用额外一个队列
> /*
>    原栈s出栈到队列q，队列再出队入栈s
>    导入的队列头文件出队的元素是出队函数的参数(引用)，故需要临时变量
>    若队列出队有返回值，则不需要临时变量
> */
> void ReverseStack2(stack<int> &s)
> {
>     queue<int> q;
>     while(!s.empty())
>     {
>         q.push(s.top());
>         s.pop();
>     }
>     while(!q.empty())
>     {
>         s.push(q.front());
>         q.pop();
>     }
> }
>
>
> // (3) 使用额外一个栈，加一些非数组变量
> /*
>    用临时变量存储栈顶元素，剩下元素原栈s弹出并入栈s2，最后将临时变量入栈，
>    即完成一次逆置，循环执行（每次出栈次数减一）
> */
> void ReverseStack3(stack<int> &s)
> {
>     stack<int> s2;
>     int tmp;
>     for(auto count = s.size(); count > 0; count--)
>     {
>         tmp = s.top();
>         s.pop();
>         for(int i = 1; i < count; i++)
>         {
>             s2.push(s.top());
>             s.pop();
>         }
>         s.push(tmp);
>         while(!s2.empty())
>         {
>             s.push(s2.top());
>             s2.pop();
>         }
>     }
> }
> ```

### 3.1.4 试给出用栈所定义的队列

> **解答：** _[code 3-1-4.cpp](./src/exercise1_zhangming/3-1-4.cpp)_
>
> 用栈定义队列需要两个栈，一个作为入队使用，一个作为出队使用。
>
> ```cpp
> #include <stack>
> #include <iostream>
>
>
> template <typename T>
> class QueueUsingStack
> {
>     private:
>         std::stack<T> s1;           // 入队使用
>         std::stack<T> s2;           // 出队使用
>     public:
>         QueueUsingStack(){}
>         ~QueueUsingStack(){}
>         bool isEmpty();
>         bool enQueue(const T &item);
>         bool deQueue(T &item);
> };
>
> template <typename T>
> inline bool QueueUsingStack<T>::isEmpty()
> {
>     return s1.empty() && s2.empty();
> }
>
> template <typename T>
> inline bool QueueUsingStack<T>::enQueue(const T &item)
> {
>     s1.push(item);
>     return true;
> }
>
> template <typename T>
> bool QueueUsingStack<T>::deQueue(T &item)
> {
>     using std::cout;
>     using std::endl;
>     if(isEmpty())
>     {
>         cout << "栈空，不能出栈" << endl;
>         return false;
>     }
>     if(s2.empty())
>     {
>         while(!s1.empty())
>         {
>             s2.push(s1.top());
>             s1.pop();
>         }
>     }
>     item = s2.top();
>     s2.pop();
>     return true;
> }
> ```

### 3.1.5 假设以带头结点的循环链表表示队列，并且只设一个指针指向队尾结点，但不设头指针，请写出相应的入队列和出队列算法

> **解答：** _[code 3-1-5.cpp](./src/exercise1_zhangming/3-1-5.cpp)_
>
> ```cpp
> #include <iostream>
>
> using namespace std;
>
> template <typename T>
> class Link
> {
>     public:
>         T Data;
>         Link<T> *Next;
>
>         Link(const T &info, Link<T> *nextlink=nullptr):
>             Data(info), Next(nextlink){}
>         Link(Link<T> *nextlink=nullptr): Next(nextlink){}
> };
>
> template <typename T>
> class LoopLink
> {
>     private:
>         Link<T> *Rear;
>         int Len;
>     public:
>         LoopLink();
>         ~LoopLink();
>         bool isEmpty();
>         bool enQueue(const T &item);
>         bool deQueue(T &item);
>         void showAll();
> };
>
> template <typename T>
> LoopLink<T>::LoopLink()
> {
>     Rear = new Link<T>();
>     Rear->Next = Rear;
>     Len = 0;
> }
>
> template <typename T>
> LoopLink<T>::~LoopLink()
> {
>     Link<T> *tmp = Rear->Next;
>     Rear->Next = nullptr;
>     while(tmp)
>     {
>         Rear = tmp->Next;
>         delete tmp;
>         tmp = Rear;
>     }
> }
>
> template <typename T>
> inline bool LoopLink<T>::isEmpty()
> {
>     return Rear->Next == Rear;
> }
>
> template <typename T>
> bool LoopLink<T>::enQueue(const T &item)
> {
>     Link<T> *tmp = Rear->Next;
>     Link<T> *Node = new Link<T>(item);
>     Rear->Next = Node;
>     Node->Next = tmp;
>     Rear = Node;
>     Len++;
>     return true;
> }
>
> template <typename T>
> bool LoopLink<T>::deQueue(T &item)
> {
>     if(isEmpty())
>     {
>         cout << "队列空" << endl;
>         return false;
>     }
>     Link<T> *tmp = Rear->Next->Next;
>     if(tmp == Rear)
>     {
>         cout << "只有一个元素" << endl;
>         item = tmp->Data;
>         Rear = Rear->Next;
>         Rear->Next = Rear;
>         Len--;
>         return true;
>     }
>     Rear->Next->Next = tmp->Next;
>     item = tmp->Data;
>     delete tmp;
>     Len--;
>     return true;
> }
>
>
> template <typename T>
> void LoopLink<T>::showAll(){
>     Link<T> *head = Rear->Next;
>     Link<T> *tmp = head->Next;
>     while(tmp != head)
>     {
>         cout << tmp->Data << " ";
>         tmp = tmp->Next;
>     }
>     cout << endl;
> }
> ```

### 3.1.6 试在一个长度为 $n$ 的数组中实现两个栈，使得二者在元素的总数目为 $n$ 之前都不溢出，并且保证 $push$ 和 $pop$ 的操作时间代价为 $O(1)$

> **解答：** _[code 3-1-6.cpp](./src/exercise1_zhangming/3-1-6.cpp)_
>
> 对于双向进行存储的栈，可以让两个栈的底分别位于作为存储的向量的始端和末端，而开始和末尾分别作为栈的初始栈顶，当栈顶相遇时，产生溢出异常。  
> 一个长为 $n$ 数组实现两个栈，可将两个栈的栈顶分别设为$-1、n$。入栈时两端向中间添加元素。
>
> ```cpp
> #include <iostream>
> using namespace std;
>
> template <typename T>
> class Stack
> {
>     private:
>         int Lfirst;                     // 左边数组标志
>         int Rfirst;                     // 右边数组标志
>         int Size;                       // 数组最大长度
>         T *Qu;
>     public:
>         Stack(const int &num):
>             Lfirst(-1), Rfirst(num), Size(num), Qu(new T[num]){}
>         ~Stack()
>         {
>             delete [] Qu;
>         }
>
>         bool isEmpty();
>         bool isFull();                  // 是否已满
>         bool lpush(const int &item);    // 左边入栈
>         bool rpush(const int &item);    // 右边入栈
>         bool lpop(T &item);             // 左边出栈
>         bool rpop(T &item);             // 右边出栈
> };
>
>
> template <typename T>
> inline bool Stack<T>::isEmpty()
> {
>     return (Lfirst == -1 && Rfirst == Size);
> }
>
> template <typename T>
> inline bool Stack<T>::isFull()
> {
>     return Lfirst + 1 == Rfirst;
> }
>
> template <typename T>
> bool Stack<T>::lpush(const int &item)
> {
>     if(isFull())
>     {
>         cout << "栈满，不能入栈" << endl;
>         return false;
>     }
>     Qu[++Lfirst] = item;
>     return true;
> }
>
> template <typename T>
> bool Stack<T>::rpush(const int &item)
> {
>     if(isFull())
>     {
>         cout << "栈满，不能入栈" <<endl;
>         return false;
>     }
>     Qu[--Rfirst] = item;
>     return true;
> }
>
>
> template <typename T>
> bool Stack<T>::lpop(T &item)
> {
>     if(Lfirst == -1)
>     {
>         cout << "栈空，不能出栈" << endl;
>         return false;
>     }
>     item = Qu[Lfirst--];
>     return true;
> }
>
> template <typename T>
> bool Stack<T>::rpop(T &item)
> {
>     if(Rfirst == Size)
>     {
>         cout << "栈空，不能出栈" << endl;
>         return false;
>     }
>     item = Qu[Rfirst++];
>     return true;
> }
> ```

### 3.1.7 编号为 $1、2、3、4$ 的 $4$ 辆列车，顺序开进一个栈式结构的站台，请问开出车站的顺序有多少种可能

> **解答：**
>
> $14$ 种可能
>
> 思路：先进站的车可以先开，也可以后开。有一种情况不可能，即编号大的车开出后，编号比其小的车只能由大到小依次开出（中间可以插入编号更大的车，但此车后面编号小的车也要遵守此规则）。例如 $312$ 的开出顺序是不可能的，$231$ 是可能的。全排列$A_{4}^{4}=24$种出法，但 $4$ 开头的只能有一种：$4321$，所以少了$A_{3}^{3}-1=5$种。$3$ 开头时，必须先 $2$ 后$1$，先 $1$ 后 $2$ 的情况有：$3124、3142、3412$，所以少了 $3$ 种。$1$ 或 $2$ 开头时，后面的车如果是 $4$，则最后两辆必须是 $32$ 或 $31$，所以又少了两种 $1423、2413$。一共少了 $5+3+2=10$ 种，最后有 $24-10=14$ 种开出方法。
>
> 下面用$+$表示进站、$-$表示出战：
>
> ```txt
> 1234: 1+ 1- 2+ 2- 3+ 3- 4+ 4-
> 1243: 1+ 1- 2+ 2- 3+ 4+ 4- 3-
> 1324: 1+ 1- 2+ 3+ 3- 2- 4+ 4-
> 1342: 1+ 1- 2+ 3+ 3- 4+ 4- 2-
> 1432: 1+ 1- 2+ 3+ 4+ 4- 3- 2-
> 2134: 1+ 2+ 2- 1- 3+ 3- 4+ 4-
> 2143: 1+ 2+ 2- 1- 3+ 4+ 4- 3-
> 2314: 1+ 2+ 2- 3+ 3- 1- 4+ 4-
> 2341: 1+ 2+ 2- 3+ 3- 4+ 4- 1-
> 2431: 1+ 2+ 2- 3+ 4+ 4- 3- 1-
> 3214: 1+ 2+ 3+ 3- 2- 1- 4+ 4-
> 3241: 1+ 2+ 3+ 3- 2- 4+ 4- 1-
> 3421: 1+ 2+ 3+ 3- 4+ 4- 2- 1-
> 4321: 1+ 2+ 3+ 4+ 4- 3- 2- 1-
> ```

### 3.1.8 证明：从初始输入序列 $1,2,...,n$可以利用一个栈得到输出序列$p_1,p_2,...,p_n,$($p_1,p_2,...,p_n$是$1,2,...,n$的一种排列)的充分必要条件是：不存在下标$i,j,k,$满足$i<j<k$的同时$p_j<p_k<p_i$

> **解答：**
>
> **[充分性]** 归纳法
>
> （1）当 $n=3$ 时，满足约束条件（不存在下标 $i,j,k$，满足 $i< j< k$ 同时$P_j<P_k<P_i$）的序列有 $5$ 种：$123、132、213、231、321$，都可以用栈得到。  
> （2）假设元素个数为 $n-1$ 时成立，当元素个数为 $n$ 时同样成立：序列$P_1,P_2,...,P_n$中，设$P_i=n$。则$P_1,P_2,...,P_{i-1},P_{i+1},...,P_n$是由$1,2,...,n-1$组成的排列，且满足约束条件，根据该假设可以利用栈得到。设$P_j=n-1$，则：
>
> - （a）$j<=i-1$时：说明 $n-1$ 在弹出$P_{i-1}$之前已经压入栈中，因此当$P_{i-1}$从栈中弹出之后，将 $n$ 压入栈并立即弹出，之后按照$P_{i+1},...,P_n$原先的顺序弹栈，即可获得$P_1,P_2,...,P_n$
> - （b）$j>=i+1$时：首先证明当$j>=i+1$时，$j$一定等于$i+1$。利用反证法：若$j>i+1$，则在$n(P_i),n-1(P_j)$之间至少有一个数，且这个数小于 $n-1$ 它的下标大于 $i$ 小于 $j$，这种情况与条件矛盾。因此 $j=i+1$。这说明序列$P_1,...P_{i-1},P_{i+1},...P_n$的生成过程中，弹出$P_{i-1}$之后，将会压入 $n—1$(即$P_{i+1}$)并立即弹出。可以作出修改如下：在压入$n-1$之后再压入 $n$，并立即弹出 $n$ 和 $n-1$，之后按照$P_{i+2},...,P_n$的顺序弹栈，即可获得$P_1,P_2,...,P_n$。
>
> 因此$P_2,P_2,...,P_n$可以用栈得到，命题在$k=n$时同样成立
>
> **[必要性]** 反证法
>
> 如果存在$P_j< P_k < P_i$，则$P_k$应比$P_j$后压入，但此时取出的顺序则为$P_j$在$P_k$之前，显然与栈的 **FILO** 原则矛盾，所以同样不存在下标 $i,j,k$，满足$i< j < k$ 同时 $P_j< P_k < P_i$。

### 3.1.9 试利用栈计算后缀表达式 $12 \  8 \  9 \  * \  +$ , 并明确写出每个步骤以及每个步骤的状态

> **解答：**
>
> 对于后缀表达式求值，从左到右扫描，遇到操作数压栈，遇到操作符出栈两次，计算后压栈。
>
> | 1    | 2    | 3    | 4       | 5       |
> | ---- | ---- | ---- | ------- | ------- |
> | 入栈 | 入栈 | 入栈 | 计算$*$ | 计算$+$ |
> |      |      | 9    |         |         |
> |      | 8    | 8    | 72      |         |
> | 12   | 12   | 12   | 12      | 84      |

### 3.1.10 试利用栈计算中缀表达式 $a×(b×c-d)+e$ 转换成后缀表达式。试写出每个步骤以及每个步骤的栈的状态

> **解答：**
>
> 中缀表达式用$InfixExp$表示，后缀表达式用$PostfixExp$表示。从左到右顺序扫描中缀表达式：
>
> 1. 当输入是操作数时，直接输出到$PostfixExp$中
> 2. 当遇到开括号时，将其入栈
> 3. 当遇到闭括号时，判断栈是否为空。为空则表示括号不匹配，清栈退出。若非空，则把栈中元素依此弹出，直到遇到第一个开括号为止，将开出元素输出到$PostfixExp$中，且弹出括号不需要放到后缀表达式中，若没有遇到开括号，说明括号不匹配，清栈退出
> 4. 当输入为运算符时：
>    - 循环，当（栈非空&&栈顶不是开括号&&栈顶元素运算符的优先级不低于输入运算符的优先级）时，反复操作将栈顶元素弹出，放到$PostfixExp$中
>    - 将输入的运算符压栈
> 5. 当$InfixExp$全部扫描完毕时，若栈中还有元素，则全部依此弹出，并依此输出到$PostfixExp$中。若弹出过程遇到开括号，则说明括号不匹配，清栈退出
>
> $a$  
> $a \ b$  
> $a \ b \ c \ ×$  
> $a \ b \ c \ × \ d \ -$  
> $a \ b \ c \ × \ d \ - \ ×$  
> $a \ b \ c \ × \ d \ - \ × \ e \ +$  
> | 1 | 2 | 3 | 4 | 5 | 6 |
> | --- | --- | --- | --- | --- | --- |
> | | | × | - | | |
> | | ( | ( | ( | | |
> | × | × | × | × | × | + |

### 3.1.11 试写出一个按照下面定义计算整数 $n$ 和 $m$ 的最大共因子 $GCD(n,m)$的递归算法

$$
GCD(n,m)
\left\{\begin{matrix}
m & \text(当m\leqslant n且n\%m = 0) \\
GCD(m,n) & 当n<m\\
GCD(m,n\%m) & 否则
\end{matrix}\right.
$$

> **解答：** _[code 3-1-11.cpp](./src/exercise1_zhangming/3-1-11.cpp)_
>
> ```cpp
> int GCD(int n, int m)
> {
>     if(m <= n && n % m == 0)
>         return m;
>     else if(n < m)
>         return GCD(m, n);
>     else
>         return GCD(m, n % m);
> }
> ```

### 3.1.12 试写出计算下面序列的前 $n$ 项和的递归算法，并给出相应的使用栈的非递归算法

$$
1+\frac{1}{2}-\frac{1}{3}+\frac{1}{4}-\frac{1}{5}...
$$

> **解答：** _[code 3-1-12.cpp](./src/exercise1_zhangming/3-1-12.cpp)_
>
> ```cpp
> #include <iostream>
> #include <stack>
>
> using namespace std;
>
>
> double Recusion(int n)
> {
>     if(n == 1)
>         return 1.0;
>     else
>         return ((n % 2) ? -1 : 1) * 1.0 / n + Recusion(n-1);
> }
>
> // 循环
> double NotRecusion(int n)
> {
>     if(n == 1)
>         return 1.0;
>     stack<double> s = stack<double>();
>     s.push(1.0);
>     for(int i = 2; i <= n; i++)
>     {
>         double sign;
>         sign = (i % 2) ? -1.0 : 1.0;
>         double tmp;
>         tmp = s.top();
>         s.pop();
>         s.push(sign/i + tmp);
>     }
>     return s.top();
> }
>
> // 栈非递归
> double StackNotRecusion(int n)
> {
>     stack<double> s;
>     s.push(1);
>     int i = 2;
>     while(i <= n)
>     {
>         double tmp = 1.0/i;
>         if(i % 2 == 1)
>             tmp = -tmp;
>         s.push(tmp);
>         i++;
>     }
>     double ret = 0;
>     while(!s.empty())
>     {
>         ret += s.top();
>         s.pop();
>     }
>     return ret;
> }
> ```

## 3.2 上机题

### 3.2.1 利用两个栈 $S_1$ 和 $S_2$ 来模拟一个队列时，如何用栈的运算来实现该队列的运算

**（1）`enqueue`: 插入一个元素**  
**（2）`dequeue`: 删除一个元素**  
**（3）`queue_empty`: 判定队列为空**

### 3.2.2 双端队列 $deque$ 是一种插入和删除操作在线性表的两端进行的数据结构，试给出利用数组实现 $deque$ 两端的插入和删除、删除操作，要求这 $4$ 个操作的时间代价均为常数

### 3.2.3 试利用非数组变量，按下述条件各设计一个相应的算法以使队列中的元素有序

**（1）使用两个辅助的队列**  
**（2）使用一个辅助的队列**

### 3.2.4 试按下述条件各设计一个算法把栈 $S_1$ 中的元素转移到栈 $S_2$ 中，并保持栈中元素的原来顺序

**（1）使用一个辅助栈**  
**（2）只使用一些辅助的非数组变量**

### 3.2.5 _Fibonacci_ 序列 $0,1,1,3.1,5,8,13,...$，其中每个元素都是前两个元素之和，可递归定义为下述公式。试设计一个计算 $fib(n)$的递归过程，并利用栈来模拟递归调用，将递归过程改写成一个非递归过程

$$
fib(n)
\left\{\begin{matrix}
n & n=0,1\\
fib(n-1) + fib(n-1) & n≥2
\end{matrix}\right.
$$

### 3.2.6 已知 _Ackermann_ 函数定义如下

$$
Ack(m,n) =
\left\{\begin{matrix}
 & n+1 & \text(当m = 0时)\\
 & Ack(m-1,1) & \text(当m \neq 0,n=0时) \\
 & Ack(m-1,Ack(m,n-1)) & \text(当m \neq 0, n \neq 0时)
\end{matrix}\right.
$$

**（1）写出 $Ack(2,1)$的计算过程。**  
**（2）写出计算 $Ack(m,n)$的非递归算法。**

> **解答：**
>
> （1）解：
>
> $$
> \begin{aligned}
> Ack(2,1) &= Ack(1,Ack(2,0)) \\
>          &= Ack(1,Ack(1,1)) \\
>          &= Ack(1,Ack(0,Ack(1,0))) \\
>          &= Ack(1,Ack(0,Ack(0,1))) \\
>          &= Ack(1,Ack(0,2)) \\
>          &= Ack(1,3) \\
>          &= Ack(0,Ack(1,2)) \\
>          &= Ack(0,Ack(0,Ack(1,1))) \\
>          &= Ack(0,Ack(0,Ack(0,Ack(1,0)))) \\
>          &= Ack(0,Ack(0,Ack(0,Ack(0,1)))) \\
>          &= Ack(0,Ack(0,Ack(0,2))) \\
>          &= Ack(0,Ack(0,3)) \\
>          &= Ack(0,4) \\
>          &= 5
> \end{aligned}
> $$

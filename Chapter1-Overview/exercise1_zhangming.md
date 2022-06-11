# 第一章 概论

:warning: _注：缺少的题号表示习题重复_

## 1.1 教材习题

### 1.1.1 设计一个算法，自大到小依次输出顺序读入的三个整数 x,y,z 的值

> **解答：** _[code 1-1-1.cpp](./src/exercise1_zhangming/1-1-1.cpp)_
>
> ```cpp
> // 或者使用std::swap
> void swap(int&, int&);
> 
> int main()
> {
>     int x, y, z;
>     std::cin >> x >> y >> z;
>     int t; // 临时变量，用来交换值
>     if (x < y)
>         swap(x, y);
>     if (x < z)
>         swap(x, z);
>     if (y < z)
>         swap(y, z);
>     std::cout << x << " " << y << " " << z << std::endl;
>     return 0;
> }
> 
> inline void swap(int& a, int& b)
> {
>     int t = a;
>     a = b;
>     b = t;
> }
> ```

### 1.1.2 试举例说明何为数据结构

> **解答：**
>
> ❗❗**HELP!**

### 1.1.3 数据的存储方式有哪些？简要介绍每一种存储方法的特点

> **解答：**
>
> 主要有顺序存储，链式存储，索引方法和散列方法。（索引和散列是顺序的一种推广）
>
> - 顺序存储：把一组数据存放在一片地址相邻的存储单元中，若存储密度太小，会造成空间浪费，访问方便，增删繁琐。（`C/C++`中，数组大小事先是固定的，不易于扩展）
> - 链式存储：在结点的存储结构中附加指针来存储结点的逻辑关系，适用于经常增删结点而动态变化的数据结构，访问某个结点时，通常需要遍历。
> - 索引方法：索引法是顺序存储的一种推广，通过建造一个由整数域 Z 映射到存储地址域 D 的索引函数 Y:Z→D，把整数索引值 z 映射到结点的存储地址 d∈D，从而形成一个存储了一组指针的索引表，每个指针指向存储区域的一个数据结点。
> - 散列方法：作为索引法的一种延伸和扩展，散列法利用散列函数进行索引值的计算，然后通过索引表求出结点的指针地址。其主要思想是根据结点的关键码值来确定其存储地址，利用散列函数的关系把关键码的值映射到存储空间的地址，然后把结点存入次存储单元中。

### 1.1.4 分析下列程序段中循环语句的执行次数

```cpp
i = 0; s = 0; n = 100;
do
{
    i = i + 1;
    s = s + 10*i;
}while(!((i < n) && (s < n)))
```

> **解答：**
>
> 执行了一次，执行一次后，$i=1，s=10$，使得 `while` 条件结果为 `false`

### 1.1.5 阅读下列算法，指出算法 A 的功能和时间复杂度，其中 h,g 分别是单循环链表中的两个结点指针

```cpp
void B(int* s, int* q)
{
    int *p;
    p = s;
    while(p->next != q)
        p = p->next;
    p->next = s;
}

void A(int* h, int* g)
{
    B(h, g);
    B(g, h);
}
```

> **解答：**
>
> A 的功能是一个单循环链表以 h,g 为分界，变成两个单循环链表，h,g 分别在两个单循环链表中。
>
> 时间复杂度：由于所有结点只遍历一次，所以时间复杂度为 $O(n)$

### 1.1.6 设 n 是偶数，计算运行下列程序段后 m 的值并给出该程序段的时间复杂度

```cpp
m = 0;
for(i = 1; i <= n; i++)
    for(j = 2*i; j <= n; j++)
        m = m + 1
```

> **解答：** _[Testcode 1-1-6.cpp](./src/exercise1_zhangming/1-1-6.cpp)_
>
> 外层循环 $n$ 次，有效次数是 $n/2$，因为此时 $j=n$  
> 当 $i=1$ 时，$j$ 循环 $n-2*1+1$；  
> 当 $i=2$ 时，$j$ 循环 $n-2*2+1$；  
> 当 $i=n/2$ 时，$j$ 循环 $n-2*(n/2)+1$ 次；  
> 所以可得 m 执行次数为：
> $\sum_{i=1}^{n/2}n-2i+1$
>
> $$
> \begin{aligned}
> f &= n-2×1+1 + n-2×2+1 + ... + n-2×\frac{n}{2}+1 \\
>   &= n×\frac{n}{2} - 2×(1+2+3....+\frac{n}{2}) + \frac{n}{2} \\
>   &= \frac{n^2}{2} - (1+\frac{n}{2})×\frac{n}{2} + \frac{n}{2} \\
>   &= \frac{n^2}{4}
> \end{aligned}
> $$
>
> 所以 $m$ 的值为$\frac{n^2}{4}$，时间复杂度是 $O(n^2)$

### 1.1.7 有下列运行时间函数, 分别写出相应的大$O$表示的运算时间

**（1）$T_1(n)=1000$**  
**（2）$T_2(n)=n^2+1000n$**  
**（3）$T_3(n)=3n^3+100n^2+1$**

> **解答：**
>
> （1）$O(1)$  
> （2）$O(n^2)$  
> （3）$O(n^3)$

### 1.1.8 给出下面两个算法的时间复杂度

```cpp
(1) for(i = 1; i <= n; i++)
        x = x + 1
(2) for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            x = x + 1
```

> **解答：**
>
> （1）时间复杂度是$O(n)$  
> （2）时间复杂度是$O(n^2)$

### 1.1.9 试给出一个求两个整数的最大公因数的算法， 并分析时间和空间复杂度

> **解答：** _[code 1-1-9.cpp](./src/exercise1_zhangming/1-1-9.cpp)_
>
> 辗转相除法
>
> ```cpp
> int gcd(int m, int n)
> {
>     int t = 1;
>     while(t != 0)
>     {
>         t = m % n;
>         m = n;
>         n = t;
>     }
>     return m;
> }
> ```

### 1.1.10 假设计算机的速度为每秒处理 $10^{10}$个操作，已知 6 个算法的时间复杂度如下，要求在一小时内完成计算。试问对每个算法来说可处理的数据规模为多少

**（1）$n^2$**  
**（2）$n^3$**  
**（3）$100n^2$**  
**（4）$n\log_{10}n$**  
**（5）$2^n$**  
**（6）$2^{2^n}$**

> **解答：**
>
> （1）$6×10^6$  
> （2）$3.31×10^4$  
> （3）$6×10^5$  
> （4）  
> （5）  
> （6）

### 1.1.11 设有函数 f(n)和 g(n)，且 f(n)在集合 O(g(n))中，下面说法中哪些正确，哪些不正确？对正确的说法给出其证明，不正确的说法给出反例

**（1）$\log_2f(n)$ 是 $O(\log_2 g(n))$**  
**（2）$2^{f(n)}$ 是 $O(2^{g(n)})$**  
**（3）${f(n)}^2$ 是 $O({g(n)}^2)$**

> **解答：**
>
> ❗❗**HELP!**

### 1.1.12 如果一个算法的时间复杂度可表示成下面的公式，试计算其复杂度

**（1）$T(n) = T(⌈n/2⌉) + 1$**  
**（2）$T(n) = T(⌊n/2⌋) + T(⌈n/2⌉) + 1$**  
**（3）$T(n)2 = 2T(⌊n/2⌋) + n$**

> **解答：** ❗❗**HELP!**
>
> （1）$O(log^n)$
>
> $$
> \begin{aligned}
>  T(n) &= T(⌈n/2⌉) + 1 \\
>       &= T(⌈n/2^2⌉) + 2 \\
>       &= ... \\
>       &= T(1) + 2^k  \quad (其中2^k=n)
> \end{aligned}
> $$
>
> （2）$O(n)$
>
> $$
> \begin{aligned}
>     T(n) &= 2T([n/2]) + 1 \\
>          &= 2(2T[n/2^2] + 1) + 1 \\
>          &= 2^2T([n/2^2]) + 2^1 + 1 \\
>          &= ... \\
>          &= 2^kT(1) + 2^{k-1} + 1 \quad (其中2^k=n)
> \end{aligned}
> $$
>
> （3）$O(nlog^n)$
>
> $$
> \begin{aligned}
>     T(n) &= T(⌊n/2⌋) + n/2 \\
>          &= T(⌊n/2^2⌋) + 2*n/2 \\
>          &= T(⌊n/2^3⌋) + 3*n/2 \\
>          &= ... \\
>          &= T(1) + 2^k*n/2 \quad (其中2^k=n)
> \end{aligned}
> $$

## 1.2 教材上机题

### 1.2.1 设 m,n 均为自然数，m 可表示为一些不超过 n$的自然数之和，编写函数 f(m,n)计算这种表示方式的数目。例如 f(5,3)=5，有五种表示方式：3+2,3+1+1,2+2+1,2+1+1+1,1+1+1+1+1

### 1.2.2.试用 `C++`的类声明定义“复数”的抽象数据类型，要求

**（1）在复数内部用浮点数定义其实部和虚部**  
**（2）实现 3 个构造函数：默认的构造函数没有参数；第二个构造函数将双精度浮点数赋值给复数的实部，虚部置为 0；第三个构造函数将两个双精度浮点数分别赋给复数的实部和虚部**  
**（3）定义获取和修改复数的实部和虚部以及$+、-、*、/$等运算的成员函数**  
**（4）定义重载的流函数来输出一个复数**

## 1.3《学习指导》教材习题解答

### 1.3.1 设字符集为字母和数字的集合，字符的顺序为 A,B,C,...,Z,0,1,3...9,请将下列字符串按字典顺序排列、存储：PAB,5C,PABC,CXY,CRSI,7,B899,B9，并分析可以采取的存储方案

> **解答：** _[code 1-3-1.cpp](./src/exercise1_zhangming/1-3-1.cpp)_
>
> 可以采用的存储结构有顺序数组和链表以及索引等方式
>
> 1. 采用二维数组，需要 `array[8][5]`
>    - 优点：结构紧凑，直观简单，代码十分容易
>    - 缺点：为每个单词都开辟了同样长度的空间，造成空间浪费
> 2. 用链表, 结构可定义为：
>
>    ```cpp
>    struct strings{
>     char string[MAX_LENGTH];
>     string *pNext;
>    }
>    ```
>
>    - 优点：若有后序操作，如增删，则效率高，并且可以使用不连续结点
>    - 缺点：操作过程相对复杂，容易出错，而且排序过程需要从表头开始沿链索一个结点、一个结点地比较搜索，相当费时。
>
> 3. 索引存储
>    索引存储是顺序存储的一种推广。使用一个字符串 `char data[500]`，将大小长度不等的数据结点（单词）顺序存储其中。并使用一个字符指针数组 `char *index[n]`存储一系列的指针，每个指针指向存储区域的一个数据结点。排序时，直接对 `index` 中的地址值进行调换修改即可，而不用修改 `data` 中的任何内容。
>
>    - 优点：由于单词长度不同，在存储时充分考虑了这个因素，可以节省空间。此外由于交换的不是单词本身二是单词的地址，可以节省时间，从空间和时间两方面得到优化。
>
> ```cpp
> #include <iostream>
> #include <string>
> 
> using namespace std;
> 
> // 1. 用链表
> class Node
> {
> public:
>     string str;
>     Node* pNext;
> 
>     Node(const string s) :
>         str(s), pNext(nullptr) {}
>     Node() :
>         str(""), pNext(nullptr) {}
> };
> 
> /* 链表类 */
> class LinkList
> {
> private:
>     Node* head;
>     int curLen;
> 
> public:
>     LinkList() :
>         head(new Node()), curLen(0) {}
>     ~LinkList();
>     int size() const { return curLen; }
>     bool compare(const string& a, const string& b); // 比较a,b字符串
>     void append(const string& s); // 添加元素并排序
>     void showAll();
> };
> 
> LinkList::~LinkList()
> {
>     Node* temp;
>     while (head)
>     {
>         temp = head;
>         head = head->pNext;
>         delete temp;
>     }
> }
> 
> bool LinkList::compare(const string& a, const string& b)
> {
>     // 返回true表明b在a前，false表明a在b前
>     auto i = a.begin();
>     auto j = b.begin();
>     while (i != a.end() && j != b.end())
>     {
>         // 1. 字符相等
>         if (*i == *j)
>         {
>             i++;
>             j++;
>             continue;
>         }
> 
>         // 2.字符均为A-Z或均为0-9情况
>         if ((*i - 'A' >= 0 && *j - 'A' >= 0) || (*i - 'A' < 0 && *j - 'A' < 0))
>         {
>             if (*i - *j < 0) // 如B-A>0，A在B前
>                 return false;
>             else
>                 return true;
>         }
>         else
>         {
>             // 3. 一个字符A-Z，一个0-9
>             if (*i - *j > 0) // 如A-5>0，A在5前
>                 return false;
>             else
>                 return true;
>         }
>     }
>     // 如果a没有迭代完，b迭代完了，b在a前
>     if (*i)
>         return true;
>     return false;
> }
> 
> void LinkList::append(const string& s)
> {
>     Node* current = head->pNext;
>     Node* previous = nullptr;
>     bool stop = false;
>     while (current != nullptr && not stop)
>     {
>         if (compare(current->str, s))
>             stop = true;
>         else
>         {
>             previous = current;
>             current = current->pNext;
>         }
>     }
>     Node* temp = new Node(s);
>     if (previous == nullptr)
>     {
>         // previous没找到，即插入第一个
>         temp->pNext = head->pNext;
>         head->pNext = temp;
>     }
>     else
>     {
>         // 在previous和current之间插入
>         temp->pNext = current;
>         previous->pNext = temp;
>     }
>     curLen++;
> }
> 
> void LinkList::showAll()
> {
>     Node* tmp = head->pNext;
>     while (tmp)
>     {
>         cout << tmp->str << " --> ";
>         tmp = tmp->pNext;
>     }
> }
> 
> int main()
> {
>     string a[] = { "PAB", "5C", "PABC", "CRSI", "7", "B899", "CXY", "B9" };
>     LinkList list = LinkList();
>     for (int i = 0; i < 8; i++)
>     {
>         list.append(a[i]);
>     }
>     list.showAll();
>     return 0;
> }
> ```

### 1.3.2 有一个包括 100 个元素的数组，每个元素的值都是实数，请写出求最大元素的值及其位置的算法，讨论它所可能采取的存储结构

> **解答：** _[code 1-3-2.cpp](./src/exercise1_zhangming/1-3-2.cpp)_
>
> _注意：要求实数，且需要考虑多个最大值情况_  
> 可采用顺序数组，链表和索引。顺序数组最优。
>
> ```cpp
> #include <iostream>
> 
> int* solution(double* A, int N, int* ret)
> {
>     // ret用来记录最大值所在的位置
>     int position = 0; // 初始化设定数组的第一个元素
>     int j = 1; // 控制最大值数组的存放
>     for (int i = 1; i < N; i++)
>     {
>         if (A[i] > A[position])
>         {
>             position = i; // 更新最大值元素的位置
>             j = 1; // 重置ret数组的下一个存放位置，0号位置预留给position
>         }
>         else if (A[i] == A[position])
>             ret[j++] = i; // 记录重复的最大值位置
>     }
>     ret[0] = position;
>     if (j < N)
>         ret[j] = -1; // -1为哨兵，前j个元素均为最大值的位置
>     return ret;
> }
> 
> int main()
> {
>     using namespace std;
>     double Num[] = { 4529.9, 88, 333, 22, 100, 232.3, 4529.9 };
>     int N = sizeof(Num) / sizeof(double);
>     int ret[N];
>     solution(Num, N, ret);
>     cout << "MaxNumber:" << Num[*ret] << endl;
>     cout << "MaxPosition:";
>     for (int i = 0; ret[i] != -1; i++)
>         cout << ret[i] << " ";
>     cout << endl;
>     return 0;
> }
> ```

### 1.3.3 以学生课程表为例，讨论它的数据结构，叙述其逻辑结构、存储结构和相关运算等三个方面

> **解答：**
>
> - 【逻辑结构】
>
>   逻辑结构由结点集合 $K$ 和关系集合 $R$ 来表示，以学生每周的课程为例。将每天的课程安排数据作为结点，一共引入 $5$ 个结点，依次为“周一”, “周二”，...，“周五”。全部结点组成结点集 $K$。  
>   这些结点是复合类型，是一个结构体，包括当日的课程名称、时间、地点等。  
>   这些结点两两之间有一个时间关系 $r$，$r=${（“周一”，“周二”），（“周二”，“周三”），（“周三”，“周四”），（“周四”，“周五”）}。此集合的 $4$ 个元素描述了“时间先后”关系 $r$。此外还引入一个关系 $r'=$ {“周日”，“周一”}，$r'$只含有一个元素，以表示周日和下周的时间顺序。$r$ 和 $r'$共同构成关系集 $R$。其中 $r$ 属于线性结构。$R$ 是一种环形关系。
>
>   |          | 周一 | 周二 | 周三 | 周四 | 周五 | 周六 | 周日 |
>   | -------- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
>   | 第一节课 |
>   | 第二节课 |
>   | 第三节课 |
>   | 第四节课 |
>
> - 【存储结构】
>
>   - 顺序表
>
>     当课程表课时较多时，可用二维数组，`course[4][5]`，一天四节课，共五天。`course[0][0]`代表周一早上第一节课。  
>     优缺点：逻辑清晰，查阅修改方便。但需要占据整块空间，课时较少时造成浪费。
>
>   - 索引
>
>     构造索引表，其中的指针分别指向每一天（或第 N 节课）的课程。  
>     优缺点：逻辑清晰，不占用整块存储空间。但算法比较复杂，附加的空间代价比较高（有索引表）
>
>   - 链表
>
>     优缺点：不用占用整块存储空间。但检索比较复杂。也可采用循环链表。
>
>     ```cpp
>     struct Course
>     {
>         int no;                 // 课次
>         char time;              // 时间
>         char location;          // 上课地点
>         char courseName;        // 课程名称
>         char teacherName;       // 授课老师
>         struct Course *Cnext;   // 下堂课指针
>     }
>     struct Days
>     {
>         int day;                // 第几天
>         struct Days *Dnext;     // 下一天
>         struct Course *courses; // 当天课程
>     }
>     ```
>
> - 【相关运算】
>
>   常见的运算包括增删改查。

## 1.4《学习指导》增补习题

### 1.4.2 已知斐波那契序列的定义如下，试编写求 k 阶斐波那契序列第 m 项值的函数算法，k、m 均作为该函数的参数

$$
\begin{aligned}
&f_0 = 0, f_1 = 0,...,f_{n-2}=0, f_{n-1} = 1;  \\
&f_n = f_{n-1} + f_{n-2}+...+f_{n-k}, n = k,k+1,...
\end{aligned}
$$

> **解答：** _[code 1-4-2.cpp](./src/exercise1_zhangming/1-4-2.cpp)_
>
> 观察可知，第 $k$ 项即$f_{k-1}$项为 $1$，前 $k-1$ 项均为 $0$。第 $k$ 项之后每一项均为前 $k$ 项之和。如：
>
> $$
> 当k=2时：0,1,1,3,3,5,8\\
> 当k=3时： 0,0,1,1,3,4,7
> $$
>
> 所以当$m<=k-1$时，第 $m$ 项为 $0$。
>
> 【数组法】
>
> ```cpp
> #include <iostream>
>
> const int MAX = 1000;
>
> using namespace std;
>
> // 数组法
> int Fibonacci_arr(int k, int m)
> {
>     int f;
>     int arr[MAX];
>     if(m <= k-1)
>         f = 0;
>     else
>     {
>         for(int i = 0; i < k-1; i++)
>             arr[i] = 0;                 // 前K-1项均为零
>         arr[k-1] = 1;
>         for(int i = k; i < m; i++)
>         {
>             int sum = 0;
>             for(int j = 1; j <= k; j++)
>                 sum += arr[i-j];
>             /* for(int j = i-k; j < i; j++)  // 前k项相加
>                 sum += arr[j]; */
>             arr[i] = sum;
>         }
>         f = arr[m-1];
>     }
>     return f;
> }
> ```
>
> 【递归法】
>
> $$
> \begin{aligned}
> f_n &= f_{n-1} + f_{n-2} + ... + f_{n-k} \\
> f_{n-1} &= f_{n-2} + f_{n-3} + ... + f_{n-k-1}\\
> \end{aligned}
> $$
>
> 两式相减得:
> $f_n = 2f_{n-1} - f_{n-k-1} \quad (n≥k+1)$
>
> ```cpp
> int Fibonacci_rec(int k, int m)
> {
>     if(m <= k-1)
>         return 0;
>     else if((m == k) || (m == k+1))     // 第k项和k+1均为1
>         return 1;
>     else
>         return 2*Fibonacci_rec(k, m-1) - Fibonacci_rec(k, m-k-1);
> }
> ```

### 1.4.3 设计一个算法，计算$i!*2^i$的值并存入数组 $a[0..arrsize-1]$的第$i-1$个分量中$(i=1.3....,n)$。假设计算机允许的整数最大值为 $maxint$，则当$n>arrsize$或对某个$k(1\leq k\leq n)$，当$k!*2^i>maxint$时，按出错处理

> **解答：** _[code 1-4-3.cpp](./src/exercise1_zhangming/1-4-3.cpp)_
>
> ```cpp
> #include <iostream>
> #include <climits>
>
> const int arrsize = 300;
> const int maxint = INT_MAX;
>
> bool Solution(int i, int a[])
> {
>     if(i < 1 || (i > arrsize))
>         return false;
>     a[0] = 2;
>     for(int j = 2; j <= i; j++)
>     {
>         if(a[j-2]*2*j > maxint)
>             return false;
>         a[j-1] = a[j-2] * 2 * j;
>     }
>     return true;
> }
> ```

### 1.4.4 设计一个算法，计算多项式$p_n(x) = \sum_{i=0}^{n}a_ix^i$的值

> **解答：** _[code 1-4-4.cpp](./src/exercise1_zhangming/1-4-4.cpp)_
>
> 多项式可以看作：$a_0+(a_1+(a_2+(a_3+...(a_{n-1}+a_nx)x)x)x)x$
>
> ```cpp
> #include <cmath>
>
> double Solution1(double a[], int x, int n)
> {
>     double tmp = a[0];
>     for(int i = 1; i <= n; i++)
>         tmp += a[i] * pow(x,i);
>     return tmp;
> }
>
> int Solution2(double a[], int x, int n)
> {
>     double tmp = a[n];
>     for(int i = n; i > 0; i--)
>         tmp = a[i-1] + x * tmp;
>     return tmp;
> }
> ```

### 1.4.5 假设有 A、B 两个高校进行田径对抗赛，各高校的单项成绩均存入计算机中，构成一张表，表中的每一行形式如下，设计算法处理下述表格，统计各高校的男女总分和团体总分并输出

| 项目名称 | 性别 | 校名 | 成绩 | 得分 |
| -------- | ---- | ---- | ---- | ---- |
| xxxxxxxx |      |      |      |      |

> **解答：** _[code 1-4-5.cpp](./src/1-4-5.cpp)_
>
> 可采用链表形式存储，因该题需要统计高校的成绩，可再建立一个高校索引表
>
> ```cpp
> enum schoolname {a, b};
> enum sex {female, male};
> enum event {x, y, z};
>
>
> class grade
> {
>     public:
>         schoolname school;          // 学校
>         sex sex;                    // 性别
>         event e;                    // 项目名称
>         int score;                  // 得分(成绩)
>         grade(){};
>         grade(schoolname sn, sex s, event e, int sc);
> };
>
>
> class sum
> {
>     private:
>         schoolname school;          // 校名
>         int malesum;                // 男总分
>         int femalesum;              // 女总分
>         int totalsum;               // 团体总分
>     public:
>         sum();
>         sum(schoolname sn);
>         void getscore(grade gra[], int n);   // 获取分数
>         void showscore();           // 输出总分
> };
> ```

### 1.4.7 下列算法对一个 n 位二进制数加 1，假如无溢出，该算法的最坏时间复杂度是什么？请分析它的平均时间复杂度

```c
void Inc(A[n])
{
    int i;
    i = n - 1;
    while(A[i] == 1)
    {
        A[i] = 0;
        i = i - 1;
    }
    A[i] = 1;
}
```

> **解答：**
>
> 最好时间复杂度是$O(1)$，最坏时间复杂度是$O(n)$。  
> 假如无溢出，那么最坏情况是除了最高位为 $0$ 其他位均为 $1$，即循环执行 $n-1$ 次，每次循环两次赋值，循环中一共 $2(n-1)$次赋值操作，循环外两次赋值，一共是 $2n$ 次。最好情况则是最低位为 $0$，不进入循坏，仅两次赋值操作。  
> 所以平均时间复杂度是 $n+1$，即$O(n)$

### 1.4.9 调用 `C` 语言函数 f(n) ，回答下列问题

**（1）试指出 f(n) 值的大小，并写出 f(n) 值的推导过程。**  
**（2）假定  n=5 ，试指出 f(5) 值得大小和执行 f(5) 时输出结果。**

```c
int f(int n)
{
    int i, j, k, sum = 0;
    for(i = 1; i < n; i++)
    {
        for(j = n; j > i-1; j--)
            for(k = 1; k < j; k++)
                sum++;
        printf("sum = %d\n", sum);
    }
    return sum;
}
```

> **解答：**
>
> - （1）当 $i=1$ 时，第二重循环执行 $n$ 次，第三重循环执行$(n-1)+...+0$ 次  
>    当 $i=2$ 时，第二重循环执行 $n-1$ 次，第三重循环执行$(n-1)+...+1$ 次  
>    当 $i=n-1$ 时，第二重循环执行 $2$ 次，第三重循环执行$(n-1)+(n-2)$次  
>    所以有：
>   $$
>   \begin{aligned}
>   f(n)&=(0+...+n-1)+(1+...+n-1)+...+((n-2)+(n-1))  \\
>       &=1×2+2×3+3×4+...+(n-2)×(n-1)+(n-1)×n-(n-1)\\
>       &=\sum_{i=1}^{n-1}n(n+1)-(n-1)\\
>       &=\frac{t(t+1)(t+2)}{3}-(n-1)\quad(t=n-1)\\
>       &=\frac{(n-1)n(n+1)}{3}-(n-1)\\
>   \end{aligned}
>   $$
>   这里是因为：
>   $$
>   \sum_{i=1}^nn(n+1)=\sum_{i=1}^n(n^2+n)=\frac{n(n+1)(2n+1)}{6}+\frac{n(n+1)}{2}
>   $$
> - （2）当 $n=5$ 时，$f(n)=\frac{4×5×6}{3}-4=36$与程序运行结果一致

## 1.5《学习指导》上机题

### 1.5.3 编写算法解决 $Josephus$ 问题：设 n 个人围坐在一个圆桌周围，现在从第 s 个人开始报数，数到第 m 个人，让他出局；然后从出局的下一个人重新开始报数，数到第 m 个人，再让他出局......如此反复直到所有人全部出局位置。对于任意给定的 n,s,m，求出这 n 个人的出局序列

# 第一章 绪论

## 习题 - 选择

### 1. 可以用（）定义一个完整的数据结构

**&emsp;&emsp;A. 数据元素
&emsp;&emsp;&emsp;&emsp;B. 数据对象**  
**&emsp;&emsp;C. 数据关系
&emsp;&emsp;&emsp;&emsp;D. 抽象数据类型**

### 2. 以下数据结构中，（）是非线性数据结构

**&emsp;&emsp;A. 树
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;B. 字符串**  
**&emsp;&emsp;C. 队列
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;D. 抽象数据类型**

### 3. 以下属于逻辑结构的是（）

**&emsp;&emsp;A. 顺序表
&emsp;&emsp;&emsp;&emsp;&emsp;B. 哈希表**  
**&emsp;&emsp;C. 有序表
&emsp;&emsp;&emsp;&emsp;&emsp;D. 单链表**

### 4. 以下与数据的存储结构无关的术语是（）

**&emsp;&emsp;A. 循环队列
&emsp;&emsp;&emsp;&emsp;B. 链表**  
**&emsp;&emsp;C. 哈希表
&emsp;&emsp;&emsp;&emsp;&emsp;D. 栈**

### 5. 以下数据结构的说法中，正确的是（）

**&emsp;&emsp;A. 数据的逻辑结构独立与其存储结构**  
**&emsp;&emsp;B. 数据的存储结构独立于其逻辑结构**  
**&emsp;&emsp;A. 数据的逻辑结构唯一决定了其存储结构**  
**&emsp;&emsp;A. 数据结构仅由其逻辑结构和存储结构决定**

### 6. 在存储数据时，通常不仅要存储各数据元素的值，而且要存储（）

**&emsp;&emsp;A. 数据的操作方法
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;B. 数据元素的类型**  
**&emsp;&emsp;C. 数据元素之间的关系
&emsp;&emsp;&emsp;&emsp;&emsp;D. 数据的存取方法**

### 7. 链式存储设计时，结点内的存储单元地址（）

**&emsp;&emsp;A. 一定连续
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;B. 一定不连续**  
**&emsp;&emsp;C. 不一定连续
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;D. 部分连续，部分不连续**

### 8. 一个算法应该是（）

**&emsp;&emsp;A. 程序
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;B. 问题求解步骤的描述**  
**&emsp;&emsp;C. 要满足五个基本特性
&emsp;&emsp;&emsp;&emsp;&emsp;D. A 和 C**

### 9. 某算法的时间复杂度为$O(n^2)$，表明该算法的（）

**&emsp;&emsp;A. 问题规模是$n^2$ &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;B. 执行时间等于$n^2$**  
**&emsp;&emsp;C. 执行时间与$n^2$成正比 &emsp;&emsp;&emsp;&emsp;&emsp;D. 问题规模与$n^2$成正比**

### 10. 以下算法的时间复杂度为（）

```cpp
void func(int n){
    int i = 1;
    while(i <= n)
       i = i * 2;
}
```

**&emsp;&emsp;A. $O(n)$
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;B. $O(n^2)$**  
**&emsp;&emsp;C. $O(nlog_2n)$
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&nbsp;D. $O(log_2n)$**

### 11.【2011 统考真题】设 n 是描述问题规模的非负整数，下面的程序片段的时间复杂度是（）

```cpp
x = 2;
while(x < n/2)
    x = 2 * x;
```

**&emsp;&emsp;A. $O(log_2n)$
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;B. $O(n)$**  
**&emsp;&emsp;C. $O(nlog_2n)$
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&nbsp;D. $O(n^2)$**

### 12.【2012 统考真题】求整数 n(n≥0)的阶乘算法如下，其时间复杂度是（）

```cpp
int fact(int n){
    if(n <= 1) return 1;
    return n * fact(n-1);
}
```

**&emsp;&emsp;A. $O(log_2n)$
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;B. $O(n)$**  
**&emsp;&emsp;C. $O(nlog_2n)$
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&nbsp;D. $O(n^2)$**

### 13.【2013 统考真题】已知两个长度分别为$m$和$n$的升序链表，若将他们合并为长度$m+n$的一个降序链表，则最坏情况下的时间复杂度是（）

**&emsp;&emsp;A. $O(n)$
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;B. $O(mn)$**  
**&emsp;&emsp;C. $O(min(m,n))$
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&nbsp;D. $O(max(m,n))$**

### 14.【2014 统考真题】下列程序段的时间复杂度是（）

```cpp
count = 0;
for(k = 1; k <= n; k *= 2)
    for(j = 1; j <= n; j++)
        count ++;
```

**&emsp;&emsp;A. $O(log_2n)$
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;B. $O(n)$**  
**&emsp;&emsp;C. $O(nlog_2n)$
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&nbsp;D. $O(n^2)$**

### 15.【2017 统考真题】下列函数的时间复杂度是（）

```cpp
int func(int n){
    int i = 0, sum = 0;
    while(sum < n)
        sum += ++i;
    return i;
}
```

**&emsp;&emsp;A. $O(log^n)$
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;B. $O(n^{1/2})$**  
**&emsp;&emsp;C. $O(n)$
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&nbsp;&emsp;&emsp;&emsp;&emsp;&emsp;&nbsp;D. $O(nlogn)$**

### 16. 有以下算法，其时间复杂度是（）

```cpp
void fun(int n){
    int i = 0;
    while(i * i * i <= n)
        i++;
}
```

**&emsp;&emsp;A. $O(n)$
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;B. $O(nlog^n)$**  
**&emsp;&emsp;C. $O(\sqrt[3]{n})$
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&nbsp;&nbsp;&nbsp;&nbsp;D. $O(\sqrt{n})$**

### 17. 下列程序段中，其中 n 为正整数，则最后一行语句的频度在最坏情况下是（）

```cpp
for(i = n-1; i > 1; i--)
    for(j = 1; j < i; j++)
        if(A[j] > A[j+1])
            A[j]与A[j+1]对换;
```

**&emsp;&emsp;A. $O(n)$
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;B. $O(nlog^n)$**  
**&emsp;&emsp;C. $O(n^3)$
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&nbsp;&nbsp;D. $O(n^2)$**

### 18. 以下算法中$m++$语句的执行次数为（）

```cpp
int m = 0, i, j;
for(i = 1; i <= n; i++)
    for(j = 1; j <= 2 *i; j++)
        m++;
```

**&emsp;&emsp;A. $n(n+1)$
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;B. $O(n)$**  
**&emsp;&emsp;C. $O(n+1)$
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&nbsp;&nbsp;&nbsp;D. $O(n^2)$**

### 19. 下面说法中，错误的是（）

**Ⅰ. 算法原地工作的含义是指不需要任何额外的辅助空间  
Ⅱ. 在相同规模$n$下，复杂度为$O(n)$的算法在时间上总是优于复杂度为$O(2^n)$  
Ⅲ. 所谓时间复杂度，是指最坏情况下估算算法执行时间的一个上界  
Ⅳ. 同一个算法，实现语言的级别越高，执行效率越低**

**&emsp;&emsp;A. Ⅰ
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&nbsp;&nbsp;B. Ⅰ,Ⅱ**  
**&emsp;&emsp;C.Ⅰ,Ⅳ
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&nbsp;&nbsp;D. Ⅲ**

### 20.【2019 统考真题】设$n$是秒速问题规模的非负整数，下列程序段的时间复杂度是（）

```cpp
x = 0;
while(n > = (x+1)*(x+1))
    x = x + 1;
```

**&emsp;&emsp;A. $O(log^n)$
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;B. $O(n^{1/2})$**  
**&emsp;&emsp;C. $O(n)$
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&nbsp;&nbsp;D. $O(n^2)$**

## 习题 - 综合

### 1. 对于两种不同的数据结构，逻辑结构或物理结构一定不相同吗

### 2. 试举一例，说明对相同的逻辑结构，同一种运算在不同的存储方式下实现时，其运算效率不同

### 3. 以下算法所需时间由下述递归方程表示，试求出该算法复杂度的级别（或阶）。式中，$n$是问题的规模，为简单起见，设$n$是$2$的整数次幂

$$
T(n)=
\left\{\begin{matrix}
1 & n=1\\
2T(n/2)+n & n>1
\end{matrix}\right.
$$

### 4. 分析以下各程序段，求出算法的时间复杂度

```cpp
(1)
i = 1; k = 0;
while(i < n - 1){
    k = k + 10 * i;
    i++;
}

(2)
y = 0;
while((y+1)*(y+1) <= n)
    y = y + 1;

(3)
for(i = 1; i <= n; i++)
    for(j = 1; j <= i; j++)
        for(k = 1; k <= j; k++)
            x++;

(4)
for(i = 0; i < n; i++)
    for(j = 0; j < m; j++)
```

## 答案与解析 - 选择

### 1. D

抽象数据类型（ADT）描述了数据的逻辑结构和抽象运算，通常用（数据对象，数据元素，基本操作集）这样的三元组来表示，从而构成一个完整的数据结构定义

### 2. A

树和图是典型的非线性数据结构

### 3. C

顺序表、哈希表和单链表是三种不同的数据结构，即描述逻辑结构、又描述存储结构和数据运算。而有序表是指关键字有序的线性表，仅描述元素之间的逻辑关系，它既可以链式存储也可以顺序存储，属于逻辑结构

### 4. D

循环队列是用顺序表表示的对了，是一种数据结构。栈是一种抽象数据类型，可采用顺序存储或链式存储，只表示逻辑结构

### 5. A

数据的逻辑是从面向实际问题的角度出发的，只采用抽象表达方式，独立于存储结构，数据的存储方式有多种不同的选择；而数据的存储结构是逻辑结构在计算机上的映射，他不能独立于逻辑结构而存在

### 6. C

在存储数据时，不仅要存储数据元素的值，而且要存储数据元素之间的关系

### 7. A

链式存储设计时，各个不同结点的存储空间可以不连续，但节点内的存储单元地址必须连续

### 8. B

程序不一定满足有穷性质，如死循环、操作系统等，而算法必须有穷。算法代表对问题求解步骤的描述，而程序则是算法在计算机上的特定实现。C 只是算法的必要条件，不能成为算法的定义

### 9. C

### 10. D

找出基本运算$i=i*2$，设执行次数为 t，则$2^t<n$，即$t≤log_2n$，因此时间复杂度度$T(n)=O(log_2n)$

### 11. A

基本运算（执行频率最高的语句）为$x=2*x$，设执行次数为$t$，则有$2^{t+1}<n/2$，所以$t<log_2{n/2}-1=log_2n-2$，得$T(n)=O(log_2n)$

### 12. B

递归出口为$fact(1)$，一共执行$n$次递归调用$fact()$，故$T(n)=O(n)$

### 13. D

两个升序链表合并，两两比较表中元素，每比较一次，确定一个元素的链表位置（取较小元素，头插法）。当一个链表比较结束之后，将另外一个链表的剩余元素插入即可。最坏情况是两个链表中的元素一次进行比较，因为$2max(m,n)≤m+n$，所以时间复杂度为$O(max(m,n))$

### 14. C

内层循环条件$j≤n$与外层循环的变量无关，各自独立，每次内层循环都执行$n$次。外层循环条件$k≤n$，增量定义为$k*=2$，可知循环次数$t$满足$k=2^i≤n$，即$t≤log2_n$。即内层循环时间复杂度为$O(n)$，外层循环的时间复杂度为$O(log_2n)$。所以$T(n)=T_1(n)×T_2(n)=O(n)×O(log_2n)=O(nlog_2n)$

### 15. B

基本运算$sum+=++i$，等价于$++i;sum=sum+i$，每执行一次$i$自增$1$。$i=0$时，$sum=0+1$；$i=1$时，$sum=0+1+2$；以此类推得出$sum=0+1+2+3+...+i=(1+i)*i/2$，可知循环次数$t$满足$(1+t)*t/2<n$，因此时间复杂度为$O(n^{1/2})$

### 16. C

基本运算为$i++$，执行次数为$t$，有$t^3≤n$。故有$T(n)=O(\sqrt[3]{n})$

### 17. D

冒泡排序代码。当所有相邻元素都为逆序时，则最后一行的语句每次都会执行

$$
T(n) = \sum_{i=2}^{n-1}\sum_{j=1}^{i-1}1=\sum_{i=2}^{n-1}i-1=(n-2)(n-1)/2=O(n^2)
$$

### 18. A

$m++$的执行次数为

$$
\sum_{i=1}^{n}\sum_{j=1}^{2i}1=\sum_{i=1}^{n}2i=n(n+1)
$$

### 19. A

Ⅰ.算法原地工作是指算法所需的辅助空间是常量  
Ⅲ.时间复杂度总是考虑最坏情况下的时间复杂度，以保证算法的运行时间不会比它更长

### 20. B

假设第$k$次循环终止，则第$k$次执行时，$(x+1)^2>n$，$x$的初始值为$0$，则第$k$次判断时，$x=k-1$，即$k^2>n$，因此时间复杂度是$O(\sqrt{n})$

## 答案与解析 - 综合

### 1. 解答

应该注意到，数据的运算也是数据结构的一个重要方面  
对于两种不同的数据结构，他们的逻辑结构和物理结构完全有可能相同。比如二叉树和二叉排序树，二叉排序树可以采用二叉树的逻辑表示和存储方式，前者通常用于表示层次关系，而后者通常用于排序和查找。虽然他们的运算都有建立树、插入结点、删除结点等功能，但是对于二叉搜索数和二叉排序树，这些运算的定义是不同的，以查找结点威力，二叉树的时间复杂度为$O(n)$，而二叉排序树的时间复杂度为$O(log_2n)$

### 2. 解答

线性表既可以用顺序存储方式实现，也可以用链式存储方式实现。在顺序存储方式下，在线性表中插入和删除元素，平均要移动近一半的元素，时间复杂度为$O(n)$；而在链式存储方式下，插入和删除的时间复杂度都是$O(1)$

### 3. 解答

时间复杂度是$O(nlog_2n)$  
设$n=2^k(k≥0)$，根据题目定义有$T(2^k)=2T(2^{k-1})+2^k=2^2T(2^{K-2})+2×2^k$，得递推公式$T(2^k)=2^iT(2^{k-1}+i×2^k$，进而得$T(2^k)=2^kT(2^0)+k×2^k$，即$T(n)=2^{log_2n}+log_2n×n=n(log_2n+1)=O(nlog_2n)$

### 4. 解答

（1） 基本语句$k=k+10*i$共执行了$n-2$次，所以$T(n)=O(n)$  
（2） 设循环体共执行$t$次，每循环一次，$y$加$1$，故$t^2≤n$，得$T(n)=O(n^{1/2})$  
（3） 基本语句$x++$的执行次数为$T(n)=O(\sum_{i=1}^{n} \sum_{j=1}^{i} \sum_{k=1}^{j})=O(\frac{1}{6}n^3)=O(n^3)$  
（4） 内循环执行$m$次，外循环执行$n$次，共执行了$m×n$次。故$T(m,n)=O(m×n)$

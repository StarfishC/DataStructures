# 数据结构

**概览：**

**[:question: 数据结构的定义是什么](#定义)**  
**[:question: 抽象数据类型是什么](#抽象数据类型-abstract-data-type)**  
**[:question: 算法是什么以及如何评估算法](#算法algorithm)**  
**[:question: 用例子说明算法的重要性](#算法algorithm)**

## 定义

**定义一**：数据结构是 $ADT$ 的物理实现 _（《数据结构与算法分析》-Clifford A.Shaffer）_

**定义二**：数据结构描述的是按照一定逻辑关系组织起来的待处理数据元素的表示及相关操作，涉及数据的 **_逻辑结构_**、数据的 **_存储结构_** 和数据的 **_运算_** _（《数据结构与算法》- 张铭）_

- 逻辑结构：具体问题中抽象出来的数据模型，反映了事物的组成结构和事物之间的逻辑关系  
  逻辑结构可以用一个二元组$B=(K,R)$表示，$K$是数据结点组成的有穷集合；关系$R$是定义在集合$K$上的一组二元关系。常见的结构有线性结构、树形结构、图结构  
  _例如：r 表示前驱关系时，<k,k'>表示 k 是 k'的前驱，k'是 k 的后继_
- 存储结构：各种逻辑结构在计算机中的物理存储表示  
  常用的基本存储映射方法有顺序方法、链式方法、索引方法和散列方法

  - 顺序方法：把逻辑上相邻的元素存储在物理位置上也相邻的存储单元中，元素之间的关系由存储关系来体现。优点是可以实现随机存储，每个元素占用最少的存储空间；缺点是只能使用相邻的一整块存储单元，因此可能产生较多的外部碎片
  - 链式方法：不要求逻辑上相邻的元素在物理位置上也相邻，借助指示元素存储地址的指针来表示元素之间的逻辑关系。优点是不会出现碎片现象，能充分利用所有存储单元；缺点是每个元素因存储指针而占用额外的存储空间，且只能顺序存取
  - 索引方法：在存储元素信息时，还建立附加的索引表。索引表中的每项成为索引项，索引项的一般形式是（关键字，地址）。优点是检索速度快；缺点是附加的索引表额外占用存储空间。另外，增删数据时也要修改索引表，因而花费较多的时间
  - 散列方法：根据元素的关键字直接计算出该元素的存储地址，又称哈希（Hash）方法。优点是检索、增删结点的操作都很快；缺点是若散列函数不好，则可能出现元素存储单位的冲突，而解决冲突会增加时间和空间开销

- 运算

## 抽象数据类型 _(Abstract Data Type)_

- 概念
  - 数据类型
    - 数据对象集
    - 数据集合相关联的操作集
  - 抽象：描述数据类型的方法不依赖于具体实现
    - 与存放数据的机器无关
    - 与数据存储的物理结构无关
    - 与实现操作的算法和编成语言无关
- 表示$(D,R,P)$

  ```c
  ADT 抽象数据类型名{
    数据对象D:<数据对象的定义>
    数据关系R:<数据关系的定义>
    基本操作P:<基本操作的定义>
  }
  ```

- 例子：“矩阵”的抽象数据类型定义

  - 类型名称：矩阵$(Matrix)$
  - 数据对象集：一个 $M×N$ 的矩阵$A_{M×N}=(a_{ij})(i=1,...,M;j=1,...,N)M×N$ 个三元组$<a,i,j>$构成，其中 $a$ 是矩阵元素的值，$i$ 是元素所在的行号，$j$ 是元素所在的列号
  - 操作集：对任意矩阵 $A、B、C ∈ Matrix$，以及整数 $i、j、M、N$

    ```cpp
      Matrix Create(int M, int N); // 返回一个 M×N 的空矩阵；
      int GetMaxRow(Matrix A);     //返回矩阵 A 的总行数；
      int GetMaxCol(Maxtrix A);    //返回矩阵 A 的总列数；
      ElementType GetEntry(Martix A, int i, int j);  // 返回矩阵A的第i行、第j列的元素
      ......
    ```

## 算法 _(Algorithm)_

1. 概念

   - 一个有限指令集
   - 接受一些输入（有些情况下不需要输入）
   - 产生输出
   - 一定在有限步骤后终止（有穷性）
   - 每一条指令必须（确定性）
     - 有充分明确的目标，不可以有歧义
     - 计算机能处理的范围之内
     - 描述不应依赖于任何一种计算机语言以及具体的实现手段

2. 常用分类

   - 穷举法：在一个可能存在可行状态的状态全集中依次遍历所有的元素，并判断是否为可行状态
   - 回溯法：一步一步向前试探，有多种选择时任意选择一种，只要可行就继续向前，一旦失败时就后退回来选择其他的可能性  
     比如：深度优先搜素
   - 分治法和递归法：把一个规模较大的问题划分成相似的小问题，各个求解，再得到整个问题的解  
     比如：快速排序、归并排序、二分法检索
   - 贪心法：试图通过局部最优解得到全局最优解  
     比如：最小生成树的$Prim$算法、$Krusal$算法、最短路径的$Dijkstra$算法
   - 动态规划：把大问题分解为若干小问题，通过求解子问题来得到原问题的解，与分治法不同的是，适合用于动态规划求解的问题，经分解得到的子问题往往不是相互独立的。一般用一个表来记录所有已解的子问题的答案，不管该子问题是否以后被利用，只要它被计算过，就将其结果填入表中，这就是动态规划的基本思路，而分治法解决这类问题可能会重复计算某些子问题  
     比如：$Floyd$算法
   - 分支界限法：在表示问题空间的树上进行系统搜索时采用广度优先策略，同时利用最优解属性的上下界来控制搜索分支

3. 算法指标

   - 空间复杂度 $S(n)$：根据算法写成的程序在执行时占用存储单元的长度。
   - 时间复杂度 $T(n)$：根据算法写成的程序在执行时耗费时间的长度。

   在分析一般算法的效率时，经常关注下面两种复杂度：最坏情况复杂度和平均复杂度

4. 复杂度的渐进表示

   - 大$O$表示法 - 最小上界  
     $f(n)=O(g(n))$ 表示存在常数 $C>0,N>0$ 使得当 $n≥N$ 时有 $f(n)≤C·g(n)$
   - $Ω$表示法 - 最大下界  
     $f(n)=Ω(g(n))$ 表示存在常数 $C>0,N>0$ 使得当 $n≥N$ 时有 $f(n)≥C·g(n)$
   - $Θ表示法$ - 上下界相同  
     $f(n)=Θ(g(n))$ 表示存在常数$C_1>0,C_2>0,N>0$ 使得当$n≥N$时有$C_1g(n)≤f(n)≤C_2g(n)$，即同时有 $f(n)=O(g(n))$ 和 $f(n)=Ω(g(n))$

   附：$n! > 2^n > n^2 > nlogn > n > logn$

5. 复杂度的分析

   - 循环主体中的变量参与循环条件的判断  
     例 1：

     ```cpp
      for(i = sum = 0; i < n; i++)
      sum += a[i]
     ```

     主要操作为赋值，时间代价主要体现在赋值操作上。循环开始时有两次赋值，分别对$i、sum$进行；循环进行了$n$次，每次循环执行两次赋值，分别对$sum、i$进行。总共$2+2n$次赋值操作，渐进复杂度为$O(n)$

     例 2：

     ```cpp
      int i = 1;
      while(i <= n)
        i = i * 2;
     ```

     $i$乘以$2$的次数正好是主体语句的执行次数$t$，因此有$2^t≤n$，取对数后得$t≤log_2n$，则$T(n)=O(log_2n)$

     例 3：

     ```cpp
      int y = 5;
      while((y+1)*(y+1) < n)
        y = y + 1;
     ```

     $y$加$1$得次数正好与$T(n)$成正比，记$t$为该程序执行次数并令$t=y-5$，有$y=t+5$，$(t+5+1)(t+5+1)<n\quad => \quad t<\sqrt{n}-6$，即$T(n)=O(\sqrt{n})$

   - 循环主体中得变量与循环条件无关

     此类题可采用数学归纳法或直接累计循环次数。多层循环时从内到外分析，忽略单步语句、条件判断语句、只关注主体语句的执行次数。此类问题有可分为递归和非递归程序

     例 1：递归 - 一般使用公式进行递推

     ```cpp
       int fact(int n)
       {
         if(n <= 1) return 1;
         return n*fact(n-1);
       }
     ```

     $T(n)=1+T(n-1)=1+1+T(n-2)=...=n-1+T(1)$即$T(n)=O(n)$

     例 2：非递归 - 可以直接累计次数

     ```cpp
       void fun(int n)
       {
         int i = 0;
         while(i*i*i <= n)
           i++;
       }
     ```

     基本运算为$i++$，设执行次数为$t$，有$t×t×t≤n$，即$t^3<n$。故有$t≤\sqrt[3]{n}$，即$T(n)=O(\sqrt[3]{n})$

## 应用实例

最大子列和问题：给定 $N$ 个整数的序列${A_1,A_2,...,A_N}$，求函数$f(i,j)=max\{0,\sum_{k=i}^{j}A_k\}$的最大值。_[code MaxSubseqSum.cpp](./src/Note/MaxSubseqSum.cpp)_

- 算法 1：暴力法

  时间复杂度$O(n^3)$

  ```cpp
  int MaxSubseqSum1(int A[], int N)
  {
    int ThisSum, MaxSum = 0;
    for(int i = 0; i < N; i++)          // i是子列左端位置
    {
        for(int j = i; j < N; j++)      // j是子列右端位置
        {
            ThisSum = 0;                // A[i]到A[j]的子列和
            for(int k = i; k <= j; k++)
                ThisSum += A[k];
            if(ThisSum > MaxSum)
                MaxSum = ThisSum;
        }
    }
    return MaxSum;
  }
  ```

- 算法 2：暴力法（优化）

  时间复杂度$O(n^2)$

  ```cpp
  int MaxSubseqSum2(int A[], int N)
  {
    int ThisSum, MaxSum = 0;
    for(int i = 0; i < N; i++)
    {
        ThisSum = 0;
        for(int j = i; j < N; j++)
        {
            ThisSum += A[j];    // 对于相同的i不同的j。只需要在j-1循环的基础上累加1项即可
            if(ThisSum > MaxSum)
                MaxSum = ThisSum;
        }
    }
    return MaxSum;
  }
  ```

- 算法 3：分而治之

  时间复杂度 $O(NlogN)$

  $$
  \begin{aligned}
  T(N) &= 2T(N/2)+cN, T(1)=O(1) \\
       &= 2[2T(N/2^2) + cN/2] + cN \\
       &= 2^kO(1) + ckN  \quad\quad其中N/2^k = 1 \\
       &=O(NlogN)
  \end{aligned}
  $$

  ```cpp
  inline int Max3(int A, int B, int C)
  {
    /* 返回3个整数中的最大值 */

    return A > B ? A > C ? A : C : B > C ? B : C;
  }

  int DivideAndConquer(int List[], int left, int right)
  {
  /_ 分治法求 List[left]到 List[right]的最大子列和 _/

    int MaxLeftSum, MaxRightSum;                // 左右两边的最大值
    int MaxLeftBorderSum, MaxRightBorderSum;    // 存放跨分界线的结果

    int LeftBorederSum, RightBorderSum;
    int center, i;

    if(left == right)
    {
        // 递归终止条件：子列只有一个数字
        if(List[left] > 0) return List[left];
        else return 0;
    }

    // 找到中分点
    center = (left + right) / 2;
    // 递归求两边子列的最大和
    MaxLeftSum = DivideAndConquer(List, left, center);
    MaxRightSum = DivideAndConquer(List, center+1, right);

    // 求跨分界线的最大子列和
    MaxLeftBorderSum = 0;
    LeftBorederSum = 0;
    for(i = center; i >= left; i--)
    {
        // 从中线向左扫描
        LeftBorederSum += List[i];
        if(LeftBorederSum > MaxLeftBorderSum)
            MaxLeftBorderSum = LeftBorederSum;
    }   // 左边扫描结束
    // 同理右边扫描
    MaxRightBorderSum = 0;
    RightBorderSum = 0;
    for(i = center + 1; i <= right; i++)
    {
        RightBorderSum += List[i];
        if(RightBorderSum > MaxRightBorderSum)
            MaxRightBorderSum = RightBorderSum;
    }

    return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
  }

  int MaxSubseqSum3(int A[], int N)
  {
  return DivideAndConquer(A, 0, N-1);
  }
  ```

- 算法 4：在线处理

  时间复杂度 $O(n)$

  ```cpp
  int MaxSubseqSum4(int A[], int N)
  {
      int ThisSum, MaxSum;
      ThisSum = MaxSum = 0;
      for(int i = 0; i < N; i++)
      {
          ThisSum += A[i];                // 向右累加
          if(ThisSum > MaxSum)
              MaxSum = ThisSum;
          else if(ThisSum < 0)            // 当前子列和为负，则不可能使后面的部分增大
              ThisSum = 0;
      }
      return MaxSum;
  }
  ```

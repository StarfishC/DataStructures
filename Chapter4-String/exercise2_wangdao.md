# 第四章 字符串

## 习题 - 选择

### 1. 设有两个串$S_1$和$S_2$，求$S_2$在$S_1$中首次出现的位置的运算称为（）

**&emsp;&emsp;A. 求子串
&emsp;&emsp;&emsp;&emsp;B. 判断是否相等**  
**&emsp;&emsp;C. 模式匹配
&emsp;&emsp;&emsp;&emsp;D. 连接**

### 2. $KMP$算法的特点是在模式匹配时指示主串的指针（）

**&emsp;&emsp;A. 不会变大
&emsp;&emsp;&emsp;&emsp;B. 不会变小**  
**&emsp;&emsp;C. 都有可能
&emsp;&emsp;&emsp;&emsp;D. 无法判断**

### 3. 设主串的长度为$n$，字串的长度为$m$，则简单的模式匹配算法的时间复杂度为（），$KMP$算法的时间复杂度为（）

**&emsp;&emsp;A. $O(m)$
&emsp;&emsp;&emsp;&emsp;B. $O(n)$**  
**&emsp;&emsp;C. $O(mn)$
&emsp;&emsp;&emsp;&emsp;D. $O(m+n)$**

### 4. 已知串$S='aaab'$，其$next$数组的值为（）

**&emsp;&emsp;A. $0123$
&emsp;&emsp;&emsp;&emsp;B. $0112$**  
**&emsp;&emsp;C. $0231$
&emsp;&emsp;&emsp;&emsp;D. $1211$**

### 5. 串$'ababaaababaa'$的$next$数组是（）

**&emsp;&emsp;A. $01234567899$
&emsp;&emsp;&emsp;&emsp;B. $012121111212$**  
**&emsp;&emsp;C. $011234223456$
&emsp;&emsp;&emsp;&emsp;D. $0123012322345$**

### 6. 串$'ababaaababaa'$的$next$数组为（）

**&emsp;&emsp;A. $-1,0,1,2,3,4,5,6,7,8,8,8$
&emsp;&emsp;&emsp;&emsp;B. $-1,0,1,0,1,0,0,0,0,1,0,1$**  
**&emsp;&emsp;C. $-1,0,0,1,2,3,1,1,2,3,4,5$
&emsp;&emsp;&emsp;&emsp;D. $-1,0,1,2,-1,0,1,2,1,1,2,3$**

### 7. 串$'ababaaababaa'$的$nextval$数组为（）

**&emsp;&emsp;A. $0,1,0,1,1,2,0,1,0,1,0,2$
&emsp;&emsp;&emsp;&emsp;B. $0,1,0,1,1,4,1,1,0,1,0,2$**  
**&emsp;&emsp;C. $0,1,0,1,0,4,2,1,0,1,0,4$
&emsp;&emsp;&emsp;&emsp;D. $0,1,1,1,0,2,1,1,0,1,0,4$**

### 8.【2015 统考真题】已知字符串$S='abaabaabacacaabaabcc'$，模式串$t$为'abaabc'。采用$KMP$算法进行匹配，第一次出现“失配”（$s[i]≠s[j]$）时，$i=j=5$，则下次开始匹配时，$i$和$j$的值分别是（）

**&emsp;&emsp;A. $i=1,j=0$
&emsp;&emsp;&emsp;&emsp;B. $i=5,j=0$**  
**&emsp;&emsp;C. $i=5,j=2$
&emsp;&emsp;&emsp;&emsp;D. $i=6,j=2$**

### 9.【2016 统考真题】设主串$T='abaabaabcabaabc'$，模式串$S='abaabc'$，采用$KMP$算法进行模式匹配，到匹配成功时为止，在匹配过程中进行的单个字符间的比较次数是（）

**&emsp;&emsp;A. $9$
&emsp;&emsp;&emsp;&emsp;B. $10$**  
**&emsp;&emsp;C. $12$
&emsp;&emsp;&emsp;&emsp;D. $15$**

## 综合应用题

### 1. 字符串模式匹配的$KMP$算法中，求模式的$next$数组值得定义如下公式

$$
next[j]=
\left\{\begin{matrix}
0, & j=1\\
max{k|1<k<j  且 'p_1...p_{k-1}'='p_{j-k+1}...p_{j-1}'}, & 此集合不空时 \\
 1,&其他情况
\end{matrix}\right.
$$

**（1）当$j=1$时，为什么要取$next[1]=0$**  
**（2）为什么要取$max{k}$，$k$最大值是多少？**  
**（3）其他情况是什么情况，为什么取$next[j]=1？$**

### 2. 设有字符串$S='aabaabaabaac', P='aabaac'$

**（1）求出$P$的$next$数组**  
**（2）若$S$作主串，$P$作模式串，试给出$KMP$算法的匹配过程**

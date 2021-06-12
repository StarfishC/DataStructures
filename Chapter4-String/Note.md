# 字符串

**概览：**

[:question: 字符串的匹配模式](#字符串的匹配模式)

## 字符串的匹配模式

### 暴力匹配模式算法

1. **概念**

   把模式$P$的字符依此与目标$T$的相应字符进行比较。首先从首字符开始，依此将两个字符串对应位置上的字符进行比较；当某次比较失败，则把模式$P$对于$T$向右移动一个字符位置，重新开始下一趟匹配；如此重复，直到某趟配串成功，或者比较到目标串的结束也没出现“配串”的情况，则匹配失败

2. **例子**

   > 目标串：$"abacaabaccabacabaa"$，匹配串：$"abacab"$
   >
   > | a   | b              | a   | c              | a   | a              | b              | a   | c              | c              | a   | b   | a   | c   | a   | b   | a     | a   |
   > | --- | -------------- | --- | -------------- | --- | -------------- | -------------- | --- | -------------- | -------------- | --- | --- | --- | --- | --- | --- | ----- | --- |
   > | a   | b              | a   | c              | a   | <u>**_b_**</u> |
   > |     | <u>**_a_**</u> | b   | a              | c   | a              | b              |
   > |     |                | a   | <u>**_b_**</u> | a   | c              | a              | b   |
   > |     |                |     | <u>**_a_**</u> | b   | a              | c              | a   | b              |
   > |     |                |     |                | a   | <u>**_b_**</u> | a              | c   | a              | b              |
   > |     |                |     |                |     | a              | b              | a   | c              | <u>**_a_**</u> | b   |
   > |     |                |     |                |     |                | <u>**_a_**</u> | b   | a              | c              | a   | b   |
   > |     |                |     |                |     |                |                | a   | <u>**_b_**</u> | a              | c   | a   | b   |
   > |     |                |     |                |     |                |                |     | <u>**_a_**</u> | b              | a   | c   | a   | b   |
   > |     |                |     |                |     |                |                |     |                | <u>**_a_**</u> | b   | a   | c   | a   | b   |
   > |     |                |     |                |     |                |                |     |                |                | a   | b   | a   | c   | a   | b   | :100: |

3. **时间复杂度**

   最好情况：一开始就匹配成功，$O(P)$  
   最坏情况：每趟都是匹配串的最后一个字符不匹配，即每趟都需要进行$|P|$次比较，再把模式右移一位，再次从模式头开始比较，最多需要$(|T|-|P|+1)$趟，因此总共需要比较$|P|(|T|-|P|+1)$次，即$O(|T||P|)$  
   平均情况：平均代价同时依赖于目标和模式中字符的分布概率。例如，假设在一个字符串中只允许使用两种字符，那么使用任一字符的概论为$1/2$。对于$j$趟扫描来说，仅比较一次的概论为$1/2$，比较两次的概论为$1/2×1/2=1/4$。对于长度为$m$的模式而言，比较$m$次的概率为$1/2×...×1/2=2^{-m}$，因此平均情况下，第$j$趟扫描的比较次数为$\sum_{k=1}^{|P|}\frac{k}{2^k}<2$，因此平均比较次数为$2(|T|-|P|+1)<2|T|$

4. **代码**

   _[code 暴力匹配](./src/Note/暴力匹配.cpp)_

   ```cpp
   #include <cstring>
   #include <cassert>
   #include <string>
   #include <iostream>

   using namespace std;

   int NaiveStrMatch(const string &T, const string &P)
   {
       int i = 0;                  // 模式的下标变量
       int j = 0;                  // 目标的下标变量
       int pLen = P.length();      // 模式的长度
       int tLen = T.length();      // 目标的长度
       if(tLen < pLen)             // 如果目标长度小于模式长度，匹配失败
           return -1;
       while(i < pLen && j < tLen)
       {
           if(T[j] == P[i])
               i++, j++;
           else
           {
               j = j - i + 1;      // 减掉匹配成功的i，往后挪一位
               i = 0;
           }
       }
       if(i >= pLen)
           return (j-pLen);        // 最后匹配成功时候j已经多加一次1了
       return -1;
   }
   ```

### KMP 模式匹配算法

> 通俗易懂视频（**B**站**UP**-正月点灯笼）：[KMP 算法 1](https://www.bilibili.com/video/BV1Px411z7Yo) + [KMP 算法 2](https://www.bilibili.com/video/BV1hW411a7ys/)

1. **理论**

   用例子简单描述，目标$"ABABCABABD"$，模式$"ABABD"$
   |0|1|2|3|4|5|6|7|8|9|
   |-|-|-|-|-|-|-|-|-|-|
   |**A**|**B**|**A**|**B**|**C**|**A**|**B**|**A**|**B**|**D**|
   |A|B|A|B|D|
   |||A|B|A|B|D|

   当$i=4$时，$C,D$不匹配。此时$"ABAB"$有最大公共前缀$"AB"$，而$"AB"$(序号$2,3$位置）在目标中已完全匹配，下次匹配时候可跳过，也即下次匹配将$P$右移两个位置,使$C,A$进行比较，其实每次右移的位数存在且与目标串无关，仅依赖于模式本身，所以如何预先处理模式本身成为算法的重点。

   **KMP 算法：** 就是利用最大公共前后缀的方式，简化匹配的过程，其核心在于如何计算当某个字符匹配失败时，从哪个位置再次进行匹配，即如何计算模式的`next`数组

2. **`next`数组的计算**

   例：$abcdaabcab$  
   |`next`|字符|说明|
   |-|-|-|
   |$-1$|$a$|匹配第一个字符$a$失败时，字串不匹配，说明模式$P$和目标$T$都需要移动一个位置|
   |$0$|$ab$|匹配尾字符$b$失败时，$a$无最大公共前后缀|
   |$0$|$abc$|匹配尾字符$c$失败时，$ab$无最大公共前后缀|
   |$0$|$abcd$|匹配尾字符$d$失败时，$abc$无最大公共前后缀|
   |$0$|$abcda$|匹配尾字符$a$失败时，$abcd$无最大公共前后缀|
   |$1$|$abcdaa$|匹配尾字符$a$失败时，$abcda$最大公共前后缀为$a$|
   |$1$|$abcdaab$|匹配尾字符$b$失败时，$abccdaa$最大公共前后缀为$a$|
   |$2$|$abcdaabc$|匹配尾字符$c$失败时，$abcdaab$最大公共前后缀为$ab$|
   |$3$|$abcdaabca$|匹配尾字符$a$失败时，$abcdaabc$最大公共前后缀$abc$|
   |$1$|$abcdaabcab$|匹配尾字符$b$失败时，$abcdaabca$最大公共前后缀为$a$|

   可得`next`数组为$[-1,0,0,0,0,1,1,2,3,1]$  
   这样求出的`next`数组还可以进一步优化，例如，若求出的$next[i]=k$，当匹配时发现$P_i≠T_j$，则需要把模式右移$i-k$位，即用$P_k$与$T_j$进行比较。若$P_i=P_k$，则可知$P_k≠T_j$，还需再右移，用$P_{next[k]}$来与$T_j$进行比较。这样，模式串$"abcdaabcab"$可以优化的下标位置为$4,6,7,9$，优化后的`next`数组为$[-1,0,0,0,-1,1,0,0,3,0]$

3. **时间复杂度**

   计算`next`数组的时间复杂度为$O(|P|)$，整个**KMP**的时间代价为$O(|P|+|T|)$，在模式长度远小于目标长度时，基本上为$O(|T|)$。此外，对于同一个模式$P$，由于`next`是预先计算的，其结果可以在**KMP**算法中被多次使用

4. **代码**

   _[code KMP 算法](./src/Note/KMP.cpp)_

   **B** 站：

   ```cpp
   void prefix_table(char pattern[], int prefix[], int n)
   {
       prefix[0] = 0;
       int len = 0;
       int i = 1;
       while(i < n)
       {
           if(pattern[i] == pattern[len])
           {
               len++;
               prefix[i] = len;
               i++;
           }
           else
           {
               if(len > 0)
                   len = prefix[len-1];
               else
                   prefix[i] = len;            // 此时len=0
               i++;
           }
       }

       // 前缀表最后一项可以不需要，结果后移一位，第一位改成-1
       for(int i = n-1; i > 0; i--)
           prefix[i] = prefix[i-1];
       prefix[0] = -1;
       cout << "prefix_table: ";
       for(int i = 0; i < n; i++)
           cout << prefix[i] << " ";
       cout << endl;
   }

   void KMP(char text[], char pattern[])
   {
       int m = strlen(text);
       int n = strlen(pattern);
       int *next = (int*)malloc(sizeof(int)*n);
       prefix_table(pattern, next, n);

       int i = 0;
       int j = 0;
       while(i < m){
           if(j == n-1 && text[i] == pattern[j])
           {
               cout << "Found pattern at " << i - j << endl;
               j = next[j];
           }
           if(text[i] == pattern[j])
               i++,j++;
           else
           {
               j = next[j];
               if(j == -1)
               {
                   i++;
                   j++;
               }
           }
       }
   }
   ```

   张铭教材（优化版）：

   ```cpp
   int *findNext(string P)
   {
       int i = 0;
       int k = -1;
       int m = P.length();
       assert(m > 0);
       int *next = new int[m];
       next[0] = -1;
       while(i < m)
       {
           while(k >= 0 && P[i] != P[k])
               k = next[k];
           i++;
           k++;
           if(i == m)
               break;
           if(P[i] == P[k])
               next[i] = next[k];          // P[i]和P[k]相等，优化
           else
               next[i] = k;                // 不需要优化
       }
       cout << "findnext: ";
       for(int i = 0; i < m; i++)
           cout << next[i] << " ";
       cout << endl;
       return next;
   }

   int KMPStrMatching(const string &T, const string &P, int *N)
   {
       int i = 0;                      // 模式下标变量
       int j = 0;                      // 目标下标变量
       int pLen = P.length();          // 模式长度
       int tLen = T.length();          // 目标长度
       if(tLen < pLen)                 // 模式长度大于目标，匹配失败
           return -1;
       while(i < pLen && j < tLen)
       {
           if(i == -1 || T[j] == P[i])
               i++, j++;
           else
               i = N[i];
       }
       if(i >= pLen)
           return j-pLen;
       else return -1;
   }
   ```

# 第三章 字符串

:warning: _注：缺少的题号表示习题重复_

## 4.1 教材习题

### 4.1.1 已知：$s="(xyz)+*"，t="(x+z)*y"$。试利用连接、抽子串和置换等基本运算，将 $s$转换为 $t$

> **解答：** _[code 4-1-1.cpp](./src/exercise1_zhangming/4-1-1.cpp)_
>
> ```cpp
> #include <string>
> #include <iostream>
> using namespace std;
>
>
> int main()
> {
>     string s = "(xyz)+*";
>     string t = "(x+z)*y";
>     char tmp = s[2];
>     s.replace(2, 1, 1, s[5]);
>     s.replace(5, 1, 1, s[6]);
>     s.replace(6, 1, 1, tmp);
>     cout << s << endl;
>     return 0;
> }
> ```

### 4.1.2 设$S_1,S_2$为串，请给出使$S_1+S_2=S_2+S_1$成立的所有可能的条件（$+$为连接运算）

> **解答：**
>
> - 当 $s_1=s_2$ 时
> - 当 $s_1≠s_2$ 时，需 $s_1$ 或 $s_2$ 其中一个为空串
> - 当 $s_1≠s_2$ 且 $s_1,s_2$ 均不空时，需 $s_1=n×s_2$，或 $s_2=n×s_1$，其中 $n$ 大于等于 $1$，如 $s_1="AB"$，$s_2="ABAB"$

### 4.1.3 编写一个程序，统计在输入字符串中各个不同字符出现的频度并将结果存入文件，字符串中的合法字符为 $A-Z$ 这 $26$ 个字母和 $0-9$ 这 $10$ 个数字

> **解答：** _[code 4-1-3.cpp](./src/exercise1_zhangming/4-1-3.cpp)_
>
> （1）可使用大小为 $36$ 的数组，当字符为 $A-Z$ 时，选择位置 $0-25$，当字符为 $0-9$ 时，选择位置 $26-36$  
> （2）也可使用链表，能节约不存在的字符空间，但是对于字符数增加操作不方便
>
> ```cpp
> int* Statistics(string s)
> {
>     int *ret = new int[36]();
>     for(auto i = 0; i < s.size(); i ++)
>     {
>         if(s[i] >= 65 && s[i] <= 90)
>             // 属于A-Z，对应数组位置0-25，即减65
>             ret[s[i] - 65] += 1;
>         else if(s[i] >= 48 && s[i] <= 57)
>             // 属于0~9，对应数组位置26-35，即减48-26=22
>             ret[s[i] - 22] += 1;
>     }
>     return ret;
> }
> ```

### 4.1.4 $S="S_1S_2...S_n"$是一个长度为 $n$ 的字符串，存放在一个数组中，编程序将 $S$ 改造后输出

**（1）将 $S$ 的所有第偶数个字符按照其原来的下表从大到小的次序放在 $S$ 的后半部分**  
**（2）将 $S$ 的所有第奇数个字符按照其原来的下表从小到大的次序放在 $S$ 的后半部分**  
**&emsp;例如, $S="ABCDEFGHIJKL"$, 则改造后的 $S="ACEGIKLJHFDB"$**

> **解答：** _[code 4-1-4.cpp](./src/exercise1_zhangming/4-1-4.cpp)_
>
> ```cpp
> void Solution(char s[], int n)
> {
>     for(int i = 1; i <= n/2; i++)
>     {
>         char tmp = s[i];
>         for(int j = i; j <= n-i; j++) // 移动字符
>             s[j] = s[j+1];
>         s[n-i] = tmp;
>     }
> }
> ```

### 4.1.5 设计算法判断一个字符串 $s$ 是否对称。对称则返回 $1$，否则返回 $0$；如 $f("abba")$返回 $1$，$f("abab")$返回 $0$

> **解答：** _[code 4-1-5.cpp](./src/4-1-5.cpp)_
>
> 思路：对比第一个字符和最后一个字符，第二个和倒数第二个...
>
> ```cpp
> int Solution(string s)
> {
>     auto n = s.size();
>     for(auto i = 0; i < s.size()/2; i++)
>         if(s[i] != s[n-1-i])
>             return 0;
>     return 1;
> }
> ```

### 4.1.6 编写算法，求所有包含在串 $s$ 中而不包含在串 $t$ 中的字符（$s$ 中重复的字符只能选一个）构成新的串 $r$，以及 $r$ 中每个字符在 $s$ 中第一次出现的位置

> **解答：** _[code 4-1-6.cpp](./src/exercise1_zhangming/4-1-6.cpp)_
>
> ```cpp
> #include <string>
>
> using namespace std;
>
> void Solution(const string &s, const string &t, string &r, int pos[])
> {
>     // C++1
>     int p = 0;
>     for(auto ch:s)
>     {
>         if(t.find(ch) == -1 && r.find(ch) == -1)
>         {   // t中不存在ch
>             r += ch;
>             pos[p++] = s.find(ch);
>         }
>     }
>
>     /* for(size_t i = 0; i < s.size(); i++){
>         if(t.find(s[i]) == -1 && r.find(s[i]) == -1){
>             r += s[i];
>             pos[p++] = i;       // 这里不用再次调用find函数
>         }
>     } */
> }
> ```

### 4.1.7 设计一个线性算法来判断串 $T$ 是否是另外一个串 $T'$的循环反转，例如 $arc$ 和 $car$ 便互为循环反转

> **解答：** _[code 4-1-7.cpp](./src/exercise1_zhangming/4-1-7.cpp)_
>
> 思路：先找到 $T$ 第一个字符在 $T'$的位置，然后从 $T$ 的第一个位置与 $T'$找到位置开始匹配
>
> ```cpp
> #include <string>
>
> using namespace std;
>
> bool Solution(const string &T1, const string &T2)
> {
>     if(T1.size() != T2.size())
>         return false;
>     int pos = T2.find(T1[0]);
>     size_t size = T1.size();
>     for(size_t i = 0; i < size; i++)
>     {
>         if(T1[i] != T2[(i+pos) % size])
>             return false;
>     }
>     return true;
> }
> ```

### 4.1.8 编写算法，从字符串 $s$ 中删除所有和字符串 $t$ 相同的字串

> **解答：** _[code 4-1-8.cpp](./src/exercise1_zhangming/4-1-8.cpp)_
>
> 思路$1$：用$string$方法找到$t$，再替换  
> 思路$2$：用$kmp$算法找到$t$，再替换
>
> ```cpp
> #include <iostream>
> #include <string>
>
> #include "../../include/kmp.h"
>
> using namespace std;
>
> void DelSubStr1(string &s, const string t)
> {
>     int delsize = t.length();
>     int pos;
>     while((pos = s.find(t)) != -1)
>     {
>         s.replace(pos, delsize, "");
>         cout << s << endl;
>     }
> }
>
> // 利用Kmp算法
> void DelSubStr2(string &s, const string t)
> {
>     int *Next = findNext(t);
>     int pos = KMPStrMatching(s, t, Next);
>     while(pos != -1)
>     {
>         s.replace(pos, t.size(), "");
>         cout << s << endl;
>         pos = KMPStrMatching(s, t, Next);
>     }
> }
> ```

### 4.1.9 求字符串$"BAAABBBAA"$的特征向量，并与目标串$"BAAABBBCDDDCCHHHHBBBAAABBBAADD"$进行匹配，试画出匹配的过程示意图

> **解答：** _[code 4-1-9.cpp](./src/exercise1_zhangming/4-1-9.cpp)_
>
> **KMP** 算法，此处求解的特征向量与教材不同，可在 [KMP.cpp](./src/Note/KMP.cpp)查看不同
>
> ```txt
>                        B  A  A  A  B  B  B  A  A
> 可求得特征向量是next = [-1, 0, 0, 0, 0, 1, 1, 1, 2]
>
> B A A A B B B C D D D C H H H H B B B A A A B B B A A D D
> B A A A B B B A A
>               × j = next[j] = 1
>             B A A A B B B A A
>               × j = next[j] = 0
>               B A A B B B A A
>               × next[j] == -1    // i++, j++
>                 B A A B B A A
>                 × next[j] == -1
>                 ......
> B A A A B B B C D D D C H H H H B B B A A A B B B A A D D
>                                 B A A A B B B A A
>                                   × j = next[j] = 0
>                                   B A A A B B B A A
>                                     × j = next[j] = 0
>                                     B A A A B B B A A
>                                     // 匹配成功，i=27，j=8，位置=i-j=19
> ```
>
> ```cpp
> #include <iostream>
> #include <string>
>
> using namespace std;
>
> int* FindNext(string s)
> {
>     int *next = new int[s.length()];
>     next[0] = 0;            // 第0个为0
>     int i = 1;
>     int len = 0;
>     int n = s.length();
>     while(i < n){
>         if(s[i] == s[len])
>         {
>             len++;
>             next[i] = len;
>             i++;
>         }else
>         {
>             if(len > 0)
>                 len = next[len-1];
>             else
>             {
>                 next[i] = len;              // 此时len=0，也可写0
>                 i++;
>             }
>         }
>     }
>
>     // 最后一项可不需要，方便KMP算法，结果后移一位，且第一位改成-1
>     for(int i = n-1; i > 0; i--)
>         next[i] = next[i-1];
>     next[0] = -1;
>     return next;
> }
>
> int KMP(string text, string pattern)
> {
>     int m = text.length();
>     int n = pattern.length();
>     int *next = FindNext(text);
>
>     int i = 0;
>     int j = 0;
>     while(i < m)
>     {
>         if(j == n-1 && text[i] == pattern[j])
>         {
>             cout << "Found pattern at " << i - j << endl;
>             return i - j;
>             // j = next[j];         // 当查找所有符合匹配时可用
>         }
>         if(text[i] == pattern[j])
>             i++,j++;
>         else
>         {
>             j = next[j];
>             if(j == -1)
>             {
>                 i++;
>                 j++;
>             }
>         }
>     }
>     return -1;
> }
> ```

## 4.2 上机题

### 4.2.1 给出函数 $atoi(x)$的实现方法，其功能是将字符串 $x$ 转换为整数，字符串 $x$ 由 $0-9$ 十个数字和表示负数的$"-"$符号组成，返回值为整型数值

### 4.2.2 设计算法来统计一个输入字符串中所包含的整数个数，并输出这些数。假设输入的字符串既有数字又有非数字字符，如$\; ak123x456\; 17960?\; 302gef4563$，其中连续数字作为一个整体看成整数，例如其中的 $123$、$456$ 等

### 4.2.3 编写算法，对给定的字符串 $str$，返回其最长重复子串及其下标位置。例如 $str="abcdacdac"$，则字串$"cdac"$是 $str$ 的最长重复子串，下标为 $2$

### 4.2.4 字符串综合练习：编写一个简单行编辑程序，对文本文件进行插入、删除等修改操作。可以是类似于 `UNIX Vi` 或 `DOS Edlin` 的简单行编辑，要求实现以下功能

**（1）行出入**  
**（2）行删除**  
**（3）改变当前行指针**  
**（4）对于超过一屏的长文件，进行分页显示**  
**（5）基于模式匹配算法进行查找和替换**

要求和提示：  
&emsp;&emsp;1. 必须实现查找字符串的操作（用 KMP 或其他模式匹配算法），不允许用编程环境所提供的查找算法（可以用函数重载）  
&emsp;&emsp;2. 有能力同学可以支持"\*"、"?"等通配符  
&emsp;&emsp;3. 本题不要求做图形界面，建议大部分同学实现普通的字符界面编辑器，注意界面简单友好。也允许实现为 word 或 UltraEdit 那样的全屏幕编辑程序  
&emsp;&emsp;4. 允许使用编程环境提供的图形包、字符串类（例如 MFC、CEditView）  
&emsp;&emsp;5. 可以研究网上开源代码包，但最好不要直接采用，可以在详细说明自己引用了哪些包中哪些代码段的情况下，进行局部引用  
&emsp;&emsp;6. 统计自己编写的代码行数、开源代码包、编程环境生成的代码框架不能计算在内

## 4.3《学习指导》教材习题解答

### 4.3.1 设有字符串变量 `String A = " ", B = "MULE", C="OLD", D="MY"`; 请计算下列表达式

**(1) A + B**  
**(2) B + A**  
**(3) D + C + B**  
**(4) B.substr(3,2)**  
**(5) C.substr(1,1)**  
**(6) A.strlength()**  
**(7) D.strlength()**  
**(8) B.Find('L')**  
**(9) C.FindLast('D')**  
**(10) D.insert(B,2)**  
**(11) B.insert(B,1)**  
**(12) B.remove(2,2)**  
**(13) B.remove(0,5)**

> **解答：** _[code 4-3-1.cpp](./src/exercise1_zhangming/4-3-1.cpp)_
>
> (1) `A + B = " MULE"`  
> (2) `B + A = "MULE "`  
> (3) `D + C + B = "MYOLDMULE"`  
> (4) `B.substr(3,2) = "E"`  
> (5) `C.substr(1,1) = "L"`  
> (6) `A.strlength() = 1`  
> (7) `D.strlength() = 2`  
> (8) `B.Find('L') = 2`  
> (9) `C.FindLast('D') = 2`  
> (10) `D.insert(B,2) = "MYMULE"`  
> (11) `B.insert(B,1) = "MMULEULE"`  
> (12) `B.remove(2,2) = "MU"`  
> (13) `B.remove(0,5) = ""`
>
> ```cpp
> #include <string>
> #include <iostream>
>
>
> int main()
> {
>     using namespace std;
>     string A = " ";
>     string B = "MULE";
>     string C = "OLD";
>     string D = "MY";
>
>     cout << "A + B = " << A + B << endl;
>     cout << "B + A = " << B + A << endl;
>     cout << "D + C + B = " << D + C + B << endl;
>     cout << "B.substr(3,2) = " << B.substr(3, 2) << endl;
>     cout << "C.substr(1,1) = " << C.substr(1, 1) << endl;
>     cout << "A.strlength() = " << A.length() << endl;
>     cout << "D.strlength() = " << D.length() << endl;
>     cout << "B.Find('L') = " << B.find('L') << endl;
>     cout << "C.FindLast('D') = " << C.find_last_of('D') << endl;
>     cout << "D.insert(B,2) = " << D.insert(2, B) << endl;
>     cout << "B.insert(B,1) = " << B.insert(1, B) << endl;
>     return 0;
> }
> ```

### 4.3.2 计算下列字符串 $P$ 的特征向量 $N[i]$(注意串内字符间有空格隔开)

**（1）$"A\ B\ C\ D\ E\ F\ G\ H"$**  
**（2）$"I\ I\ I\ I\ I\ I\ I\ I"$**  
**（3）$"B\ A\ B\ B\ A\ B\ A\ B"$**

> **解答：**
>
> （1）$[-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]$  
> （2）$[-1, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]$  
> （3）$[-1, 0, 0, 0, 0, 1, 2, 1, 2, 3, 4, 5, 6, 3, 4]$

### 4.3.3 对 $S="a\ b\ a\ b\ b\ a\ a\ b\ a\ a",P="a\ a\ b"$，按 **KMP** 快速分析计算过程

> **解答：**
>
> 字符串按有空格处理
>
> ```txt
>               a  '' a  '' b
> 特征向量next=[-1, 0, 0, 1, 2]
>
> a b a b b a a b a a
> a a b
>   ×  i = 2, j = 2, j = next[j] = 0
>   a a b
>   ×  i = 2, j = 0, next[j] = -1
>    a a b
>    ×  i = 3, j = 0, j = next[j] = -1
>     a a b
>       ×  i = 6, j = 2, j = next[j] = 0
>
> a b a b b a a b a a
>       a a b
>       ×  i = 6, j = 0, next[j] = -1
>        a a b
>        ×  i = 7, j = 0, next[j] = -1
>         a a b
>         ×  i = 8, j = 0, next[j] = -1
>          a a b
>          ×  i = 9, j = 0, next[j] = -1
>           a a b         // 匹配成功，i=14，j=4，pos=i-j=10
> ```

## 4.4 《学习指导》教材上机题解答

### 4.4.1 设计一个算法，删去串 $S$ 中从第 $index$ 位置开始的共 $count$ 个字符，讨论对存储空间的处理，估计算法的执行时间

### 4.4.2 采用标注字符串写出程序，若 $x$ 和 $y$ 是两个字符串，找出 $x$ 中第一个不在 $y$ 中出现的字符及其位置

### 4.4.3 设计模式匹配算法，其中模板 $P$ 含有通配符"$?$"和"$\_$"。字符"$?$"可以和任意字符匹配，字符"$\_$"可以和任意子串匹配。搜索字符串 $S$，找出其中匹配模板 $P$ 的一个子串

## 4.5 《学习指导》增补习题

### 4.5.3 已知字符串$S_1$中存放一段英文，写出算法$format(S_1,S_2,S_3,n)$，将其按给定的长度 $n$ 格式化成两端对齐的字符串$S_2$，多余的字符送$S_3$

> **解答：** _[code 4-5-3.cpp](./src/exercise1_zhangming/4-5-3.cpp)_
>
> ```cpp
> #include <iostream>
> #include <string>
>
> using namespace std;
>
>
> void format(const string &s1, string &s2, string &s3, int n)
> {
>     if(s2.size() != 0 || s3.size() != 0)
>     {
>         cout << "s2,s3有非空串" << endl;
>         return;
>     }
>     if(s1.size() <= n)
>     {
>         s2 = s1;
>         s3 = "";
>         return;
>     }
>     for(size_t i = 0; i < s1.size(); i++)
>     {
>         if(i <= n-1)
>             s2 += s1[i];
>         else
>             s3 += s1[i];        // 也可以break之后用子串提取方式赋值
>     }
> }
> ```

### 4.5.4 编写算法比较两个字符串是否相等

> **解答：** _[code 4-5-4.cpp](./src/exercise1_zhangming/4-5-4.cpp)_
>
> 题目应该是用 $char$ 数组存放的字符串，而不是 $string$ 类。此题应该用 `C` 语言风格
>
> ```cpp
> int equal(char *s1, char *s2)
> {
>     int i = 0;
>     while(s1[i] != '\0' && s2[i] != '\0')
>     {
>         if(s1[i] != s2[i])
>             return 0;
>         i++;
>     }
>     if(s1[i] == '\0' && s2[i] == '\0')
>         return 1;
>     return 0;
> }
> ```

### 4.5.5 设计一个递归算法实现字符串逆序存储，要求不另设串存储空间

> **解答：** _[code 4-5-5.cpp](./src/exercise1_zhangming/4-5-5.cpp)_
>
> 思路：两两交换即可完成逆序存储，第一个和最后一个字符，第二个和倒数第二个...但此题要求递归
>
> ```cpp
> #include <cstring>
>
> void reverseString(char *s1, int n = 1)
> {
>     int len = strlen(s1);
>     if(len > n)
>     {
>         char tmp = s1[len-n];
>         s1[len-n] = s1[0];
>         s1[0] = tmp;
>         return reverseString(++s1, ++n);
>     }
> }
> ```

### 4.5.8 设计算法，将一个字符串拷贝到另一个字符串

> **解答：** _[code 4-5-8.cpp](./src/exercise1_zhangming/4-5-8.cpp)_
>
> ```cpp
> char* copystr(char *s1, const char *s2)
> {
>     // s2复制到s1
>     if(s1 == NULL || s2 == NULL)
>         return NULL;
>     char *addr = s1;
>     while((*s1++ = *s2++) != '\0');
>     return addr;
> }
> ```

### 4.5.11 假设以定长顺序存储结构表示串，试设计一个算法，求串 $s$ 中出现的第一个最长重复子串及其位置，并分析算法的时间复杂度

> **解答：** _[code 4-5-11.cpp](./src/exercise1_zhangming/4-5-11.cpp)_
>
> 类似求 **KMP** 算法中特征向量，但模式串要逐步缩短，如 $abcab$，需要求 $abcab,bcab,cab,ab$ 的特征向量，时间算法复杂度为$O(N^2)$
>
> ```cpp
> #include <string>
> #include <iostream>
>
> using namespace std;
>
>
> void CommonStr(const string &s, string &sub, int &loc)
> {
>     int next[50];
>     int i, j, k;
>     int len = 0;
>     int max = 0;
>     for(k = 1; k < s.size(); k++)
>     {
>         i = k;
>         j = k - 1;
>         next[k] = k - 1;
>         while(i < s.size()){
>             if(j == k - 1 || s[i] == s[j])
>             {
>                 i++,j++;
>                 next[i] = j;
>                 if(s[i] == s[j])
>                     len = j - k + 1;
>                 else
>                     len = j - k;
>             }else
>                 j = next[j];
>             if(len > max)
>             {
>                 loc = k;
>                 max = len;
>             }
>         }
>     }
>     for(int i = loc; i < loc + max; i++)
>         sub += s[i];
> }
> ```

## 4.6 《学习指导》增补上机题

### 4.6.3 函数 `void insert(char *s, char *t, int pos)`将字符串 $t$ 插入到字符串 $s$ 中，插入位置为 $pos$。请用 `C` 语言实现该函数。假设分配给字符串 $s$ 的空间足够让字符串 $t$ 插入。（说明：不得使用任何库函数）

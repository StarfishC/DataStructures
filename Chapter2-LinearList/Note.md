# 线性表

**概览：**

**[:question: 线性表的定义是什么](#线性表的定义)**  
**[:question: 如何描述线性表的抽象数据类型](#线性表的抽象数据类型描述)**  
**[:question: 如何实现线性表的存储](#线性表的存储实现)**

## 线性表的定义

由同类型数据元素构成有序序列的线性结构，表中元素的个数称为线性表的 **_长度_**；线性表没有元素时，称为 **_空表_**；表的起始位置称 **_表头_**，结束位置称 **_表尾_**。

## 线性表的抽象数据类型描述

- 类型名称：线性表
- 数据对象集是 $n(≥0)$个元素构成的有序序列$(a_1,a_2,...,a_n)$
- 操作集：线性表 $L∈List$,整数 $i$ 表示位置，元素 $X∈ElemetType$，线性表的基本操作主要有：
  - `List MakeEmpty()`：初始化一个空线性表 $L$；
  - `ElementType FindKth(int K, List L)`：根据位序 $K$，返回相应元素；
  - `int Find(ElementType X, List L)`：在线性表 $L$ 中查找 $X$ 第一次出现的位置；
  - `void Insert(ElementType X, int i, List L)`：在位序 $i$ 前插入一个新元素 $X$；
  - `void Delete(int i, List L)`：删除指定位序 $i$ 的元素；
  - `int Length(List L)`：返回线性表 $L$ 的长度 $n$。

## 线性表的存储实现

1. 线性表顺序存储实现（`C` 实现 _[code ArrList.c](src/Note/ArrList.c)_）

   - 结构

     ```cpp
     typedef struct LNode *List;
     struct LNode{
         ElementType Data[MAXSIZE];
         int Last;   // 线性表最后一个元素
     };
     ```

   - 初始化（建立空表）

     ```cpp
     List MakeEmpty(){
         List Ptrl;
         Ptrl = (List)malloc(sizeof(struct LNode));
         Ptrl->Last = -1;
         return Ptrl;
     }
     ```

   - 查找（平均比较次数为$(n+1)/2$，平均时间性能为 $O(n)$）

     ```cpp
     int Find(ElementType X, List Ptrl){
         int i = 0;
         while(i <= Ptrl->Last && Ptrl->Data[i] != X)
             i++;
         if(i > Ptrl->Last) return -1;    // 没找到返回-1
         else return i;                   // 返回的是存储位置
     }
     ```

   - 插入（第 $i(1≤i≤n+1)$个位置上插入一个值为 $X$ 的新元素），平均移动次数为 $n/2$，平均时间性能 $O(n)$

     ```cpp
     void Insert(ElementType X, int i, List Prtl){
         int j;
         if(Ptrl->Last == MAXSIZE-1){
             printf("表满");
             return;
         }
         if(i < 1 || i > Ptrl->Last+2){
             printf("位置不合法");
             return;
         }
         for(int j = Ptrl->Last; j >= i-1; j--)
             Ptrl->Data[j+1] = Ptrl->Data[j];      // i位置后的元素后挪
         Ptrl->Data[i-1] = X;
         Ptrl->Last++;
         return;
     }
     ```

   - 删除（删除表的第 $i(1≤i≤n)$个位置上的元素），平均移动次数$(n-1)/2$，平均时间性能 $O(n)$

     ```cpp
     void Delete(int i, List Prtl){
         if(i < 1 || i > Ptrl->Last+1){
             printf("不存在第%d个元素", i);
             return;
         }
         for(int j = i; j <= Ptrl->Last; j++)
             Ptrl->Data[j-1] = Ptrl->Data[j];
         Ptrl->Last --;
         return;
     }
     ```

2. 线性表的链式存储实现（`C` 实现 _[code LinkList.c](src/Note/LinkList.c)_）

   - 结构

     ```cpp
     typedef struct LNode *List;
     struct LNode{
         ElementType Data;
         List Next;
     };
     struct LNode L;
     List Ptrl;
     ```

   - 表长（$O(n)$）

     ```cpp
     int Length(List Ptrl){
         List p = Ptrl;
         int count;
         while(p){
             p = p->Next;
             count ++;
         }
         return count;
     }
     ```

   - 查找

     ```cpp
     // 按序号查找
     List FindKth(int K, List Ptrl){
         List p = Ptrl;
         int i = 1;
         while(p != NULL && i < K){
             p = p->Next;
             i++;
         }
         if(i == K) return p;
         else return NULL;
     }

     // 按值查找
     List Find(ElementType X, List Ptrl){
         List p = Ptrl;
         while(p != NULL && p->Data != X)
             p = p->Next;
         return p;
     }
     ```

   - 插入（在第 $i-1$ 个结点后插入一个值为 $X$ 的新结点）

     先构造一个新结点，用 $s$ 指向；  
     再找到链表的第 $i-1$ 个结点，用 $p$ 指向；  
     修改指针，插入结点($p$ 之后插入新结点是 $s$)

     ```cpp
     List Insert(ElementType X, int i, List Ptrl){
        List p, s;
        if(i == 1){                         // 新结点插入表头
            s = (List)malloc(sizeof(struct LNode));
            s->Data = X;
            s->Next = Ptrl;
            return s;
        }
        p = FindKth(i-1, Ptrl);             // 找第i-1个结点
        if(p == NULL){
            printf("参数i错");
            return NULL;
        }else{
            s = (List)malloc(sizeof(LNode));
            s->Data = X;
            s->Next = p->Next;
            p->Next = s;
            return Ptrl;
        }
     }
     ```

   - 删除（删除链表的第 $i$ 个位置上的结点）

     先找到链表的第 $i-1$ 个结点，用 $p$ 指向；  
     再用指针 $s$ 只想要被删除的结点($p$ 的下一个结点)；  
     修改指针，删除 $s$ 所指结点；  
     释放 $s$ 结点的空间。

     ```cpp
     List Delete(int i, List Ptrl){
         List p, s;
         if(i == 1){             // 删除的是第一个结点
             s = Ptrl;
             if(Ptrl != NULL) Ptrl = Ptrl->Next;
             else return NULL;
             free(s);
             return Ptrl;
         }
         p = FindKth(i-1, Ptrl);
         if(p == NULL){
             printf("第%d个结点不存在", i-1);
             return NULL;
         }else if(p->Next == NULL){
             printf("第%d个结点不存在", i);
             return NULL;
         }else{
             s = p->Next;
             p->Next = s->Next;
             free(s);
             return Ptrl;
         }
     }
     ```

   _附：  
   `C++` 线性表顺序实现 [code ArrList.cpp](./src/Note/ArrList.cpp)  
   `C++` 线性表链式实现 [code LinkList.cpp](./src/Note/LinkList.cpp)_

3. 顺序表和链表对比

    - 存取读写方式  
      > 顺序表可以顺序存取，也可以随机存取，链表智能从表头顺序存取元素
    - 逻辑结构与物理结构
      > 顺序存储时，逻辑上相邻的元素，对应的物理存储位置也相邻。而采用链式存储时，逻辑上相邻的元素，物理存储位置不一定相邻，对应的逻辑关系通过指针链接来表示
    - 查找、插入和删除
      > 按值查找时，顺序表无序时，两者的时间复杂度均为$O(n)$；顺序表有序时，可采用二分法查找，此时时间复杂度为$O(log_2n)$  
      > 按序号查找时，顺序表支持随机访问，时间复杂度为$O(1)$，而链表的平均时间复杂度为$O(n)$  
      > 顺序表的插入、删除操作，平均需要移动半个表长的元素。而链表的插入、删除操作，只需要修改相关结点的指针域即可
    - 空间分配
      > 顺序存储在静态存储分配情形下，一旦存储空间装满就不能扩充，若再加入新元素，则会出现内存溢出，因此需要预先分配足够大的存储空间。预先分配过大，可能会导致顺序表后部大量闲置。动态存储分配虽然存储空间可以扩充，但需要移动大量元素，导致操作效率降低，且若内存中没有更大的连续存储空间，则会导致分配失败  
      > 链式存储的结点空间只在需要时申请分配，只要内存有空间就可以分配，操作灵活、高效

   **不要使用顺序表场合**  
   线性表经常要插入/删除内容元素时，不宜使用顺序表，因为顺序表的插入/删除平均情况下需要移动一半的元素。此外，无法确定线性表长度最大值时，也不宜采用顺序表。

   **不要使用链表场合**  
   经常对线性表进行按位置访问，而且按位读取操作比插入/删除操作频繁时，不宜使用链表，因为顺链表扫描浏览比按顺序表都下标元素要费时。此外，指针本身的存储开销也要考虑，如果与结点内容所占空间相比，指针所占的比例较大时（超过 $1:1$），应慎重选择。

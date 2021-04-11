# 栈和队列

**概览：**

**:bulb: 栈**  
**[:question: 栈的定义是什么](#栈的定义)**  
**[:question: 如何描述栈的抽象数据类型](#栈的抽象数据类型描述)**  
**[:question: 如何实现栈的存储](#栈的存储实现)**

**:bulb: 队列**  
**[:question: 队列的定义是什么](#队列的定义)**  
**[:question: 如何描述队列的抽象数据类型](#队列的抽象数据类型描述)**  
**[:question: 如何实现队列的存储](#队列的存储实现)**

**:bulb: 栈与队列**  
**[:question: 栈与队列的应用场景有哪些](#栈与队列的应用)**  
**[:question: 顺序栈与链式栈的比较](#顺序栈与链式栈的比较)**  
**[:question: 顺序队列与链式队列的比较](#顺序队列与链式队列的比较)**  
**[:question: 栈与队列的变种结构](#栈与队列的变种结构)**

## 栈

### 栈的定义

具有一定操作约束的线性表，只在一端（栈顶）做插入删除

- 插入数据：入栈（$push$）
- 删除数据：出栈（$pop$）
- 后入先出：$Last In First Out(LIFO)$

### 栈的抽象数据类型描述

- 类型名称：堆栈（$Stack$）
- 数据对象集：一个有 $0$ 个或多个元素的有穷线性表。
- 操作集：长度为 $MaxSize$ 的堆栈 $S∈Stack$，堆栈元素 $item∈ElementType$
  - `Stack CreateStack(int MaxSize)`：生成空堆栈，最大长度是 $MaxSize$；
  - `int IsFull(Stack S, int MaxSize)`：判断栈是否已满；
  - `void Push(Stack S, ElementType item)`：元素 $item$ 入栈；
  - `int IsEmpty(Stack S)`：判断堆栈 $S$ 是否为空；
  - `ElementType Pop(Stack S)`：删除并返回栈顶元素

### 栈的存储实现

1. 栈的顺序存储实现 （`C` 实现 _[code ArrStack.c](./src/Note/ArrStack.c)_）

   - 结构

     ```cpp
     #define MaxSize <元素最大个数>
     typedef struct SNode *Stack;
     struct SNode
     {
         ElementType Data[MaxSize];
         int Top;
     };
     ```

   - 入栈

     ```cpp
     void Push(Stack PtrS, ElementType item)
     {
         if(PtrS->Top == MaxSize-1){
             printf("栈满");
             return;
         }else{
             PtrS->Data[++(PtrS->Top)] = item;
             return;
         }
     }
     ```

   - 出栈

     ```cpp
     ElementType Pop(Stack PtrS)
     {
         if(PtrS->Top == -1)
         {
             printf("栈空");
             return ERROR;       // ERROR是ElementType特殊值，标志错误
         }else
         {
             return (PtrS->Data[(PtrS->Top)--])
         }
     }
     ```

2. 栈的链式存储实现

   栈的链式存储结构实际上就是一个单链表，叫做 **_链栈_**。（`C` 实现 _[code LinkStack.c](./src/Note/LinkStack.c)_）

   - 结构

     ```cpp
     typedef struct SNode *Stack;
     struct SNode
     {
         ElementType Data;
         struct SNode *Next;
     };
     ```

   - 建立空栈

     ```cpp
     Stack CreateStack()
     {
         Stack S = (Stack)malloc(sizeof(struct SNode));
         S->Next = NULL;
         return S;
     }
     ```

   - 判断栈空

     ```cpp
     int IsEmpty(Stack S)
     {
         return (S->Next == NULL);
     }
     ```

   - 入栈

     ```cpp
     void Push(ElementType item, Stack S)
     {
         Stack TmpCell;
         TmpCell = (Stack)malloc(sizeof(struct SNode));
         TmpCell->Data = item;
         TmpCell->Next = S->Next;
         S->Next = TmpCell;
     }
     ```

   - 出栈

     ```cpp
     ElementType Pop(Stack S)
     {
         Stack FirstCell;
         ElementType TopData;
         if(IsEmpty(S)){
             printf("栈空");
             return NULL;
         }else
         {
             FirstCell = S->Next;
             S->Next = FirstCell->Next;
             TopElem = FirstCell->Element;
             free(FirstCell);
             return TopData;
         }
     }
     ```

_附：  
`C++` 栈顺序实现 [code ArrStack.cpp](./src/Note/ArrStack.cpp)  
`C++` 栈链式实现 [code LinkStack.cpp](./src/Note/LinkStack.cpp)_

### 范例

- **例 1**：一个数组实现两个堆栈，要求最大地利用数组空间，使数组只要有空间入栈操作就可以成功。_[code example.c](./src/Note/example1.c)_

  ```cpp
   #include <stdio.h>
   #include <stdlib.h>

   #define MaxSize 100
   #define ERROR -100

   typedef int ElementType;

   struct DStack
   {
       ElementType Data[MaxSize];
       int Top1;           // 栈1的栈顶指针
       int Top2;           // 栈2的栈顶指针
   };

   struct DStack* CreateStack()
   {
       struct DStack *S = (struct DStack*)malloc(sizeof(struct DStack));
       S->Top1 = -1;
       S->Top2 = MaxSize;
       return S;
   }

   // 入栈
   void Push(struct DStack *PtrS, ElementType item, int Tag)
   {
       // Tag区分栈1,2
       if(PtrS->Top2 - PtrS->Top1 == 1)
       {
           printf("栈满");
           return;
       }
       if(Tag == 1)
           PtrS->Data[++PtrS->Top1] = item;
       else
           PtrS->Data[--PtrS->Top2] = item;
   }

   // 出栈
   ElementType Pop(struct DStack *PtrS, int Tag)
   {
       if(Tag == 1)
       {
           if(PtrS->Top1 == -1)
           {
               printf("栈1空\n");
               return ERROR;
           }
           return PtrS->Data[PtrS->Top1--];
       }else
       {
           if(PtrS->Top2 == MaxSize)
           {
               printf("栈2空\n");
               return ERROR;
           }
           return PtrS->Data[PtrS->Top2--];
       }
   }
  ```

- **例 2**：后缀表达式求值 _[code example2.cpp](./src/Note/example2.cpp)_

  > 求解步骤：
  >
  > - 如果遇到一个操作数，则压栈
  > - 如果遇到一个运算符，就从栈中弹出两个操作数，按照运算符对这两个操作数进行相应的运算，然后将计算结果压入栈中

  ```cpp
  #include <iostream>
  #include <stack>


  class Calculator
  {
      private:
          std::stack<double> S;
          bool GetTwoOperands(double &opd1, double &opd2);
          void Compute(char op);
      public:
          Calculator(): S(std::stack<double>()){}
          void run();
          void clear();
  };


  bool Calculator::GetTwoOperands(double &opd1, double &opd2)
  {
      using namespace std;
      if(S.empty())
      {
          cerr << "Missing operand!" << endl;
          return false;
      }
      opd1 = S.top();
      S.pop();
      if(S.empty())
      {
          cerr << "Missing operand!" << endl;
          return false;
      }
      opd2 = S.top();
      S.pop();
      return true;
  }

  void Calculator::Compute(char op)
  {
      using namespace std;
      bool result;
      double operand1, operand2;
      result = GetTwoOperands(operand1, operand2);
      if(result == true)
      {
          switch(op)
          {
              case '+': S.push(operand2 + operand1);
                        break;
              case '-': S.push(operand2 - operand1);
                        break;
              case '*': S.push(operand2 * operand1);
                        break;
              case '/': if(abs(operand1) < 1E-7)
                        {
                            cerr << "Divide by 0!" << endl;
                            S = stack<double>();
                        }else
                            S.push(operand2 / operand1);
                        break;
          }
      }else
          S = stack<double>();
  }

  void Calculator::run()
  {
      using namespace std;
      char c;
      double newOperand, res;
      while(cin >> c, c != '=')
      {
          switch(c)
          {
              case '+':
              case '-':
              case '*':
              case '/':
                  Compute(c);
                  break;
              default:
                  cin.putback(c);
                  cin >> newOperand;
                  S.push(newOperand);
                  break;
          }
      }
      res = S.top();
      cout << res << endl;
  }


  int main()
  {
      // 23 34 45 * 5 6 + 7 + / +
      Calculator c;
      c.run();
  }
  ```

- :question::question:**例 3**：栈与递归。背包问题：设有一个背包可以放入的物品重量为$s$，现有$n$件物品，重量分别为$w_0,w_1,...,w_{n-1}$，问能否从这$n$件物品中选择若干件放入背包，使其重量之和正好为$s$。_[code exmaple3.cpp](./src/Note/example3.cpp)_

  > 如果用$knap(s,n)$表示上述背包的解，其返回值应为布尔值。背包问题如果有解，其选择只有两种可能：选择一组物品中包含$w_{n-1}$，此时$knap(s,n)$的解就是$knap(s-w_{n-1},n-1)$的解；选择中不包含$w_{n-1}$，这样$knap(s,n)$的解就是$knap(s,n-1)$的解，即
  >
  > $$
  > knap(s,n)
  > \left\{\begin{matrix}
  > true &当s=0;\\
  > false &当s<0或s>0且n<1;\\
  > knap(s-w_{n-1},n-1)\quad || \quad knap(s,n-1) &当s>0且n≥1
  > \end{matrix}\right.
  > $$

  ```cpp
  #include <iostream>

  double w[10];

  // 背包问题的递归算法
  bool knap(int s, int n)
  {
      using std::cout;
      if(s == 0)
          return true;
      if((s < 0) || (s > 0 && n < 1))
          return false;
      if(knap(s-w[n-1], n-1))
      {
          cout << w[n-1];
          return true;
      }
      else return knap(s, n-1);
  }


  // 背包问题的非递归实现
  /*
     背包递归规则有两种
     规则1：若w[n-1]包含在解中，求解knap(s-w[n-1], n-1)
     规则2：若w[n-1]不包含在解中，求解knap(s, n-1)

     knap算法中有两处递归规则，因此加上递归出口返回地址共有3种情况：
     (1) 计算knap(s,n)完毕返回到调用本函数的其他函数
     (2) 计算knap(s-w[n-1], n-1)完毕，返回本调用函数继续计算
     (3) 计算knap(s, n-1)完毕，返回到本调用函数继续计算
     rd分别用0,1,2表示上述三种情况
  */

  #include <stack>

  using std::stack;
  using std::cout;
  using std::endl;
  struct KnapNode
  {
      int s;
      int rd;
  };

  KnapNode tmp, x;

  stack<KnapNode> Stack;

  bool nonRecKnap(int s, int n)
  {
      int t, n0 = n;
      bool k = false;

      tmp.s = s;
      tmp.rd = 0;
      Stack.push(tmp);

      while(!Stack.empty())
      {
          t = Stack.size();
          tmp = Stack.top();
          while(tmp.s >= 0 && (tmp.s <= 0 || n0 > t))
          {   // 判断栈顶元素是否满足递归出口条件

              if(tmp.s == 0)
              {
                  k = true;
                  break;
              }else
              { // 尚未到达递归出口前，按规则1进行压栈
                  x.s = tmp.s - w[n0 - 1 - t];
                  x.rd = 1;
                  Stack.push(x);
              }
              t = Stack.size();
              tmp = Stack.top();
          }
          while(!Stack.empty())
          {
              tmp = Stack.top();
              Stack.pop();
              t = Stack.size();
              if(tmp.rd == 0)                 // 算法结束
                  return k;
              if(tmp.rd == 1){                // 从规则1返回
                  if(k == true)
                      cout << w[n0 - 1 - t] << endl;
                  else
                  { // 否则回溯，采用规则2进栈
                      x = Stack.top();
                      tmp.s = x.s;
                      tmp.rd = 2;
                      Stack.push(tmp);
                      break;
                  }
              }

          }
      }
      return k;
  }
  ```

## 队列

### 队列的定义

具有一定操作约束的线性表，只能在一端插入，另一端删除

- 插入数据：入队列（$AddQ$）
- 删除数据：出队列（$DeleteQ$）
- 先进先出：$FirstInFirstOut(FIFO)$

### 队列的抽象数据类型描述

- 类型名称：队列（$Queue$）
- 数据对象集：一个有 $0$ 个或多个元素的有穷线性表
- 操作集：长度为 $MaxSize$ 的队列 $Q∈Queue$，队列元素 $item∈ElementType$
  - `Queue CreateQueue(int MaxSize)`：生成长度为 $MaxSize$ 的空队列
  - `int IsFullQ(Queue Q, int MaxSize)`：判断队列是否已满
  - `void AddQ(Queue Q, ElementType item)`：将数据元素 $item$ 插入队列
  - `int IsEmptyQ(Queue Q)`：判断队列是否为空
  - `ElementType DeleteQ(Queue Q)`：将队首元素队列中删除并返回

### 队列的存储实现

通常由一个一维数组和一个记录队列头元素位置的变量 $front$ 以及一个记录队尾元素位置的变量 $rear$ 组成。（通常使用循环队列，空一个位置判定是否队满）

1. 队列的顺序存储实现 （`C` 实现 _[code ArrQueue.c](./src/Note/ArrQueue.c)_）

   - 结构

     ```cpp
     #define MaxSize <数据元素的最大个数>
     typedef struct QNode* Queue;
     struct QNode
     {
         ElementType Data[MaxSize];
         int rear;
         int front;
     };
     ```

   - 入队

     ```cpp
     void AddQ(Queue PtrQ, ElementType item)
     {
         if((PtrQ->rear+1) % MaxSize == PtrQ->front)
         {
             printf("队列满");
             return;
         }
         PtrQ->rear = (PtrQ->rear+1) % MaxSize;
         PtrQ->Data[PtrQ->rear] = item;
     }
     ```

   - 出队

     ```cpp
     ElementType DeleteQ(Queue PtrQ)
     {
         if(PtrQ->front == PtrQ->rear)
         {
             printf("队列空");
             return ERROR;
         }else{
             PtrQ->front = (PtrQ->front+1) % MaxSize;
             return PtrQ->Data[PtrQ->front];
         }
     }
     ```

2. 队列的链式存储实现

   用单链表实现 （`C` 实现 _[code LinkQueue.c](./src/Note/LinkQueue.c)_）

   - 结构

     ```cpp
     struct Node
     {
         ElementType Data;
         struct Node *Next;
     };

     typedef struct QNode *Queue;
     struct QNode            // 链队列结构
     {
         struct Node *rear;  // 指向队尾节点
         struct Node *front; // 指向队首节点
     };
     ```

   - 入队

     ```cpp
     void AddQ(Queue PtrQ, ElementType item)
     {
         struct Node *TmpNode;
         if(PtrQ->front == NULL)
         {
             // 队列没有元素
             TempNode = (struct Node *)malloc(sizeof(struct Node));
             TempNode->Data = item;
             TempNode->Next = NULL;
             PtrQ->front = TempNode;
             PtrQ->rear = TempNode;
         }else
         {
             // 队列已有元素
             TempNode = (struct Node *)malloc(sizeof(struct Node));
             TempNode->Data = item;
             TempNode->Next = PtrQ->rear;
             PtrQ->rear = TempNode;
         }
     }
     ```

   - 出队

     ```cpp
     ElementType DeleteQ(Queue PtrQ)
     {
         struct Node *FrontCell;
         ElementType FrontElem;

         if(PtrQ->front == NULL)
         {
             printf("队列空");
             return ERROR;
         }
         FrontCell = PtrQ->front;
         if(PtrQ->front == PtrQ->rear)
             // 只有一个元素
             PtrQ->front = PtrQ->rear = NULL;
         else
             PtrQ->front = PtrQ->front->Next;
         FrontElem = FrontCell->Data;
         free(FrontCell);
         return FrontElem;
     }
     ```

_附：  
`C++` 队列顺序实现 [code ArrQueue.cpp](./src/Note/ArrQueue.cpp)  
`C++` 队列链式实现 [code LinkQueue.cpp](./src/Note/LinkQueue.cpp)_

## 栈与队列

### 栈与队列的应用

- 栈 - 常见的应用包括函数调用和递归实现、深度优先周游、表达式转换和求值等。
- 队列 - 常见的应用包括广度优先周游、消息缓冲器、操作系统的各种资源管理等。

### 顺序栈与链式栈的比较

时间效率上，顺序栈和链式栈的基本操作都只要常数时间。  
空间角度看，顺序栈必须说明一个固定的长度，栈不满时，会浪费一些空间，但一个数组可以存储两个栈，这样浪费的空间相对少一些；链式栈的长度可根据需要增减，但每个元素都需要一个指针域，从而产生结构性开销。  
访问元素时，顺序栈可以快速定位并读取内部元素，而链式栈需要遍历。

### 顺序队列与链式队列的比较

大致与顺序栈和链式栈比较类似，要注意的是在空间代价上，顺序队列不像顺序栈那样，不能在一个数组中存储两个队列，除非总有数据项从一个队列转入另一个队列。

### 栈与队列的变种结构

- 双端队列：限制插入和删除在线性表的两端进行。栈和队列都是特殊的双端队列，对其存取设置了限制。（STL 中的栈和队列都是通过双端队列 deque 实现的）
- 双栈：两个底部相连的栈。双栈是一种添加限制的双端队列，它规定从某端插入的元素只能从该端删除。
- 超队列：一种删除受限的双端队列，删除只允许在一段进行，而插入可在两端进行。
- 超栈：一种插入受限的双端队列，插入只限制在一端而删除允许在两端。

// File:    图的表示.c
// Author:  csh
// Date:    2020/07/18
// ===================


#include <stdlib.h>
#include <stdio.h>
#define MaxVertexNum 100

// 1. 邻接矩阵表示图
typedef int DataType;
typedef int WeightType;
typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv;         // 顶点数
    int Ne;         // 边数
    WeightType G[MaxVertexNum][MaxVertexNum];
    DataType Data[MaxVertexNum];         // 存顶点的数据
};

typedef PtrToGNode MGraph;


// MGraph初始化
// 初始化一个由VertexNum个顶点但没有边的图
typedef int Vertex;                     // 用顶点下标表示顶点
MGraph CreateGraph(int VertexNum){
    MGraph Graph;
    Vertex V,W;

   Graph = (MGraph)malloc(sizeof(struct GNode));
   Graph->Nv = VertexNum;
   Graph->Ne = 0;

   for(V = 0; V < Graph->Nv; V++)
       for(W = 0; W < Graph->Nv; W++)
           Graph->G[V][W] = 0;

   return Graph;
}


// 像MGraph插入边
typedef struct ENode* PtrToENode;
struct ENode{
    Vertex V1, V2;      // 有向边<V1,V2>
    WeightType Weight;  // 权重
};
typedef PtrToENode Edge;

void InsertEdge(MGraph Graph, Edge E){
    // 插入边
    Graph->G[E->V1][E->V2] = E->Weight;

    // 若是无向图
    Graph->G[E->V2][E->V1] = E->Weight;
}

MGraph BuildGraph(){
    MGraph Graph;
    Edge E;
    Vertex V;
    int Nv, i;
    scanf("%d", &Nv);
    Graph = CreateGraph(Nv);
    scanf("%d", &(Graph->Ne));
    if(Graph->Ne != 0){
        E = (Edge)malloc(sizeof(struct ENode));
        for(i = 0; i < Graph->Ne; i++){
            scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
            InsertEdge(Graph, E);
        }
    }

    // 如果顶点有数据的话，读入数据
    for(V = 0; V < Graph->Nv; V++)
        scanf("%d", &(Graph->Data[V]));
    return Graph;
}


// 2. 邻接表表示图
typedef struct AdjVNode* PtrToAdjVNode;
struct AdjVNode{
    Vertex Adjv;                    // 邻接点下标
    WeightType Weight;              // 边权重
    PtrToAdjVNode Next;             // 指向下一个结点
};

typedef struct Vnode{
    PtrToAdjVNode FirstEdge;
    DataType Data;                  // 存放顶点的数据
}AdjList[MaxVertexNum];             // AdjList是邻接表类型

typedef struct GLNode *PtrToGLNode;
struct GLNode{
    int Nv;                         // 顶点数
    int Ne;                         // 边数
    AdjList G;                      // 邻接表
};
typedef PtrToGLNode LGraph;

LGraph CreateLGraph(int VertexNum){
    Vertex V, W;
    LGraph Graph;

    Graph = (LGraph)malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;

    for(V = 0; V < Graph->Nv; V++)
        Graph->G[V].FirstEdge = NULL;
    return Graph;
}

void InsertEdge2(LGraph Graph, Edge E){
    PtrToAdjVNode NewNode;

    // 插入边<v1,v2>
    // 为V2建立新的邻接点
    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->Adjv = E->V2;
    NewNode->Weight = E->Weight;
    // 将v2插入v1的表头
    NewNode->Next = Graph->G[E->V1].FirstEdge;
    Graph->G[E->V1].FirstEdge = NewNode;

    // 若是无向图
    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->Adjv = E->V1;
    NewNode->Weight = E->Weight;

    NewNode->Next = Graph->G[E->V1].FirstEdge;
    Graph->G[E->V2].FirstEdge = NewNode;
}

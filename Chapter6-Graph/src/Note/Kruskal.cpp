/******************************************************************************
 * File:           Kruskal.cpp
 * Author:         caoshenghui <576365750@qq.com>
 * Github:         https://github.com/caoshenghui
 * Description:
 * LICENSE:        MIT
******************************************************************************/


#include "Graph.hpp"
#include "MinHeap.hpp"


void Kruskal(Graph &G, Edge* &MST)
{
    ParTree<int> A(G.verticesNum());                // 等价类
    MinHeap<Edge> H(G.verticesNum());               // 最小堆
    MST = new Edge[G.verticesNum() - 1];
    int MSTTag = 0;                                 // 最小生成树的边计数
    bool heapEmpty;
    for(int i = 0; i < G.verticesNum(); i++)        // 将图的所有边插入最小堆H
        for(Edge e = G.firstEdge(i); G.isEdge(e); e = G.nextEdge(e))
            if(G.fromVertex(e) < G.toVertex(e))     // 防止无向图重复边插入
                H.insert(e)
    int EquNum = G.verticesNum();                   // 开始n个顶点分别作为一个等价类
    while(EquNum > 1)                               // 当等价类的个数大于1时合并等价类
    {
        heapEmpty = H.isEmpty();
        if(!heapEmpty)
            Edge e = H.removeMin();
        if(heapEmpty || e.weight == INFINITY)
        {
            std::cout << "不存在最小生成树" << std::endl;
            delete [] MST;
            MST = nullptr;
            return;
        }
        int from = G.fromVertex(e);
        int to = G.toVertex(e);
        if(A.Different(from, to))                   // 边e的两个顶点不在一个等价类
        {
            A.Union(from, to);                      // 合并两个等价类
            AddEdgetoMST(e, MST, MSTTag++);         // 将边e加到MST
            EquNum--;                               // 等价类个数减一
        }
    }
}

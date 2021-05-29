/******************************************************************************
 * File:           Prim.cpp
 * Author:         caoshenghui <576365750@qq.com>
 * Github:         https://github.com/caoshenghui
 * Description:
 * LICENSE:        MIT
******************************************************************************/


#include "Graph.hpp"


class Dist
{
    public:
        int length;
        int index;
        int pre;
};



int minVertex(Graph& G, Dist* &D);
// s是开始顶点，数组MST用于保存最小生成树的边
void Prim(Graph &G, int s, Edge * &MST)
{
    int MSTtag = 0;
    MST = new Edge[G.verticesNum()-1];
    Dist *D;
    D = new Dist[G.verticesNum()];
    for(int i = 0; i < G.verticesNum(); i++)
    {
        G.mark[i] = UNVISITED;
        D[i].index = i;
        D[i].length = INFINITY;
        D[i].pre = s;
    }
    D[s].length = 0;
    G.mark[s] = VISITED;
    int v = s;
    for(int i = 0; i < G.verticesNum(); i++)
    {
        if(D[v].length == INFINITY) return;     // 非连通，有不可达的顶点
        // 因为v的加入，需要刷新与v相邻接的顶点的D值
        for(Edge e = G.firstEdge(v); G.isEdge(e); e = G.nextEdge(e))
            if((G.mark[G.toVertex(e)] != VISITED) && (D[G.toVertex(e)].length > e.weight))
            {
                D[G.toVertex(e)].length = e.weight;
                D[G.toVertex(e)].pre = v;
            }
        v = minVertex(G, D);                    // 在D数组中找到最小值记为v
        G.mark[v] = VISITED;
        Edge edge(D[v].pre, D[v].index, D[v].length);
        AddEdgetoMST(edge, MST, MSTtag++);      // 将边edge加入到MST中
    }

}

int minVertex(Graph& G, Dist* &D)
{
    int i, v;
    for(i = 0; i < G.verticesNum(); i++)
        if(G.mark[i] == UNVISITED)
        {
            v = i;
            break;
        }
    for(i = 0; i < G.verticesNum(); i++)
        if(G.mark[i] == UNVISITED && D[i].length < D[v].length)
            v = i;                              // 当前发现的具有最小距离的顶点
    return v;
}

/******************************************************************************
 * File:           Dijkstra.cpp
 * Author:         caoshenghui <576365750@qq.com>
 * Github:         https://github.com/caoshenghui
 * Description:
 * LICENSE:        MIT
******************************************************************************/


#include "MinHeap.hpp"
#include "Graph.hpp"


class Dist
{
    public:
        int index;                  // 顶点的索引值
        int length;                 // 当前最短路径长度
        int pre;                    // 路径最后经过的顶点
};


void Dijkstra(Graph& G, int s, Dist * &D)
{
    D = new Dist[G.verticesNum()];
    for(int i = 0; i < G.verticesNum(); i++)
    {
        G.mark[i] = UNVISITED;
        D[i].index = i;
        D[i].length = INFINITY;
        D[i].pre = s;
    }
    D[s].length = 0;                // 源点到自身的路径长度设置为0
    MinHeap<Dist> H(G.edgesNum());  // 最小值堆用于找出最短路径
    H.insert(D[s]);
    for(int i = 0; i < G.verticesNum(); i++)
    {
        bool Found = false;
        Dist d;
        while(!H.isEmpty())
        {
            d = H.removeMin();
            if(G.mark[d.index] == UNVISITED)
            {
                Found = true;
                break;
            }
        }
        if(!Found)                  // 没有符合条件的最短路径则跳出本次循环
            break;
        int v = d.index;
        G.mark[v] = VISITED;
        // 加入v后需要刷新D中v邻接点的最短路径长度
        for(Edge e = G.firstEdge(v); G.isEdge(e); e = G.nextEdge(e))
            if(D[G.toVertex(e)].length > (D[v].length + G.weight(e)))
            {
                D[G.toVertex(e)].length = D[v].length + G.weight(e);
                D[G.toVertex(e)].pre = v;
                H.insert(D[G.toVertex(e)]);
            }
    }
}

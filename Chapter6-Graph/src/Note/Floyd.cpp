/******************************************************************************
 * File:           Floyd.cpp
 * Author:         caoshenghui <576365750@qq.com>
 * Github:         https://github.com/caoshenghui
 * Description:
 * LICENSE:        MIT
******************************************************************************/


#include "Graph.hpp"

class Dist
{
    public:
        int index;
        int length;
        int pre;
};

void Floyd(Graph &G, Dist** &D)
{
    int i, j, v;
    D = new Dist*[G.verticesNum()];
    for(i = 0; i < G.verticesNum(); i++)
        D[i] = new Dist[G.verticesNum()];
    for(i = 0; i < G.verticesNum(); i++)
        for(j = 0; j < G.verticesNum(); j++)
            if(i == j)
            {
                D[i][j].length = 0;
                D[i][j].pre = i;
            }
            else
            {
                D[i][j].length = INFINITY;
                D[i][j].pre = -1;
            }
    for(v = 0; v < G.verticesNum(); v++)
        for(Edge e = G.firstEdge(v); G.isEdge(e); e = G.nextEdge(e))
        {
            D[v][G.toVertex(e)].length = G.weight(e);
            D[v][G.toVertex(e)].pre = v;
        }
    // 顶点i到顶点j的路径经过顶点v如果变短，则更新路径长度
    for(v = 0; v < G.verticesNum(); v++)
        for(i = 0; i < G.verticesNum(); i++)
            for(j = 0; j < G.verticesNum(); j++)
                if(D[i][j].length > (D[i][v].length + D[v][j].length))
                {
                    D[i][j].length = D[i][v].length + D[v][j].length;
                    D[i][j].pre = D[v][j].pre;
                }
}

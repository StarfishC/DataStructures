/******************************************************************************
 * File:           Graph.hpp
 * Author:         caoshenghui <576365750@qq.com>
 * Github:         https://github.com/caoshenghui
 * Description:
 * LICENSE:        MIT
******************************************************************************/


#ifndef __GRAHP_H_
#define __GRAHP_H_

#include <queue>
#include <iostream>


const int INFINITY = 9999999;
const int UNVISITED = -2;
const int VISITED = -1;


class Edge
{
    public:
        int from, to, weight;                                   // 边的起点、终点、权
        Edge(): Edge(-1, -1, 0){}
        Edge(int f, int t, int w): from(f), to(t), weight(w){}
};


class Graph
{
    public:
        int numVertex;                                          // 图中顶点的个数
        int numEdge;                                            // 图中边的条数
        int *mark;                                              // 标记图的顶点是否被访问过
        int *indegree;                                          // 存放图中顶点的入度

        Graph(int numVert);
        virtual ~Graph();

        int verticesNum();                                      // 返回图中顶点的个数
        int edgesNum();                                         // 返回图的边数
        Edge firstEdge(int oneVertex);                          // 返回依附于顶点oneVertex的第一条边
        Edge nextEdge(Edge preEdge);                            // 返回与preEdge有相同顶点的下一条边
        bool setEdge(int fromVertex, int toVertex, int weight); // 添加边
        bool delEdge(int fromVertex, int toVertex);             // 删除边
        bool isEdge(Edge oneEdge);                              // oneEdge是否是边
        int fromVertex(Edge oneEdge);                           // 返回oneEdge的始点
        int toVertex(Edge oneEdge);                             // 返回oneEdge的终点
        int weight(Edge oneEdge);                               // 返回oneEdge的权
};

void DFS(Graph &G, int v);
void BFS(Graph &G, int v);
void Visit(Graph &G, int v);


Graph::Graph(int numVert):
    numVertex(numVert), numEdge(0),
    indegree(new int[numVert]{0}),
    mark(new int[numVert]{UNVISITED}){}

Graph::~Graph()
{
    delete [] mark;
    delete [] indegree;
}

int Graph::verticesNum()
{
    return numVertex;
}

bool Graph::isEdge(Edge oneEdge)
{
    if(oneEdge.weight > 0 && oneEdge.weight < INFINITY && oneEdge.to >= 0)
        return true;
    return false;
}


void DFS(Graph &G, int v)
{
    G.mark[v] = VISITED;
    Visit(G, v);
    for(Edge e = G.firstEdge(v); G.isEdge(e); e = G.nextEdge(e))
    {
        if(G.mark[G.toVertex(e)] == UNVISITED)
            DFS(G, G.toVertex(e));
    }
}

void BFS(Graph &G, int v)
{
    using std::queue;
    queue<int> Q;
    Visit(G, v);
    G.mark[v] = VISITED;
    Q.push(v);
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        // 与该顶点邻接的所有未访问过的顶点入队
        for(Edge e = G.firstEdge(v); G.isEdge(e); e = G.nextEdge(e))
            if(G.mark[G.toVertex(e)] == UNVISITED)
            {
                Visit(G, G.toVertex(e));
                G.mark[G.toVertex(e)] = VISITED;
                Q.push(G.toVertex(e));
            }
    }
}
#endif

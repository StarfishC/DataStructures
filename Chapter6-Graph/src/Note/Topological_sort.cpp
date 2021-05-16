// File:    Topological_sort.cpp
// Author:  csh
// Date:    2021/5/16
// ===================


#include "Adjacency_list.cpp"


void TopsortbyQueue(Graph& G)
{
    for(int i = 0; i < G.verticesNum(); i++)
        G.mark[i] = UNVISITED;
    using std::queue;
    queue<int> Q;
    for(int i = 0; i < G.verticesNum(); i++)            // 入队入度为0的顶点
        if(G.indegree[i] == 0)
            Q.push(i);
    while(!Q.empty())
    {
        int v = Q.front();
        Q.pop();
        Visit(G, v);
        G.mark[v] = VISITED;
        for(Edge e = G.firstEdge(v); G.isEdge(e); e = G.nextEdge(e))
        {
            G.indegree[G.toVertex(e)] --;               // 与该顶点相邻的顶点入度减1
            if(G.indegree[G.toVertex(e)] == 0)          // 如果入度变为0，则入队
                Q.push(G.toVertex(e));
        }
    }

    for(int i = 0; i < G.verticesNum(); i++)
    {
        if(G.mark[i] == UNVISITED)
        {
            std::cout << "此图有环!";
            break;
        }
    }
}

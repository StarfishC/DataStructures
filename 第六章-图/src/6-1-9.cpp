// File:    6-1-9.cpp
// Author:  csh
// Date:    2020/12/20
// ===================


#include <queue>

// 邻接矩阵
bool HasCirclePath(Graph &G, int V){
    for(int i = 0; i < G.verticesNum(); i++)
        G.mark[i] = 0;
    using std::queue;
    queue<int> Q;
    G.mark[V] = 1;
    Q.push(V);
    while(!Q.empty()){
        int V = Q.front();
        Q.pop();
        for(Egde e = G.firstEdge(); G.isEdge(e); e = G.nextEdge(e)){
            if(!G.mark[G.toVertex(e)]){             // 该点未访问过则访问
                G.mark[G.toVertex(e)] = 1;
                Q.push(G.toVertex(e));
            }else
                return false;
        }
    }
    return true;
}


// 邻接表
#include <stack>

bool hasCirclePath(Graph &G){
    for(int i = 0; i < G.verticesNum(); i++)
        G.mark[i] = 0;
    using std::stack;
    stack<int> S;
    for(int i = 0; i < G.verticesNum(); i++){
        if(!G.indegree[i])                  // 度数为0的顶点入栈
            S.push(i);
    }
    int count = 0;                          // 记录已访问过的顶点数
    while(!S.empty()){
        int V = S.top();
        S.pop();
        count++;
        G.mark[V] = 1;
        for(Edge e = G.firstEdge(V); G.isEdge(e); e = G.nextEdge(e)){
            G.indegree[G.toVertex(e)]--;
            if(!G.indegree[G.toVertex(e)])
                S.push(G.toVertex(e));
        }
    }
    return (count < G.verticesNum());
}

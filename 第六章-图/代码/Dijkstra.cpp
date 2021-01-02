// File:    Dijkstra.cpp
// Author:  csh
// Date:    2020/10/03
// ===================


#include "图.cpp"
#include "MinHeap.cpp"

class Dist{
    public:
        int index;                  // 顶点的索引值
        int length;                 // 当前最短路径长度
        int pre;                    // 路径最后经过的顶点
};

void Dijkstra(Graph &G, int s, Dist * &D){
    D = new Dist[G.verticesNum()];  // 数组D记录当前找到的最短特殊路径长度
    for(int i = 0; i < G.verticesNum(); i++){
        G.mark[i] = UNVISITED;
        D[i].index = i;
        D[i].length = INFINITY;
        D[i].pre = s;
    };
    D[s].length = 0;
    MinHeap<Dist> H(G.edgesNum());
    H.insert(D[s]);
    for(int i = 0; i < G.verticesNum(); i++){
        bool FOUND = false;
        Dist d;
        while(!H.isEmpty()){
            d = H.removeMin();
            if(G.mark[d.index] == UNVISITED){
                FOUND = true;
                break;
            }
        }
        if(!FOUND)
            break;
        int v = d.index;
        G.mark[v] = VISITED;
        for(Edge e = G.firstEdge(v); G.isEdge(e); e = G.nextEdge(e)){
            if (D[G.toVertex(e)].length > (D[v].length + G.weight(e))){
                D[G.toVertex(e)].length = D[v].length + G.weight(e);
                D[G.toVertex(e)].pre = v;
                H.insert(D[G.toVertex(e)]);
            }
        }
    }
}

void Flyod(Graph &G, Dist ** &D){
    int i, j, v;
    D = new Dist*[G.verticesNum()];
    for(i = 0; i < G.verticesNum(); i++)
        D[i] = new Dist[G.verticesNum()];
    // 初始化数组D
    for(i = 0; i < G.verticesNum(); i++)
        for(j = 0; j < G.verticesNum(); j++){
            if(i == j){
                D[i][j].length = 0;
                D[i][j].pre = i;
            }else{
                D[i][j].length = INFINITY;
                D[i][j].pre = -1;
            }
        }
    for(v = 0; v < G.verticesNum(); v++)
        for(Edge e = G.firstEdge(v); G.isEdge(e); e = G.nextEdge(e)){
            D[v][G.toVertex(e)].length = G.weight(e);
            D[v][G.toVertex(e)].pre = v;
        }

    // 顶点i到顶点j的路径经过顶点v如果变短，则更新路径长度
    for(v = 0; v < G.verticesNum(); v++)
        for(i = 0; i < G.verticesNum(); i++)
            for(j = 0; j < G.verticesNum(); j++)
                if(D[i][j].length > (D[i][v].length + D[v][j].length)){
                    D[i][j].length = D[i][v].length + D[v][j].length;
                    D[i][j].pre = D[v][j].pre;
                }
}


int minVertex(Graph &G, Dist * &D){
    int i, v;
    for(i = 0; i < G.verticesNum(); i++)
        if(G.mark[i] == UNVISITED){
            v = i;
            break;
        }
    for(i = 0; i < G.verticesNum(); i++)
        if(G.mark[i] == UNVISITED && D[i].length < D[v].length)
            v = i;
    return v;
}

void Prim(Graph &G, int s, Edge * &MST){
    // s是开始的顶点，数组MST用于保存最小生成树的边
    int MSTtag  = 0;                    // 最小生成树的边计数
    MST = new Edge[G.verticesNum() - 1];
    Dist *D;
    D = new Dist[G.verticesNum()];
    for(int i = 0; i < G.verticesNum(); i++){
        G.mark[i] = UNVISITED;
        D[i].index = i;
        D[i].length = INFINITY;
        D[i].pre = s;
    }
    D[s].length = 0;
    G.mark[s] = VISITED;
    int v = s;
    for(int i = 0; i < G.verticesNum(); i++){
        if(D[v].length == INFINITY) return;        // 不连通，有不可达顶点
        for(Edge e = G.firstEdge(v); G.isEdge(e); e = G.nextEdge(e))
            if(G.mark[G.toVertex(e)] != VISITED && D[G.toVertex(e)].length > e.weight){
                D[G.toVertex(e)].length = e.weight;
                D[G.toVertex(e)].pre = v;
            }
    }
    v = minVertex(G, D);
    G.mark[v] = VISITED;
    Edge edge(D[v].pre, D[v].index, D[v].length);
    AddEdgeToMST(edge, MST, MSTtag++);
}

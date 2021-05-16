// File:    6-1-22.cpp
// Author:  csh
// Date:    2021/01/02
// ===================


int Center(Graph &G, int **D){
    // 用Floyd算法求每对顶点间的最短路径
    int i, j, v, u, w;              // i,j,u,w是计数器，v记录相应顶点
    int max[G.VerticesNum()];       // 记录每个顶点的偏心距
    int cen, min;                   // 记录中心，Min记录最小的顶点偏心距
    // 初始化D
    for(i = 0; i < G.VerticesNum(); i++)
        for(j = 0; j < G.VerticesNum(); j++)
        {
            if(i == j) D[i][j] = 0;
            else D[i][j] = INFINITY;
        }
    // D = adj[0]，将边的值填入D数组
    for(v = 0; v < G.VerticesNum(); v++)
        for(Edge e = G.FirstEdge(v); G.IsEdge(e); e = G.NextEdge(e))
            D[v][e.to] = G.Weight(e);
    // 如果两个顶点间的最短路径经过顶点v,则有D[i][j] > (D[i][v] + D[v][j])
    // 通过对的循环，相当于将图的一个顶点一个顶点的扩大
    for(v = 0; v < G.VerticesNum(); v++)
        for(i = 0; i < G.VerticesNum(); i++)
            for(j = 0; j < G.VerticesNum(); j++)
                if(D[i][j] > (D[i][v] + D[v][j]))
                    D[i][j] = D[i][v] + D[v][j];
    // 循环求每个顶点的偏心距
    for(w = 0; w < G.VerticesNum(); w++)
    {
        Max[w] = D[0][w];           // 初始偏心距为D[0][w]
        for(u = 1; u < G.VerticesNum(); u++)
        {
            if(D[u][w] > Max[w])
                Max[w] = D[u][w];
        }
    }
    cen = 0;            // 中心的初值设为0
    min = Max[0];       // 中心的偏心距设为Max[0]
    for(w = 1; w < G.VerticesNum(); w++)
        if(Max[w] < min){
            cen = w;
            min = Max[w];
        }
    return cen;
}

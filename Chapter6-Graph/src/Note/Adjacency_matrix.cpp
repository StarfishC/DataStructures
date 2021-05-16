// File:    Adjacency_matrix.cpp
// Author:  csh
// Date:    2021/5/15
// ===================


#include "Graph.cpp"


class Graphm: public Graph
{
    private:
        int **matrix;                           // 指向相邻矩阵的指针
    public:
        Graphm(int numVert);
        ~Graphm();
        Edge firstEdge(int oneVertex);          // 返回依附于顶点oneVertex的第一条边
        Edge nextEdge(Edge preEdge);            // 返回与preEdge有相同顶点的下一条边
        void setEdge(int from, int to, int weight);     // 设置一条边
        void delEdge(int from, int to);         // 删除一条边
};

Graphm::Graphm(int numVert): Graph(numVert)
{
    int i;
    matrix = new int *[numVertex];
    for(i = 0; i < numVertex; i++)
        matrix[i] = new int[numVertex]{0};
}

Edge Graphm::firstEdge(int oneVertex)
{
    Edge myEdge;
    myEdge.from = oneVertex;
    for(int i = 0; i <= numVertex; i++)
    {
        if(matrix[oneVertex][i] != 0)
        {
            myEdge.to = i;
            myEdge.weight = matrix[oneVertex][i];
            break;
        }
    }
    return myEdge;
}

void Graphm::setEdge(int from, int to, int weight)
{
    if(matrix[from][to] <= 0)           // 如果原边不存在则边数和终点入度加1
    {
        numEdge++;
        indegree[to]++;
    }
    matrix[from][to] = weight;
}

void Graphm::delEdge(int from, int to)
{
    if(matrix[from][to] > 0)            // 如果原边不存在则边数和终点入度减1
    {
        numEdge--;
        indegree[to]--;
    }
    matrix[from][to] = 0;
}

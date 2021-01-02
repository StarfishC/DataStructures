// File:    图.cpp
// Author:  csh
// Date:    2020/10/02
// ===================


#include <queue>
#include <iostream>

const int INFINITY = 999999;
const int UNVISITED = -2;
const int VISITED = -1;

class Edge{
    public:
        int from, to, weight;                           // 边的起点、终点、权
        Edge(): Edge(-1, -1, 0){}                       // 默认构造函数
        Edge(int f, int t, int w): from{f}, to{t}, weight{w}{}
};


class Graph{
    public:
        int numVertex;                                  // 图中顶点的个数
        int numEdge;                                    // 图中边的条数
        int *mark;                                      // 标记图的顶点是否被访问过
        int *indegree;                                  // 存放图中顶点的入读

        Graph(int numVert);
        virtual ~Graph();

        int verticesNum();                              // 返回图的顶点个数
        int edgesNum();                                 // 返回图的边数
        Edge firstEdge(int oneVertex);                  // 返回依附于顶点oneVertex的第一条边
        Edge nextEdge(Edge preEdge);                    // 返回与preEdge有相同顶点的下一条边
        bool setEdge(int fromVertex, int toVertex, int weight);     // 添加边
        bool delEdge(int fromVertex, int toVertex);     // 删除边
        bool isEdge(Edge oneEdge);                      // oneEdge是否是边
        int fromVertex(Edge oneEdge);                   // 返回oneEdge的始点
        int toVertex(Edge oneEdge);                     // 返回oneEdge的终点
        int weight(Edge oneEdge);                       // 返回oneEdge的权

        void DFS();
};


Graph::Graph(int numVert): numVertex(numVert), numEdge(0),
                           indegree(new int[numVert]{0}),
                           mark(new int[numVert]{UNVISITED}){}

Graph::~Graph(){
    delete [] mark;
    delete [] indegree;
}

int Graph::verticesNum(){
    return numVertex;
}

bool Graph::isEdge(Edge oneEdge){
    if(oneEdge.weight > 0 && oneEdge.weight < INFINITY && oneEdge.to >= 0)
        return true;
    return false;
}


// 相邻矩阵表示图
class Graphm: public Graph{
    private:
        int **matrix;
    public:
        Graphm(int numVert);
        ~Graphm();
        Edge firstEdge(int oneVertex);
        Edge nextEdge(Edge preEdge);
        void setEdge(int from, int to, int weight);
        void delEdge(int from, int to);
};

Graphm::Graphm(int numVert): Graph(numVert){
    int i, j;
    matrix = new int *[numVertex];
    for(i = 0; i < numVertex; i++)
        matrix[i] = new int[numVertex]{0};
}

Edge Graphm::firstEdge(int oneVertex){
    Edge myEdge;
    myEdge.from = oneVertex;
    for(int i = 0; i <= numVertex; i++){
        if(matrix[oneVertex][i] != 0){
            myEdge.to = i;
            myEdge.weight = matrix[oneVertex][i];
            break;
        }
    }
    return myEdge;
}

Edge Graphm::nextEdge(Edge preEdge){
    Edge myEdge;
    myEdge.from = preEdge.from;
    if(preEdge.to < numVertex){                         // 如果该边+1越界，则不存在下一条边
        for(int i = preEdge.to + 1; i < numVertex; i++){
            if(matrix[preEdge.from][i] != 0){
                myEdge.to = i;
                myEdge.weight = matrix[preEdge.from][i];
                break;
            }
        }
    }
    return myEdge;
}

void Graphm::setEdge(int from, int to, int weight){
    if(matrix[from][to] <= 0){                          // 如果原边不存在
        numEdge++;
        indegree[to]++;
    }
    matrix[from][to] = weight;
}

void Graphm::delEdge(int from, int to){
    if(matrix[from][to] > 0){
        numEdge--;
        indegree[to]--;
    }
    matrix[from][to] = 0;
}


void Visit(Graph &G, int v);

// 深度优先周游
void DFS(Graph &G, int v){
    G.mark[v] = VISITED;
    Visit(G, v);            // 访问顶点
    for(Edge e = G.firstEdge(v); G.isEdge(e); e = G.nextEdge(e))
        if(G.mark[G.toVertex(e)] == UNVISITED)
            DFS(G, G.toVertex(e));
}

void BFS(Graph &G, int v){
    using std::queue;
    queue<int> Q;
    Visit(G, v);
    G.mark[v] = VISITED;
    Q.push(v);
    if(!Q.empty()){
        int u = Q.front();
        Q.pop();
        for(Edge e = G.firstEdge(u); G.isEdge(e); e = G.nextEdge(e))
            if(G.mark[G.toVertex(e)] == UNVISITED){
                Visit(G, G.toVertex(e));
                G.mark[G.toVertex(e)] = VISITED;
                Q.push(G.toVertex(e));
            }
    }
}

void TopsortbyQueue(Graph &G){
    for(int i = 0; i < G.verticesNum(); i++)
        G.mark[i] = UNVISITED;
    using std::queue;
    using std::cout;
    using std::endl;
    queue<int> Q;
    for(int i = 0; i < G.verticesNum(); i++)
        if(G.indegree[i] == 0)
            Q.push(i);
    while(!Q.empty()){
        int v = Q.front();
        Q.pop();
        Visit(G, v);
        G.mark[v] = VISITED;
        for(Edge e = G.firstEdge(v); G.isEdge(e); e = G.nextEdge(e)){
            G.indegree[G.toVertex(e)] --;
            if(G.indegree[G.toVertex(e)] == 0)
                Q.push(G.toVertex(e));
        }
    }

    for(int i = 0; i < G.verticesNum(); i++)
        if(G.mark[i] == UNVISITED){
            cout << "此图有环" << endl;
            break;
        }
}

// File:    6-1-13.cpp
// Author:  csh
// Date:    2020/12/26
// ===================



// 无向图
void Graph::Apart(){
    int i, j;
    for(i = 0; i < numVertex; i++)
        Mark[i] = UNVISITED;
    for(i = 0; i < numVertex; i++){
        // 检查所有顶点是否被标记，从未标记顶点开始周游
        if(Mark[i] == UNVISITED){
            do_traverse(i, j);
            j++;
        }
    }
}

void Graph::do_traverse(int v, int mark){
    Mark[i] = VISITED;
    value[v] = mark;

    // 访问v邻接到的未被访问的结点，并递归地按照深度优先的方式进行周游
    for(Edge e = FirstEdge(v); IsEdge(e); e = NextEdge(e)){
        if(Mark[ToVertices(e)] == UNVISITED)
            do_traverse(ToVertices(e), mark));
    }
}



// 有向图

// 判断u,v是否连通
bool Graph::connected(int u, int v){
    for(int i = 0; i < numVertex; i++)
        Mark[i] = UNVISITED;
    using std::queue;
    queue<int> Q;
    Q.push(u);
    while(!Q.empty()){
        int temp = Q.front();
        Q.pop();
        Mark[temp] = VISITED;
        if(temp == v)
            return true;
        for(Edge e = FirstEdge; IsEdge(e); e = NextEdge(e)){
            // 相邻的未访问的结点入队
            if(Mark[ToVertex(e)] == UNVISITED)
                Q.push(ToVertex(e));
        }
    }
    return false;
}

void Graph::Apart(){
    memset(value 0, numVertex * sizeof(int));
    int mark = 0;
    for(int i = 0; i < numVertex-1; i++){
        if(value[i] > 0)                    // 结点i已经属于某个连通分量
            continue;
        mark++;
        value[i] = mark;
        for(int j = i+1; j < numVertex; j++){
            if(value[j] > 0)                // 结点j已经属于某个连通分量
                continue;
            if(connected(i, j)){
                if(connected(j, i))
                    value[j] = mark;
            }
        }
    }
}

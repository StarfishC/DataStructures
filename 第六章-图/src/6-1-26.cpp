// File:    6-1-26.cpp
// Author:  csh
// Date:    2020/12/26
// ===================


// 方法一
void FindPath(Graph &G, int v, int vj, Edge * &path, int l){
    if(v == vj){                    // 当前结点是目标结点
        printpath(path, l);
        return;
    }
    for(Edge e = G.FirstEdge(v); G.IsEdge(e); e = G.NextEdge(e)){
        if(!InPath(G.ToVertex(e))){
            // InPath判断下一搜索结点是否已在路径中出现过
            l++;
            path[l] = G.ToVertex(e);
            FindPath(G, G.ToVertex(e), vj, path.l);
            l--;
        }
    }
}


// 方法二
void allSimplePath(Graph &G, int i, int j){
    int *path = new int[G.VerticesNum()];
    using std::stack;
    stack<int> aStack;
    aStack.push(i);
    G.Mark[i] = VISITED;
    int mark = -1;              // 标识变量，防止重复访问
    while(!aStack.empty()){
        Edge e;
        // 寻找第一个所连顶点未被访问的且没有重复访问的顶点
        for(e = G.FirstEdge(aStack.top()); G.IsEdge(e); e = NextEdge(e)){
            if(G.Mark[G.ToVertices(e)] == UNVISITED && G.ToVertices(e) > mark){
                aStack.push(G.ToVertices(e));
                G.Mark[G.ToVertices(e)] = VISITED;
                break;
            }
        }
        mark = -1;
        if(!G.IsEdge(e)){       // 如果某个顶点没有边了，则把他从栈中弹出，标记为未访问
            mark = aStack.top();
            G.Mark[mark] = UNVISITED;
            aStack.pop();
        }
        // 如果栈顶元素为Vj,则输出栈中保存的路径
        if(aStack.top() == j){
            int a = 0;
            while(!aStack.empty()){
                path[a++] = aStack.top();
                aStack.pop();
            }
            while(a >= 0){
                aStack.push(path[a]);
                cout << path[a] << " ";
            }
            cout << endl;
            mark = j;
            G.Mark[aStack.top()] = UNVISITED;
            aStack.pop();
        }
    }
}

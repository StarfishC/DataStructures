// File:    6-1-24.cpp
// Author:  csh
// Date:    2020/12/26
// ===================


static int length = 1;                  // 用来监控是否遍历完了图
void root(Graph &G){
    using std::queue;
    Queue<int> aQueue;
    for(int i = 0; i < G.verticesNum(); i++){
        aQueue.push(i);
        G.mark[i] = VISITED;
        while(!aQueue.empty()){
            int x = aQueue.top();
            aQueue.pop();
            for(Edge e = G.FirstEdge(x); G.IsEdge(e); e = G.NextEdge(e)){
                length++;
                G.Mark[G.ToVertices(e)] = VISITED;
                aQueue.push(G.ToVertices(e));
            }
        }
        if(length == G.numberVert)      // 判断这个结点是否是根结点的条件
            cout << i;
        length = 1;                     // 重新使监控恢复到原来的数值
        aQueue.MakeEmpty();
    }
    return;
}

// File:    6-1-21.cpp
// Author:  csh
// Date:    2021/01/02
// ===================


// 如果存在负值循环则返回false，其他情况返回true
bool ShortestPath(Graph &G, int s, Dist *&D){
    D = new Dist[G.VerticesNum()];
    int i,j;
    // 初始化D数组
    for(int i = 0;G < VerticesNum(); i++){
        D[i].length = INFINITY;
        D[i].pre = s;
    }
    D[s].length = 0;

    for(int i = 0; i < G.VerticesNum(); i++)
    {
        for(int j = 0; j < G.VerticesNum(); j++)
        {
            if(D[j].length != INFINITY)
                for(Edge e = G.FirstEdge(j); G.IsEdge(e); e = G.NextEdge(e))
                    if(D[G.ToVertex(e)].length > (D[j].length + G.Weight(e)))
                    {
                        D[G.ToVertex(e)].length = D[j].length + G.Weight(e);
                        D[G.ToVertex(e)].pre = j;
                    }
        }
    }
    for(int i = 0; i < G.VerticesNum(); i++)
    {
        if(D[i].length != INFINITY)
        {
            for(Edge e = G.FirstEdge(e); G.IsEdge(e); e = G.NextEdge(e))
            {
                if(D[G.ToVertex(e)].length > (D[i].length + G.Weight[e]))
                {
                    cout << "存在负循环";
                    return false;
                }
            }
        }
    }
    return true;
}

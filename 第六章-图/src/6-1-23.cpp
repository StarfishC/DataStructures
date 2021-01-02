// File:    6-1-23.cpp
// Author:  csh
// Date:    2021/01/02
// ===================


bool DAG::IsTree()
{
    bool InTag = true;              // 入度标识位
    bool OutTag = true;             // 出度标识位
    /* 以上两个变量位true表示当前访问过的顶点的相应度数均不大于1，
       为false表示当前访问过的顶点有部分顶点的相应度数大于1
    */
    for(int i = 0; i < numVertex; i++)
    {
        // 若有一个顶点的入度大于1，则将InTag标记为false
        if(Indegree[i] > 1)
            InTag = false;
        if(Outdegree[i] > 1)
            OutTag = false;
        // 若有一个顶点的出度和入度都大于1，则该DAG不是树
        if(!InTag && !OutTag)
            return false;
    }
    return true;
}

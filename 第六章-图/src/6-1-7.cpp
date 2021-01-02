// File:    6-1-7.cpp
// Author:  csh
// Date:    2020/12/20
// ===================


struct Edge{
    int from;
    int to;
    int weight;
};

class Graph{
    public:
        int verticesNum();
        int edgesNum();
        Edge firstEdge(int oneVertex);
        Edge nextEdge(Edge preEdge);
        bool setEdge(int fromVertex, int toVertex, int weight);
        bool delEdge(int fromVertex, int toVertex);
};

// 邻接矩阵
class Graphm: public Graph{
    public:
        Graphm(int num);
        Graphm* transpose(){
            int numVertex = verticesNum();
            Graphm *GT = new Graphm(numVertex);
            Edge tempE;
            for(int i = 0; i < numVertex; i++){
                tempE = firstEdge(i);
                while(tempE.to != -1){
                    GT->setEdge(tempE.to, i, tempE.weight);
                    tempE = nextEdge(tempE);
                }
            }
            return GT;
        }
};

// 邻接表
class Graphl:public Graph{
    public:
        Graphl(int num);
        Graphl* transpose(){
            int numVertex = verticesNum();
            Graphl *GT = new Graphl(numVertex);
            Edge tempE;
            Link<listUnit> *temp;
            for(int i = numVertex-1; i >= 0; i--){
                temp = graList[i].head;
                while(temp->next){
                    GT->setEdge(temp->next->element.vertex, i, temp->next->element.weight);
                    temp = temp->next;
                }
            }
            return GT;
        }
};

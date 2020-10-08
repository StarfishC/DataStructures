// File:    邻接表.cpp
// Author:  csh
// Date:    2020/10/02
// ===================


#include "图.cpp"


// 邻接表中边结点的定义
struct listUint{
    int vertex;
    int weight;
};


// 链表元素类
template <typename T>
class Link{
    public:
        T element;
        Link *next;
        Link(const T &elemval, Link *nextval = nullptr){
            element = elemval;
            next = nextval;
        }
        Link(Link *nextval=nullptr){
            next = nextval;
        }
};


// 链表类
template <typename T>
class LList{
    public:
        Link<T> *head;
        LList(){
            head = new Link<T>();
        }
};


// 邻接表
class Graphl: public Graph{
    private:
        LList<listUint> *graList;                       // 保存所有边的数组
    public:
        Graphl(int numVert);
        ~Graphl();

        Edge firstEdge(int oneVertex);
        Edge nextEdge(Edge preEdge);
        void setEdge(int from, int to, int weight);
        void delEdge(int from, int to);
};


Graphl::Graphl(int numVert): Graph(numVert){
    graList = new LList<listUint>[numVert];
}

Graphl::~Graphl(){
    delete [] graList;
}

Edge Graphl::firstEdge(int oneVertex){
    Edge myEdge;
    myEdge.from = oneVertex;
    Link<listUint> *temp = graList[oneVertex].head;
    if(temp->next){
        myEdge.to = temp->next->element.vertex;
        myEdge.weight = temp->next->element.weight;
    }
    return myEdge;
}

Edge Graphl::nextEdge(Edge preEdge){
    Edge myEdge;
    myEdge.from = preEdge.from;
    Link<listUint> *temp = graList[preEdge.from].head;
    while(temp->next && temp->next->element.vertex <= preEdge.to)
        temp = temp->next;
    if(temp->next){
        myEdge.to = temp->next->element.vertex;
        myEdge.weight = temp->next->element.weight;
    }
    return myEdge;
}

void Graphl::setEdge(int from, int to, int weight){
    Link<listUint> *temp = graList[from].head;
    while(temp->next && temp->next->element.vertex < to)
        temp = temp->next;
    // 如果from-to的边不存在
    if(temp->next){
        temp->next = new Link<listUint>;
        temp->next->element.vertex = to;
        temp->next->element.weight = weight;
        numEdge++;
        indegree[to]++;
    }

    // 如果存在
    if(temp->next->element.vertex == to){
        temp->next->element.weight = weight;
        return;
    }

    // 如果from-to存在，且后面还有边
    if(temp->next->element.vertex > to){
        Link<listUint> *other = temp->next;
        temp->next = new Link<listUint>;
        temp->next->element.vertex = to;
        temp->next->element.weight = weight;
        temp->next->next = other;
        numEdge++;
        indegree[to]++;
        return;
    }
}

void Graphl::delEdge(int from, int to){
    Link<listUint> *temp = graList[from].head;
    while(temp->next && temp->next->element.vertex < 0)
        temp = temp->next;
    if(temp->next == nullptr) return;
    if(temp->next->element.vertex > 0) return;
    if(temp->next->element.vertex == to){
        Link<listUint> *other = temp->next->next;
        delete temp->next;
        temp->next = other;
        numEdge--;
        indegree[to]--;
        return;
    }
}

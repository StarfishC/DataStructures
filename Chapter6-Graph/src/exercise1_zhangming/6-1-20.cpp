// File:    6-1-19.cpp
// Author:  csh
// Date:    2020/12/31
// ===================


void setEdge(int from, int to, int weight){
    Link<listUnit> *temp = graList[from].head;
    while(temp->next && temp->next->element.vertex < to)
        temp = temp->next;
    if(temp->next == nullptr){
        temp->next = new Link<listUnit>;
        temp->next->element.vertex = to;
        temp->netx->element.weight = weight;
        numEdge++;
        Indegree[to]++;
        return;
    }
    if(temp->next->element.vertex == to){
        // (from,to)已经存在
        temp->next->element.weight = weight;
        return;
    }
    if(temp->next->element.vertex > to){
        Link<listUnit> *other = temp->next;
        temp->next = new Link<listUnit>;
        temp->next->element.vertex = to;
        temp->next->element.weight = weight;
        temp->next->next = other;
        numEdge++;
        Indegree[to]++;
    }
}

void delEdge(int from, int to){
    Link<listUnit> *temp = graList[from].head;
    while(temp->next && temp->next->element.vertex < to)
        temp = temp->next;
    if(temp->next == nullptr){
        cout << "The Edge isn't exist!" << endl;
        return;
    }
    if(temp->next->element.vertex == to){
        Link<listUnit> *other = temp->next->next;
        delete temp->next;
        temp->next = other;
        numEdge--;
        Indegree[to]--;
    }
}

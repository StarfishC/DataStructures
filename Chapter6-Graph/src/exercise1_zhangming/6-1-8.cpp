// File:    6-1-8.cpp
// Author:  csh
// Date:    2020/12/20
// ===================


// 邻接矩阵
Graphm* Graphm::squareGraph(){
    Graphm *temp = new Graphm(numVert);
    int i,j,k;
    for(i = 0; i < numVert; i++){
        for(j = 0; j < numVert; j++){
            if(matrix[i][j] == 1){
                for(k = 0; k < numVert; k++){
                    if(i != k && matrix[j][k] == 1)
                        temp->matrix[i][k] = 1;
                }
            }
        }
    }
}


// 邻接表
Graphl* Graphl::squareGraph(){
    Graphl *current = new Graphl(numVert);
    Link<listUint> *node, *temp, *temp2;
    int i, j, k;
    for(i = 0; i < numVert; i++){
        node = current->graList[i].head;
        temp = graList[i].head;
        while(temp->next){
            temp = temp->next;
            j = temp->element.vertex;
            temp2 = graList[j].head;
            while(temp2->next){
                temp2 = temp2->next;
                if(i != temp2->element.vertex){
                    node->next = new Link;
                    node->next->element.vertex = temp2->element->vertex;
                    node->next->element.weight = temp2->element.weight + temp->element.weight;
                    node = node->next;
                }
            }
        }
    }
    return current;
}

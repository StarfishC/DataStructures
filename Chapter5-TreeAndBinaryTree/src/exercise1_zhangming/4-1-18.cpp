// File:    4-1-18.cpp
// Author:  csh
// Date:    2020/09/13
// ===================


bool IsMinHeap(int k[], int length){
    for(int i = 0; i <= (length-1)/2; i++){
        if(2*i + 2 <= length){          // 左右孩子都有结点
            if(!(k[i] <= k[2*i + 1] && k[i] <= k[2*i + 2]))
                return false;
        }
        else if(!(k[i] <= k[2*i + 1]))  // 判断左孩子结点
            return false;
    }
    return true;
}

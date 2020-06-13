// File:    1-2-2.cpp
// Author:  csh
// Date:    2020/05/01
// ===================


#include <iostream>

using namespace std;


int main(){
    // Num存放100个实数
    double Num[100] = {4542.9, 8, 3333, 4542.9, 8, 33, 22, 123, 3412, 4542.9, 56, 77, 45};
    int pos[100];                   //记录最大值所在位置的数组
    int position = 0;               //初始化设定数组的第一个元素为最大值
    int j;                          //指示位置数组pos的下标
    for(int i = 1; i < 100; i++){
        if(Num[i] > Num[position]){
            position = i;           //更新最大元素的位置
            j = 1;                  //位置数组pos的下标恢复为1，下标为0的位置为position预留
        }else if(Num[i] == Num[position])
            pos[j++] = i;           //记下重复最大值的位置
    }
    pos[0] = position;
    if(j < 100)
        pos[j] = -1;                //-1是标识值，前j个元素均为最大值位置，相当于哨兵

    cout << "最大值为:" << Num[position] << endl;
    cout << "最大值所在的位置为:";
    for(int i = 0; i < 100; i++){
        if(pos[i] == -1)
            break;
        cout << pos[i]+1 <<" ";
    }
    cout << endl;
    return 0;
}

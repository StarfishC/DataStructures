// File:    堆.cpp
// Author:  csh
// Date:    2020/07/04
// ===================


#include <iostream>
#include <cstdlib>

using namespace std;

template <typename T>
class MinHeap{
    private:
        T *heapArray;                       // 存放堆数据的数组
        int CurrentSize;                    // 当前堆中的元素数目
        int MaxSize;                        // 最大元素数目
        void swap(int pos_x, int pos_y);    // 交换位置x和y的元素
        void BuildHeap();                   // 建堆
    public:
        MinHeap(const int n);               // 构造函数
        ~MinHeap(){delete [] heapArray;};   // 析构函数
        bool isEmpty();                     // 判断堆是否为空
        bool isLeaf(int pos) const;         // 判断是否是叶结点
        int leftChild(int pos) const;       // 返回左孩子位置
        int rightChild(int pos) const;      // 返回右孩子位置
        int parent(int pos) const;          // 返回父结点位置
        bool remove(int pos, T &node);      // 删除给定下标的元素
        bool insert(const T &newNode);      // 插入新元素
        T& removeMin();                     // 从堆中删除最小值
        void siftUp(int position);          // 从position开始向上调整
        void siftDown(int left);            // 从left开始向下筛选
};


template <typename T>
MinHeap<T>::MinHeap(const int n){
    if(n < 0)
        return;
    CurrentSize = 0;
    MaxSize = n;
    heapArray = new T[MaxSize];
    BuildHeap();
}

template <typename T>
void MinHeap<T>::BuildHeap(){
    for(int i = CurrentSize/2 -1; i >= 0; i--)
        siftDown(i);
}

template <typename T>
int MinHeap<T>::leftChild(int pos) const{
    return 2*pos + 1;
}

template <typename T>
int MinHeap<T>::rightChild(int pos) const{
    return 2*pos + 2;
}

template <typename T>
int MinHeap<T>::parent(int pos) const{
    return (pos - 1) / 2;
}

template <typename T>
bool MinHeap<T>::insert(const T &newNode){
    if(CurrentSize == MaxSize)                  // 堆满
        return false;
    heapArray[CurrentSize] = newNode;
    siftUp(CurrentSize);
    CurrentSize++;
    return true;
}

template <typename T>
T& MinHeap<T>::removeMin(){
    if(CurrentSize == 0){
        cout << "Can't delete" << endl;
        exit(1);
    }else{
        swap(0, --CurrentSize);                 // 交换堆顶和堆尾的元素
        if(CurrentSize > 1)                     // 若当前元素大于1则从堆顶开始向下筛选
            siftDown(0);
        return heapArray[CurrentSize];
    }
}

template <typename T>
bool MinHeap<T>::remove(int pos, T &node){
    if(pos < 0 || pos >= CurrentSize)
        return false;
    node = heapArray[pos];                      // 记录删除的元素
    heapArray[pos] = heapArray[--CurrentSize];  // 用最后的元素值代替被删除结点
    if(heapArray[parent(pos)] > heapArray[pos]) // 当前元素小于父结点，向上调整
        siftUp(pos);
    else siftDown(pos);
    return true;
}

template <typename T>
void MinHeap<T>::siftUp(int position){
    int temppos = position;
    T temp = heapArray[temppos];
    while((temppos > 0) && (heapArray[parent(temppos)] > temp)){
        heapArray[temppos] = heapArray[parent(temppos)];
        temppos = parent(temppos);
    }
    heapArray[temppos] = temp;
}

template <typename T>
void MinHeap<T>::siftDown(int left){
    int i = left;                               // 标识父结点
    int j = leftChild(i);                       // 用于记录关键值比较小的子结点
    T temp = heapArray[i];                      // 保存父结点
    while(j < CurrentSize){
        if((j < CurrentSize - 1) && (heapArray[j] > heapArray[j+1]))    // 若有右子节点，且小于左子结点
            j++;                                // 指向右子结点
        if(temp > heapArray[j]){                // 如果父结点大于子结点的值则交换位置
            heapArray[i] = heapArray[j];
            i = j;
            j = leftChild(j);
        }
        else break;
    }
    heapArray[i] = temp;
}

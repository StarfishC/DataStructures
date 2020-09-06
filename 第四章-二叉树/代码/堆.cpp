// File:    堆.cpp
// Author:  csh
// Date:    2020/09/05
// ===================


#include <cstdlib>

template <typename T>
class MinHeap{
    private:
        T *heapArray;                                   // 存放堆数据的数组
        int CurrentSize;                                // 当前堆中的元素数目
        int MaxSize;                                    // 最大元素数目
        void swap(int pos_x, int pos_y);                // 交换位置x和y的元素
        void buildHeap();                               // 建堆
    public:
        MinHeap(const int n);
        virtual ~MinHeap(){delete []heapArray;}         // 析构函数
        bool isEmpty();                                 // 判断是否为空
        bool isLeaf(int pos) const;                     // 判断是否是叶结点
        int leftChild(int pos) const;                   // 返回左孩子位置
        int rightChild(int pos) const;                  // 返回右孩子位置
        int parent(int pos) const;                      // 返回父结点位置
        bool remove(int pos, T &node);                  // 删除给定的下标元素
        bool insert(const T &newNode);                  // 向堆中插入新元素newNode
        T removeMin();                                  // 堆顶删除最小值
        void siftUp(int position);                      // 从position开始向上调整
        void siftDown(int left);                        // 从left开始向下筛选
};

template <typename T>
MinHeap<T>::MinHeap(const int n){
    if(n <= 0)
        return;
    CurrentSize = 0;
    MaxSize = n;
    heapArray = new T[MaxSize];
    buildHeap();
}

template <typename T>
bool MinHeap<T>::isEmpty(){
    return CurrentSize == 0;
}

template <typename T>
bool MinHeap<T>::isLeaf(int pos) const{
    return (pos >= CurrentSize/2 && pos < CurrentSize);
}

template <typename T>
void MinHeap<T>::buildHeap(){
    for(int i = CurrentSize/2 - 1; i >= 0; i--){
        siftUp(i);
    }
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
    if(CurrentSize == MaxSize)
        return false;
    heapArray[CurrentSize++] = newNode;
    siftDown(CurrentSize);
    return true;
}

template <typename T>
T MinHeap<T>::removeMin(){
    if(CurrentSize == 0)
        exit(1);
    else{
        T tmp = heapArray[0];
        swap(0, --CurrentSize);
        if(CurrentSize > 1)
            siftDown(0);
        return tmp;
    }
}

template <typename T>
bool MinHeap<T>::remove(int pos, T &node){
    if(pos < 0 || pos >= CurrentSize)
        return false;
    node = heapArray[pos];
    heapArray[pos] = heapArray[--CurrentSize];              // 最后的元素替代被删除元素
    if(heapArray[parent(pos)] > heapArray[pos])             // 当前元素小于父结点，向上调整
        siftUp(pos);
    else
        siftDown(pos);
    return true;
}

template <typename T>
void MinHeap<T>::siftUp(int position){
    int temppos = position;
    T temp = heapArray[position];
    while(temppos > 0 && heapArray[parent(temppos)] > temp){
        heapArray[temppos] = heapArray[parent(temppos)];
        temppos = parent(temppos);
    }
    heapArray[temppos] = temp;
}

template <typename T>
void MinHeap<T>::siftDown(int left){
    int i = left;                                           // 标识父结点
    int j = leftChild(i);                                   // 用于记录关键之比较小的结点
    T temp = heapArray[i];
    while(j < CurrentSize){
        if((j < CurrentSize - 1) && (heapArray[j] > heapArray[j+1]))    // 若存在右结点且小于左节点
            j++;
        if(temp > heapArray[j]){
            heapArray[i] = heapArray[j];
            i = j;
            j = leftChild(j);
        }else break;
    }
    heapArray[i] = temp;
}

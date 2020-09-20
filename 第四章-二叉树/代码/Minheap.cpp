// File:    Minheap.cpp
// Author:  csh
// Date:    2020/09/20
// ===================


#include <iostream>

template <typename T>
class MinHeap{
    private:
        T *heapArray;                           // 存放堆数据的数组
        int currentSize;                        // 当前堆中元素的数目
        int maxSize;                            // 最大元素数目
        void buildHeap();                       // 建堆
        void swap(int pos_x, int pos_y);        // 交换x，y位置元素
    public:
        MinHeap(const int n);
        virtual ~MinHeap(){delete [] heapArray;}
        inline bool isEmpty();                  // 判断堆是否为空
        bool isLeaf(int pos) const;             // 判断是否为叶结点
        int leftChild(int pos) const;           // 返回左孩子位置
        int rightChild(int pos) const;          // 返回右孩子位置
        int parent(int pos) const;              // 返回父结点位置
        bool remove(int pos, T &val);           // 删除指定下标的元素
        bool insert(const T &newVal);           // 堆中插入新元素
        T& removeMin();                         // 从堆顶删除最小值
        void siftUp(int position);              // 从position向上调整
        void siftDown(int position);            // 从position向下筛选

        void preOrder();
        void preOrder(int pos);
};

template <typename T>
MinHeap<T>::MinHeap(const int n){
    if(n <= 0)
        return;
    currentSize = 0;
    maxSize = n;
    heapArray = new T[maxSize];
    buildHeap();
}

template <typename T>
void MinHeap<T>::swap(int pos_x, int pos_y){
    if(pos_x < currentSize && pos_y < currentSize){
        T temp = heapArray[pos_x];
        heapArray[pos_x] = heapArray[pos_y];
        heapArray[pos_y] = temp;
    }
}

template <typename T>
void MinHeap<T>::buildHeap(){
    for(int i = currentSize/2 - 1; i >= 0; i--)
        siftDown(i);
}

template <typename T>
bool MinHeap<T>::isEmpty(){
    return currentSize == 0;
}

template <typename T>
bool MinHeap<T>::isLeaf(int pos) const{
    return pos >= currentSize/2 && pos < currentSize;
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
bool MinHeap<T>::insert(const T &newVal){
    if(currentSize == maxSize)
        return false;
    heapArray[currentSize] = newVal;
    siftUp(currentSize++);
    return true;
}

template <typename T>
bool MinHeap<T>::remove(int pos, T &val){
    if(pos < 0 || pos >= currentSize)
        return false;
    val = heapArray[pos];
    heapArray[pos] = heapArray[--currentSize];          // 最后位置元素替代被删除元素
    if(heapArray[parent(pos)] > heapArray[pos])         // 当前位置元素小于父结点，向上调整
        siftUp(pos);
    else siftDown(pos);                                 // 当前位置元素大于父结点，向下调整
    return true;
}

template <typename T>
T& MinHeap<T>::removeMin(){
    if(currentSize == 0)
        return;
    else{
        swap(0, --currentSize);
        if(currentSize > 1)
            siftDown(0);
        return heapArray[currentSize];
    }
}

template <typename T>
void MinHeap<T>::siftUp(int position){
    int temppos = position;
    T temp = heapArray[temppos];
    while(temppos > 0 && heapArray[parent(temppos)] > temp){    // 父结点元素大于当前结点
        heapArray[temppos] = heapArray[parent(temppos)];
        temppos = parent(temppos);
    }
    heapArray[temppos] = temp;
}

template <typename T>
void MinHeap<T>::siftDown(int position){
    int i = position;                   // 标志父结点
    int j = leftChild(i);               // 记录关键值比较的子结点
    T temp = heapArray[i];
    while(j < currentSize){
        if(j < currentSize - 1 && heapArray[j] > heapArray[j+1])
            // 若有右子结点并且小于左子结点，那么j指向右子结点
            j++;
        if(temp > heapArray[j]){        // 如果父结点大于子结点的值则交换
            heapArray[i] = heapArray[j];
            i = j;
            j = leftChild(j);
        }else break;
    }
    heapArray[i] = temp;
}

template <typename T>
void MinHeap<T>::preOrder(){
    preOrder(0);
}

template <typename T>
void MinHeap<T>::preOrder(int pos){
    using std::cout;
    if(pos < currentSize && pos >= 0){
        cout << heapArray[pos] << " ";
        preOrder(2*pos + 1);
        preOrder(2*pos + 2);
    }
}


int main(int argc, char *argv[]){
    MinHeap<int> a(10);
    int arr[] = {12, 14, 15, 19, 20, 17, 18, 24, 22, 26};
    for(int i = 0; i < 10; i++)
        a.insert(arr[i]);
    a.preOrder();
    return 0;
}

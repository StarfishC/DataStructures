/******************************************************************************
 * File:           置换选择排序.cpp
 * Author:         caoshenghui <576365750@qq.com>
 * Github:         https://github.com/caoshenghui
 * Description:
 * LICENSE:        MIT
******************************************************************************/


template <typename T>
void replacementSelection(T *A, int n, const char *in, const char *out)
{
    T mval;                                 // 存放最小堆的最小值
    T r;                                    // 存放从输入缓冲区中读入的元素
    FILE *inputFile;                        // 输入文件句柄
    FILE *outputFile;                       // 输出文件句柄
    Buffer<T> input;                        // 输入缓冲区
    Buffer<T> output;                       // 输出缓冲区
    initFiles(inputFile, outputFile, in, out);      // 初始化输入输出文件
    initMinHeapArray(inputFile, n, A);      // 从输入文件读入n个数据初始化堆数组A
    MinHeap<T> H(A, n);                     // 建立最小堆
    initInputBuffer(input, inputFile);      // 初始化输入缓冲区，读入一部分数据
    for(int last = n-1; last >= 0; ;)
    {
        mval = H.heapArray[0];              // 获得堆的最小值
        sendToOutputBuffer(input, output, inputFile, outputFile, mval);     // 把mval送到输出缓冲区
        input.read(r);                      // 从输入缓冲区读入一个记录r
        if(!less(r, mval))                  // 如果r大于等于输出值，r放到堆的根结点
            H.heapArray[0] = r;
        else
        {
            H.heapArray[0] = H.heapArray[last];     // 用堆中last位置记录代替根结点
            H.heapArray[last] = r;          // r放到last位置
            H.setSize(last);                // 堆规模减一
            last--;
        }
        if(last != 0)
            H.SiftDown(0);                  // 重排序堆，向下筛选
    }
    endUp(output, inputFile, outputFile);   // 处理输出缓冲区，关闭输入/输出文件
}

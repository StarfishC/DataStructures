// File:    2-5-2.cpp
// Author:  csh
// Date:    2020/08/23
// ===================

#include <iostream>

using namespace std;

class Queue{
    private:
        int *qu;
        int front;
        int count;
        int msize;
    public:
        Queue(int size){
            msize = size;
            qu = new int[msize];
            count = 0;
            front = 0;
        }
        ~Queue(){
            delete [] qu;
        }
        bool isEmpty(){
            return count == 0;
        }
        bool enQueue(int item){
            if(count == msize){
                cout << "队列满，不能入队" << endl;
                return false;
            }
            int rear;       // 待入队位置
            rear = (front + count) % msize;
            qu[rear] = item;
            count++;
            return true;
        }
        bool deQueue(int &item){
            if(count == 0){
                cout << "队列空，不能出队" << endl;
                return false;
            }
            item = qu[front];
            front = (front + 1) % msize;
            count --;
            return false;
        }
};


int main(){
    Queue q = Queue(5);
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);

    int ret;
    while(!q.isEmpty()){
        q.deQueue(ret);
        cout << ret << " ";
    }
    cout << endl;
    return 0;
}

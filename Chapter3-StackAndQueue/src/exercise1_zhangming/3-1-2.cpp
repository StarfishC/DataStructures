// File:    3-1-2.cpp
// Author:  csh
// Date:    2020/08/23
// Update:  2020/02/21
// ===================

#include <iostream>


template <typename T>
class Queue
{
    private:
        int front;
        int count;
        int msize;
        T *qu;
    public:
        Queue(int size):
            msize(size), qu(new T[size]), count(0), front(0){}
        ~Queue()
        {
            delete [] qu;
        }

        inline bool isEmpty()
        {
            return count == 0;
        }
        bool enQueue(const int &item)
        {
            using std::cout;
            using std::endl;
            if(count == msize)
            {
                cout << "队列满，不能入队" << endl;
                return false;
            }
            int rear;       // 待入队位置
            rear = (front + count) % msize;
            qu[rear] = item;
            count++;
            return true;
        }
        bool deQueue(int &item)
        {
            using std::cout;
            using std::endl;
            if(count == 0)
            {
                cout << "队列空，不能出队" << endl;
                return false;
            }
            item = qu[front];
            front = (front + 1) % msize;
            count --;
            return false;
        }
};


int main()
{
    using namespace std;
    Queue<int> q = Queue<int>(5);
    q.enQueue(1);
    q.enQueue(2);
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

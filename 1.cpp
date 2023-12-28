#include <iostream>
using namespace std;
#define MAX_SIZE 10
class queue
{
    int q[MAX_SIZE];
    int rear = -1;
    int front = -1;

public:
    bool isFull()
    {
        if ((rear + 1) % MAX_SIZE == front)
            return 1;
        else
            return 0;
    }
    void insert(int data)
    {
        if (isFull())
        {
            cout << "Queue is Full" << endl;
            return;
        }
        else if (front = -1)
            front = rear = 0;
        else
            rear = (rear + 1) % MAX_SIZE;
        q[rear] = data;
    }
    int dele()
    {
        if (front == -1)
        {
            cout << "Queue Empty" << endl;
            return 0;
        }
        else if (front == rear)
        {
            int value = q[front];
            front = rear = -1;
            return value;
        }
        else
        {
            int value = q[front];
            front = (front + 1) % MAX_SIZE;
            return value;
        }
    }
};
int main()
{
    queue q;
    q.insert(1);
    q.insert(2);
    q.insert(3);
    q.insert(4);
    q.insert(5);
    q.insert(6);
    q.insert(7);
    q.insert(8);
    q.insert(9);
    q.insert(10);
    // q.insert(11);
    // q.insert(11);
    // q.insert(11);
    // q.insert(11);
    cout << q.dele();
}
#include <iostream>
using namespace std;
#define MAX_SIZE 100
class stack
{
    int s[MAX_SIZE];
    int top = -1;

public:
    bool isFull()
    {
        if (top == MAX_SIZE - 1)
            return 1;
        else
            return 0;
    }
    bool isEmpty()
    {
        if (top == -1)
            return 1;
        else
            return 0;
    }
    void push(int data)
    {
        if (isFull())
        {
            cout << "Queue overflow" << endl;
            return;
        }
        else

            s[++top] = data;
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow" << endl;
            return 0;
        }
        else
        {
            int value = s[top--];
            return value;
        }
    }
};
int main()
{
    stack s1, s2;
    int choice;

    while (choice != 0)
    {
        cout << "Enter choice \n 1 for enqueue and 2 for dequeue" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            int value;
            cout << "Enter value";
            cin >> value;
            s1.push(value);
            break;
        case 2:
            if (!s1.isEmpty())
            {
                while (!s1.isEmpty())
                {
                    s2.push(s1.pop());
                }
                cout << "Data:" << s2.pop();
                while (!s2.isEmpty())
                {
                    s1.push(s2.pop());
                }
            }
            else
            {
                cout << "Queue Underflow";
                return 0;
            }
            break;
        }
    }
    return 0;
}

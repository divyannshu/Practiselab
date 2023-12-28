#include <iostream>
using namespace std;
class node
{
    node *next;
    int data;
    int priority;

public:
    node *head = NULL;
    void create_LL(int value, int priority)
    {
        node *p = new node;
        p->data = value;
        p->priority = priority;
        p->next = NULL;
        if (head == NULL)
            head = p;
        else
        {
            if (priority >= head->priority)
            {
                p->next = head;
                head = p;
                cout << "Entered else if" << endl;
            }
            else
            {
                node *temp = head;
                node *q = NULL;
                while (temp != NULL && priority < temp->priority)
                {
                    q = temp;
                    temp = temp->next;
                }
                q->next = p;
                p->next = temp;
                cout << "Entered else else" << endl;
            }
        }
        cout << "Created node" << endl;
        ;
    }
    void display(node *head)
    {

        while (head != NULL)
        {
            cout << "Data:" << head->data << endl;
            cout << "Priority:" << head->priority << endl;
            head = head->next;
        }
    }
    int max()
    {
        return head->data;
    }
    int extractMax()
    {
        if (head == NULL)
            return 0;
        node *p = head;
        head = p->next;
        return p->data;
    }
};
int main()
{
    node nn;
    int n;
    cout << "Enter number of nodes";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int value;
        int priority;
        cout << "Enter value:";
        cin >> value;
        cout << "Enter priority:";
        cin >> priority;
        nn.create_LL(value, priority);
    }
    nn.display(nn.head);
    cout << "Extracted MAX:" << nn.extractMax() << endl;
    cout << "Max value:" << nn.max() << endl;

    return 0;
}
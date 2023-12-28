#include <iostream>
using namespace std;
class node
{
    node *next;
    int data;

public:
    node *head = NULL;
    void create_LL(int value)
    {
        node *p = new node;
        p->data = value;
        p->next = NULL;
        if (head == NULL)
            head = p;
        else
        {
            node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = p;
        }
    }
    node *reverse_LL(node *curr)
    {
        if (curr == NULL || curr->next == NULL)
            return curr;
        node *new_head = reverse_LL(curr->next);
        curr->next->next = curr;
        curr->next = NULL;
        return new_head;
    }
    void display(node *head)
    {

        while (head != NULL)
        {
            cout << "Data:" << head->data << endl;
            head = head->next;
        }
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
        cout << "Enter value:";
        cin >> value;
        nn.create_LL(value);
    }
    // nn.display(head);
    node *head = nn.reverse_LL(nn.head);
    nn.display(head);
    return 0;
}
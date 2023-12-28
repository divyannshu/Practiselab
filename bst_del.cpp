#include <iostream>
using namespace std;

class node
{
    node *left;
    node *right;
    int data;

public:
    node *root = NULL;
    void createBST(int data)
    {
        node *p = new node;
        p->data = data;

        if (root = NULL)
        {
            root = p;
            root->left = NULL;
            root->right = NULL;
        }

        else
        {
            node *temp = root;
            node *follow = NULL;

            while (temp != NULL)
            {
                follow = temp;
                if (data < temp->data)
                    temp = temp->left;
                else
                    temp = temp->right;
            }
            if (data < follow->data)
                follow->left = p;
            else
                follow->right = NULL;
        }
        p->left = NULL;
        p->right = NULL;
    }
    void InOrder(node *root)
    {
        if (root == NULL)
            return;
        InOrder(root->left);
        cout << "Data:" << root->data << endl;
        InOrder(root->right);
    }
};
int main()
{
    node n;
    n.createBST(45);
    n.createBST(38);
    n.createBST(55);
    n.createBST(56);
    n.createBST(30);
    n.createBST(44);
    n.InOrder(n.root);
}
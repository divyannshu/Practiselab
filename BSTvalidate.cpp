
#include <iostream>
#include <stdint.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node *root = NULL;
void create_node(int num)
{
    Node *p = new Node;
    p->data = num;

    if (root == NULL)
    {
        root = p;
        root->left = NULL;
        root->right = NULL;
    }
    else
    {
        Node *temp = root;
        Node *q = NULL;

        while (temp != NULL)
        {
            q = temp;
            if (num < temp->data)
                temp = temp->left;
            else
                temp = temp->right;
        }
        if (num < q->data)
            q->left = p;
        else
            q->right = p;
        p->left = NULL;
        p->right = NULL;
    }
}
int maxValue(Node *root)
{
    if (root == NULL)
        return INT16_MIN;
    int value = root->data;
    int left_max = maxValue(root->left);
    int right_max = maxValue(root->right);
    return max(value, max(left_max, right_max));
}
int minValue(Node *root)
{
    if (root == NULL)
        return INT16_MAX;
    int value = root->data;
    int left_max = minValue(root->left);
    int right_max = minValue(root->right);
    return min(value, min(left_max, right_max));
}
int isBST(Node *root)
{
    if (root == NULL)
        return 1;
    if (root->left != NULL && root->data <= maxValue(root->left))
        return 0;
    if (root->right != NULL && root->data >= minValue(root->right))
        return 0;
    if (!isBST(root->left) || !isBST(root->right))
        return 0;
    return 1;
}
void inOrder(struct Node *node)
{
    if (node == NULL)
    {
        return;
    }
    inOrder(node->left);
    cout << node->data << endl;
    inOrder(node->right);
}
int main()
{
    create_node(25);
    create_node(22);
    create_node(63);
    create_node(42);
    create_node(32);
    create_node(71);
    cout << "Inorder traversal" << endl;
    inOrder(root);
    if (isBST(root))
        cout << "Is BST" << endl;
    else
        cout << "Not a BST" << endl;
    return 0;
}

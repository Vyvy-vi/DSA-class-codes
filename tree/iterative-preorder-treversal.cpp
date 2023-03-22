/*
Preorder traversal of tree iteratively
*/

#include <iostream>
#include <stack>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    node() : data(0), left(NULL), right(NULL) {}
    node(int x) : data(x), left(NULL), right(NULL) {}
};

void preOrderTraversal(node *root)
{
    if (root == NULL)
        return;

    stack<node *> s;
    s.push(root);

    while (!s.empty())
    {
        node *curr = s.top();
        s.pop();
        if (curr != NULL)
        {
            cout << curr->data << " ";
            s.push(curr->right);
            s.push(curr->left);
        }
    }
    cout << endl;
}

void preOrderTraversalTest(node *root)
{
    if (root == NULL)
        return;

    stack<node *> s;
    s.push(root);

    while (!s.empty())
    {
        node *curr = s.top();
        s.pop();
        if (curr != NULL)
        {
            cout << curr->data << " ";
            s.push(curr->right);
            if (curr->left != NULL)
            {
                cout << curr->left->data << " ";
                if (curr->left->right)
                    s.push(curr->left->right);
            }
        }
    }
    cout << endl;
}

int main(void)
{
    node *root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    root->right->left = new node(60);
    root->right->right = new node(70);
    root->left->left = new node(40);
    root->left->right = new node(50);

    preOrderTraversal(root);
    preOrderTraversalTest(root);
}
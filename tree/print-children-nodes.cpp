/*
Print children nodes
yyhu
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

void printChildNodes(node *root)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        cout << root->data << " ";
    }
    printChildNodes(root->left);
    printChildNodes(root->right);
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
    root->left->right->left = new node(80);

    printChildNodes(root);
}
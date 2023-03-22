/*
Find Diameter
Diameter is the maximum nodes between two leaf nodes, includinng the leaf nodes
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

int getHeight(node *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(getHeight(root->left), getHeight(root->right));
}

// O(n^2) - worst case (if tree is skewed to left or right, i.e. max nodes are at one side)
int getDiameter(node *root)
{
    if (root == NULL)
        return 0;

    int d1 = getHeight(root->left) + getHeight(root->right);
    int d2 = getDiameter(root->left);
    int d3 = getDiameter(root->right);

    return max(d1, max(d2, d3));
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

    cout << getDiameter(root) << endl;
}
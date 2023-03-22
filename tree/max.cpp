#include <iostream>
#include <queue>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    node() : data(0), left(NULL), right(NULL) {}
    node(int x) : data(x), left(NULL), right(NULL) {}
};

int getMax(node *root)
{
    if (root == NULL)
        return INT_MIN;
    else
        return max(root->data, max(getMax(root->left), getMax(root->right)));
}

int main()
{
    node *root = new node(20);
    root->left = new node(80);
    root->right = new node(30);
    root->right->left = new node(40);
    root->right->right = new node(50);

    cout << getMax(root) << endl;
}
/*
Convert this tree to a double linked list that represent the inorder traversal of the tree
*/

#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    node() : data(0), left(NULL), right(NULL) {}
    node(int x) : data(x), left(NULL), right(NULL) {}
};

node *pre = NULL;
node *tree2dllInorder(node *root)
{
    if (root == NULL)
    {
        return root;
    }
    node *head = tree2dllInorder(root->left);

    if (pre == NULL)
    {
        head = root;
    }
    else
    {
        root->left = pre;
        pre->right = root;
    }
    pre = root;

    tree2dllInorder(root->right);
    return head;
}

void printDLL(node *head)
{
    if (head == NULL)
    {
        cout << endl;
        return;
    }
    cout << head->data << " ";
    printDLL(head->right);
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

    node *ans = tree2dllInorder(root);
    printDLL(ans);
}
#include <iostream>
#include <queue>
using namespace std;

// find the Kth smallest element
// search() - O(n) with array or LL, O(log n) with BST
// insertion - O(1) with array or LL, O(log n) with BST
// deletion - O(n) with array or LL, O(log n) with BST
// Kth smallest element - O(n) everywhere, O(h+k) with BST -> inorder traversal

struct node
{
    int val;
    node *left;
    node *right;
    node(int _val) : val(_val), left(NULL), right(NULL) {}
};

node *insert(node *root, int val)
{
    if (root == NULL)
        return new node(val);
    else if (val < root->val)
        root->left = insert(root->left, val);
    else if (val > root->val)
        root->right = insert(root->right, val);

    return root;
}

int count = 0;
void print_kth_smallest_element(node *root, int k)
{
    if (root != NULL)
    {
        print_kth_smallest_element(root->left, k);
        ::count++;
        if (::count == k)
        {
            cout << root->val << endl;
            return;
        }
        print_kth_smallest_element(root->right, k);
    }
}

void printKLevel(node *root)
{
    if (root == NULL)
        return;
    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *curr = q.front();
        q.pop();
        cout << curr->val << " ";
        if (curr->left != NULL)
        {
            q.push(curr->left);
        }
        if (curr->right != NULL)
        {
            q.push(curr->right);
        }
    }
    cout << endl;
}

int main()
{
    node *root = new node(40);
    root = insert(root, 20);
    root = insert(root, 80);
    root = insert(root, 10);
    root = insert(root, 90);
    root = insert(root, 60);
    root = insert(root, 30);
    printKLevel(root);
    print_kth_smallest_element(root, 2);
}
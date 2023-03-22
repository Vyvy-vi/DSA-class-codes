#include <iostream>
using namespace std;

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

bool check_bst(node *root, int min = INT_MIN, int max = INT_MAX)
{
    if (root == NULL)
        return true;

    return (
        root->val > min &&
        root->val < max &&
        check_bst(root->left, min, root->val) &&
        check_bst(root->right, root->val, max));
}

// broken
bool check_bst_broken(node *root)
{
    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL)
        return true;

    bool val = true;

    if (root->left != NULL && root->left->val > root->val)
        val = false;
    if (root->right != NULL && root->right->val < root->val)
        val = false;

    return val && check_bst(root->left) && check_bst(root->right);
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

    cout << boolalpha << check_bst(root) << endl;

    root->left->left = new node(1000);

    cout << boolalpha << check_bst(root) << endl;
}
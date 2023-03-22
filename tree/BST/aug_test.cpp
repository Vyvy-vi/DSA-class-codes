#include <iostream>
using namespace std;

struct node
{

    int val;
    node *left;
    node *right;
    int lcount;
    node(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
        lcount = 0;
    }
};

node *insert(node *root, int x)
{
    if (root == NULL)
        return new node(x);

    if (x < root->val)
    {
        root->left = insert(root->left, x);
        root->lcount++;
    }

    else if (x > root->val)
        root->right = insert(root->right, x);

    return root;
}

node *kthsmallestelement(node *root, int k)
{
    if (root == NULL)
        return root;

    int count = root->lcount + 1;
    if (count == k)
    {
        return root;
    }
    if (k < count)
    {
        return kthsmallestelement(root->left, k);
    }
    return kthsmallestelement(root->right, k - count);
}

int main()
{
    node *root = NULL;
    int keys[] = {20, 8, 22, 4, 12, 10, 14};
    for (auto x : keys)
    {
        root = insert(root, x);
    }

    node *ans = kthsmallestelement(root, 4);
    if (ans == NULL)
    {
        cout << "Not possible";
    }
    else
    {
        cout << ans->val << endl;
    }
}
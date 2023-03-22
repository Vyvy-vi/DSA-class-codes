// Augmented BST for finding Kth smallest-element
// i) k == lcount + 1 -> return root
// ii) k < lcount + 1 -> return root->left
// iii) k > lcount + 1 -> return root->right (k -> k-lcount-1)

#include <iostream>
#include <queue>
using namespace std;

struct node
{
    int val;
    int lcount;
    node *left;
    node *right;
    node(int _val) : val(_val), lcount(0), left(NULL), right(NULL) {}
};

node *insert(node *root, int val)
{
    if (root == NULL)
        return new node(val);
    if (val < root->val)
    {
        root->left = insert(root->left, val);
        root->lcount++;
    }
    else if (val > root->val)
        root->right = insert(root->right, val);

    return root;
}

node *KthSmallestElement(node *root, int k)
{
    if (root == NULL)
        return root;

    int count = root->lcount + 1;

    if (k == count)
        return root;

    if (k < count)
        return KthSmallestElement(root->left, k);

    return KthSmallestElement(root->right, k - count);
}

int main()
{
    node *root = NULL;

    int keys[] = {20, 8, 22, 4, 12, 10, 14};
    for (auto x : keys)
    {
        root = insert(root, x);
    }

    node *ans = KthSmallestElement(root, 4);

    if (ans != NULL)
        cout << ans->val << endl;
    else
        cout << "Can't find Kth smallest element" << endl;
}
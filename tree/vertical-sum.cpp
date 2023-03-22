#include <iostream>
#include <map>
using namespace std;

// Print vertical sum of tree
// We can use a map here

struct node
{
    int data;
    node *left;
    node *right;

    node(int _data) : data(_data), left(NULL), right(NULL) {}
};

void vSum_R(node *root, int hd, map<int, int> &vertical_sum)
{
    if (root == NULL)
        return;

    vSum_R(root->left, hd - 1, vertical_sum);
    vertical_sum[hd] += root->data;
    vSum_R(root->right, hd + 1, vertical_sum);
}

void getVerticalSum(node *root)
{
    map<int, int> vertical_sum;
    vSum_R(root, 0, vertical_sum);

    for (auto it : vertical_sum)
    {
        cout << it.second << " ";
    }
    cout << endl;
}

int main()
{
    node *root = new node(10);
    root->left = new node(20);
    root->left->left = new node(40);
    root->left->right = new node(50);
    root->right = new node(30);
    // root->right->left = new node(70);
    root->right->right = new node(60);

    getVerticalSum(root);
}
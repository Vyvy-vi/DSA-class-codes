#include <iostream>
#include <queue>
using namespace std;

struct node
{
    int val;
    node *left;
    node *right;
    node() : val(0), left(NULL), right(NULL) {}
    node(int _val) : val(_val), left(NULL), right(NULL) {}
};

// O(h) time, O(h) space
bool searchBST(node *root, int val)
{
    if (root == NULL)
        return false;
    else if (val == root->val)
        return true;
    else if (val < root->val)
        return searchBST(root->left, val);
    else
        return searchBST(root->right, val);
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

// O(h) time, O(1) space
bool searchBSTIteratively(node *curr, int val)
{
    while (curr != NULL)
    {
        if (val == curr->val)
            return true;
        else if (val < curr->val)
            curr = curr->left;
        else
            curr = curr->right;
    }
    return false;
}

// O(n) time, O(log n) space
node *insertBST_R(node *root, int val)
{
    if (root == NULL)
        return new node(val);
    else if (val > root->val)
        root->right = insertBST_R(root->right, val);
    else if (val < root->val)
        root->left = insertBST_R(root->left, val);

    return root;
}

// O(n) time, O(1) space
node *insertBST_I(node *root, int val)
{
    node *temp = new node(val);
    node *curr = root;
    node *parent = NULL;
    while (curr != NULL)
    {
        parent = curr;
        if (val < curr->val)
            curr = curr->left;
        else if (val > curr->val)
            curr = curr->right;
        else
            return root;
    }

    if (parent == NULL)
        return root;
    if (parent->val < val)
        parent->right = temp;
    else if (parent->val > val)
        parent->left = temp;

    return root;
}

node *getInorderSuccessor(node *root)
{
    root = root->right;
    while (root != NULL && root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

// inorder succesor (when higher value child is inserted at root when root deleted)
// inorder predeccesor (when lower value child is inserted at root when root deleted)
// this function uses the inorder successor
node *deleteBST_R(node *root, int val)
{
    if (root == NULL)
        return root;

    if (val < root->val)
        root->left = deleteBST_R(root->left, val);
    else if (val > root->val)
        root->right = deleteBST_R(root->right, val);
    else
    {
        node *temp;
        if (root->left != NULL && root->right != NULL)
        {
            node *inorder_successor = getInorderSuccessor(root);
            root->val = inorder_successor->val;
            root->right = deleteBST_R(root->right, inorder_successor->val);
            return root;
        }
        else if (root->left == NULL)
            temp = root->right;
        else if (root->right == NULL)
            temp = root->left;

        delete root;
        return temp;
    }
    return root;
}

node *getFloor(node *root, int val)
{
    node *result = NULL;

    while (root)
    {
        if (val == root->val)
            return root;
        else if (val < root->val)
            root = root->left;
        else
        {
            result = root;
            root = root->right;
        }
    }
    return result;
}

int main()
{
    node *root = new node(20);
    root->left = new node(15);
    root->right = new node(30);
    root->right->right = new node(40);
    root->right->right->right = new node(50);
    root->left->left = new node(12);
    root->left->right = new node(18);
    root->right->right->left = new node(35);
    root->right->right->right->right = new node(80);
    root->left->left->left = new node(7);

    cout << searchBST(NULL, 11) << endl;
    cout << searchBST(root, 1) << endl;
    cout << searchBST(root, 20) << endl;
    cout << searchBST(root, 15) << endl;
    cout << searchBST(root, 40) << endl;
    cout << searchBST(root, 50) << endl;
    cout << searchBST(root, 12) << endl;
    cout << searchBST(root, 18) << endl;
    cout << searchBST(root, 35) << endl;
    cout << searchBST(root, 80) << endl;
    cout << searchBST(root, 7) << endl;

    cout << endl;

    cout << searchBSTIteratively(NULL, 11) << endl;
    cout << searchBSTIteratively(root, 1) << endl;
    cout << searchBSTIteratively(root, 20) << endl;
    cout << searchBSTIteratively(root, 15) << endl;
    cout << searchBSTIteratively(root, 40) << endl;
    cout << searchBSTIteratively(root, 50) << endl;
    cout << searchBSTIteratively(root, 12) << endl;
    cout << searchBSTIteratively(root, 18) << endl;
    cout << searchBSTIteratively(root, 35) << endl;
    cout << searchBSTIteratively(root, 80) << endl;
    cout << searchBSTIteratively(root, 7) << endl;

    cout << endl;

    printKLevel(root);
    node *ans = insertBST_R(root, 0);
    printKLevel(ans);
    cout << searchBSTIteratively(ans, 0) << endl;

    printKLevel(root);
    ans = insertBST_I(root, 1);
    printKLevel(ans);
    cout << searchBSTIteratively(ans, 1) << endl;

    printKLevel(root);
    ans = deleteBST_R(root, 1);
    printKLevel(ans);
    cout << searchBSTIteratively(ans, 1) << endl;

    printKLevel(root);
    ans = deleteBST_R(root, 20);
    printKLevel(ans);
    cout << searchBSTIteratively(ans, 20) << endl;

    node *root2 = new node(20);
    root2->left = new node(5);
    root2->right = new node(15);
    root2->right->left = new node(12);
    root2->right->right = new node(30);

    cout << "Floor of 14: " << getFloor(root2, 14)->val << endl;
    cout << "Floor of 4: " << getFloor(root2, 4)->val << endl;
    cout << "Floor of 12: " << getFloor(root2, 12)->val << endl;
    cout << "Floor of 100: " << getFloor(root2, 100)->val << endl;
    cout << "Floor of 1000: " << getFloor(root2, 1000)->val << endl;
}
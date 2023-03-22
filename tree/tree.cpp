/*
Tree data structure
- used to represent heirarchial data
- recursive in nature
- non-linear data structure

- Root node : has no parent
- Leaf nodes (external nodes) : have no children
- Internal nodes
- Root node is a special kind of internal node

- decendents: all child nodes branching from the parent
- ancestors: all parents leading to the child node

Applications of trees:
- used to represent heirarchical data
  - HTML content / json objects
  - inheritence oops
  - file directory
  - org structure
- Binary Search Tree
- Binary Heap
- used to represent priority queues: needed for Kruskal's, Prim's, Dijkstra's
- B and B+ ->
  - used for indexing in DB
  - alternative to hashing
- Spanning tree Algorithm (concept used by bridges)
- Shortest path (concept used by routers)
- Parse tree
- Suffix tree
  - used for fast searching in strings
  - preprocess the text and making suffix tree of that
  - O(m) size of pattern
- Binary index tree
  - used to search query in the given range
  - faster, but range is limited
- Segment trees
 - more powerful in range
*/

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

void preorder(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";

    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int heightOfTree(node *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(heightOfTree(root->left), heightOfTree(root->right));
}

int heightOfTrees(node *root, int level = 0)
{
    if (root == NULL)
        return level;
    return max(heightOfTrees(root->left, level + 1), heightOfTrees(root->right, level + 1));
}

int countNodes(node *root)
{
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// print nodes at distance k
void printNodesAtDistanceK(node *root, int k)
{
    if (root == NULL)
        return;
    if (k == 0)
        cout << root->data << " ";

    printNodesAtDistanceK(root->left, k - 1);
    printNodesAtDistanceK(root->right, k - 1);
}

void levelByLevelTraversal(node *root)
{
    int height = heightOfTree(root);
    for (int i = 0; i < height; i++)
    {
        printNodesAtDistanceK(root, i);
        cout << endl;
    }
    cout << endl;
}

// space complexity O(w) - w = width of tree
// time complexity O(n)
void levelByLevelQueue(node *root)
{
    if (root == NULL)
        return;
    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *curr = q.front();
        q.pop();
        cout << curr->data << " ";
        if (curr->left != NULL)
            q.push(curr->left);

        if (curr->right != NULL)
            q.push(curr->right);
    }
    cout << endl;
}

// O(h) space
// O(n) time
int maxNode(node *root)
{
    if (root == NULL)
        return INT_MIN;
    return max(max(maxNode(root->left), maxNode(root->right)), root->data);
}

// O(h) space
// O(n) time
int minNode(node *root)
{
    if (root == NULL)
        return INT_MIN;
    return min(min(minNode(root->left), minNode(root->right)), root->data);
}

void leftView(node *root)
{
    if (root == NULL)
        return;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int count = q.size();
        for (int i = 0; i < count; i++)
        {
            node *curr = q.front();
            q.pop();
            if (i == 0)
            {
                cout << curr->data << " ";
            }
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
    }
    cout << endl;
}

void rightView(node *root)
{
    if (root == NULL)
        return;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int count = q.size();
        for (int i = 0; i < count; i++)
        {
            node *curr = q.front();
            q.pop();
            if (i == count - 1)
            {
                cout << curr->data << " ";
            }
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
    }
    cout << endl;
}

bool checkChildrenSumProperty(node *root)
{
    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }

    int sum = ((root->left != NULL) ? root->left->data : 0) + ((root->right != NULL) ? root->right->data
                                                                                     : 0);
    if (root->data != sum)
        return false;
    return checkChildrenSumProperty(root->left) && (checkChildrenSumProperty(root->right));
}

// O(n^2)
bool checkBalancedTreeByHeight(node *root)
{
    if (root == NULL)
        return true;
    return (abs(heightOfTree(root->left) - heightOfTree(root->right)) <= 1) && checkBalancedTreeByHeight(root->left) && checkBalancedTreeByHeight(root->right);
}

// O(n)
int checkBalanced(node *root)
{
    if (root == NULL)
        return 0;

    int lh = checkBalanced(root->left);
    if (lh == -1)
        return -1;

    int rh = checkBalanced(root->right);
    if (rh == -1)
        return -1;

    if (abs(lh - rh) > 1)
        return -1;

    return 1 + max(lh, rh);
}

// O(n)
bool checkBinaryTree(node *root)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->left != NULL && root->right == NULL)
    {
        return false;
    }
    else if (root->right != NULL && root->left == NULL)
    {
        return false;
    }
    return checkBinaryTree(root->left) && checkBinaryTree(root->right);
}

int maxWidthOfBinaryTree(node *root)
{
    if (root == NULL)
        return 0;
    queue<node *> q;
    q.push(root);
    int res = 0;
    while (!q.empty())
    {
        int count = q.size();
        res = max(res, count);
        for (int i = 0; i < count; i++)
        {
            node *curr = q.front();
            q.pop();
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
    }
    return res;
}

// assumption - elements are distinct
node *lowestCommonAncestor(node *root, int val1, int val2)
{
    if (root == NULL)
        return NULL;

    if (root->data == val1 || root->data == val2)
        return root;

    node *lcaLeft = lowestCommonAncestor(root->left, val1, val2);
    node *lcaRight = lowestCommonAncestor(root->right, val1, val2);

    if (lcaLeft != NULL && lcaRight != NULL)
        return root;
    else if (lcaLeft != NULL)
        return lcaLeft;
    else
        return lcaRight;
}

int main()
{
    node *root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    root->right->left = new node(40);
    root->right->right = new node(50);
    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
    cout << endl;

    node *root2 = new node(1);
    root2->left = new node(2);
    root2->right = new node(3);
    root2->left->left = new node(4);
    root2->right->right = new node(5);
    root2->left->left->left = new node(6);
    root2->left->left->right = new node(7);
    root2->right->right->left = new node(8);
    root2->right->right->right = new node(9);
    root2->right->right->right->right = new node(10);

    cout << endl;

    cout << heightOfTree(NULL) << endl;
    cout << heightOfTree(new node(10)) << endl;
    cout << heightOfTree(root) << endl;
    cout << heightOfTree(root2) << endl;

    cout << endl;

    cout << countNodes(NULL) << endl;
    cout << countNodes(new node(10)) << endl;
    cout << countNodes(root) << endl;
    cout << countNodes(root2) << endl;

    cout << endl;

    printNodesAtDistanceK(root, 0);
    cout << endl;
    printNodesAtDistanceK(root, 1);
    cout << endl;
    printNodesAtDistanceK(root, 2);
    cout << endl;
    printNodesAtDistanceK(root, 3);
    cout << endl;

    levelByLevelTraversal(root);
    levelByLevelTraversal(root2);

    levelByLevelQueue(root);
    levelByLevelQueue(root2);

    cout << endl;

    cout << maxNode(root) << endl;
    cout << maxNode(root2) << endl;

    cout << endl;

    leftView(root);
    leftView(root2);

    rightView(root);
    rightView(root2);

    node *root3 = new node(2);
    root3->left = new node(2);

    node *root4 = new node(5);
    root4->left = new node(2);
    root4->right = new node(3);
    root4->left->left = new node(1);
    root4->left->right = new node(1);

    node *root6 = new node(5);
    root6->left = new node(2);
    root6->left->left = new node(3);

    cout << endl;

    cout << checkChildrenSumProperty(NULL) << endl;
    cout << checkChildrenSumProperty(new node(10)) << endl;
    cout << checkChildrenSumProperty(root3) << endl;
    cout << checkChildrenSumProperty(root4) << endl;
    cout << checkChildrenSumProperty(root) << endl;

    cout << endl;

    cout << checkBinaryTree(NULL) << endl;
    cout << checkBinaryTree(new node(10)) << endl;
    cout << checkBinaryTree(root3) << endl;
    cout << checkBinaryTree(root4) << endl;
    cout << checkBinaryTree(root) << endl;

    cout << endl
         << "---";
    cout << endl;

    cout << checkBalancedTreeByHeight(NULL) << endl;
    cout << checkBalancedTreeByHeight(new node(10)) << endl;
    cout << checkBalancedTreeByHeight(root3) << endl;
    cout << checkBalancedTreeByHeight(root4) << endl;
    cout << checkBalancedTreeByHeight(root6) << endl;

    cout << checkBalanced(NULL) << endl;
    cout << checkBalanced(new node(10)) << endl;
    cout << checkBalanced(root3) << endl;
    cout << checkBalanced(root4) << endl;
    cout << checkBalanced(root6) << endl;
    cout << endl
         << "---";
    cout << endl;

    cout << maxWidthOfBinaryTree(NULL) << endl;
    cout << maxWidthOfBinaryTree(new node(10)) << endl;
    cout << maxWidthOfBinaryTree(root3) << endl;
    cout << maxWidthOfBinaryTree(root4) << endl;
    cout << maxWidthOfBinaryTree(root) << endl;

    cout << endl;

    node *root5 = new node(10);
    root5->left = new node(20);
    root5->right = new node(30);
    root5->right->left = new node(50);
    root5->right->right = new node(60);
    root5->right->left->left = new node(70);
    root5->right->right->left = new node(80);
    root5->right->right->right = new node(90);
    root5->right->right->right->right = new node(40);

    cout << lowestCommonAncestor(new node(10), 10, 10)->data << endl;

    for (int i = 10; i <= 90; i += 10)
    {
        for (int j = 20; j <= 90; j += 10)
        {
            node *ans = lowestCommonAncestor(root5, i, j);
            cout << i << ", " << j << " -> lca = " << ans->data << endl;
        }
    }
}

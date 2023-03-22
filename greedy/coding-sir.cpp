#include <iostream>
#include <queue>
using namespace std;

struct node
{
    char ch;
    int freq;
    node *left;
    node *right;

    node(
        char _ch,
        int _freq,
        node *_left = NULL,
        node *_right = NULL) : ch(_ch), freq(_freq), left(_left), right(_right) {}
};

void PHC(node *root, string str);

struct cmp
{
    bool operator()(node *l, node *r) const
    {
        return l->freq > r->freq;
    }
};

template <size_t N>
void HuffmanCode(char (&arr)[N], int (&freq)[N])
{
    priority_queue<node *, vector<node *>, cmp> nodeMinHeap;
    for (int i = 0; i < N; i++)
        nodeMinHeap.push(new node(arr[i], freq[i]));

    while (nodeMinHeap.size() > 1)
    {
        node *left = nodeMinHeap.top();
        nodeMinHeap.pop();
        node *right = nodeMinHeap.top();
        nodeMinHeap.pop();

        nodeMinHeap.push(new node('$', left->freq + right->freq, left, right));
    }
    PHC(nodeMinHeap.top(), "");
}

void PHC(node *root, string str)
{
    if (root->ch != '$')
    {
        cout << root->ch << ": " << str << endl;
        return;
    }

    PHC(root->left, str + "0");
    PHC(root->right, str + "1");
}

int main()
{
    char alpha[] = {'a', 'd', 'b', 'e', 'f'};
    int freqs[] = {10, 50, 20, 40, 80};
    HuffmanCode(alpha, freqs);
}
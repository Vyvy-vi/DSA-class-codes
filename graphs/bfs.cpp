#include <iostream>
#include <queue>
using namespace std;

// bfs is like level order traversal
void BFS(vector<int> adj[], int v, bool visited[])
{

    queue<int> q;
    visited[v] = true;
    q.push(v);

    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        cout << p << " ";
        for (int x : adj[p])
        {
            if (!visited[x])
            {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int v)
{
    for (int i = 0; i < v; i++)
    {
        for (auto x : adj[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}

int BFS_wrapper(vector<int> adj[], int v)
{
    bool visited[v];
    // no of connected comoponents / islands -
    int cnt = 0;
    for (int i = 0; i < v; i++)
        visited[i] = false;

    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            BFS(adj, i, visited);
            cnt++;
        }
    }
    cout << endl;
    return cnt;
}

int main()
{
    int v = 4;
    vector<int> adj[v];

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);

    // BFS(adj, v, 0);
    cout << BFS_wrapper(adj, v) << endl;
}
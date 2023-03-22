#include <iostream>
#include <queue>
using namespace std;

void DFS_R(vector<int> adj[], int s, bool visited[])
{
    visited[s] = true;
    cout << s << " ";

    for (int u : adj[s])
    {
        if (!visited[u])
            DFS_R(adj, u, visited);
    }
}

int DFS(vector<int> adj[], int v)
{
    bool visited[v];
    for (int i = 0; i < v; i++)
        visited[i] = false;

    int count = 0;

    for (int i = 0; i < v; i++)
    {
        cout << endl;
        DFS_R(adj, i, visited);
        count++;
    }
    return count;
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{
    int v = 8;
    vector<int> adj[v];

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 4);
    addEdge(adj, 3, 4);
    addEdge(adj, 5, 6);
    addEdge(adj, 7, 7);

    cout << DFS(adj, v) << endl;
    // cout << DFS_recursion(adj, v) << endl;
}
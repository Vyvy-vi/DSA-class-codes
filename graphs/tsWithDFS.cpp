/*
Topological Sorting

DFS traversal used here
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

void DFS_R(vector<int> adj[], int s, bool visited[], stack<int> &stk)
{
    visited[s] = true;

    for (int u : adj[s])
    {
        if (!visited[u])
            DFS_R(adj, u, visited, stk);
    }
    stk.push(s);
}

void ts(vector<int> adj[], int v)
{
    bool visited[v];
    stack<int> stk;

    for (int i = 0; i < v; i++)
        visited[i] = false;

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
            DFS_R(adj, i, visited, stk);
    }

    while (!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;
}

int main()
{
    int v = 5;

    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 3, 4);

    ts(adj, v);
}
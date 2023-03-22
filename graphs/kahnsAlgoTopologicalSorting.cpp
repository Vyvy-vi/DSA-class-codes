/*
Topological Sorting

BFS traversal used here

Analysis of clustering algorithms for credit risk evaluation using multiple correspondence analysis
*/

#include <iostream>
#include <queue>
using namespace std;

int v = 6;
vector<int> in_degree(v, 0);

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    in_degree[v]++;
}

void ts(vector<int> adj[], int v)
{
    queue<int> q;

    for (int i = 0; i < v; i++)
    {
        if (in_degree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (int x : adj[u])
        {
            if (--in_degree[x] == 0)
                q.push(x);
        }
    }

    cout << endl;
}

int main()
{
    vector<int> adj[v];

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 3, 5);

    ts(adj, v);
}
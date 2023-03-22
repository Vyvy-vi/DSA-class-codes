#include <iostream>
#include <queue>
using namespace std;

// application of BFS

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void shortest_path(vector<int> adj[], int v, int source)
{
    bool visited[v];
    for (int i = 0; i < v; i++)
        visited[i] = false;

    int distance[v];
    for (int i = 0; i < v; i++)
        distance[i] = INT_MAX;

    distance[0] = 0;

    queue<int> q;
    visited[source] = true;
    q.push(source);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int x : adj[curr])
        {
            if (!visited[x])
            {
                visited[x] = true;
                distance[x] = distance[curr] + 1;
                q.push(x);
            }
        }
    }

    for (int i = 0; i < v; i++)
        cout << distance[i] << " ";
    cout << endl;
}

int main()
{
    int v = 4;
    vector<int> adj[v];

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);

    shortest_path(adj, v, 0);
}
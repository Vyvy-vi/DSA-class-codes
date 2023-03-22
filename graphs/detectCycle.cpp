/* Detect cycle in undirected graph
 input: 1 - 2 - 3 - 4
                | - 5
 output: false
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool DFS_R(vector<int> adj[], int source, bool visited[], int parent)
{
    visited[source] = true;
    for (int child : adj[source])
    {
        if (!visited[child])
        {
            if (DFS_R(adj, child, visited, source))
                return true;
        }
        else if (parent != child)
        {
            return true;
        }
    }
    return false;
}

bool DFS(vector<int> adj[], int v)
{
    bool visited[v];
    for (int i = 0; i < v; i++)
        visited[i] = false;

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            if (DFS_R(adj, i, visited, -1))
                return true;
        }
    }

    return false;
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

    cout << DFS(adj, v) << endl;

    int v2 = 5;
    vector<int> adj2[v2];

    addEdge(adj2, 0, 1);
    addEdge(adj2, 0, 2);
    addEdge(adj2, 0, 3);
    addEdge(adj2, 1, 4);

    cout << DFS(adj2, v2) << endl;
}

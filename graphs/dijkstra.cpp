#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

#define V 4

vector<int> dijkstra(int graph[V][V], int source)
{
    vector<int> key(V, INT_MAX);

    bool mset[V] = {false};
    key[source] = 0;

    for (int count = 0; count < V; count++)
    {
        int u = -1;
        for (int i = 0; i < V; i++)
        {
            if (mset[i] == false && (u == -1 || key[i] < key[u]))
                u = i;
        }

        mset[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] != 0 && mset[v] == false)
                key[v] = min(key[v], key[u] + graph[u][v]);
        }
    }
    return key;
}

int main()
{
    int graph[V][V] = {
        {0, 5, 10, 0},
        {5, 0, 3, 20},
        {10, 3, 0, 2},
        {0, 20, 2, 0},
    };

    vector<int> dist = dijkstra(graph, 0);
    for (auto x : dist)
        cout << x << " ";
    cout << endl;
    return 0;
}
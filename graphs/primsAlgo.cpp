/*
Minimum Spanning Tree
(Prims Algorithm)
*/

#include <iostream>
using namespace std;
#include <algorithm>

#define V 4
int MST(int graph[V][V])
{
    int key[V];
    fill(key, key + V, INT_MAX);
    int res = 0;
    bool mset[V] = {false};
    key[0] = 0;
    for (int count = 0; count < V; count++)
    {
        int u = -1;
        for (int i = 0; i < V; i++)
        {
            if (mset[i] == false && (u == -1 || key[i] < key[u]))
            {
                u = i;
            }
        }
        mset[u] = true;
        res = res + key[u];
        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] != 0 && mset[v] == false)
            {
                key[v] = min(key[v], graph[u][v]);
            }
        }
    }
    return res;
}
int main()
{
    int graph[V][V] = {
        {0, 5, 2, 1},
        {5, 0, 7, 3},
        {2, 7, 0, 9},
        {1, 3, 9, 0},
    };
    cout << MST(graph);
    return 0;
}
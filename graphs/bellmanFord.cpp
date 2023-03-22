#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

#define V 4
#define E 5

struct Edge
{
    int src, dest, weight;

    Edge(int _src, int _dest, int _weight) : src(_src), dest(_dest), weight(_weight) {}
};

void print_distance(int dist[], int prev[], int source)
{
    cout << "Start at " << char(65 + source) << ": " << dist[source] << endl;
    for (int i = 1; i < V; i++)
    {
        cout << char(65 + i)
             << " (via "
             << char(65 + prev[i])
             << "): "
             << dist[i] << endl;
    }
}

void bellmanFord(Edge graph[E], int source = 0)
{
    int distance[V];
    int prev[V];

    for (int i = 0; i < V; i++)
        distance[i] = INT_MAX;

    distance[source] = 0;
    prev[source] = -1;

    // relax
    for (int i = 0; i < V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            Edge e = graph[j];

            if (distance[e.src] + e.weight < distance[e.dest])
            {
                distance[e.dest] = distance[e.src] + e.weight;
                prev[e.dest] = e.src;
            }
        }
    }

    // check for negative-weight cycle
    for (int i = 0; i < E; i++)
    {
        Edge e = graph[i];

        if (distance[e.src] + e.weight < distance[e.dest])
        {
            cout << "Cycle detected" << endl;
            return;
        }
    }

    print_distance(distance, prev, source);
}

int main()
{
    Edge graph[E] = {
        Edge(0, 1, 1),
        Edge(0, 2, 4),
        Edge(1, 2, -3),
        Edge(1, 3, 2),
        Edge(2, 3, 3)};

    bellmanFord(graph);
}
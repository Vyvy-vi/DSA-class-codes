#include <iostream>
#include <algorithm>

#define V 4
#define E 6

int parent[V];
int ranks[V];

using namespace std;

struct Edge
{
    int src, dest, wt;
    Edge() {}
    Edge(int s, int d, int w) : src(s), dest(d), wt(w) {}
};

int finds(int i)
{
    if (parent[i] == i)
        return i;

    return finds(parent[i]);
}

void unions(int i, int j)
{
    i = finds(parent[i]);
    j = finds(parent[j]);

    if (ranks[i] < ranks[j])
    {
        parent[i] = j;
    }
    else if (ranks[j] < ranks[i])
    {
        parent[j] = i;
    }
    else
    {
        parent[j] = i;
        ranks[i]++;
    }
}

bool edgeComp(Edge a, Edge b)
{
    return a.wt < b.wt;
}

int kruskals(Edge arr[])
{
    sort(arr, arr + E, edgeComp);
    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
        ranks[i] = 0;
    }

    int res = 0;
    for (int i = 0, s = 0; s < V - 1; i++)
    {
        Edge e = arr[i];
        int x = finds(e.src);
        int y = finds(e.dest);

        if (x != y)
        {
            res += e.wt;
            unions(x, y);
            s++;
        }
    }
    return res;
}

int main()
{
    Edge graph[E];
    graph[0] = Edge(0, 1, 2);
    graph[1] = Edge(1, 2, 8);
    graph[2] = Edge(2, 3, 4);
    graph[3] = Edge(0, 3, 7);
    graph[4] = Edge(0, 2, 3);
    graph[5] = Edge(1, 3, 6);

    cout << kruskals(graph) << endl;
    return 0;
}

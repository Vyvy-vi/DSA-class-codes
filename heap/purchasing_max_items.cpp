#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

template <size_t N>
int purchasing_max_items(int (&cost)[N], int cost_sum)
{
    sort(cost, cost + N);
    int count = 0;
    for (int i = 0; (i < N && cost_sum > 0); i++)
    {
        cost_sum -= cost[i];
        count++;
    }
    return count;
}

// O(N)
template <size_t N>
int purchasing_max_items_eff(int (&cost)[N], int cost_sum)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < N; i++)
    {
        pq.push(cost[i]);
    }

    int count = 0;
    while (cost_sum > 0)
    {
        cost_sum -= pq.top();
        pq.pop();
        count++;
    }

    return count;
}

int main()
{
    int cost_sum = 10;
    int cost[] = {5, 6, 1, 2, 3, 4};

    cout << purchasing_max_items_eff(cost, cost_sum) << endl;
}
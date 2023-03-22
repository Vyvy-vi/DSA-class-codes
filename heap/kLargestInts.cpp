#include <iostream>
#include <queue>
using namespace std;

// O(N + K.log N)
template <size_t N>
void printKLargest_KLOGN(int (&arr)[N], int k = 1)
{
    priority_queue<int> pq;

    for (int i = 0; i < N; i++)
        pq.push(arr[i]);

    for (int i = 0; i < k; i++)
    {
        cout << pq.top() << endl;
        pq.pop();
    }
}

// O(N +  (N - k) * log k)
// O(N + log N) for k ~= N

// O(N + N.log N) for k << N
// O(N.log N) for k << N

template <size_t N>
void printKLargest(int (&arr)[N], int k = 1)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    // O(k)
    for (int i = 0; i < k; i++)
        pq.push(arr[i]);

    // O((N - k) * log k)
    for (int i = k; i < N; i++)
    {
        if (pq.top() < arr[i])
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    // O(k)
    while (!pq.empty())
    {
        cout << pq.top() << endl;
        pq.pop();
    }
}

int main()
{
    int arr[] = {10, 35, 1, 2, 89, 20, 11};
    int k = 2;
    printKLargest(arr, k);
}
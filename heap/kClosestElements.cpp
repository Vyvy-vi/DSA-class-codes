#include <iostream>
#include <queue>
using namespace std;

// theta(order of K.N), O(N^2)
template <size_t N>
void kClosestElements(int (&arr)[N], int x, int k)
{
    bool visited[N] = {false};

    for (int i = 0; i < k; i++)
    {
        int minDiff = INT_MAX;
        int minIndex;
        for (int j = 0; j < N; j++)
        {
            if (abs(arr[j] - x) < minDiff && visited[j] == false)
            {
                minDiff = abs(arr[j] - x);
                minIndex = j;
            }
        }
        cout << arr[minIndex] << " ";
        visited[minIndex] = true;
    }
    cout << endl;
}

// make max heap with paired first k elements
// insert pair<int, int> {DIFF, INDEX} for first k elements
// O(N.logK)
template <size_t N>
void kClosestElementsEff(int (&arr)[N], int x, int k)
{
    priority_queue<pair<int, int>> diffQueue;

    for (int i = 0; i < k; i++)
        diffQueue.push({abs(arr[i] - x), i});

    for (int i = k; i < N; i++)
    {
        if (abs(arr[i] - x) < diffQueue.top().first)
        {
            diffQueue.pop();
            diffQueue.push({abs(arr[i] - x), i});
        }
    }

    while (!diffQueue.empty())
    {
        cout << arr[diffQueue.top().second] << " ";
        diffQueue.pop();
    }
    cout << endl;
}

int main()
{
    int arr[] = {10, 30, 5, 40, 38, 80, 70};
    kClosestElements(arr, 25, 3);
    kClosestElementsEff(arr, 25, 3);
}
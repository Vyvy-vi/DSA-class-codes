#include <iostream>
#include <queue>
using namespace std;

double getMedian(vector<int> &v)
{
    if (v.size() == 1)
        return v[0];
    if (v.size() == 2)
        return (v[0] + v[1]) / 2.0;

    sort(v.begin(), v.end());

    int mid = v.size() / 2;

    if (v.size() % 2 == 0)
    {
        return (v[mid] + v[mid - 1]) / 2.0;
    }
    else
    {
        return v[mid];
    }
}

// O(N^2 log N)
template <size_t N>
void printMedianFromStream_Ineff(int (&arr)[N])
{
    vector<int> v;

    for (int i = 0; i < N; i++)
    {
        v.push_back(arr[i]);
        cout << getMedian(v) << " ";
    }
    cout << endl;
}

template <size_t N>
void printMedianFromStream_eff(int (&arr)[N])
{
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    maxHeap.push(arr[0]);
    cout << maxHeap.top() << " ";

    for (int i = 1; i < N; i++)
    {
        if ((arr[i] < maxHeap.top()) && maxHeap.size() > minHeap.size())
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            maxHeap.push(arr[i]);
        }
        else if (maxHeap.size() > minHeap.size())
            minHeap.push(arr[i]);
        else if (arr[i] <= maxHeap.top())
            maxHeap.push(arr[i]);
        else
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
            minHeap.push(arr[i]);
        }

        if (i & 1)
            cout << (maxHeap.top() + minHeap.top()) / 2.0 << " ";
        else
            cout << maxHeap.top() << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {25, 7, 10, 15, 20};
    int arr2[] = {6, 5, 4, 3, 2, 1};
    int arr3[] = {6, 2, 9, 3, 5, 4, 1, 7};

    printMedianFromStream_Ineff(arr);

    printMedianFromStream_eff(arr);
    printMedianFromStream_eff(arr2);
    printMedianFromStream_eff(arr3);
}
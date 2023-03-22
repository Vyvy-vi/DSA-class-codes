#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> pq;

    // On insertion in priority queue, a max heap is created by default

    pq.push(20);
    pq.push(70);
    pq.push(10);
    pq.push(90);
    pq.push(40);

    cout << pq.top() << endl;

    int arr[] = {20, 70, 10, 90, 40};
    priority_queue<int> pq2(arr, arr + 5);
    cout << pq2.top() << endl;

    vector<int> v = {20, 70, 10, 80, 40};
    priority_queue<int> pq3(v.begin(), v.end());
    cout << pq3.top() << endl;
}

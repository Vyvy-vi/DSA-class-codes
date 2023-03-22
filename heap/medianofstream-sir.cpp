#include <iostream>
using namespace std;

// O(n^2)
int main()
{
    int arr[] = {25, 7, 10, 15, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int temp[n];

    int size = 0;
    for (int i = 0; i < n; i++)
    {
        temp[i] = arr[i];
        size++;

        int j = i;

        while (j > 0 && temp[j] < temp[j - 1])
        {
            swap(temp[j], temp[j - 1]);
            j--;
        }

        if (size & 1)
            cout << temp[size / 2] << " ";
        else
            cout << (temp[size / 2] + temp[(size / 2) - 1]) / 2.0 << " ";
    }
    cout << endl;
}
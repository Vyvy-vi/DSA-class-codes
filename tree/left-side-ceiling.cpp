#include <iostream>
#include <set>
using namespace std;

// naive method O(n^2)
template <size_t n>
void printCeil(int (&arr)[n])
{
    cout << -1 << " ";
    for (int i = 1; i < n; i++)
    {
        int d = INT_MAX;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] >= arr[i])
                d = min(d, arr[j] - arr[i]);
        }
        if (d == INT_MAX)
            cout << -1 << " ";
        else
            cout << d + arr[i] << " ";
    }
    cout << endl;
}

// efficient approach with trees (sets) O(n.log(n))
template <size_t n>
void printCeil_Eff(int (&arr)[n])
{
    cout << -1 << " ";

    set<int> s;

    for (int i = 0; i < n - 1; i++)
    {
        s.insert(arr[i]);
        auto val = s.lower_bound(arr[i + 1]);
        if (val != s.end())
            cout << *val << " ";
        else
            cout << -1 << " ";
    }

    cout << endl;
}

int main()
{
    int arr[] = {2, 8, 30, 15, 25, 12};
    int arr2[] = {5, 4, 3, 2, 1};
    int arr3[] = {1, 2, 3, 4, 5};

    printCeil(arr);
    printCeil(arr2);
    printCeil(arr3);

    cout << endl;

    printCeil_Eff(arr);
    printCeil_Eff(arr2);
    printCeil_Eff(arr3);
}
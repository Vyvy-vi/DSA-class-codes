#include <iostream>
#define capacity 10
using namespace std;

inline static int left(int i)
{
    return 2 * i + 1;
}

inline static int right(int i)
{
    return 2 * i + 2;
}

inline static int parent(int i)
{
    return (i & 1) ? (i - 1) / 2 : i / 2;
}

int insert(int arr[], int size, int key)
{
    if (size == capacity)
    {
        throw std::overflow_error("Overflow. Can't insert more elements in heap");
        return size;
    }

    size++;

    int i = size - 1;
    arr[i] = key;

    while (i != 0 && arr[parent(i)] > arr[i])
    {
        swap(arr[parent(i)], arr[i]);
        i = parent(i);
    }

    return size;
}

void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[capacity] = {1, 3, 5};
    int size = 3;

    print(arr, size);

    size = insert(arr, size, 4);

    print(arr, size);

    size = insert(arr, size, 2);

    print(arr, size);
}
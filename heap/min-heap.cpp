#include <iostream>
#include <vector>
using namespace std;

struct MinHeap
{
    int *arr;
    int size;
    int capacity;

    MinHeap(int cap) : arr(new int[cap]), size(0), capacity(cap) {}

    static inline int left(int i)
    {
        return 2 * i + 1;
    }

    static inline int right(int i)
    {
        return 2 * i + 2;
    }

    static inline int parent(int i)
    {
        return (i & 1) ? (i - 1) / 2 : i / 2;
    }

    void insert(int key)
    {
        if (size == capacity)
        {
            throw std::overflow_error("Overflow. Can't insert more elements in heap");
            return;
        }

        size++;

        int i = size - 1;
        arr[i] = key;

        while (i != 0 && arr[parent(i)] > arr[i])
        {
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }

    void print(int *array = NULL, int arr_size = 0)
    {
        if (array == NULL)
        {
            array = arr;
            arr_size = size;
        }
        for (int i = 0; i < arr_size; i++)
            cout << array[i] << " ";
        cout << endl;
    }

    void MinHeapify(int i = 0, int *array = NULL, int arr_size = 0)
    {
        if (array == NULL)
        {
            array = arr;
            arr_size = size;
        }
        int l = left(i);
        int r = right(i);
        int smallest = i;

        if (l < arr_size && array[l] < array[smallest])
            smallest = l;

        if (r < arr_size && array[r] < array[smallest])
            smallest = r;

        if (smallest != i)
        {
            swap(array[smallest], array[i]);
            MinHeapify(smallest, array, arr_size);
        }
    }

    void MaxHeapify(int i = 0, int *array = NULL, int arr_size = 0)
    {
        if (array == NULL)
        {
            array = arr;
            arr_size = size;
        }
        int l = left(i);
        int r = right(i);
        int largest = i;

        if (l < arr_size && array[l] > array[largest])
            largest = l;

        if (r < arr_size && array[r] > array[largest])
            largest = r;

        if (largest != i)
        {
            swap(array[largest], array[i]);
            MaxHeapify(largest, array, arr_size);
        }
    }

    int extractMin()
    {
        if (size < 0)
            return INT_MAX;

        if (size == 1)
        {
            size--;
            return arr[0];
        }

        swap(arr[0], arr[--size]);
        MinHeapify(0);
        return arr[size];
    }

    void decreaseKey(int index, int val)
    {
        if (index >= size)
        {
            throw std::overflow_error("Can't fetch key at index larger than the size of the heap.");
            return;
        }
        arr[index] = val;

        while (index != 0 && arr[index] < arr[parent(index)])
        {
            swap(arr[index], arr[parent(index)]);
            index = parent(index);
        }
    }

    void deleteKey(int index)
    {
        decreaseKey(index, INT_MIN);
        extractMin();
    }

    // this is O(n)
    template <size_t N>
    void buildHeap(int (&arr)[N])
    {
        for (int i = (N - 2) / 2; i >= 0; i--)
            MinHeapify(i, arr, N);
    }

    // O(n.logn)
    template <size_t N>
    void heapSort(int (&arr)[N], bool reverse = false)
    {
        buildHeap(arr);
        for (int i = N - 1; i > 0; i--)
        {
            if (reverse)
            {
                swap(arr[0], arr[i]); // swap root with last leaf node
                MinHeapify(0, arr, i);
            }

            else
            {
                swap(arr[0], arr[i]);
                MaxHeapify(0, arr, i);
            }
        }
    }
};

template <size_t N>
MinHeap buildNewHeap(int (&arr)[N])
{
    MinHeap temp = MinHeap(N);
    for (int i = 0; i < N; i++)
    {
        temp.insert(arr[i]);
    }
    return temp;
}

int main()
{
    MinHeap m = MinHeap(5);
    m.insert(6);
    m.insert(5);
    m.insert(4);
    m.insert(3);
    m.insert(2);
    m.print();

    m.arr[0] = INT_MAX;
    m.print();

    m.MinHeapify();
    m.print();

    m.deleteKey(2);
    m.print();

    cout << endl;

    int arr[] = {50, 40, 30, 20, 10};
    int N = sizeof(arr) / sizeof(arr[0]);

    cout << "Array: ";
    m.print(arr, N);
    MinHeap m2 = buildNewHeap(arr);

    cout << "BuildHeap (insertion-based): ";
    m2.print();
    m.buildHeap(arr);
    cout << "BuildHeap (minheapify-based): ";
    m.print(arr, N);

    int arr2[] = {5, 4, 3, 2, 1};
    m.print(arr2, N);
    m.heapSort(arr2, true);
    m.print(arr2, N);
    m.heapSort(arr2);
    m.print(arr2, N);
}
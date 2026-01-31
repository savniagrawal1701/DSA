
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n)
{
    int startIdx = (n / 2) - 1;

    for (int i = startIdx; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int minheap[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    int n = sizeof(minheap) / sizeof(minheap[0]);
    cout << "The min heap is " << endl;
    printArray(minheap, n);
    buildHeap(minheap, n);
    cout << "The convertes max heap is :" << endl;
    printArray(minheap, n);

    return 0;
}

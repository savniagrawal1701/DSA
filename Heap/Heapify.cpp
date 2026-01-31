#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i; //
    int left = 2 * i; // (Note: Use 2*i+1 for 0-indexed)
    int right = 2 * i + 1; // (Note: Use 2*i+2 for 0-indexed)

    if (left < n && arr[largest] < arr[left]) { //
        largest = left; //
    }
    if (right < n && arr[largest] < arr[right]) { //
        largest = right; //
    }

    if (largest != i) { //
        swap(arr[largest], arr[i]); //
        heapify(arr, n, largest); //
    }
}

int main() {
    int arr[] = {0, 10, 20, 15, 30, 40}; // Index 0 is often a placeholder in 1-indexed heaps
    int n = 6;
    heapify(arr, n, 1);
    cout << "Heap after heapifying at index 1: ";
    for(int i = 1; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}
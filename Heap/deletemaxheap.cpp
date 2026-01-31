#include <iostream>
#include <algorithm>
using namespace std;

class Heap {
public:
    int arr[100];
    int size;

    Heap() {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val) {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1) {
            int parent = index / 2;
            if (arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                return;
            }
        }
    }

    void deletefromHeap() {
        if (size == 0) {
            cout << "No element present" << endl;
            return;
        }

        arr[1] = arr[size];
        size = size - 1;

        int i = 1;
        while (i < size) {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            if (leftIndex <= size && arr[leftIndex] > arr[i] && (rightIndex > size || arr[leftIndex] > arr[rightIndex])) {
                swap(arr[leftIndex], arr[i]);
                i = leftIndex;
            } 
            else if (rightIndex <= size && arr[rightIndex] > arr[i]) {
                swap(arr[rightIndex], arr[i]);
                i = rightIndex;
            } 
            else {
                return;
            }
        }
    }

    void print() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Heap h;
    
    // Inserting elements into the Max-Heap
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    cout << "Heap before deletion: ";
    h.print();

    h.deletefromHeap();
    cout << "Heap after deleting root: ";
    h.print();

    return 0;
}
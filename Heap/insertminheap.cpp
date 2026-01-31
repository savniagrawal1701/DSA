#include <iostream>
#include <algorithm>
using namespace std;

class MinHeap {
public:
    int arr[100];
    int size;

    MinHeap() {
        size = 0;
    }

    void insert(int val) {
        size = size + 1;
        int index = size;
        arr[index] = val; 
        while (index > 1) {
            int parent = index / 2;

            if (arr[parent] > arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
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
    MinHeap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    
    cout << "Heap elements after insertion(Min heap): ";
    h.print(); // Output: 50 52 53 55 54 (or similar valid min-heap structure)
    return 0;
}

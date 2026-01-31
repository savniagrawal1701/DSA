// here the root is having the index 1 not 0
// array also starts from 1
#include <iostream>
#include <algorithm>

using namespace std;

class Heap
{
public:
    int arr[100]; // Array to store heap elements
    int size;

    // Constructor
    Heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent; // index = parent; updates the index variable to the parent's index, allowing the while loop to move up one level in the tree in the next iteration
            }
            else
            {
                return;
            }
        }
    }
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    cout << "Heap elements after insertion: ";
    h.print();

    return 0;
}

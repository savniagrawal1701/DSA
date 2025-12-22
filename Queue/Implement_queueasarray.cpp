#include <iostream>

using namespace std;

class ArrayQueue {
private:
    int *arr;
    int start, end;
    int currSize, maxSize;

public:
    ArrayQueue() {
        maxSize = 10;
        arr = new int[maxSize];
        start = -1;
        end = -1;
        currSize = 0;
    }

    void push(int val) {
        if (currSize == maxSize) {
            cout << "Queue Overflow: Cannot push " << val << endl;
            return;
        }
        if (currSize == 0) {
            start = 0;
            end = 0;
        } else {
            // Corrected: Use maxSize for circular wrapping
            end = (end + 1) % maxSize;
        }
        arr[end] = val;
        currSize++;
    }

    int pop() {
        if (currSize == 0) {
            cout << "Queue Underflow: Queue is empty" << endl;
            return -1;
        }
        int element = arr[start];
        if (currSize == 1) {
            // Corrected: Reset to -1 when empty
            start = -1;
            end = -1;
        } else {
            // Corrected: Use maxSize for circular wrapping
            start = (start + 1) % maxSize;
        }
        currSize--;
        return element;
    }

    int topele() {
        if (currSize == 0) return -1;
        return arr[start];
    }

    int size() {
        return currSize;
    }

    void display() {
        if (currSize == 0) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements: ";
        int i = start;
        for (int count = 0; count < currSize; count++) {
            cout << arr[i] << " ";
            i = (i + 1) % maxSize;
        }
        cout << endl;
    }
};

int main() {
    ArrayQueue q;
    int choice, val;

    do {
        cout << "\n--- QUEUE MENU ---" << endl;
        cout << "1. Push (Enqueue)" << endl;
        cout << "2. Pop (Dequeue)" << endl;
        cout << "3. Peek (Top/Front Element)" << endl;
        cout << "4. Display All Elements" << endl;
        cout << "5. Show Current Size" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            q.push(val);
            break;
        case 2:
            val = q.pop();
            if (val != -1) cout << "Popped element: " << val << endl;
            break;
        case 3:
            val = q.topele();
            if (val != -1) cout << "Front element: " << val << endl;
            else cout << "Queue is empty!" << endl;
            break;
        case 4:
            q.display();
            break;
        case 5:
            cout << "Current Queue Size: " << q.size() << endl;
            break;
        case 6:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
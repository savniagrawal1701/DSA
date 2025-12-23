#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *next;
    Node(int d) {
        val = d;
        next = NULL;
    }
};

class LinkedListQueue {
private:
    Node *start; 
    Node *end; 
    int currentSize; 

public:
    LinkedListQueue() {
        start = end = NULL;
        currentSize = 0;
    }

    void push(int x) {
        Node *temp = new Node(x);
        if(start == NULL) {
            start = end = temp;
        }
        else {
            end->next = temp; 
            end = temp; 
        }
        currentSize++;
    }

    int pop() {
        if (start == NULL) {
            return -1; 
        }
        
        int value = start->val; 
        Node *temp = start; 
        start = start->next; 

        if (start == NULL) {
            end = NULL;
        }

        delete temp; 
        currentSize--; 
        return value; 
    }
    
    int peek() {
        if (start == NULL) {
            return -1; 
        }
        return start->val; 
    }

    bool isEmpty() {
        return (currentSize == 0);
    }

    int getSize() {
        return currentSize;
    }

    void display() {
        if (start == NULL) {
            cout << "Queue is empty." << endl;
            return;
        }
        Node *temp = start;
        cout << "Queue (Front to Rear): ";
        while (temp != NULL) {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedListQueue q;
    int choice, value;

    do {
        cout << "\n--- QUEUE MENU (Linked List) ---" << endl;
        cout << "1. Push (Enqueue)" << endl;
        cout << "2. Pop (Dequeue)" << endl;
        cout << "3. Peek (Front Element)" << endl;
        cout << "4. Display All" << endl;
        cout << "5. Check if Empty" << endl;
        cout << "6. Get Size" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                q.push(value);
                cout << value << " added to queue." << endl;
                break;
            case 2:
                value = q.pop();
                if (value == -1) cout << "Queue Underflow!" << endl;
                else cout << "Removed element: " << value << endl;
                break;
            case 3:
                value = q.peek();
                if (value == -1) cout << "Queue is empty!" << endl;
                else cout << "Front element: " << value << endl;
                break;
            case 4:
                q.display();
                break;
            case 5:
                if (q.isEmpty()) cout << "Queue is empty." << endl;
                else cout << "Queue is not empty." << endl;
                break;
            case 6:
                cout << "Current size: " << q.getSize() << endl;
                break;
            case 7:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
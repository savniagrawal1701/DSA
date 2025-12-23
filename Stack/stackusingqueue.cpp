#include <bits/stdc++.h>
using namespace std;

class QueueStack {
    queue<int> q;

public:
    void push(int x) {
        int s = q.size(); 
        q.push(x); 

        for (int i = 0; i < s; i++) {
            q.push(q.front()); 
            q.pop(); 
        }
    }

    int pop() {
        if (q.empty()) return -1;
        int n = q.front(); 
        q.pop(); 
        return n; 
    }

    int top() {
        if (q.empty()) return -1;
        return q.front(); 
    }

    bool isEmpty() {
        return q.empty(); 
    }

    int size() {
        return q.size();
    }

    void display() {
        if (q.empty()) {
            cout << "Stack is empty." << endl;
            return;
        }

        // We use a copy of the queue so we don't destroy the original data
        queue<int> temp = q;
        cout << "Stack (Top to Bottom): ";
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    QueueStack st;
    int choice, val;

    do {
        cout << "\n--- STACK MENU (Using Queue) ---" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Top (Peek)" << endl;
        cout << "4. Display" << endl;
        cout << "5. Check Empty" << endl;
        cout << "6. Current Size" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> val;
                st.push(val);
                break;
            case 2:
                val = st.pop();
                if (val == -1) cout << "Stack is empty!" << endl;
                else cout << "Popped value: " << val << endl;
                break;
            case 3:
                val = st.top();
                if (val == -1) cout << "Stack is empty!" << endl;
                else cout << "Top element: " << val << endl;
                break;
            case 4:
                st.display();
                break;
            case 5:
                if (st.isEmpty()) cout << "Stack is empty." << endl;
                else cout << "Stack is not empty." << endl;
                break;
            case 6:
                cout << "Size: " << st.size() << endl;
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
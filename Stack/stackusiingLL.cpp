#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node
{
    int val;
    Node *next;
    Node(int d)
    {
        val = d;
        next = NULL;
    }
};

// Structure to represent stack
class LinkedListStack
{
private:
    Node *top; // Top of Stack
    int size;  // Size

public:
    // Constructor
    LinkedListStack()
    {
        top = NULL;
        size = 0;
    }

    void push(int x)
    {
        Node *temp = new Node(x);

        temp->next = top;
        top = temp;

        size++;
    }

    int pop()
    {

        if (top == NULL)
        {
            return -1;
        }

        int value = top->val;
        Node *temp = top;
        top = top->next;
        delete temp;
        size--;

        return value;
    }

    int tope()
    {

        if (top == NULL)
        {
            return -1;
        }

        return top->val; // Return the top
    }
    int sizeofstack()
    {
        return size;
    }
    bool isEmpty()
    {
        return (size == 0);
    }
    void display()
    {
        if (top == NULL)
        {
            cout << "Stack is empty." << endl;
            return;
        }

        Node *temp = top;
        cout << "Stack (Top to Bottom): ";
        while (temp != NULL)
        {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    LinkedListStack st;
    int choice, value;

    do
    {
        cout << "\n--- STACK MENU ---" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display All" << endl;
        cout << "5. Show Size" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            st.push(value);
            break;
        case 2:
            value = st.pop();
            if (value == -1)
                cout << "Stack Underflow!" << endl;
            else
                cout << "Popped: " << value << endl;
            break;
        case 3:
            value = st.tope();
            if (value == -1)
                cout << "Stack is empty!" << endl;
            else
                cout << "Top: " << value << endl;
            break;
        case 4:
            st.display();
            break;
        case 5:
            cout << "Size: " << st.sizeofstack() << endl;
            break;
        case 6:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 6);

    return 0;
}
#include <iostream>

using namespace std;

class Stack
{
private:
    // Array to hold elements
    int *st;
    // Maximum capacity
    int capacity;
    // Index of top element
    int top;

public:
    // Constructor
    Stack(int size = 1000)
    {
        capacity = size;
        st = new int[capacity];
        top = -1;
    }

    void push(int val)
    {
        if (top >= 100)
        {
            cout << "Stack Overflow: Cannot push element " << val << endl;
            return;
        }
        top++;
        st[top] = val;
    }
    int topele()
    {
        if (top ==-1)
        {
            cout << "Stack Underflow: Cannot pop element from empty stack" << endl;
            return -1;
        }

        return st[top];
    }

    void pop()
    {
        if (top ==-1)
        {
            cout << "Stack Underflow: Cannot pop element from empty stack" << endl;
            return;
        }

        top--;
    }

    int size()
    {
        return top + 1;
    }

    void display()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements (top to bottom): ";
        for (int i = top; i >= 0; i--)
        {
            cout << st[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.display();

    cout << "Top element is: " << s.topele() << endl;

    s.pop();
    s.display();

    s.pop();
    s.pop();
    s.pop(); // Attempting to pop from an empty stack (Underflow case)

    return 0;
}

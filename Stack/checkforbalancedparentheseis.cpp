#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (auto it : s) {
            if (it == '(' || it == '{' || it == '[')
                st.push(it);
            else {
                if (st.empty()) return false;
                char ch = st.top();
                st.pop();

                if ((it == ')' && ch == '(') ||
                    (it == ']' && ch == '[') ||
                    (it == '}' && ch == '{'))
                    continue;
                else
                    return false;
            }
        }
        return st.empty();
    }
};

int main() {
    Solution sol;
    string input;
    int choice;

    do {
        cout << "\n--- VALID PARENTHESES CHECKER ---" << endl;
        cout << "1. Check a string" << endl;
        cout << "2. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter bracket string (e.g., {([])}): ";
                cin >> input;
                if (sol.isValid(input)) {
                    cout << "Result: Valid (True)" << endl;
                } else {
                    cout << "Result: Invalid (False)" << endl;
                }
                break;
            case 2:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 2);

    return 0;
}
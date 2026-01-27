#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
   
    bool isValid(string s) {
       
        int minOpen = 0, maxOpen = 0;

        for (char c : s) {
            if (c == '(') {
                minOpen++;
                maxOpen++;
            } else if (c == ')') {
                minOpen--;
                maxOpen--;
            } else {
              
                minOpen--;
                maxOpen++;
            }

            if (maxOpen < 0) return false;

            minOpen = max(minOpen, 0);
        }
        return minOpen == 0;
    }
};

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;

    Solution sol;
    if (sol.isValid(s)) {
        cout << "Valid parenthesis string" << endl;
    } else {
        cout << "Invalid parenthesis string" << endl;
    }
    return 0;

}

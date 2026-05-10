#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to print Pattern 7
    void pattern8(int N) {
        // Outer loop for rows
        for (int i = 0; i < N; i++) {
            
            for (int j = 0; j < i ; j++) {
                cout << " ";
            }

            for (int j = 0; j < 2*N-2 * i - 1; j++) {
                cout << "*";
            }

            for (int j = 0; j <i ; j++) {
                cout << " ";
            }

            // Move to next row
            cout << endl;
        }
    }
};

int main() {
    Solution sol;
    int N = 5;
    sol.pattern8(N);
    return 0;
}
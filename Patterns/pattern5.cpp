#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to print Pattern 6
    void pattern5(int N) {
        // Outer loop for rows
        for (int i = 0; i <N; i++) {
           
            for (int j = i; j <N; j++) {
                cout << "*";
            }
          
            cout << endl;
        }
    }
};

int main() {
    // Create object of Solution class
    Solution sol;

    // Define size of pattern
    int N = 5;

    // Call pattern function
    sol.pattern5(N);

    return 0;
}
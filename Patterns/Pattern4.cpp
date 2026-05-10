#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to print Pattern 6
    void pattern4(int N) {
        // Outer loop for rows
        for (int i = 1; i <=N; i++) {
           
            for (int j = 1; j <=i; j++) {
                cout << i;
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
    sol.pattern4(N);

    return 0;
}
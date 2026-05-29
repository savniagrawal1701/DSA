#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to compute maximum price obtainable by cutting the rod
    int rodCutting(vector<int> price, int n) {

        // Initialize a DP table where dp[i][j] stores the max price 
        // using first i rod lengths to make total rod length j
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        // Fill the base case: only using the first rod length (length = 1)
        for(int length = 0; length <= n; length++) {
            // We can use rod of length 1 (index 0) multiple times
            dp[0][length] = length * price[0];
        }

        // Iterate through each rod piece starting from index 1
        for(int i = 1; i < n; i++) {
            for(int length = 0; length <= n; length++) {

                // Option 1: Do not cut with this rod (copy from above)
                int notTake = dp[i - 1][length];

                // Option 2: Cut with current rod length (reuse allowed)
                int take = INT_MIN;
                int rodLength = i + 1;

                // Check if this rod fits in current length
                if(rodLength <= length) {
                    take = price[i] + dp[i][length - rodLength];
                }

                // Store the best value in the DP table
                dp[i][length] = max(take, notTake);
            }
        }

        // Return the answer from the last row and column (full rod length)
        return dp[n - 1][n];
    }
};

// Driver code
int main() {
    // Length of the rod
    int n = 8;

    // Price list where price[i] is the value of rod of length i+1
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};

    // Create object of Solution class
    Solution obj;

    // Call rodCutting function and print the result
    int maxValue = obj.rodCutting(price, n);
    cout << "The maximum obtainable value is: " << maxValue << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to solve the rod cutting problem
    int rodCutting(vector<int>& price, int n) {
        // Initialize DP table with dimensions [n][n + 1]
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));
        
        for(int length = 0; length <= n; length++){
            dp[0][length] = price[0]*length;
        }
        
        // Fill the DP table
        for (int ind = 1; ind < n; ++ind) { 
            for (int length = 1; length <= n; ++length) { 
                
                // Case when the piece is not taken
                int notTaken = 0+dp[ind - 1][length];
                
                // Case when the piece is taken
                int taken = INT_MIN;
                
                /* Length of the rod piece 
                corresponding to the current index*/
                int rodLength = ind + 1;
                
                // Check if the piece can be taken
                if (rodLength <= length) {
                    taken = price[ind] + dp[ind][length - rodLength];
                }
                
                /* Update dp[ind][length] with the maximum of 
                including or not including the current piece*/
                dp[ind][length] = max(notTaken, taken);
            }
        }
        
        // Return the result 
        return dp[n - 1][n];
    }
};

int main() {
    vector<int> price = {2, 4, 6, 8};
    int n = price.size();

    // Create an instance of Solution class
    Solution sol;

    // Print the result
    cout << "The Maximum value is " << sol.rodCutting(price, n) << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to solve the rod cutting problem
    int rodCutting(vector<int>& price, int n) {
        // Initialize DP table with dimensions [n + 1]
        vector<int> prev(n+1, 0), cur(n+1, 0);
        
        for(int length = 0; length <= n; length++){
            prev[length] = price[0]*length;
        }
        
        // Fill the DP table
        for (int ind = 1; ind < n; ++ind) { 
            for (int length = 1; length <= n; ++length) { 
                
                // Case when the piece is not taken
                int notTaken = 0+prev[length];
                
                // Case when the piece is taken
                int taken = INT_MIN;
                
                /* Length of the rod piece 
                corresponding to the current index*/
                int rodLength = ind + 1;
                
                // Check if the piece can be taken
                if (rodLength <= length) {
                    taken = price[ind] + cur[length - rodLength];
                }
                
                /* Update cur[length] with the maximum of 
                including or not including the current piece*/
                cur[length] = max(notTaken, taken);
            }
            prev = cur;
        }
        
        // Return the result 
        return prev[n];
    }
};

int main() {
    vector<int> price = {2, 4, 6, 8};
    int n = price.size();

    // Create an instance of Solution class
    Solution sol;

    // Print the result
    cout << "The Maximum value is " << sol.rodCutting(price, n) << endl;

    return 0;
}
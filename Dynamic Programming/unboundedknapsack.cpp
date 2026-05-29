#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Utility function for solving the unbounded knapsack problem using recursion + memoization
    int knapsackUtil(vector<int>& wt, vector<int>& val, int ind, int W, vector<vector<int>>& dp) {
        // Base case: if we're at the first item
        if (ind == 0) {
            // Calculate and return the maximum value for the given weight limit
            return (W / wt[0]) * val[0];
        }

        // If the result for this index and weight limit is already calculated, return it
        if (dp[ind][W] != -1)
            return dp[ind][W];

        // Calculate the maximum value without taking the current item
        int notTaken = knapsackUtil(wt, val, ind - 1, W, dp);

        // Initialize 'taken' with a very small value
        int taken = INT_MIN;

        // If current item can fit in the remaining capacity
        if (wt[ind] <= W)
            taken = val[ind] + knapsackUtil(wt, val, ind, W - wt[ind], dp);

        // Store and return the maximum of taking or not taking the current item
        return dp[ind][W] = max(notTaken, taken);
    }

    // Main function to call the utility function and set up DP table
    int unboundedKnapsack(int n, int W, vector<int>& val, vector<int>& wt) {
        // Create a DP table initialized with -1
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));

        // Call the recursive function and return the answer
        return knapsackUtil(wt, val, n - 1, W, dp);
    }
};

// Driver code
int main() {
    // Initialize item weights
    vector<int> wt = {2, 4, 6};

    // Initialize item values
    vector<int> val = {5, 11, 13};

    // Weight capacity of the knapsack
    int W = 10;

    // Number of items
    int n = wt.size();

    // Create Solution object
    Solution obj;

    // Output the result
    cout << "The Maximum value of items the thief can steal is " 
         << obj.unboundedKnapsack(n, W, val, wt) << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to solve the unbounded knapsack problem using tabulation
    int unboundedKnapsack(int n, int W, vector<int>& val, vector<int>& wt) {
        // Create a DP table where dp[i][j] represents max value using first i items and capacity j
        vector<vector<int>> dp(n, vector<int>(W + 1, 0));

        // Base condition: fill first row considering infinite supply of first item
        for (int i = wt[0]; i <= W; i++) {
            dp[0][i] = (i / wt[0]) * val[0];
        }

        // Loop through all items starting from second
        for (int ind = 1; ind < n; ind++) {
            // Loop through all capacities from 0 to W
            for (int cap = 0; cap <= W; cap++) {
                // Case 1: Not taking the current item
                int notTaken = dp[ind - 1][cap];

                // Case 2: Taking the current item (if it fits)
                int taken = INT_MIN;
                if (wt[ind] <= cap)
                    taken = val[ind] + dp[ind][cap - wt[ind]];

                // Store the best of both choices
                dp[ind][cap] = max(notTaken, taken);
            }
        }

        // Return the maximum value possible for n items and capacity W
        return dp[n - 1][W];
    }
};

// Driver code
int main() {
    // Item weights
    vector<int> wt = {2, 4, 6};

    // Item values
    vector<int> val = {5, 11, 13};

    // Knapsack capacity
    int W = 10;

    // Number of items
    int n = wt.size();

    // Create object
    Solution obj;

    // Output result
    cout << "The Maximum value of items the thief can steal is "
         << obj.unboundedKnapsack(n, W, val, wt) << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to solve the unbounded knapsack problem using space-optimized DP
    int unboundedKnapsack(int n, int W, vector<int>& val, vector<int>& wt) {
        // Create a 1D DP array where cur[cap] stores max value for given capacity
        vector<int> cur(W + 1, 0);

        // Base condition: fill values for first item
        for (int i = wt[0]; i <= W; i++) {
            cur[i] = (i / wt[0]) * val[0];
        }

        // Iterate through remaining items
        for (int ind = 1; ind < n; ind++) {
            for (int cap = 0; cap <= W; cap++) {
                // Option 1: Not take current item
                int notTaken = cur[cap];

                // Option 2: Take current item (if it fits)
                int taken = INT_MIN;
                if (wt[ind] <= cap) {
                    taken = val[ind] + cur[cap - wt[ind]];
                }

                // Store the better option
                cur[cap] = max(notTaken, taken);
            }
        }

        // Return max value for capacity W
        return cur[W];
    }
};

int main() {
    vector<int> wt = {2, 4, 6}; // Weights of items
    vector<int> val = {5, 11, 13}; // Values of items
    int W = 10; // Capacity of knapsack
    int n = wt.size(); // Number of items

    Solution obj; // Create Solution object
    cout << "The Maximum value of items the thief can steal is "
         << obj.unboundedKnapsack(n, W, val, wt) << endl;

    return 0;
}
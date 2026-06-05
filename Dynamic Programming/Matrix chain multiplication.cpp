#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the minimum multiplication cost
    int matrixChainOrder(vector<int>& arr, int i, int j) {
        // Base case: if only one matrix is present, no multiplication needed
        if (i == j) return 0;

        // Initialize minimum cost as very large
        int minCost = INT_MAX;

        // Try all possible partitions
        for (int k = i; k < j; k++) {
            // Cost of multiplying matrices from i to k
            int cost1 = matrixChainOrder(arr, i, k);

            // Cost of multiplying matrices from k+1 to j
            int cost2 = matrixChainOrder(arr, k + 1, j);

            // Cost of multiplying the two resulting matrices
            int costMultiply = arr[i - 1] * arr[k] * arr[j];

            // Total cost for this partition
            int total = cost1 + cost2 + costMultiply;

            // Update minimum
            minCost = min(minCost, total);
        }

        return minCost;
    }
};

// Driver code
int main() {
    Solution sol;
    vector<int> arr = {40, 20, 30, 10, 30}; 
    int n = arr.size();

    cout << "Minimum number of multiplications is: "
         << sol.matrixChainOrder(arr, 1, n - 1) << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Recursive function with memoization
    int solve(vector<int>& arr, int i, int j, vector<vector<int>>& dp) {
        // Base case: only one matrix, no multiplication
        if (i == j) return 0;

        // If already computed, return from dp
        if (dp[i][j] != -1) return dp[i][j];

        // Initialize min cost as very large
        int minCost = INT_MAX;

        // Try every partition
        for (int k = i; k < j; k++) {
            int cost1 = solve(arr, i, k, dp);
            int cost2 = solve(arr, k + 1, j, dp);
            int costMultiply = arr[i - 1] * arr[k] * arr[j];

            int total = cost1 + cost2 + costMultiply;

            minCost = min(minCost, total);
        }

        // Store and return result
        return dp[i][j] = minCost;
    }

    // Function to start the memoization approach
    int matrixChainOrder(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(arr, 1, n - 1, dp);
    }
};

// Driver code
int main() {
    Solution sol;
    vector<int> arr = {40, 20, 30, 10, 30};
    cout << "Minimum number of multiplications is: "
         << sol.matrixChainOrder(arr) << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int matrixMultiplication(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        // A single matrix needs no multiplication cost
        for (int i = 1; i < n; ++i) {
            dp[i][i] = 0;
        }

        // Filling the dp array
        for (int length = 2; length < n; ++length) { // length of the chain
            for (int i = 1; i <= n - length; ++i) {
                int j = i + length - 1;
                for (int k = i; k < j; ++k) {
                    int cost = dp[i][k] + dp[k + 1][j] + nums[i - 1] * nums[k] * nums[j];
                    if (cost < dp[i][j]) {
                        dp[i][j] = cost;
                    }
                }
            }
        }

        // The result is in dp[1][n-1]
        return dp[1][n - 1];
    }
};

int main() {
    Solution sol;
    vector<int> nums = {10, 15, 20, 25};
    // Output should be 8000
    cout << sol.matrixMultiplication(nums) << endl; 
    return 0;
}

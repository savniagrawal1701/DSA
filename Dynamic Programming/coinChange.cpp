#include <bits/stdc++.h>
using namespace std;

// Solution class to implement memoization approach
class Solution {
public:
    // Function to find minimum coins
    int coinChange(vector<int>& coins, int amount) {
        // Creating dp array initialized with -2 
        // (-2 means not calculated yet)
        vector<int> dp(amount + 1, -2);

        // Calling helper function
        return helper(coins, amount, dp);
    }

private:
    // Helper recursive function
    int helper(vector<int>& coins, int rem, vector<int>& dp) {
        // If remaining amount is zero
        if (rem == 0) return 0;

        // If remaining amount is negative
        if (rem < 0) return -1;

        // If already computed
        if (dp[rem] != -2) return dp[rem];

        // Initialize minimum with large value
        int mini = INT_MAX;

        // Try every coin
        for (int coin : coins) {
            // Recursive call
            int res = helper(coins, rem - coin, dp);

            // If result is valid
            if (res >= 0 && res < mini)
                mini = 1 + res;
        }

        // Store result in dp
        dp[rem] = (mini == INT_MAX) ? -1 : mini;
        return dp[rem];
    }
};

// Driver function
int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    Solution obj;
    cout << obj.coinChange(coins, amount) << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

// Solution class to implement tabulation approach
class Solution {
public:
    // Function to find minimum coins
    int coinChange(vector<int>& coins, int amount) {
        // Creating dp array of size amount+1
        vector<int> dp(amount + 1, INT_MAX);

        // Base case: dp[0] = 0
        dp[0] = 0;

        // Loop through all amounts from 1 to amount
        for (int i = 1; i <= amount; i++) {
            // Try each coin
            for (int coin : coins) {
                // If coin can be used
                if (i - coin >= 0 && dp[i - coin] != INT_MAX) {
                    // Update dp[i] with minimum coins
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
            }
        }

        // If dp[amount] is still infinity, return -1
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

// Driver function
int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    Solution obj;
    cout << obj.coinChange(coins, amount) << endl;
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

// Class containing the solution method
class Solution {
public:

    // Function to compute minimum elements to reach target sum
    int minimumElements(vector<int>& arr, int T) {
        int n = arr.size();

        // Create two vectors for previous and current rows
        vector<int> prev(T + 1, 0);
        vector<int> cur(T + 1, 0);

        // Initialize base case for the first row
        for (int i = 0; i <= T; i++) {
            if (i % arr[0] == 0)
                prev[i] = i / arr[0];
            // Very large value if not possible
            else
                prev[i] = 1e9; 
        }

        // Fill table using bottom-up approach
        for (int ind = 1; ind < n; ind++) {
            for (int target = 0; target <= T; target++) {

                // Option 1: Not take the current element
                int notTake = prev[target];

                // Option 2: Take the current element if possible
                int take = 1e9;
                if (arr[ind] <= target)
                    take = 1 + cur[target - arr[ind]];

                // Store minimum of take and notTake
                cur[target] = min(notTake, take);
            }

            // Update previous row with current row values
            prev = cur;
        }

        // Retrieve answer from the last row
        int ans = prev[T];

        // Return -1 if target cannot be formed
        if (ans >= 1e9)
            return -1;

        // Return minimum number of elements required
        return ans;
    }
};

// Main function to test the solution
int main() {

    // Input array
    vector<int> arr = {1, 2, 3};

    // Target sum
    int T = 7;

    // Create object of Solution class
    Solution sol;

    // Call function to get result
    int result = sol.minimumElements(arr, T);

    // Output the result
    cout << "The minimum number of coins required to form the target sum is "
         << result << endl;

    // Return 0 to indicate successful execution
    return 0;
}
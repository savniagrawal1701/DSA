#include <bits/stdc++.h>
using namespace std;

// Recursive function with memoization to count ways to make change
long countWaysToMakeChangeUtil(vector<int>& arr, int ind, int T, vector<vector<long>>& dp) {
    // Base case: if we are at the first element
    if (ind == 0) {
        return (T % arr[0] == 0); // Only one way if divisible
    }

    // If already calculated, return stored value
    if (dp[ind][T] != -1)
        return dp[ind][T];

    // Do not take the current coin
    long notTaken = countWaysToMakeChangeUtil(arr, ind - 1, T, dp);

    // Take the current coin (if feasible)
    long taken = 0;
    if (arr[ind] <= T)
        taken = countWaysToMakeChangeUtil(arr, ind, T - arr[ind], dp);

    // Store the result in DP table
    return dp[ind][T] = notTaken + taken;
}

// Function to initialize DP table and start recursion
long countWaysToMakeChange(vector<int>& arr, int n, int T) {
    vector<vector<long>> dp(n, vector<long>(T + 1, -1));
    return countWaysToMakeChangeUtil(arr, n - 1, T, dp);
}

int main() {
    vector<int> arr = {1, 2, 3};
    int target = 4;
    int n = arr.size();

    cout << "The total number of ways is " << countWaysToMakeChange(arr, n, target) << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

// Function to count the number of ways to make change for a given target sum
long countWaysToMakeChange(vector<int>& arr, int n, int T) {
    vector<vector<long>> dp(n, vector<long>(T + 1, 0)); // Create a DP table

    // Initializing base condition
    for (int i = 0; i <= T; i++) {
        if (i % arr[0] == 0)
            dp[0][i] = 1;
        // Else condition is automatically fulfilled,
        // as dp array is initialized to zero
    }

    for (int ind = 1; ind < n; ind++) {
        for (int target = 0; target <= T; target++) {
            long notTaken = dp[ind - 1][target];

            long taken = 0;
            if (arr[ind] <= target)
                taken = dp[ind][target - arr[ind]];

            dp[ind][target] = notTaken + taken;
        }
    }

    return dp[n - 1][T];
}

int main() {
    vector<int> arr = {1, 2, 3};
    int target = 4;
    int n = arr.size();

    cout << "The total number of ways is " << countWaysToMakeChange(arr, n, target) << endl;

    return 0; // Return 0 to indicate successful program execution
}

#include <bits/stdc++.h>
using namespace std;

// Function to count the number of ways to make change for a given target sum
long countWaysToMakeChange(vector<int>& arr, int n, int T) {
    vector<long> prev(T + 1, 0);  // Create a vector to store the previous DP state

    // Initialize base condition
    for (int i = 0; i <= T; i++) {
        if (i % arr[0] == 0)
            prev[i] = 1;  // There is one way to make change for multiples of the first coin
        // Else condition is automatically fulfilled,
        // as the prev vector is initialized to zero
    }

    for (int ind = 1; ind < n; ind++) {
        vector<long> cur(T + 1, 0);  // Create a vector to store the current DP state
        for (int target = 0; target <= T; target++) {
            long notTaken = prev[target];  // Number of ways without taking the current coin

            long taken = 0;
            if (arr[ind] <= target)
                taken = cur[target - arr[ind]];  // Number of ways by taking the current coin
                
            cur[target] = notTaken + taken;  // Total number of ways for the current target
        }
        prev = cur;  // Update the previous DP state with the current state for the next coin
    }

    return prev[T];  // Return the total number of ways to make change for the target
}

int main() {
    vector<int> arr = {1, 2, 3};  // Coin denominations
    int target = 4;  // Target sum
    int n = arr.size();  // Number of coin denominations

    // Call the function to calculate and output the total number of ways to make change
    cout << "The total number of ways is " << countWaysToMakeChange(arr, n, target) << endl;

    return 0;  // Return 0 to indicate successful program execution
}
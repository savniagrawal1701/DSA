#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Recursive helper function with memoization
    // i -> current index in s
    // j -> current index in t
    // dp -> memoization table
    int helper(int i, int j, string &s, string &t,
               vector<vector<int>> &dp) {
        // If we have matched all characters of t
        // then we found one valid subsequence
        if (j == t.size()) return 1;

        // If we have exhausted s but not t
        // then no valid subsequence can be formed
        if (i == s.size()) return 0;

        // If this state has been already computed
        if (dp[i][j] != -1) return dp[i][j];

        // If current characters of s and t match
        if (s[i] == t[j]) {
            // Option 1: take this character and move both indices
            int take = helper(i + 1, j + 1, s, t, dp);

            // Option 2: skip this character of s and move only in s
            int notTake = helper(i + 1, j, s, t, dp);

            // Store result in dp table
            return dp[i][j] = take + notTake;
        } else {
            // If characters do not match, we can only skip s[i]
            return dp[i][j] = helper(i + 1, j, s, t, dp);
        }
    }

    // Main function to count distinct subsequences
    int numDistinct(string s, string t) {
        // Initialize dp table with -1 (uncomputed states)
        vector<vector<int>> dp(s.size(),
                               vector<int>(t.size(), -1));

        // Start recursion from index 0 of s and t
        return helper(0, 0, s, t, dp);
    }
};

// Driver code
int main() {
    Solution sol;

    // Input strings
    string s = "babgbag";
    string t = "bag";

    // Print number of distinct subsequences
    cout << sol.numDistinct(s, t) << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to count distinct subsequences
    int numDistinct(string s, string t) {
        // Get lengths of both strings
        int n = s.size();
        int m = t.size();

        // Create dp table of size (n+1) x (m+1)
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));

        // Base case: empty t can be formed from any suffix of s
        for (int i = 0; i <= n; i++) {
            dp[i][m] = 1;
        }

        // Fill dp table from bottom to top
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                // If characters match, we have two options:
                // 1. Take this character -> dp[i+1][j+1]
                // 2. Skip this character -> dp[i+1][j]
                if (s[i] == t[j]) {
                    dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j];
                } else {
                    // If characters don't match, we can only skip
                    dp[i][j] = dp[i + 1][j];
                }
            }
        }

        // Final answer is stored at dp[0][0]
        return dp[0][0];
    }
};

int main() {
    Solution sol;
    string s = "babgbag";
    string t = "bag";
    cout << sol.numDistinct(s, t) << endl; 
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to count distinct subsequences
    int numDistinct(string s, string t) {
        // Length of source string
        int n = s.size();
        // Length of target string
        int m = t.size();

        // Create dp array of size m+1, initialize with 0
        vector<long long> dp(m + 1, 0);

        // Base case: Empty target string can always be formed
        // in exactly 1 way (by deleting all characters of s)
        dp[m] = 1;

        // Traverse source string from end to start
        for (int i = n - 1; i >= 0; i--) {
            // Create a copy of dp for current iteration
            vector<long long> curr = dp;

            // Traverse target string from end to start
            for (int j = m - 1; j >= 0; j--) {
                // If characters match, we can either take it or skip it
                if (s[i] == t[j]) {
                    curr[j] = dp[j + 1] + dp[j];
                } 
                // Else we can only skip this character of s
                else {
                    curr[j] = dp[j];
                }
            }

            // Update dp for next iteration
            dp = curr;
        }

        // Answer is number of ways to form entire t
        return (int)dp[0];
    }
};

int main() {
    Solution sol;
    string s = "rabbbit";
    string t = "rabbit";
    cout << sol.numDistinct(s, t) << endl; 
    return 0;
}

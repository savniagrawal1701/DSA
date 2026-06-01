#include <bits/stdc++.h>
using namespace std;

// Function to calculate the edit distance between two strings
int editDistanceUtil(string& S1, string& S2, int i, int j, vector<vector<int>>& dp) {
    // Base cases
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;

    // If the result for this state has already been calculated, return it
    if (dp[i][j] != -1)
        return dp[i][j];

    // If the characters at the current positions match, no operation is needed
    if (S1[i] == S2[j])
        return dp[i][j] = 0 + editDistanceUtil(S1, S2, i - 1, j - 1, dp);

    // Minimum of three choices:
    // 1. Replace the character at S1[i] with the character at S2[j]
    // 2. Delete the character at S1[i]
    // 3. Insert the character at S2[j] into S1
    else
        return dp[i][j] = 1 + min(editDistanceUtil(S1, S2, i - 1, j - 1, dp),
                                  min(editDistanceUtil(S1, S2, i - 1, j, dp),
                                      editDistanceUtil(S1, S2, i, j - 1, dp)));
}

// Function to calculate the minimum number of operations required to transform S1 into S2
int editDistance(string& S1, string& S2) {
    int n = S1.size();
    int m = S2.size();

    // Create a DP table to memoize results
    vector<vector<int>> dp(n, vector<int>(m, -1));

    // Call the utility function with the last indices of both strings
    return editDistanceUtil(S1, S2, n - 1, m - 1, dp);
}

int main() {
    string s1 = "horse";
    string s2 = "ros";

    // Call the editDistance function and print the result
    cout << "The minimum number of operations required is: " << editDistance(s1, s2);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

// Function to calculate the edit distance between two strings
int editDistance(string& S1, string& S2) {
    int n = S1.size();
    int m = S2.size();

    // Create a DP table to store edit distances
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Initialize the first row and column
    for (int i = 0; i <= n; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= m; j++) {
        dp[0][j] = j;
    }

    // Fill in the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (S1[i - 1] == S2[j - 1]) {
                // If the characters match, no additional cost
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                // Minimum of three choices:
                // 1. Replace the character at S1[i-1] with S2[j-1]
                // 2. Delete the character at S1[i-1]
                // 3. Insert the character at S2[j-1] into S1
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
            }
        }
    }

    // The value at dp[n][m] contains the edit distance
    return dp[n][m];
}

int main() {
    string s1 = "horse";
    string s2 = "ros";

    // Call the editDistance function and print the result
    cout << "The minimum number of operations required is: " << editDistance(s1, s2);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

// Function to calculate the edit distance between two strings
int editDistance(string& S1, string& S2) {
    int n = S1.size();
    int m = S2.size();

    // Create two arrays to store previous and current row of edit distances
    vector<int> prev(m + 1, 0);
    vector<int> cur(m + 1, 0);

    // Initialize the first row
    for (int j = 0; j <= m; j++) {
        prev[j] = j;
    }

    // Calculate edit distances row by row
    for (int i = 1; i <= n; i++) {
        cur[0] = i; // Initialize the first column of the current row
        for (int j = 1; j <= m; j++) {
            if (S1[i - 1] == S2[j - 1]) {
                // If the characters match, no additional cost
                cur[j] = prev[j - 1];
            } else {
                // Minimum of three choices:
                // 1. Replace the character at S1[i-1] with S2[j-1]
                // 2. Delete the character at S1[i-1]
                // 3. Insert the character at S2[j-1] into S1
                cur[j] = 1 + min(prev[j - 1], min(prev[j], cur[j - 1]));
            }
        }
        prev = cur; // Update the previous row with the current row
    }

    // The value at cur[m] contains the edit distance
    return cur[m];
}

int main() {
    string s1 = "horse";
    string s2 = "ros";

    // Call the editDistance function and print the result
    cout << "The minimum number of operations required is: " << editDistance(s1, s2);
    return 0;
}
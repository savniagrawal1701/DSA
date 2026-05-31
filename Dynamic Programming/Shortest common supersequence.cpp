#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to return the shortest common supersequence of two strings
    string shortestSupersequence(string s1, string s2) {

        // Get the lengths of the two strings
        int n = s1.size();
        int m = s2.size();

        // Create a 2D DP table to store lengths of LCS
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Initialize base cases: when either string is empty
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= m; i++) {
            dp[0][i] = 0;
        }

        // Fill the DP table using bottom-up approach
        for (int ind1 = 1; ind1 <= n; ind1++) {
            for (int ind2 = 1; ind2 <= m; ind2++) {

                // If characters match, take diagonal + 1
                if (s1[ind1 - 1] == s2[ind2 - 1])
                    dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];

                // Otherwise, take max from left or top
                else
                    dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
            }
        }

        // Start from bottom-right of the DP table to build the supersequence
        int i = n;
        int j = m;
        string ans = "";

        // Traverse the table in reverse to find the supersequence
        while (i > 0 && j > 0) {

            // If characters are equal, include it once
            if (s1[i - 1] == s2[j - 1]) {
                ans += s1[i - 1];
                i--;
                j--;
            }

            // Move in the direction of greater value
            else if (dp[i - 1][j] > dp[i][j - 1]) {
                ans += s1[i - 1];
                i--;
            } else {
                ans += s2[j - 1];
                j--;
            }
        }

        // If any characters are left in s1, add them
        while (i > 0) {
            ans += s1[i - 1];
            i--;
        }

        // If any characters are left in s2, add them
        while (j > 0) {
            ans += s2[j - 1];
            j--;
        }

        // Since we added characters in reverse order, reverse the result
        reverse(ans.begin(), ans.end());

        // Return the final shortest supersequence
        return ans;
    }
};

// Driver code
int main() {

    // Define input strings
    string s1 = "brute";
    string s2 = "groot";

    // Create object of Solution class
    Solution obj;

    // Call the function and print result
    cout << "The Shortest Common Supersequence is " << obj.shortestSupersequence(s1, s2);

    return 0;
}

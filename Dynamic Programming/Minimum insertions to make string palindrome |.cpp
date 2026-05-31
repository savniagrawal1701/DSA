#include <bits/stdc++.h>
using namespace std;

// Define a class named Solution
class Solution {
public:

    // Function to calculate Longest Common Subsequence
    int lcs(string s1, string s2) {
        
        // Get sizes of both strings
        int n = s1.size();
        int m = s2.size();

        // Create a dp table of size (n+1) x (m+1)
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        // Initialize first row as 0
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        // Initialize first column as 0
        for (int i = 0; i <= m; i++) {
            dp[0][i] = 0;
        }

        // Fill dp table using bottom-up approach
        for (int ind1 = 1; ind1 <= n; ind1++) {
            for (int ind2 = 1; ind2 <= m; ind2++) {

                // If characters match, add 1 to previous diagonal
                if (s1[ind1 - 1] == s2[ind2 - 1])
                    dp[ind1][ind2] = 
                        1 + dp[ind1 - 1][ind2 - 1];

                // Else take max from top or left
                else
                    dp[ind1][ind2] = 
                        max(dp[ind1 - 1][ind2], 
                            dp[ind1][ind2 - 1]);
            }
        }

        // Return bottom-right value
        return dp[n][m];
    }

    // Function to find length of Longest Palindromic Subsequence
    int longestPalindromeSubsequence(string s) {
        
        // Reverse the string
        string t = s;
        reverse(s.begin(), s.end());

        // LCS of s and its reverse is the LPS
        return lcs(s, t);
    }

    // Function to find min insertions to make string a palindrome
    int minInsertion(string s) {
        
        // Get length of input string
        int n = s.size();

        // Get length of longest palindromic subsequence
        int k = longestPalindromeSubsequence(s);

        // Return total - palindromic length
        return n - k;
    }
};

// Main function
int main() {
    
    // Create object of Solution class
    Solution obj;

    // Input string
    string s = "abcaa";

    // Call minInsertion and print result
    cout << "The Minimum insertions required to make string palindrome: "
         << obj.minInsertion(s);

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Solution {

public:

    // Function to compute LCS using 2-row DP
    int lcs(string s1, string s2) {

        // Get sizes
        int n = s1.size();
        int m = s2.size();

        // Initialize prev and cur rows
        vector<int> prev(m + 1, 0), cur(m + 1, 0);

        // Fill rows
        for (int ind1 = 1; ind1 <= n; ind1++) {
            for (int ind2 = 1; ind2 <= m; ind2++) {

                // If characters match
                if (s1[ind1 - 1] == s2[ind2 - 1])
                    cur[ind2] = 1 + prev[ind2 - 1];

                // Else take max from prev row or left
                else
                    cur[ind2] = max(prev[ind2], cur[ind2 - 1]);
            }

            // Move cur to prev
            prev = cur;
        }

        // Return result
        return prev[m];
    }

    // Function to compute LPS
    int longestPalindromeSubsequence(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        return lcs(s, t);
    }

    // Function to compute min insertions
    int minInsertion(string s) {
        int n = s.size();
        int k = longestPalindromeSubsequence(s);
        return n - k;
    }
};

int main() {
    Solution sol;
    string s = "abcaa";
    cout << "The Minimum insertions required to make string palindrome: "
         << sol.minInsertion(s) << endl;
    return 0;
}

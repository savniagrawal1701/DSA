#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    /* Function to calculate the length of 
    the Longest Palindromic Subsequence*/
    int func(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        // Declare a 2D DP array to store length of the LCS
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        // Initialize first row and first column to 0
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= m; i++) {
            dp[0][i] = 0;
        }

        // Fill in the DP array
        for (int ind1 = 1; ind1 <= n; ind1++) {
            for (int ind2 = 1; ind2 <= m; ind2++) {
                if (s1[ind1 - 1] == s2[ind2 - 1])
                    dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
                else
                    dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
            }
        }
        // The value at dp[n][m] contains length of the LCS
        return dp[n][m];
    }
public:
    /* Function to calculate the length of 
    the Longest Palindromic Subsequence*/
    int longestPalinSubseq(string s){
        // Store a reversed copy of the string
        string t = s;
        reverse(s.begin(), s.end());

        /* Call the LCS function to find the 
        length of the Longest Common Subsequence*/
        return func(s, t);
    }
};
int main() {
    string s = "bbabcbcab";
    
    //Create an instance of Solution class
    Solution sol;
    
    // Print the result
    cout << "The Length of Longest Palindromic Subsequence is " << sol.longestPalinSubseq(s);
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    /* Function to calculate the length of 
    the Longest Palindromic Subsequence*/
    int lcs(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        /* Create two arrays to store the 
        previous and current rows of DP values*/
        vector<int> prev(m + 1, 0), cur(m + 1, 0);

        /* Base Case is covered as we have
        initialized the prev and cur to 0.*/

        for (int ind1 = 1; ind1 <= n; ind1++) {
            for (int ind2 = 1; ind2 <= m; ind2++) {
                if (s1[ind1 - 1] == s2[ind2 - 1])
                    cur[ind2] = 1 + prev[ind2 - 1];
                else
                    cur[ind2] = max(prev[ind2], cur[ind2 - 1]);
            }
            // Update the prev array with current values
            prev = cur;
        }
        // The value at prev[m] contains length of LCS
        return prev[m];
    }
public:
    /* Function to calculate the length of 
    the Longest Palindromic Subsequence*/
    int longestPalinSubseq(string s){
        // Store a reversed copy of the string
        string t = s;
        reverse(s.begin(), s.end());

        /* Call the LCS function to find the 
        length of the Longest Common Subsequence*/
        return lcs(s, t);
    }
};
int main() {
    string s = "bbabcbcab";
    
    //Create an instance of Solution class
    Solution sol;
    
    // Print the result
    cout << "The Length of Longest Palindromic Subsequence is " << sol.longestPalinSubseq(s);
    return 0;
}

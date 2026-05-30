//recursion
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int solve(int i, int j, string &s1, string &s2) {
    // Base Case: If any string is exhausted
    if (i < 0 || j < 0) return 0;

    // Match case
    if (s1[i] == s2[j]) {
        return 1 + solve(i - 1, j - 1, s1, s2);
    }
    
    // Non-match case
    return max(solve(i - 1, j, s1, s2), solve(i, j - 1, s1, s2));
}

int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();
    return solve(n - 1, m - 1, text1, text2);
}


//memo
#include <bits/stdc++.h>
using namespace std;

int lcsUtil(string& s1, string& s2, int ind1, int ind2, vector<vector<int>>& dp) {
    if (ind1 < 0 || ind2 < 0) return 0;
    if (dp[ind1][ind2] != -1) return dp[ind1][ind2];
    
    if (s1[ind1] == s2[ind2]) 
        return dp[ind1][ind2] = 1 + lcsUtil(s1, s2, ind1 - 1, ind2 - 1, dp);
        
    return dp[ind1][ind2] = max(lcsUtil(s1, s2, ind1 - 1, ind2, dp), lcsUtil(s1, s2, ind1, ind2 - 1, dp));
}

int lcs(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return lcsUtil(s1, s2, n - 1, m - 1, dp);
}

//tabulation
#include <bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    vector<int> prev(m + 1, 0), cur(m + 1, 0);
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) 
                cur[j] = 1 + prev[j - 1];
            else 
                cur[j] = max(prev[j], cur[j - 1]);
        }
        prev = cur;
    }
    return prev[m];
}

//space optim
#include <bits/stdc++.h>
using namespace std;

int lcs(string s, string t)
{
    int n = s.size();
    int m = t.size();
    
    vector<int> prev(m + 1, 0), cur(m + 1, 0);
    
    // Explicit base case initialization shown in the video
    for (int j = 0; j <= m; j++) prev[j] = 0;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) 
                cur[j] = 1 + prev[j - 1];
            else 
                cur[j] = max(prev[j], cur[j - 1]);
        }
        // FIXED: The current row is assigned to prev for the next iteration
        prev = cur; 
    }
    
    return prev[m];
}

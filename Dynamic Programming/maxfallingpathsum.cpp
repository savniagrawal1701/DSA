#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
    // Base Case 1: Out of bounds
    if (j < 0 || j >= matrix[0].size()) return -1e9;
    
    // Base Case 2: Reached the first row
    if (i == 0) return matrix[0][j];
    
    // If already computed, return the cached value
    if (dp[i][j] != -1) return dp[i][j];

    // Explore all 3 paths
    int up = matrix[i][j] + f(i - 1, j, matrix, dp);
    int ld = matrix[i][j] + f(i - 1, j - 1, matrix, dp);
    int rd = matrix[i][j] + f(i - 1, j + 1, matrix, dp);

    // Store and return the maximum
    return dp[i][j] = max(up, max(ld, rd));
}

int getMaxPathSum(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    
    int maxi = -1e9;
    
    // The start point can be any cell in the last row
    for (int j = 0; j < m; j++) {
        maxi = max(maxi, f(n - 1, j, matrix, dp));
    }
    return maxi;
}

#include <bits/stdc++.h>
using namespace std;

int getMaxPathSum(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));

    // Base Condition: Initialize the first row
    for (int j = 0; j < m; j++) {
        dp[0][j] = matrix[0][j];
    }

    // Traverse the matrix iteratively
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            
            int up = matrix[i][j] + dp[i - 1][j];
            
            int ld = matrix[i][j];
            if (j - 1 >= 0) ld += dp[i - 1][j - 1];
            else ld += -1e9; // Out of bounds penalty
            
            int rd = matrix[i][j];
            if (j + 1 < m) rd += dp[i - 1][j + 1];
            else rd += -1e9; // Out of bounds penalty

            dp[i][j] = max(up, max(ld, rd));
        }
    }

    // The answer is the maximum value in the last row
    int maxi = -1e9;
    for (int j = 0; j < m; j++) {
        maxi = max(maxi, dp[n - 1][j]);
    }
    
    return maxi;
}

#include <bits/stdc++.h>
using namespace std;

int getMaxPathSum(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    
    // Instead of a 2D array, we just need the previous row and current row
    vector<int> prev(m, 0), cur(m, 0);

    // Base Condition
    for (int j = 0; j < m; j++) {
        prev[j] = matrix[0][j];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            
            int up = matrix[i][j] + prev[j];
            
            int ld = matrix[i][j];
            if (j - 1 >= 0) ld += prev[j - 1];
            else ld += -1e9;
            
            int rd = matrix[i][j];
            if (j + 1 < m) rd += prev[j + 1];
            else rd += -1e9;

            cur[j] = max(up, max(ld, rd));
        }
        // Current row becomes the previous row for the next iteration
        prev = cur;
    }

    int maxi = -1e9;
    for (int j = 0; j < m; j++) {
        maxi = max(maxi, prev[j]);
    }
    
    return maxi;
}
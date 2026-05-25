#include <bits/stdc++.h>
using namespace std;

// Class containing the solution logic
class Solution {
public:
    // Function to calculate minimum path sum with memoization
    int minPath(int i, int j,
                vector<vector<int>> &grid,
                vector<vector<int>> &dp) {
        // If we are at (0,0), return that cell's value
        if (i == 0 && j == 0)
            return grid[0][0];

        // If out of bounds, return large number
        if (i < 0 || j < 0)
            return 1e9;

        // If already computed, return from dp
        if (dp[i][j] != -1)
            return dp[i][j];

        // Compute path by going up
        int up = grid[i][j] +
                 minPath(i - 1, j, grid, dp);

        // Compute path by going left
        int left = grid[i][j] +
                   minPath(i, j - 1, grid, dp);

        // Store the minimum in dp and return
        return dp[i][j] = min(up, left);
    }

    // Main function that initializes dp and calls helper
    int minPathSum(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Create dp table initialized with -1
        vector<vector<int>> dp(n,
                vector<int>(m, -1));

        // Start from bottom-right corner
        return minPath(n - 1, m - 1, grid, dp);
    }
};

// Driver function
int main() {
    vector<vector<int>> grid = {
        {5, 9, 6},
        {11, 5, 2}
    };

    Solution obj;
    cout << "Minimum sum path: "
         << obj.minPathSum(grid) << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

// Class to solve the problem
class Solution {
public:
    // Function to calculate minimum path sum
    int minPathSum(vector<vector<int>> &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        // Create DP table
        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Fill the table
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // First cell initialization
                if (i == 0 && j == 0)
                    dp[i][j] = matrix[i][j];
                else {
                    // Calculate from top
                    int up = matrix[i][j];
                    if (i > 0) up += dp[i - 1][j];
                    else up += 1e9;

                    // Calculate from left
                    int left = matrix[i][j];
                    if (j > 0) left += dp[i][j - 1];
                    else left += 1e9;

                    // Take minimum
                    dp[i][j] = min(up, left);
                }
            }
        }

        // Return result
        return dp[n - 1][m - 1];
    }
};

// Driver function
int main() {
    vector<vector<int>> matrix{
        {5, 9, 6},
        {11, 5, 2}
    };

    Solution obj;
    cout << "Minimum sum path: " << obj.minPathSum(matrix) << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class solution{
public:

    // Function to find the minimum sum path in grid
    int minSumPath(int n, int m, vector<vector<int>> &matrix) {
    
        // Create 1D vector for previous row
        vector<int> prev(m, 0);
    
        // Loop through each row
        for (int i = 0; i < n; i++) {
        
            // Create temp vector for current row
            vector<int> temp(m, 0);
        
            // Loop through each column
            for (int j = 0; j < m; j++) {
            
                // If at the start cell
                if (i == 0 && j == 0)
                    temp[j] = matrix[i][j];
                else {
                    
                    // Take up direction if valid
                    int up = matrix[i][j];
                    if (i > 0)
                        up += prev[j];
                    else
                        up += 1e9;
                    
                    // Take left direction if valid
                    int left = matrix[i][j];
                    if (j > 0)
                        left += temp[j - 1];
                    else
                        left += 1e9;
                    
                    // Take minimum of both directions
                    temp[j] = min(up, left);
                }
            }
    
            // Move current row to previous
            prev = temp;
        }
    
        // Return result at destination
        return prev[m - 1];
    }
};

int main() {
    vector<vector<int>> matrix{
        {5, 9, 6},
        {11, 5, 2}
    };

    int n = matrix.size();
    int m = matrix[0].size();
    
    Solution obj;
    
    cout << "Minimum sum path: " << obj.minSumPath(n, m, matrix) << endl;
    return 0;
}
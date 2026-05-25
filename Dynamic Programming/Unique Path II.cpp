#include <bits/stdc++.h>
using namespace std;

class Solution {
private:

    //Function to solve the problem using memoization
    int func(int i, int j, vector<vector<int>>& matrix, vector<vector<int>> &dp){
        // Base cases
        if (i < 0 || j < 0 || matrix[i][j] == 1) return 0;
        else if(i == 0 && j == 0) return 1;
        
        // If the result is already computed, return it
        if(dp[i][j] != -1) return dp[i][j];

        /* Calculate the number of ways by
        moving up and left recursively.*/
        int up = func(i - 1, j, matrix, dp);
        int left = func(i, j - 1, matrix, dp);

        // Return the total ways
        return dp[i][j] = up + left;
    }
    
public:

    /*Function to find all unique paths to reach
    matrix[m-1][n-1] form matrix[0][0] with obstacles*/
    int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Initialize DP table to memoize results
        vector<vector<int>> dp(m, vector<int>(n, -1)); 
        
        //Return the total number of paths
        return func(m-1, n-1, matrix, dp);
    }
};

int main() {
    vector<vector<int>> maze{
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    
    //Create an instance of Solution class
    Solution sol;

    cout << "Number of paths with obstacles: " << sol.uniquePathsWithObstacles(maze) << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Function to solve the problem using tabulation
    int func(int m, int n, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                // Base conditions
                if (matrix[i][j] == 1) {
                    /* If there's an obstacle at the 
                    cell, no paths can pass through it*/
                    dp[i][j] = 0;
                    continue;
                }
                if (i == 0 && j == 0) {
                    /* If we are at the starting 
                    point, there is one path to it*/
                    dp[i][j] = 1;
                    continue;
                }

                int up = 0;
                int left = 0;

                /* Check if we can move up and left 
                (if not at the edge of the maze)*/
                if (i > 0)
                    up = dp[i - 1][j];
                if (j > 0)
                    left = dp[i][j - 1];

                /* Total number of paths to reach (i, j)
                is the sum of paths from above and left*/
                dp[i][j] = up + left;
            }
        }

        /* The final result is stored in dp[m-1][n-1],
        which represents the destination*/
        return dp[m - 1][n - 1];
    }

public:
    /* Function to find all unique paths to reach 
    matrix[m-1][n-1] from matrix[0][0] with obstacles*/
    int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
        int m = matrix.size();   
        int n = matrix[0].size(); 

        // Initialize DP table to memoize results
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Return the total number of paths
        return func(m, n, matrix, dp);
    }
};

int main() {
    vector<vector<int>> maze{
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    // Create an instance of Solution class
    Solution sol;

    cout << "Number of paths with obstacles: " << sol.uniquePathsWithObstacles(maze) << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Function to solve the problem using tabulation
    int func(int m, int n, vector<vector<int>>& matrix) {
        
        vector<int> prev(n, 0), curr(n, 0);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                // Base conditions
                if (matrix[i][j] == 1) {
                    /* If there's an obstacle at the 
                    cell, no paths can pass through it*/
                    curr[j] = 0;
                    continue;
                }
                if (i == 0 && j == 0) {
                    /* If we are at the starting 
                    point, there is one path to it*/
                    curr[j] = 1;
                    continue;
                }

                int up = 0;
                int left = 0;

                /* Check if we can move up and left 
                (if not at the edge of the maze)*/
                if (i > 0)
                    up = prev[j];
                if (j > 0)
                    left = curr[j - 1];

                /* Total number of paths to reach (i, j)
                is the sum of paths from above and left*/
                curr[j] = up + left;
            }
            
            prev = curr;
        }

        /* The final result is stored in dp[m-1][n-1],
        which represents the destination*/
        return prev[n-1];
    }

public:
    /* Function to find all unique paths to reach 
    matrix[m-1][n-1] from matrix[0][0] with obstacles*/
    int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
        int m = matrix.size();   
        int n = matrix[0].size(); 

        // Return the total number of paths
        return func(m, n, matrix);
    }
};

int main() {
    vector<vector<int>> maze{
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    // Create an instance of Solution class
    Solution sol;

    cout << "Number of paths with obstacles: " << sol.uniquePathsWithObstacles(maze) << endl;
    return 0;
}

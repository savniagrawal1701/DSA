//the most optimal is the binary search one 
//it is known as patience sorting algorithm.
#include <bits/stdc++.h>
using namespace std;

int getLIS(int ind, int prev_ind, int arr[], int n) {
    // Base Case: If we reach the end of the array
    if (ind == n) return 0;
    
    // Choice 1: Not Take the element
    int len = 0 + getLIS(ind + 1, prev_ind, arr, n);
    
    // Choice 2: Take the element (if it is valid)
    if (prev_ind == -1 || arr[ind] > arr[prev_ind]) {
        len = max(len, 1 + getLIS(ind + 1, ind, arr, n));
    }
    
    return len;
}

int longestIncreasingSubsequence(int arr[], int n) {
    // Start from index 0, with no previous element (-1)
    return getLIS(0, -1, arr, n);
}


#include <bits/stdc++.h>
using namespace std;

int getLIS(int ind, int prev_ind, int arr[], int n, vector<vector<int>>& dp) {
    // Base Case
    if (ind == n) return 0;
    
    // Check if the state is already computed (using coordinate shift for prev_ind)
    if (dp[ind][prev_ind + 1] != -1) return dp[ind][prev_ind + 1];
    
    // Choice 1: Not Take
    int len = 0 + getLIS(ind + 1, prev_ind, arr, n, dp);
    
    // Choice 2: Take
    if (prev_ind == -1 || arr[ind] > arr[prev_ind]) {
        len = max(len, 1 + getLIS(ind + 1, ind, arr, n, dp));
    }
    
    // Store the result in DP table with shifted index
    return dp[ind][prev_ind + 1] = len;
}

int longestIncreasingSubsequence(int arr[], int n) {
    // DP Table initialized to -1
    // Rows: 0 to n-1 (size n)
    // Columns: -1 to n-1 -> mapped to 0 to n (size n+1)
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    
    return getLIS(0, -1, arr, n, dp);
}

//tabulation
#include <bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(int arr[], int n) {
    // DP table initialized to 0
    // Rows represent 'ind' (0 to n)
    // Columns represent 'prev_ind' shifted by +1 (0 to n)
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    
    // Bottom-up loops
    for (int ind = n - 1; ind >= 0; ind--) {
        for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--) {
            
            // Choice 1: Not Take
            int len = 0 + dp[ind + 1][prev_ind + 1]; // prev_ind remains same
            
            // Choice 2: Take
            if (prev_ind == -1 || arr[ind] > arr[prev_ind]) {
                len = max(len, 1 + dp[ind + 1][ind + 1]); // prev_ind becomes ind
            }
            
            // Store with coordinate shift
            dp[ind][prev_ind + 1] = len;
        }
    }
    
    // Original starting state was ind = 0, prev_ind = -1
    return dp[0][-1 + 1]; 
}

//space optim
#include <bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequenceSpaceOpt(int arr[], int n) {
    // Two rows of size n + 1, initialized to 0
    vector<int> next(n + 1, 0);
    vector<int> curr(n + 1, 0);
    
    for (int ind = n - 1; ind >= 0; ind--) {
        for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--) {
            
            // Choice 1: Not Take
            int len = 0 + next[prev_ind + 1];
            
            // Choice 2: Take
            if (prev_ind == -1 || arr[ind] > arr[prev_ind]) {
                len = max(len, 1 + next[ind + 1]);
            }
            
            curr[prev_ind + 1] = len;
        }
        // Move curr row to next row for the next iteration
        next = curr;
    }
    
    return next[-1 + 1];
}


//the code in which dp[n]is used for calculation 
#include <bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence1D(int arr[], int n) {
    // dp[ind] stores the length of LIS ending exactly at index 'ind'
    vector<int> dp(n, 1); // Every element is an LIS of length 1 by itself
    int maxi = 1;         // Keeps track of the overall maximum length
    
    for (int ind = 0; ind < n; ind++) {
        // This matches the exact line from the image: for(prev = 0 -> ind-1)
        for (int prev = 0; prev < ind; prev++) {
            
            // if(arr[prev] < arr[ind])
            if (arr[prev] < arr[ind]) {
                
                // dp[ind] = max(1 + dp[prev], dp[ind])
                dp[ind] = max(1 + dp[prev], dp[ind]);
            }
        }
        // Track the largest value found in the DP array
        maxi = max(maxi, dp[ind]);
    }
    
    return maxi;
}

#include <bits/stdc++.h>
using namespace std;

// Class containing the method to find the count of Longest Increasing Subsequences
class Solution {
public:
    // Method to calculate the count of LIS
    int findNumberOfLIS(vector<int>& arr) {
        // Store the size of the input sequence
        int n = arr.size();

        // Store the length of the increasing subsequence ending at each position
        vector<int> dp(n, 1);

        // Store the count of increasing subsequences ending at each position
        vector<int> ct(n, 1);

        // Track the maximum subsequence length found so far
        int maxi = 1;

        // Loop through each position in the sequence
        for (int i = 0; i < n; i++) {
            // Compare the current position with all previous positions
            for (int j = 0; j < i; j++) {
                // If an increasing sequence is found that is longer than the current best for this position
                if (arr[j] < arr[i] && dp[j] + 1 > dp[i]) {
                    // Update the best subsequence length for this position
                    dp[i] = dp[j] + 1;

                    // Reset the count to match the source subsequence count
                    ct[i] = ct[j];
                }
                // If an increasing sequence of the same best length is found
                else if (arr[j] < arr[i] && dp[j] + 1 == dp[i]) {
                    // Add the count of subsequences from the previous position
                    ct[i] = ct[i] + ct[j];
                }
            }
            // Update the global maximum subsequence length if needed
            maxi = max(maxi, dp[i]);
        }

        // Store the total number of subsequences of maximum length
        int countLIS = 0;

        // Sum the counts of all positions where the length equals the maximum length
        for (int i = 0; i < n; i++) {
            if (dp[i] == maxi) {
                countLIS += ct[i];
            }
        }

        // Return the total number of longest increasing subsequences
        return countLIS;
    }
};

int main() {
    // Define the input sequence
    vector<int> arr = {1, 5, 4, 3, 2, 6, 7, 2};

    // Create an object of Solution class
    Solution sol;

    // Output the total count of longest increasing subsequences
    cout << "The count of Longest Increasing Subsequences (LIS) is " 
         << sol.findNumberOfLIS(arr) << endl;

    return 0;
}
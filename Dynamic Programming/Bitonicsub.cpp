#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to return the length of the longest bitonic sequence
    int LongestBitonicSequence(vector<int>& arr) {
        int n = arr.size(); // Size of the array 
        
        // LIS_dp[i] stores the length of LIS ending at index i
        vector<int> LIS_dp(n, 1);  

        // To store the length of longest bitonic sequence
        int maxLen = 0;

        // Computing the LIS DP array 
        for(int i = 0; i < n; i++) {

            // For each previous index
            for(int prev = 0; prev < i; prev++) {
                
                /* If the element at index i can be
                 included in the LIS ending at prev index */
                if(arr[prev] < arr[i] && LIS_dp[i] < LIS_dp[prev] + 1) {
                    LIS_dp[i] = LIS_dp[prev] + 1; // Update the DP value
                }
            }
        }
    
        // LDS_dp[i] stores the length of LDS starting from index i
        vector<int> LDS_dp(n, 1);  
        
        // Computing the LDS DP array 
        for(int i = n-1; i >= 0; i--) {

            // For each previous index
            for(int prev = n-1; prev > i; prev--) {
                
                /* If the element at index i can be
                 included in the LIS ending at prev index */
                if(arr[prev] < arr[i] && LDS_dp[i] < LDS_dp[prev] + 1) {
                    LDS_dp[i] = LDS_dp[prev] + 1; // Update the DP value
                }
            }
            
            // Update the maximum possible length of Longest Bitonic Sequence
            maxLen = max(maxLen, LIS_dp[i] + LDS_dp[i] - 1);
        }
        
        return maxLen;
    }
};


int main() {
    vector<int> arr = {5, 1, 4, 2, 3, 6, 8, 7};
    
    // Creating an object of Solution class
    Solution sol;
    
    // Function call to get the length of longest bitonic sequence
    int lengthOfLongestBitonicSequence = sol.LongestBitonicSequence(arr);
    
    //  Output
    cout << "The length of the Longest Bitonic Sequence is: " << lengthOfLongestBitonicSequence << endl;
    
    return 0;
}
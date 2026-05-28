#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to count partitions with given difference
    int countPartitions(vector<int>& arr, int d) {
        // Calculate total sum of array
        int totalSum = accumulate(arr.begin(), arr.end(), 0);

        // Check if solution is possible
        if ((totalSum + d) % 2 != 0 || d > totalSum) return 0;

        // Calculate target sum
        int K = (totalSum + d) / 2;

        // Create dp array of size K+1
        vector<int> dp(K + 1, 0);

        // Base case: empty set makes sum 0
        dp[0] = 1;

        // If first element <= K, mark it
        if (arr[0] <= K) dp[arr[0]] += 1;

        // Process remaining elements
        for (int i = 1; i < arr.size(); i++) {
            vector<int> curr(K + 1, 0);
            curr[0] = 1;

            for (int t = 0; t <= K; t++) {
                int notTake = dp[t];
                int take = 0;
                if (arr[i] <= t) {
                    take = dp[t - arr[i]];
                }
                curr[t] = take + notTake;
            }
            dp = curr;
        }
        return dp[K];
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 4};
    int d = 1;
    cout << sol.countPartitions(arr, d) << endl;
    return 0;
}
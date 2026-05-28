#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to count number of ways to assign '+' or '-' to reach target
    int findTargetSumWays(vector<int>& nums, int target) {
        // Calculate the total sum of the array
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        // If target is not achievable (because of sum or parity), return 0
        if ((totalSum - target) < 0 || (totalSum - target) % 2 != 0) 
            return 0;

        // Our problem reduces to subset sum with sum = (totalSum - target) / 2
        int subsetSum = (totalSum - target) / 2;

        // Initialize memo table with -1
        vector<vector<int>> dp(nums.size(), vector<int>(subsetSum + 1, -1));

        // Call recursive function with memoization
        return countSubsets(nums, nums.size() - 1, subsetSum, dp);
    }

private:
    // Recursive function with memoization
    int countSubsets(vector<int>& nums, int ind, int target, vector<vector<int>>& dp) {
        // Base case: when we are at index 0
        if (ind == 0) {
            // Two scenarios:
            if (target == 0 && nums[0] == 0) return 2; // {pick or not pick 0}
            if (target == 0 || target == nums[0]) return 1; // Either pick or skip
            return 0; // Otherwise no valid way
        }

        // Return if already computed
        if (dp[ind][target] != -1) return dp[ind][target];

        // Exclude current element
        int notPick = countSubsets(nums, ind - 1, target, dp);

        // Include current element if it is <= target
        int pick = 0;
        if (nums[ind] <= target)
            pick = countSubsets(nums, ind - 1, target - nums[ind], dp);

        // Store and return result
        return dp[ind][target] = pick + notPick;
    }
};

// Driver code
int main() {
    Solution sol;
    vector<int> nums = {1,1,1,1,1};
    int target = 3;
    cout << sol.findTargetSumWays(nums, target) << endl; // Output: 5
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find number of ways to assign + or - to reach the target
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        // First calculate the total sum of all numbers
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        // If (target + totalSum) is odd or target > totalSum, no valid partition exists
        if ((totalSum + target) % 2 != 0 || abs(target) > totalSum) return 0;

        // We now need to count subsets with sum = (target + totalSum) / 2
        int newTarget = (totalSum + target) / 2;

        // Create DP table: dp[i][j] = number of ways to make sum j using first i numbers
        vector<vector<int>> dp(n + 1, vector<int>(newTarget + 1, 0));

        // Base case: One way to form sum 0 (by taking no elements)
        for (int i = 0; i <= n; i++) dp[i][0] = 1;

        // Fill DP table iteratively
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= newTarget; j++) {
                // Exclude current element
                dp[i][j] = dp[i - 1][j];

                // Include current element if it does not exceed current target j
                if (nums[i - 1] <= j) {
                    dp[i][j] += dp[i - 1][j - nums[i - 1]];
                }
            }
        }

        return dp[n][newTarget];
    }
};

// Driver code
int main() {
    Solution sol;
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    cout << sol.findTargetSumWays(nums, target) << endl; // Output: 5
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to count number of ways to assign signs to reach the target
    int findTargetSumWays(vector<int>& nums, int target) {
        // Step 1: calculate total sum of array
        int total = accumulate(nums.begin(), nums.end(), 0);

        // Step 2: check feasibility
        if ((total + target) % 2 != 0 || abs(target) > total) return 0;

        // Step 3: new target for subset sum problem
        int newTarget = (total + target) / 2;

        // Step 4: initialize dp array of size newTarget + 1 with 0
        vector<int> dp(newTarget + 1, 0);

        // Step 5: base case: one way to form sum 0 (by choosing nothing)
        dp[0] = 1;

        // Step 6: iterate over each number
        for (int num : nums) {
            // Step 7: update dp array from right to left
            for (int j = newTarget; j >= num; j--) {
                dp[j] += dp[j - num];
            }
        }

        // Step 8: final answer
        return dp[newTarget];
    }
};

// Driver code
int main() {
    Solution sol;
    vector<int> nums = {1,1,1,1,1};
    int target = 3;
    cout << sol.findTargetSumWays(nums, target) << endl;
    return 0;
}

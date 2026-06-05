#include <bits/stdc++.h>
using namespace std;

// Solution class to compute minimum cost to cut a stick
class Solution {
public:
    // Recursive function to find the minimum cost to cut between indices i and j in cuts
    int findMinimumCost(int i, int j, vector<int> &cuts) {
        // Base case: no cuts to consider
        if (i > j) {
            return 0;
        }

        int mini = INT_MAX;

        // Try cutting at every position between i and j
        for (int ind = i; ind <= j; ind++) {
            // Cost of making the current cut plus
            // cost of cutting left and right sub-segments recursively
            int ans = cuts[j + 1] - cuts[i - 1] +
                      findMinimumCost(i, ind - 1, cuts) +
                      findMinimumCost(ind + 1, j, cuts);

            // Update minimum cost
            mini = min(mini, ans);
        }

        return mini;
    }

    // Function to calculate minimum total cost to cut the stick
    int minimumCost(int n, int c, vector<int> &cuts) {
        // Add the two ends of the stick to the cuts array
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);

        // Sort the cuts array
        sort(cuts.begin(), cuts.end());

        // Compute the minimum cost to make all cuts between indices 1 and c
        return findMinimumCost(1, c, cuts);
    }
};

int main() {
    vector<int> cuts = {3, 5, 1, 4};
    int c = cuts.size();
    int n = 7;

    Solution sol;
    cout << "The minimum cost incurred is: " << sol.minimumCost(n, c, cuts) << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

// Solution class to compute minimum cost to cut a stick using memoization
class Solution {
public:
    // Recursive function with memoization to find minimum cost between indices i and j in cuts
    int findMinimumCost(int i, int j, vector<int> &cuts, vector<vector<int>> &dp) {
        // Base case: no cuts to consider
        if (i > j) {
            return 0;
        }

        // Return precomputed result if available
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int mini = INT_MAX;

        // Try cutting at every position between i and j
        for (int ind = i; ind <= j; ind++) {
            // Calculate cost of current cut plus costs of left and right subproblems
            int ans = cuts[j + 1] - cuts[i - 1] +
                      findMinimumCost(i, ind - 1, cuts, dp) +
                      findMinimumCost(ind + 1, j, cuts, dp);

            // Update minimum cost
            mini = min(mini, ans);
        }

        // Store and return the minimum cost found
        return dp[i][j] = mini;
    }

    // Function to calculate minimum total cost to cut the stick
    int minimumCost(int n, int c, vector<int> &cuts) {
        // Add the two ends of the stick to the cuts array
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);

        // Sort the cuts array
        sort(cuts.begin(), cuts.end());

        // Create a DP table initialized with -1
        vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));

        // Compute minimum cost to make all cuts between indices 1 and c
        return findMinimumCost(1, c, cuts, dp);
    }
};

int main() {
    vector<int> cuts = {3, 5, 1, 4};
    int c = cuts.size();
    int n = 7;

    Solution sol;
    cout << "The minimum cost incurred is: " << sol.minimumCost(n, c, cuts) << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

// Solution class to compute minimum cost to cut a stick using tabulation (bottom-up DP)
class Solution {
public:
    // Function to calculate minimum total cost to cut the stick using tabulation
    int minimumCost(int n, int c, vector<int> &cuts) {
        // Add the two ends of the stick to the cuts array
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);

        // Sort the cuts array
        sort(cuts.begin(), cuts.end());

        // Create a DP table initialized with 0
        vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));

        // Fill the DP table for all possible segments
        // i traverses backward from c to 1
        for (int i = c; i >= 1; i--) {
            // j traverses forward from i to c
            for (int j = i; j <= c; j++) {
                int mini = INT_MAX;

                // Try making a cut at every position between i and j
                for (int ind = i; ind <= j; ind++) {
                    // Cost of making the current cut plus costs of left and right subproblems
                    int ans = cuts[j + 1] - cuts[i - 1] + dp[i][ind - 1] + dp[ind + 1][j];

                    // Update minimum cost
                    mini = min(mini, ans);
                }

                // Store the minimum cost in DP table
                dp[i][j] = mini;
            }
        }

        // The answer is the minimum cost to cut between indices 1 and c
        return dp[1][c];
    }
};

int main() {
    vector<int> cuts = {3, 5, 1, 4};
    int c = cuts.size();
    int n = 7;

    Solution sol;
    cout << "The minimum cost incurred is: " << sol.minimumCost(n, c, cuts) << endl;

    return 0;
}

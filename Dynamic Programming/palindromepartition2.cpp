#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Check if substring s[start...end] is palindrome
    bool isPalindrome(const string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }

    // Recursive helper with memoization to find min cuts from index 'start'
    int minCutsHelper(const string& s, int start, vector<int>& memo) {
        int n = (int)s.size();

        // If reached end or substring is palindrome, no cut needed
        if (start == n || isPalindrome(s, start, n - 1))
            return 0;

        // Return stored result if already computed
        if (memo[start] != -1)
            return memo[start];

        int minCuts = INT_MAX;

        // Try all possible partitions
        for (int end = start; end < n; end++) {
            if (isPalindrome(s, start, end)) {
                // 1 cut plus cuts for the remaining substring
                int cuts = 1 + minCutsHelper(s, end + 1, memo);
                minCuts = min(minCuts, cuts);
            }
        }

        // Store and return minimum cuts needed from this start
        return memo[start] = minCuts;
    }

public:
    // Public function to get minimum cuts for palindrome partitioning
    int minCut(string s) {
        int n = (int)s.size();
        vector<int> memo(n, -1);
        return minCutsHelper(s, 0, memo);
    }
};

int main() {
    string s = "aab";

    Solution sol;
    cout << "Minimum cuts needed: " << sol.minCut(s) << "\n";

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Check if substring s[i...j] is palindrome
    bool isPalindrome(const string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

public:
    // Tabulation approach to find minimum cuts for palindrome partitioning
    int minCut(string s) {
        int n = (int)s.size();
        // dp[i] = min cuts needed for substring s[i...end]
        vector<int> dp(n + 1, 0);  

        // Base case: no cuts needed beyond the last index
        dp[n] = -1;

        // Fill dp from end to start
        for (int i = n - 1; i >= 0; i--) {
            int minCuts = INT_MAX;

            // Check all substrings s[i...j]
            for (int j = i; j < n; j++) {
                if (isPalindrome(s, i, j)) {
                    // 1 cut plus cuts needed after j
                    minCuts = min(minCuts, 1 + dp[j + 1]);
                }
            }

            dp[i] = minCuts;
        }

        // dp[0] holds the min cuts needed for full string
        return dp[0];
    }
};

int main() {
    string s = "aab";

    Solution sol;
    cout << "Minimum cuts needed: " << sol.minCut(s) << "\n";

    return 0;
}
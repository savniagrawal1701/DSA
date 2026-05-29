int knapsackUtil(int ind, int W, vector<int>& wt, vector<int>& val, vector<vector<int>>& dp) {
    if (ind == 0) return (wt[0] <= W) ? val[0] : 0;
    if (dp[ind][W] != -1) return dp[ind][W];
    int notTaken = knapsackUtil(ind - 1, W, wt, val, dp);
    int taken = (wt[ind] <= W) ? val[ind] + knapsackUtil(ind - 1, W - wt[ind], wt, val, dp) : INT_MIN;
    return dp[ind][W] = max(notTaken, taken);
}

int knapsack(vector<int>& wt, vector<int>& val, int n, int W) {
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));
    for (int i = wt[0]; i <= W; i++) dp[0][i] = val[0];
    for (int ind = 1; ind < n; ind++) {
        for (int cap = 0; cap <= W; cap++) {
            int notTaken = dp[ind - 1][cap];
            int taken = (wt[ind] <= cap) ? val[ind] + dp[ind - 1][cap - wt[ind]] : INT_MIN;
            dp[ind][cap] = max(notTaken, taken);
        }
    }
    return dp[n - 1][W];
}
int knapsack(vector<int>& wt, vector<int>& val, int n, int W) {
    vector<int> prev(W + 1, 0), cur(W + 1, 0);
    for (int i = wt[0]; i <= W; i++) prev[i] = val[0];
    for (int ind = 1; ind < n; ind++) {
        for (int cap = 0; cap <= W; cap++) {
            int notTaken = prev[cap];
            int taken = (wt[ind] <= cap) ? val[ind] + prev[cap - wt[ind]] : INT_MIN;
            cur[cap] = max(notTaken, taken);
        }
        prev = cur;
    }
    return prev[W];
}
//space optimisation 2
int knapsack(vector<int>& wt, vector<int>& val, int n, int W) {
    vector<int> prev(W + 1, 0);
    for (int i = wt[0]; i <= W; i++) prev[i] = val[0];
    for (int ind = 1; ind < n; ind++) {
        for (int cap = W; cap >= 0; cap--) {
            int notTaken = prev[cap];
            int taken = (wt[ind] <= cap) ? val[ind] + prev[cap - wt[ind]] : INT_MIN;
            prev[cap] = max(notTaken, taken);
        }
    }
    return prev[W];
}

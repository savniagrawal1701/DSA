#include<bits/stdc++.h>
using namespace std;

int f(int ind, vector<int> &heights, vector<int> &dp) {
    if(ind == 0) return 0;
    
    if(dp[ind] != -1) return dp[ind];
    
    int left = f(ind-1, heights, dp) + abs(heights[ind] - heights[ind-1]);
    int right = INT_MAX;
    
    if(ind > 1) right = f(ind-2, heights, dp) + abs(heights[ind] - heights[ind-2]);
    
    return dp[ind] = min(left, right);
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1, -1);
    return f(n-1, heights, dp);
}

int main() {
    // Sample Test Case
    vector<int> heights = {10, 20, 30, 10};
    int n = heights.size();
    
    cout << "Minimum energy (Memoization): " << frogJump(n, heights) << endl;
    
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int frogJump(int n, vector<int> &heights)
{
    int prev = 0;
    int prev2 = 0;
    
    for(int i = 1; i<n; i++) {
        int fs = prev + abs(heights[i] - heights[i-1]);
        int ss = INT_MAX;
        
        if(i > 1) ss = prev2 + abs(heights[i] - heights[i-2]);
        
        int curi = min(fs, ss);
        prev2 = prev;
        prev = curi;
    }
    
    return prev;
}

int main() {
    // Sample Test Case
    vector<int> heights = {10, 20, 30, 10};
    int n = heights.size();
    
    cout << "Minimum energy (Space Optimized): " << frogJump(n, heights) << endl;
    
    return 0;
}

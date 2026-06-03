#include <bits/stdc++.h>
using namespace std;

int printingLongestIncreasingSubsequence(vector<int>& arr, int n) {
    vector<int> dp(n, 1);
    vector<int> hash(n);
    
    int maxi = 1;
    int lastIndex = 0;
    
    for (int ind = 0; ind < n; ind++) {
        hash[ind] = ind; 
        for (int prev = 0; prev < ind; prev++) {
            if (arr[prev] < arr[ind] && 1 + dp[prev] > dp[ind]) {
                dp[ind] = 1 + dp[prev];
                hash[ind] = prev; 
            }
        }
        if (dp[ind] > maxi) {
            maxi = dp[ind];
            lastIndex = ind;
        }
    }
    
    // --- FROM SCREENSHOT (LINES 23-31) ---
    vector<int> temp;
    temp.push_back(arr[lastIndex]);
    while(hash[lastIndex] != lastIndex) {
        lastIndex = hash[lastIndex];
        temp.push_back(arr[lastIndex]);
    }
    
    reverse(temp.begin(), temp.end());
    for(auto it : temp) cout << it << " ";
    cout << endl;
    
    return maxi;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Hardcoded custom test case from the screenshot: 
    // Size = 6, Elements = 5 4 11 1 16 8
    int n = 6;
    vector<int> arr = {5, 4, 11, 1, 16, 8};

    cout << "The Longest Increasing Subsequence elements are: " << "\n";
    int length = printingLongestIncreasingSubsequence(arr, n);
    
    cout << "Length of LIS: " << length << "\n";

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* Function to find the length of 
    the Longest Common Substring (LCS) */
    int longestCommonSubstr(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
    
        // Initialize a 2D DP table with dimensions
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Initialize the answer variable
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // Characters match, increment substring length
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    
                    /* Update the maximum substring 
                    length found so far */
                    ans = max(ans, dp[i][j]);
                } else {
                    /* Characters don't match, 
                    substring length becomes 0 */
                    dp[i][j] = 0;
                }
            }
        }
        // Return the length of Longest Common Substring
        return ans;
    }
};

int main() {
    string s1 = "abcjklp";
    string s2 = "acjkp";

    // Create an instance of Solution class
    Solution sol;
    
    // Print the result
    cout << "The Length of Longest Common Substring is " << sol.longestCommonSubstr(s1, s2) << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* Function to find the length of 
    the Longest Common Substring (LCS) */
    int longestCommonSubstr(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
    
        /* Initialize two vectors to store 
        previous and current row values*/
        vector<int> prev(m+1, 0);
        vector<int> cur(m+1, 0);  
        
        /* Initialize the answer variable to
        store the maximum LCS length found*/
        int ans = 0; 
    
        // Loop through both strings
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                // Characters match, increment substring length
                if(str1[i-1] == str2[j-1]){
                    int val = 1 + prev[j-1]; 
                    cur[j] = val; 
                    
                    /* Update the maximum substring
                    length found so far*/
                    ans = max(ans, val); 
                }
                else{
                    /* Characters don't match,
                    substring length becomes 0*/
                    cur[j] = 0; 
                }
                
            }
            /* Update the previous row with 
            the values of the current row*/
            prev = cur; 
        }
        // Return the length of Longest Common Substring
        return ans;
    }
};

int main() {
    string s1 = "abcjklp";
    string s2 = "acjkp";

    // Create an instance of Solution class
    Solution sol;
    
    // Print the result
    cout << "The Length of Longest Common Substring is " << sol.longestCommonSubstr(s1, s2) << endl;

    return 0;
}
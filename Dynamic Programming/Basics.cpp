#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int fib(int n, vector<int> &dp)
    {

        if (n <= 1)
            return n;

        if (dp[n] != -1)
            return dp[n];

        dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
        return dp[n];
    }
};

int main()
{
    int n = 10;
    vector<int> dp(n + 1, -1);
    Solution sol;
    cout << sol.fib(n, dp);
    return 0;
}



//Tabulation
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to calculate Fibonacci using tabulation
    int fib(int n) {
        // If n is 0 or 1, return n
        if (n <= 1) return n;

        // Create dp array
        vector<int> dp(n + 1, 0);

        // Initialize base cases
        dp[0] = 0;
        dp[1] = 1;

        // Fill dp array iteratively
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        // Return final answer
        return dp[n];
    }
};

int main() {
    int n = 10;
    Solution sol;
    cout << sol.fib(n);
    return 0;
}


//Tabulation+reduced space
using namespace std;

class Solution {
public:
    int fib(int n) {
        // If n is 0 return 0
        if(n == 0) return 0;
        // If n is 1 return 1
        if(n == 1) return 1;

        // prev2 stores fib(n-2)
        int prev2 = 0;
        // prev stores fib(n-1)
        int prev = 1;
        // curr stores current fib
        int curr;

        // Loop from 2 to n
        for(int i = 2; i <= n; i++) {
            // Calculate current fib
            curr = prev + prev2;
            // Update prev2
            prev2 = prev;
            // Update prev
            prev = curr;
        }
        // Return final answer
        return prev;
    }
};

int main() {
    Solution s;
    int n = 10;
    cout << s.fib(n);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1000000007;

// Function to evaluate the number of ways to parenthesize the expression to get True or False
int f(int i, int j, int isTrue, string &exp) {
    // Base case 1: If i > j, it's an invalid expression, return 0.
    if (i > j) return 0;
    
    // Base case 2: If i and j are the same, evaluate the single character.
    if (i == j) {
        if (isTrue == 1) return exp[i] == 'T' ? 1 : 0;
        else return exp[i] == 'F' ? 1 : 0;
    }
    
    ll ways = 0;
    
    // Iterate through the expression to divide it into left and right subexpressions
    for (int ind = i + 1; ind <= j - 1; ind += 2) {
        // Recursively calculate the number of ways to make the left and right subexpressions true or false
        ll lT = f(i, ind - 1, 1, exp);  // Number of ways to make the left expression true.
        ll lF = f(i, ind - 1, 0, exp);  // Number of ways to make the left expression false.
        ll rT = f(ind + 1, j, 1, exp);  // Number of ways to make the right expression true.
        ll rF = f(ind + 1, j, 0, exp);  // Number of ways to make the right expression false.

        // Check the operator at the current index and update ways accordingly.
        if (exp[ind] == '&') {  // AND operator
            if (isTrue) ways = (ways + (lT * rT) % mod) % mod;
            else ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lF * rF) % mod) % mod;
        }
        else if (exp[ind] == '|') {  // OR operator
            if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lT * rT) % mod) % mod;
            else ways = (ways + (lF * rF) % mod) % mod;
        }
        else {  // XOR operator
            if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod) % mod;
            else ways = (ways + (lF * rF) % mod + (lT * rT) % mod) % mod;
        }
    }
    return ways;  // Return the total number of ways to evaluate the expression
}

// Function to start evaluating the expression
int evaluateExp(string &exp) {
    int n = exp.size();
    return f(0, n - 1, 1, exp);  // Start evaluation with isTrue set to true.
}

int main() {
    // Example expression
    string exp = "F|T^F";
    
    // Evaluate the expression and find the number of ways to get the result as True
    int ways = evaluateExp(exp);
    
    // Output the result
    cout << "The total number of ways: " << ways << "\n";

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1000000007;

// Function to evaluate the number of ways to parenthesize the expression to get True or False
int f(int i, int j, int isTrue, string &exp, vector<vector<vector<ll>>> &dp) {
    // Base case 1: If i > j, it's an invalid expression, return 0.
    if (i > j) return 0;
    
    // Base case 2: If i and j are the same, evaluate the single character.
    if (i == j) {
        if (isTrue == 1) return exp[i] == 'T' ? 1 : 0;
        else return exp[i] == 'F' ? 1 : 0;
    }

    // If the result for this subproblem has been computed before, return it.
    if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
    
    ll ways = 0;
    
    // Iterate through the expression to divide it into left and right subexpressions
    for (int ind = i + 1; ind <= j - 1; ind += 2) {
        // Recursively calculate the number of ways to make the left and right subexpressions true or false
        ll lT = f(i, ind - 1, 1, exp, dp);  // Number of ways to make the left expression true.
        ll lF = f(i, ind - 1, 0, exp, dp);  // Number of ways to make the left expression false.
        ll rT = f(ind + 1, j, 1, exp, dp);  // Number of ways to make the right expression true.
        ll rF = f(ind + 1, j, 0, exp, dp);  // Number of ways to make the right expression false.

        // Check the operator at the current index and update ways accordingly.
        if (exp[ind] == '&') {  // AND operator
            if (isTrue) ways = (ways + (lT * rT) % mod) % mod;
            else ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lF * rF) % mod) % mod;
        }
        else if (exp[ind] == '|') {  // OR operator
            if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lT * rT) % mod) % mod;
            else ways = (ways + (lF * rF) % mod) % mod;
        }
        else {  // XOR operator
            if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod) % mod;
            else ways = (ways + (lF * rF) % mod + (lT * rT) % mod) % mod;
        }
    }
    
    // Store the result in the DP table and return it.
    return dp[i][j][isTrue] = ways;
}

// Function to start evaluating the expression
int evaluateExp(string &exp) {
    int n = exp.size();
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, -1)));  // DP table initialization
    return f(0, n - 1, 1, exp, dp);  // Start evaluation with isTrue set to true.
}

int main() {
    string exp = "F|T^F";  // Example expression
    
    // Evaluate the expression and find the number of ways to get the result as True
    int ways = evaluateExp(exp);
    
    // Output the result
    cout << "The total number of ways: " << ways << "\n";

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1000000007;

// Function to evaluate the number of ways to parenthesize the expression to get True or False
int evaluateExp(string &exp) {
    int n = exp.size();
    
    // DP table to store the number of ways to evaluate the expression from i to j with isTrue (0 or 1)
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, 0)));

    // Iterate through the string from right to left for bottom-up DP
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= n - 1; j++) {
            // Base case 1: If i > j, it's an invalid expression, so continue.
            if (i > j) continue;

            // Iterate through the possible values of isTrue (either 1 or 0)
            for (int isTrue = 0; isTrue <= 1; isTrue++) {
                // Base case 2: If i == j, evaluate the single character.
                if (i == j) {
                    if (isTrue == 1) dp[i][j][isTrue] = exp[i] == 'T';
                    else dp[i][j][isTrue] = exp[i] == 'F';
                    continue;
                }

                // Recurrence logic for other subexpressions
                ll ways = 0;
                for (int ind = i + 1; ind <= j - 1; ind += 2) {
                    // Number of ways to make the left and right subexpressions true or false
                    ll lT = dp[i][ind - 1][1];
                    ll lF = dp[i][ind - 1][0];
                    ll rT = dp[ind + 1][j][1];
                    ll rF = dp[ind + 1][j][0];

                    // Perform the operation based on the operator at the current index
                    if (exp[ind] == '&') {  // AND operator
                        if (isTrue) ways = (ways + (lT * rT) % mod) % mod;
                        else ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lF * rF) % mod) % mod;
                    }
                    else if (exp[ind] == '|') {  // OR operator
                        if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lT * rT) % mod) % mod;
                        else ways = (ways + (lF * rF) % mod) % mod;
                    }
                    else {  // XOR operator
                        if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod) % mod;
                        else ways = (ways + (lF * rF) % mod + (lT * rT) % mod) % mod;
                    }
                }
                dp[i][j][isTrue] = ways;  // Store the result in the DP table
            }
        }
    }
    return dp[0][n - 1][1];  // Return the number of ways to evaluate the entire expression as true
}

int main() {
    string exp = "F|T^F";  // Example expression
    
    // Evaluate the expression and find the number of ways to get the result as True
    int ways = evaluateExp(exp);
    
    // Output the result
    cout << "The total number of ways: " << ways << "\n";

    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Function to check if s1 can be formed by inserting exactly one character into s2
bool checkPossible(string &s1, string &s2) {
    if(s1.size() != s2.size() + 1) return false;
    int first = 0;
    int second = 0;
    while(first < s1.size()) {
        if(second < s2.size() && s1[first] == s2[second]) {
            first++;
            second++;
        }
        else {
            first++;
        }
    }
    if(first == s1.size() && second == s2.size()) return true;
    return false;
}

// Comparator function to sort strings by length
bool compareLength(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}

// Function to find the length of the longest string chain
int longestStrChain(vector<string> &arr) {
    int n = arr.size();
    if (n == 0) return 0;

    // Sort the array by string length to ensure proper DP transitions
    sort(arr.begin(), arr.end(), compareLength);

    vector<int> dp(n, 1);
    int maxi = 1;

    // LIS-style DP approach
    for(int i = 0; i < n; i++) {
        for(int prev = 0; prev < i; prev++) {
            if(checkPossible(arr[i], arr[prev]) && 1 + dp[prev] > dp[i]) {
                dp[i] = 1 + dp[prev];
            }
        }
        if(dp[i] > maxi) {
            maxi = dp[i];
        }
    }
    return maxi;
}

int main() {
    // Example test case
    vector<string> words = {"a", "b", "ba", "bca", "bda", "bdca"};

    cout << "Words list: ";
    for (const string &w : words) {
        cout << w << " ";
    }
    cout << endl;

    int result = longestStrChain(words);
    cout << "Length of the longest string chain: " << result << endl;

    return 0;
}

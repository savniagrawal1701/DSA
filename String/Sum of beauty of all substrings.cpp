#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int sum = 0;

        
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> freq;

            for (int j = i; j < n; j++) {
                
                freq[s[j]]++;

                int maxi = INT_MIN;
                int mini = INT_MAX;

                
                for (auto it : freq) {
                    mini = min(mini, it.second);
                    maxi = max(maxi, it.second);
                }

                
                sum += (maxi - mini);
            }
        }

        return sum;
    }
};

int main() {
    Solution sol;
    string s = "xyyzkhdix";
    cout << "Beauty Sum: " << sol.beautySum(s) << endl;
    return 0;
}

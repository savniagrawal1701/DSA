#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
 
    int numberOfSubstrings(string s) {
  
        vector<int> freq(3, 0);

        int res = 0;

        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            // Increment frequency of current character
            freq[s[right] - 'a']++;

            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                // Count all substrings from current right to end
                res += (s.length() - right);

        
                freq[s[left] - 'a']--;
                left++;
            }
        }

        return res;
    }
};

// Driver code
int main() {
    Solution sol;
    string s = "abcabc";
    cout << sol.numberOfSubstrings(s) << endl;
    return 0;
}
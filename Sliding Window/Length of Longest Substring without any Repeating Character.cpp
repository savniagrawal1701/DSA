#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestNonRepeatingSubstring(string& s) {
        int n = s.size();
       
        int HashLen = 256; 
        int hash[HashLen]; 
        for (int i = 0; i < HashLen; ++i) {
            hash[i] = -1;
        }

        int l = 0, r = 0, maxLen = 0;
        while (r < n) {
        
            if (hash[s[r]] != -1) {
               if(hash[s[r]]>=l)
               {
                l=hash[s[r]]+1;
               }
            }
            int len = r - l + 1;
            maxLen = max(len, maxLen);
            
            hash[s[r]] = r;
        
            r++;
        }
        return maxLen;
    }
};

int main() {
    string s = "cadbzabcd"; 
    
    Solution sol;

    int result = sol.longestNonRepeatingSubstring(s);

    cout << "The maximum length is:\n";
    cout << result << endl;

    return 0;
}


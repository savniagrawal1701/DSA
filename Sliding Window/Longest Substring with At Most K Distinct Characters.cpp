#include <bits/stdc++.h>
using namespace std;

int longestSubstringKDistinct(string s, int k) {
    int maxlen = 0;
    int l = 0, r = 0;
    unordered_map<char, int> mpp;

    while (r < s.size()) {
        mpp[s[r]]++;

        if (mpp.size() > k) {
            mpp[s[l]]--;
            if (mpp[s[l]] == 0) {
                mpp.erase(s[l]);
            }
            l = l + 1;
        }

        if (mpp.size() <= k) {
            maxlen = max(maxlen, r - l + 1);
        }

        r = r + 1;
    }

    return maxlen;
}

int main() {
    string s = "aaabbccd";
    int k = 2;

    int result = longestSubstringKDistinct(s, k);

    cout << "Maximum length of substring with " << k << " distinct characters: " << result << endl;

    return 0;
}

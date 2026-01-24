#include<bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
    int n = s.size();
    int m = t.size();
    int hash[256] = {0}; // Pre-fill with chars to find
    int l = 0, r = 0, minlen = 1e9, sIndex = -1, cnt = 0;

    for (int i = 0; i < m; i++) {
        hash[t[i]]++;
    }

    while (r < n) {
        // Expand right pointer
        if (hash[s[r]] > 0) {
            cnt = cnt + 1;
        }
        hash[s[r]]--;

        // Shrink left pointer when all chars are matched
        while (cnt == m) {
            if (r - l + 1 < minlen) {
                minlen = r - l + 1;
                sIndex = l;
            }

            hash[s[l]]++;
            if (hash[s[l]] > 0) {
                cnt = cnt - 1;
            }
            l = l + 1;
        }
        r = r + 1;
    }

    return (sIndex == -1) ? "" : s.substr(sIndex, minlen);
}

int main() {
    string s = "ddaaabbca";
    string t = "abc";
    cout << "Minimum Window Substring: " << minWindow(s, t) << endl;
    return 0;
}

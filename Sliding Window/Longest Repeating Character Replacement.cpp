#include<bits/stdc++.h>

using namespace std;

int characterReplacement(string s, int k) {
    int n = s.length();
    int l = 0, r = 0, maxlen = 0, maxf = 0;
    vector<int> hash(26, 0);

    while (r < n) {
        hash[s[r] - 'A']++;
        maxf = max(maxf, hash[s[r] - 'A']);

        if ((r - l + 1) - maxf > k) {
            hash[s[l] - 'A']--;
            l++;
        }

        if ((r - l + 1) - maxf <= k) {
            maxlen = max(maxlen, r - l + 1);
        }

        r++;
    }
    return maxlen;
}

int main() {
    string s = "AABABBA";
    int k = 2;
    cout << characterReplacement(s, k) << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    static bool comparator(pair<int, char> p1, pair<int, char> p2) {
        if (p1.first > p2.first) return true;
        if (p1.first < p2.first) return false;
        return p1.second < p2.second;
    }

public:
    // 1. Changed return type to string
    string frequencySort(string s) {
        pair<int, char> freq[128]; // Use 128 to handle uppercase and symbols
        
        for (int i = 0; i < 128; i++) {
            freq[i] = {0, (char)i};
        }

        for (char ch : s) {
            freq[(int)ch].first++;
        }

        sort(freq, freq + 128, comparator);

        // 2. Build the string by repeating characters
        string ans = "";
        for (int i = 0; i < 128; i++) {
            if (freq[i].first > 0) {
                // Add the character 'freq[i].first' times
                ans.append(freq[i].first, freq[i].second);
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    string s = "tree";

    // Now returns a full string
    string result = sol.frequencySort(s);

    cout << result << endl; // Output: "eert"

    return 0;
}
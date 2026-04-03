#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string ans = "";

        reverse(s.begin(), s.end());

        for (int i = 0; i < n; i++) {
            string word = "";
            
            while (i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }
            reverse(word.begin(), word.end());

            if (word.length() > 0) {
                ans += " " + word;
            }
        }

        return ans.length() > 0 ? ans.substr(1) : "";
    }
};

int main() {
    Solution sol;
    string input = "the sky is blue";
    string result = sol.reverseWords(input);

    cout << "Original: " << input << endl;
    cout << "Reversed: " << result << endl;

    return 0;
}
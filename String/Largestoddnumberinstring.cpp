#include<iostream>
using namespace std;
class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        string ans = "";
        for (int i = n - 1; i >= 0; i--) {
            if ((num[i] - '0') % 2 != 0) {
                return num.substr(0, i + 1);
            }
        }
        return ans;
    }
};
int main()
{
    string s = "345769";

    Solution sol;

    string ans = sol.largestOddNumber(s);

    cout << "The result is: " << ans << endl;

    return 0;
}
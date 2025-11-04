#include <bits/stdc++.h>
using namespace std;

// Solution class
class Solution
{
public:
    vector<int> printLeaders(vector<int> &v, int n)
    {

        vector<int> ans;
        int max = v[n - 1];
        ans.push_back(v[n - 1]);

        for (int i = n - 2; i >= 0; i--)
            if (v[i] > max)
            {
                ans.push_back(v[i]);
                max = v[i]; // no need of maxi function and maxi
            }
        return ans;
    }
};
int main()
{
    vector<int> nums = {10, 28, 13, 5, 1, 7};
    Solution s1;
    vector<int> ans = s1.printLeaders(nums, nums.size());
    for (int i = ans.size() - 1; i >= 0; i--)
    { // for sorted array kyuki aapni wali ulti hai
        cout << ans[i] << " ";
    }

    cout << endl;
    return 0;
}
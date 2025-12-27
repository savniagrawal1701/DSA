#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreater(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> res(n);

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }
            if (st.empty()) res[i] = -1;
            else res[i] = st.top();
            st.push(nums[i]);
        }

        return res;
    }
};

int main() {
    vector<int> nums = {4,12,5,3,1,2,5,3,1,2,4,6};
    Solution sol;
    vector<int> ans = sol.nextGreater(nums);

    for (int x : ans) {
        cout << x << " ";
    }

    cout << endl;
    return 0;
}
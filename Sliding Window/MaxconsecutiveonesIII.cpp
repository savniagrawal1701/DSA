#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int left = 0;

        int zerocount = 0;
        int maxlen = 0;

        for (int right = 0; right < nums.size(); right++) {

            if (nums[right] == 0) {
                zerocount++;
            }

            if (zerocount > k) {
                if (nums[left] == 0) {
                    zerocount--;
                }
             
                left++; 
            }

            maxlen = max(maxlen, right - left + 1);
        }

        return maxlen;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;

    cout << sol.longestOnes(nums, k) << endl;
    return 0;
}
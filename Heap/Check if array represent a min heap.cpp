#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
   
    bool isMinHeap(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i <= (n / 2) - 1; i++) {

            int left = 2 * i + 1;

            if (left < n && nums[i] > nums[left]) {
                return false;
            }

            int right = 2 * i + 2;
            if (right < n && nums[i] > nums[right]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {10, 20, 30, 21, 23};

  
    cout << (obj.isMinHeap(nums) ? "true" : "false") << endl;
    return 0;
}

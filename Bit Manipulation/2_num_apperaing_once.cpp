#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> singleNumber(vector<int>& nums){
      
        int n = nums.size();
        long XOR = 0;
        for(int i=0; i < n; i++) {
          
            XOR = XOR ^ nums[i];
        }
       
        int rightmost = (XOR & (XOR - 1)) ^ XOR;
      int b1 = 0, b2 = 0;
       
        for(int i=0; i < n; i++) {
           
            if(nums[i] & rightmost) {
                b1 = b1 ^ nums[i];
            }
            else {
                b2 = b2 ^ nums[i];
            }
        }
       
        if(b1 < b2) return {b1, b2};
        return {b2, b1};
    }
};

int main() {
    vector<int> nums = {1, 2, 1, 3, 5, 2};
 
    Solution sol; 
    vector<int> ans = sol.singleNumber(nums);
    
    cout << "The single numbers in given array are: " << ans[0] << " and " << ans[1];
    
    return 0;
}
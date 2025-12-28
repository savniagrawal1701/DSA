//a problem where we need to return the indexes
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target) {
       vector<int> ans ;
       unordered_map<int,int>mp;
       for(int i =0;i<nums.size();i++){
        int num=nums[i];
           int complement = target - num; 
           if (mp.find(complement) != mp.end()) {
           ans.push_back(mp[complement]);
            ans.push_back(i);
           }
             mp[nums[i]] = i;
       }
       return ans;
    }
};
int main() {
    Solution sol;
    vector<int> arr = {2, 6, 5, 8, 11};

    vector<int> res = sol.twoSum(arr, 10);
    cout << "[" << res[0] << ", " << res[1] << "]\n";

    return 0;
}

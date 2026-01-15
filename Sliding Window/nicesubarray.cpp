#include <bits/stdc++.h>
using namespace std;
class solution{
    public:
long long Subarrays(std::vector<int>& nums, int goal) {
    if (goal < 0) return 0;

    int l = 0, r = 0;
    long long sum = 0;
    long long cnt = 0;
    int n = nums.size();

    while (r < n) {
        sum += (nums[r]%2);
        while (sum > goal) {
            sum -= (nums[l]%2);
            l = l + 1;
        }
        cnt = cnt + (r - l + 1);
        r = r + 1;
    }

    return cnt;
}
long long countSubarrays(std::vector<int>& nums, int goal) {
    int ans=Subarrays(nums,goal)-Subarrays(nums,goal-1);
    return ans;
}
}; 
int main(){
    solution sol;
    vector<int> nums = {1,1,2,1,1};
    int goal = 3;

    long long result = sol.countSubarrays(nums, goal);

    cout << "Number of subarrays with sum " << goal << " is: " << result << endl;

    return 0;
}
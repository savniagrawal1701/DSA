#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int atMostK(vector<int> &nums, int K)
    {
        unordered_map<int, int> freq;
        int left = 0, count = 0, right = 0;
        while (right < nums.size())
        {
            freq[nums[right]]++;
            while (freq.size() > K)
            {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0)
                {
                    freq.erase(nums[left]);
                    
                }
                left++;
               
            }
             count = count + (right - left + 1);
                right = right + 1;
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 1, 3, 4};
    int k = 3;
    cout << sol.subarraysWithKDistinct(nums, k) << endl;
    return 0;
}

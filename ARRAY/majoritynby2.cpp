#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele;
        int count = 0;
        int n = nums.size();
        for (int temp=0; temp < n; temp++) {
            if (count == 0) {
                count = 1;
                ele = nums[temp];
            } else if (nums[temp] == ele) {
                count++;
            } else {
                count--;
            }
        }
        int cnt1 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == ele)
                cnt1++;
        }

        if (cnt1 > (n / 2))
            return ele;
        return -1;
    }
};
int main()
{
    Solution s1;
    vector<int> a={1,6,7,9,1,0,1,1,1,1};
    int ans =s1.majorityElement(a);
    cout<<"The element that occur more than n/2 times is : "<<ans;
    return 0;
}
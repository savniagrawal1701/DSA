#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        long long sum=n*(n+1)/2;
        long long sum2=0;
        for(int i =0;i<n;i++){
            sum2 += nums[i];
        }
        return (sum-sum2);
    }
};
int main()
{
   Solution s1;
    vector<int> v = {0,1,2,3,4,5,6,7,9};
    cout << "Missing number is" << endl;
    int ans =s1.missingNumber(v);
    cout<<ans;
    return 0;
}

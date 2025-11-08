#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int XOR = 0 ;
        int n=nums.size();
        for(int i=0;i<n;i++){
            XOR=XOR^nums[i];
        }
        return XOR;
    }
};
int main(){
    vector<int> a={11,5,2,11,6,3,6,9,4,2,5,9,4};
    Solution s1;
    int ans=s1.singleNumber(a);
    cout<<"The number that appear once in a array is :"<<ans;
    return 0;
}

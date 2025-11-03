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
    Solution s1;
    vector<int> v={1,2,1,2,4,7,8,7,4};
    int num=s1.singleNumber(v);
    cout<<"The singke number is "<<num<<endl;

}

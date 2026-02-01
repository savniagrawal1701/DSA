#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n =nums.size();
        priority_queue<int,vector<int>,greater<int>> minheap;
        for(int i =0;i<k;i++){
            minheap.push(nums[i]);
        }
        for(int i=k;i<=n-1;i++){
            if(nums[i]>minheap.top()){
                minheap.pop();
                minheap.push(nums[i]);
            }
        }
        int ans=minheap.top();
        return ans;
    }
};
int main(){
    vector<int> nums={3,2,3,1,2,4,5,5,6};
    int k=4;
    Solution sol;
    int ans=sol.findKthLargest(nums,k);
    cout<<"The Kth largest element in the array is :"<<ans<<endl;
    return 0;
}
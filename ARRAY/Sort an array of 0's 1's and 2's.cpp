//optimised solution (Dutch star algorithm)
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
     int low=0;int mid=0;int high= nums.size()-1;
     while(mid<=high) {
        if(nums[mid]==0){
            swap(nums[mid],nums[low]);
            low++;
            mid++;
        }else if(nums[mid]==1){
            mid++;
        }else{
            swap(nums[mid],nums[high]);
            high--;
        }

     }  
    }
};
int main()
{
   Solution s1;
    vector<int> arr = {0,1,2,0, 2, 1, 2, 0, 1};
    s1.sortColors(arr);
    cout << "After sorting:" << endl;
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

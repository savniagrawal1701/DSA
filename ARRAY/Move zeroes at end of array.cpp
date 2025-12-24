#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void zeroesatend(vector<int>& nums) {
     int j=-1;
     for(int i=0;i<nums.size();i++){
        if(nums[i]==0){
            j=i;
            break;
        }
     }
        if (j==-1) return ;
     for(int i=j+1;i<nums.size();i++){
        if(nums[i]!=0){
            swap(nums[i],nums[j]);
            j++;
        }
     }
    }
};
int main()
{
   Solution s1;
    vector<int> arr = {0,8,6,2,0,5, 2, 0, 1};
    s1.zeroesatend(arr);
    cout << "After sorting:" << endl;
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}


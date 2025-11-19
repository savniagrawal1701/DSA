#include <bits/stdc++.h>
using namespace std;
class solution
{
public:
    int totalarrayrot(vector<int> &nums)
    {
         int low = 0;
        int n=nums.size();
        int high = nums.size()-1;
        int ans = INT_MAX;
       int index;
        while (low <= high)
        {
            int mid = low + (high-low)/ 2;
            if (nums[low] <= nums[mid])
            { //= is there for one element
              
                
                if(ans>nums[low]){
                    index=low;
                }
                  ans = min(ans, nums[low]);
                 low = mid + 1;
            }
            else
            {
             
                  if(ans>nums[mid]){
                    index=mid;
                }
                 ans = min(ans, nums[mid]);
                  high = mid - 1;
            }
        }
   return index;
    }
};
int main()
{
    vector<int> arr = {7, 9, 1, 2, 3, 4, 5, 6};
    solution s1;
    int ans = s1.totalarrayrot(arr);

    cout << "The minimum in the array is " << ans << "\n";
    return 0;
}
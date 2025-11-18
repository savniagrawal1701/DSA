#include <bits/stdc++.h>
using namespace std;
class solution
{
public:
    int mininrotatedsorted(vector<int> &nums)
    {
        int low = 0;
        int high = nums.size()-1;
        int ans = INT_MAX;
        while (low <= high)
        {
            int mid = low + (high-low)/ 2;
            if (nums[low] <= nums[mid])
            { //= is there for one element
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
                ans = min(ans, nums[mid]);
            }
        }
        return ans;
    }
};
int main()
{
    vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    solution s1;
    int ans = s1.mininrotatedsorted(arr);

    cout << "The minimum in the array is " << ans << "\n";
    return 0;
}
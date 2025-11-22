#include <bits/stdc++.h>
using namespace std;
class solution
{
public:
    int sumbyD(vector<int> &nums, int div)
    {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            sum = sum + ceil(double(nums[i]) / double(div));
        }
        return sum;
    }
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int ans = -1;
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (sumbyD(nums, mid) <= threshold)
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
    };
    int main() {
    solution solver;
    vector<int> arr = {1, 2, 3, 4, 5};
    
    int ans = solver.smallestDivisor(arr, 7);
    cout << "The minimum divisor is: " << ans << "\n";
    return 0;
}
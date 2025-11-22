#include <bits/stdc++.h>
using namespace std;
class solution
{
public:
    bool possible(vector<int> &v, int day, int m, int k)
    {
        int count = 0;
        int noofB=0;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] <= day)
                count++;
            else
            {
                noofB += (count / k);
                count = 0;
            }
        }
        noofB += (count / k); // last wwale count ke liye where if is still working but there are no more elements
        return noofB >= m;
    }
    int roseGarden(vector<int> &v, int r, int b)
    {
        int ans =-1;
        long long val = r*1LL*b*1LL;
        if (v.size() < val)
            return ans;
        int mini = INT_MIN;
        int maxi = INT_MAX;
        for (int i = 0; i < v.size(); i++)
        {

            mini = min(mini, v[i]);

            maxi = max(maxi, v[i]);
        }
        long long  low = mini;
        long long  high = maxi;
        while (low <= high)
        {
            long long mid = low + (high - low) / 2;
            if (possible(v, mid, b, r))
            {
                ans=mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
        
    }
};
int main() {
    vector<int> arr = {7, 7, 7, 7, 13, 11, 11, 7};
    solution sol;
    int ans = sol.roseGarden(arr, 3, 2);

    if (ans == -1)
        cout << "We cannot make m bouquets.\n";
    else
        cout << "We can make bouquets on day " << ans << "\n";

    return 0;
}
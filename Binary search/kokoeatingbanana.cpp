#include <bits/stdc++.h>
using namespace std;
class solution
{
public:
    // to know the range
    int maxinaaray(vector<int> &v)
    {
        int maxi = INT_MIN;
        int n = v.size();
        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi, v[i]);
        }
        return maxi;
    }

    int calculatehours(vector<int> &v, int k)
    {
        int totalh = 0;
        int n = v.size();
        for (int i = 0; i < n; i++)
        {
            totalh += ceil((double)v[i] / (double)k);
        }
        return totalh;
    }
    int minratetoeat(vector<int> &v, int h)
    {
        int low = 1;
        int high = maxinaaray(v);
        int ans =  maxinaaray(v);
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int totalh = calculatehours(v, mid);
            if (totalh <= h)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};
int main() {
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    solution obj;
    cout <<"Bananas to eat hourly "<< obj.minratetoeat(piles, h);
    return 0;
}
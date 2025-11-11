#include <bits/stdc++.h>
using namespace std;
class solution
{
public:
    int lowerbound(vector<int> &v, int target)
    { 
        int n = v.size();
        int low = 0;
        int high = n - 1;
        int ans=n;
        while (low <= high)
        {
            int mid = low + (high-low) / 2;
            if (v[mid] >=target)
            {
               ans=mid;
               high=mid-1;
            }else{
                low=mid+1;
            }
            
        }
        return ans;
    }
};
int main()
{
    solution s1;
    vector<int> x = {2, 3, 4, 5, 6, 7, 9};
    int ans = s1.lowerbound(x, 1);
    cout << "Index at which the target is present is: " << ans;
    return 0;
}

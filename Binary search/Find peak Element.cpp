#include <bits/stdc++.h>
using namespace std;
class solution
{
public:
    int peakelement(vector<int> &v)
    {
        int n = v.size();
        int low = 1;
        int high = n - 2;
        if (n == 1)
            return v[0];
        if (v[0] > v[1])
            return v[0];
        if (v[n - 1] > v[n - 2])
            return v[n - 1];
        while (low <= high)
        {
           int mid = low + (high - low) / 2;
            if (v[mid] > v[mid - 1] && v[mid] > v[mid + 1])
            {
                return v[mid];
            }
            else if (v[mid] > v[mid - 1])
            {
                low = mid + 1;
            }
            else if (v[mid] > v[mid + 1])
            {
                high = mid - 1;
            }
            else
            {
                high = mid - 1; // or low=mid+1 any will work
            }
        }
        return -1;
    }
};
int main()
{

    vector<int> nums = {5,8,6,7,0};
    solution obj;
    int ans = obj.peakelement(nums);
    cout << "The peak element is :" << ans << endl;

    return 0;
}

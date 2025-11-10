#include <bits/stdc++.h>
using namespace std;
class solution
{
public:
    int binarysearch(vector<int> &v, int target)
    {
        int n = v.size();
        int low = 0;
        int high = n - 1;
        while (low <= high)
        {
            int mid = low + high / 2;
            if (v[mid] == target)
            {
                return mid;
            }
            else if (target > v[mid])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return -1;
    }
};
int main()
{
    solution s1;
    vector<int> x = {2, 3, 4, 5, 6, 7, 9};
    int ans = s1.binarysearch(x, 3);
    cout << "Index at which the target is present is: " << ans;
    return 0;
}
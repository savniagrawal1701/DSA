#include <bits/stdc++.h>
using namespace std;
class solution
{
public:
    int maxprod(vector<int> &v)
    {
        int prefix = 1;
        int suffix = 1;
        int maxp = INT_MIN;
        int n = v.size();
        for (int i = 0; i < n; i++)
        {
            if (prefix == 0)
            {
                prefix = 1;
            }
            if (suffix == 0)
            {
                suffix = 1;
            }
            prefix = prefix * v[i];
            suffix = suffix * v[n - i - 1];
         maxp = max(maxp, max(prefix, suffix));
        }
        return maxp;
    }
};

int main()
{

    vector<int> arr = {2, 2,1, -2, 4};

    solution obj;
    cout << "Maximum product subarray ans: " << endl;
    cout << obj.maxprod(arr) << endl;

    return 0;
}
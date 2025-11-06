#include <bits/stdc++.h>
using namespace std;

// Solution class
class Solution
{
public:
    void nextpermutation(vector<int>& v)
    {
        int ind = -1;
        int n = v.size();
        for (int i = n - 2; i >= 0; i--)
        {
            if (v[i] < v[i + 1]){
                ind = i;
            break;
        }
    }
        if (ind == -1)
        {
            reverse(v.begin(), v.end());
            return;
        }
        for (int i = n - 1; i > ind; i--)
        {
            if (v[i] > v[ind])
            {
                swap(v[i], v[ind]);
                break;
            }
        }
        reverse(v.begin() + ind + 1 , v.end());
   
    }
};
int main()
{
    vector<int> nums = {3, 2, 1, 9, 7, 8, 9, 1};
    Solution s1;
    s1.nextpermutation(nums);

    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

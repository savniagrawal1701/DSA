#include <bits/stdc++.h>
using namespace std;
class solution
{
public:
    vector<vector<int>> getPowerSet(vector<int> &nums)
    {
        int n = nums.size();

        int subsets = 1 << n;
        vector<vector<int>> ans;

        for (int num = 0; num < subsets; num++)
        {
            vector<int> subset;
            for (int i = 0; i < n; i++)
            {
                if (num & (1 << i))
                {
                    subset.push_back(nums[i]);
                }
            }
            ans.push_back(subset);
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {5, 7, 8};

    solution obj;
    vector<vector<int>> subsets = obj.getPowerSet(nums);

    cout << "Initial Input Array: ";
    for (auto num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    cout << "Subsets: " << endl;
    for (auto subset : subsets)
    {
        cout << "[ ";
        for (auto num : subset)
        {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
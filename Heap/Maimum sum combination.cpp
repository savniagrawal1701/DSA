#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxCombinations(vector<int> &nums1, vector<int> &nums2, int k)
    {

        sort(nums1.begin(), nums1.end(), greater<int>());
        sort(nums2.begin(), nums2.end(), greater<int>());

        priority_queue<tuple<int, int, int>> maxHeap;

        set<pair<int, int>> visited;

        maxHeap.push({nums1[0] + nums2[0], 0, 0});
        visited.insert({0, 0});

        vector<int> result;
        while (k-- && !maxHeap.empty())
        {
            auto top = maxHeap.top();
            int sum = get<0>(top);
            int i = get<1>(top);
            int j = get<2>(top);
            maxHeap.pop();

            result.push_back(sum);

            if (i + 1 < nums1.size() && !visited.count({i + 1, j}))
            {
                maxHeap.push({nums1[i + 1] + nums2[j], i + 1, j});
                visited.insert({i + 1, j});
            }

            if (j + 1 < nums2.size() && !visited.count({i, j + 1}))
            {
                maxHeap.push({nums1[i] + nums2[j + 1], i, j + 1});
                visited.insert({i, j + 1});
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {7, 3};
    vector<int> nums2 = {1, 6};
    int k = 2;
    vector<int> result = sol.maxCombinations(nums1, nums2, k);
    for (int val : result)
        cout << val << " ";
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &arr, int i, vector<int> &dp)
    {

        if (i < 0)
            return 0;

        if (i == 0)
            return arr[0];

        if (dp[i] != -1)
            return dp[i];

        int pick = arr[i] + solve(arr, i - 2, dp);

        int notPick = solve(arr, i - 1, dp);

        return dp[i] = max(pick, notPick);
    }

    int maximumNonAdjacentSum(vector<int> &arr)
    {
        int n = arr.size();

        vector<int> dp(n, -1);

        return solve(arr, n - 1, dp);
    }
};

int main()
{
    vector<int> arr = {2, 1, 4, 9};
    Solution obj;

    cout << obj.maximumNonAdjacentSum(arr);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumNonAdjacentSum(vector<int> &arr)
    {

        int n = arr.size();

        if (n == 1)
            return arr[0];

        vector<int> dp(n);

        dp[0] = arr[0];

        dp[1] = max(arr[0], arr[1]);

        for (int i = 2; i < n; i++)
        {

            dp[i] = max(arr[i] + dp[i - 2], dp[i - 1]);
        }

        return dp[n - 1];
    }
};

int main()
{
    vector<int> arr = {2, 1, 4, 9};
    Solution obj;
    cout << obj.maximumNonAdjacentSum(arr);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSum(vector<int> &nums)
    {

        if (nums.empty())
            return 0;

        int prev2 = 0;
        int prev = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {

            int include = nums[i] + prev2;

            int exclude = prev;

            int curr = max(include, exclude);

            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
};

int main()
{
    vector<int> arr = {3, 2, 5, 10, 7};
    Solution obj;
    cout << obj.maxSum(arr) << endl;
    return 0;
}

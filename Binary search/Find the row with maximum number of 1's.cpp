#include <bits/stdc++.h>
using namespace std;
class solution
{
public:
    int lowerbound(vector<int> &v, int n, int target)
    {
        int low = 0;
        int high = n - 1;
        int ans = n;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (v[mid] >= target)
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
    int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
    {
        int cnt_max = 0;
        int index = -1;

        for (int i = 0; i < n; i++)
        {
            int cnt_ones = m - lowerbound(matrix[i], m, 1);
            if (cnt_ones > cnt_max)
            {
                cnt_max = cnt_ones;
                index = i;
            }
        }
        return index;
    }
};
int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
    int n = 3, m = 3;

    solution obj;
    int ans=obj.rowWithMax1s(matrix, n, m);
    cout << "The row with maximum no. of 1's is : " <<ans << endl;
    return 0;
}

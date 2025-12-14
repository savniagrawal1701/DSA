#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void reverseArray(vector<int> &arr, int i)
    {

        int n = arr.size();
        if (i >= n / 2) return ;
        

            swap(arr[i], arr[n - i - 1]);
            reverseArray(arr, i + 1);
        
    }
};

int main()
{

    Solution sol;

    vector<int> arr = {1, 2, 0, 4, 5,6,7};

    sol.reverseArray(arr, 0);

    for (int num : arr)
    {
        cout << num << " ";
    }

    return 0;
}
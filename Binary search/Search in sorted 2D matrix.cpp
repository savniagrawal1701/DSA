#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
   
    bool searchArray(vector<vector<int>>& array, int target) {
       
        int n = array.size();

        int m = array[0].size();

        int low = 0, high = n * m - 1;

        while (low <= high) {
           
            int mid = (low + high) / 2;

            int r = mid / m;
            int c = mid % m;

            if (array[r][c] == target)
                return true;

            else if (array[r][c] < target)
                low = mid + 1;

            else
                high = mid - 1;
        }

        return false;
    }
};

int main() {
   
    vector<vector<int>> array = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 13}
    };

    Solution obj;

    if (obj.searchArray(array, 12))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}

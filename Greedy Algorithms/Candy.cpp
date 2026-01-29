#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int candy(vector<int>& ratings) {

        int n = ratings.size();

        int candies = n;
        int i = 1;

        while (i < n) {
            if (ratings[i] == ratings[i - 1]) {
                i++;
                continue;
            }
            int peak = 0;

            while (i < n && ratings[i] > ratings[i - 1]) {
                peak++;
                candies += peak;
                i++;
            }

            int valley = 0;
            while (i < n && ratings[i] < ratings[i - 1]) {
                valley++;
                candies += valley;
                i++;
            }
    
            candies -= min(peak, valley);
        }

        return candies;
    }
};

int main() {
    Solution sol;
    vector<int> ratings = {1, 3, 6, 8, 9, 5, 3};
    cout << "Minimum candies required: " << sol.candy(ratings) << endl;

    return 0;
}
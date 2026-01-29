#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i = 0;
        int n = intervals.size();
        
        while (i < n && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i]);
            i++;
        }
        
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);
        
        while (i < n) {
            res.push_back(intervals[i]);
            i++;
        }
        
        return res;
    }
};
int main(){
    Solution sol;
   vector<vector<int>> intervals2 = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    vector<int> newInterval2 = {4, 8};
    vector<vector<int>> result2 = sol.insert(intervals2, newInterval2);
      cout << "Resultant array is: ";
    for (const auto& interval : result2) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl; // Expected: [1,2] [3,10] [12,16]

    return 0;

}
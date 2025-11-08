#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(ans.empty()||intervals[i][0]>ans.back()[1]){
                ans.push_back(intervals[i]);
            }else{
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
            }
        }
        return ans;
    }
};
int main()
{
   Solution s1;
    vector<vector<int>> v = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    cout << "Result is:" << endl;
    vector<vector<int>> result =s1.merge(v);
       for (auto v : result) {
        cout << "[" << v[0] << "," << v[1] << "] ";
    }
    return 0;
}

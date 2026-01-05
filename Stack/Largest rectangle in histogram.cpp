#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();
        
        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] > heights[i]) {
                int element = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                maxArea = max(heights[element] * (nse - pse - 1), maxArea);
            }
            st.push(i);
        }
        
        while(!st.empty()) {
            int nse = n;
            int element = st.top();
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            maxArea = max(heights[element] * (nse - pse - 1), maxArea);
        }
        
        return maxArea;
    }
};

int main() {
    vector<int> histo = {3,2,10,11,5,10,6,3}; // Input histogram
    Solution obj;
    cout << "The largest area in the histogram is " << obj.largestRectangleArea(histo) << endl;
    return 0;
}

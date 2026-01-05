#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
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

public:
    
    int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &matrix){
       
        int n = matrix.size();
        int m = matrix[0].size();
      
        vector<vector<int>> prefixSum(n, vector<int>(m));
       
        for(int j=0; j < m; j++) {
            int sum = 0;
            
            for(int i=0; i < n; i++) {
                sum += matrix[i][j];
             
                if(matrix[i][j] == 0) {
                    prefixSum[i][j] = 0;
                    sum = 0;
                }
                prefixSum[i][j] = sum;
            }
        }
        int maxArea = 0;
        for(int i = 0; i < n; i++) {
            int area = largestRectangleArea(prefixSum[i]);
           
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1, 0, 1, 0, 0}, 
        {1, 0, 1, 1, 1}, 
        {1, 1, 1, 1, 1}, 
        {1, 0, 0, 1, 0}
    };
    
    Solution sol; 
    int ans = 
        sol.maximalAreaOfSubMatrixOfAll1(matrix);
    
    cout << "The largest rectangle area containing all 1s is: " << ans;
    return 0;
}
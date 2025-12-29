#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int left = 0;
        int right = n - 1;
     
        int maxLeft = 0;
        int maxRight = 0;
        int totalWater = 0;
  
        while (left <= right) {

            if (height[left] <= height[right]) {
              
                if (height[left] >= maxLeft) {
                    maxLeft = height[left];
                } else {
                  
                    totalWater += maxLeft - height[left];
                }
                left++; 
            } else {
               
                if (height[right] >= maxRight) {
                    maxRight = height[right];
                } else {
                    
                    totalWater += maxRight - height[right];
                }
                right--; 
            }
        }
        return totalWater;
    }
};
int main() {
 
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
 
    Solution sol;
  
    int result = sol.trap(height);
    
    cout << "Trapped Rainwater: " << result << endl;
    
    return 0;
}

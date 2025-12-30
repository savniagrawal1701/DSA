#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int> &asteroids){
        
        int n = asteroids.size();
        
        vector<int> st;  
        
        for(int i=0; i < n; i++) {
           
            if(asteroids[i] > 0) {
                st.push_back(asteroids[i]);
            }
            else {
                while(!st.empty() && st.back() > 0 && 
                      st.back() < abs(asteroids[i])) {
                    
                    st.pop_back();
                }
                if(!st.empty() && 
                    st.back() == abs(asteroids[i])) {
                    
                    st.pop_back();
                }
                else if(st.empty() ||
                        st.back() < 0){
                    st.push_back(asteroids[i]);
                }
            }
        }
        return st;
    }
};

int main() {
    vector<int> arr = {4,7,1,1,2,-3,-7,17,15,-16};
 Solution sol;
    vector<int> ans = sol.asteroidCollision(arr);
    
    cout << "The state of asteroids after collisions is: ";
    for(int i=0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    
    return 0;
}